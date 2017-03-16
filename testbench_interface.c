/* testbench_interface.c
 * Created by Alec Thomas 16/3/17
 * Description: This file implements an interface to the testbench
 * which is identical to the bot interface.
 */

#include <interface.h>
#include <testbench.h>
#include <utils.h>

float get_velocity(void) {
    return testbench_get_velocity();
}

int set_velocity(double v) {
    int pmv = velocity_pmv_lookup(v);
    return testbench_set_pmv(pmv);
}
