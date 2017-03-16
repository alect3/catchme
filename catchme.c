#include <interface.h>

int distance;
float race_time;
float a;
float target_velocity;
float target_distance = 0;
unsigned long initial_time = 0;
unsigned long prev_time;
float vel_to_pwm = 0.4;
float dx;
float current_distance= 0;
int current_PWM;

void setup() {
  // put your setup code here, to run once:
  distance = 100;
  race_time = 9.58;
  a = 2*distance/(race_time*race_time); // set aceleration rate
  initial_time = millis();
  dx = distance/race_time;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float current_velocity = get_velocity();
  unsigned long current_time = millis();
  long dt = (long) (current_time - initial_time);
  
  target_distance = target_distance + dx*dt;
  current_distance = current_distance+current_velocity*dt;

  if((current_distance>distance)&&(target_velocity !=0)){
    Serial.println(current_time);
    target_velocity=0;
  }else{
    target_velocity = (target_distance - current_distance)/dt;
    a = (target_velocity - current_velocity)/dt;
    current_PWM = int(current_PWM + a*vel_to_pwm);
  }

  set_velocity(current_PWM);
  prev_time = current_time;
}