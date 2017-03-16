/* interface.c
 * Created by Alec Thomas 16/3/17
 */

#include <interface.h>

#if defined(__AVR_ATmega1280__)
#include <bot_interface.c>
#else
#include <benchmark_interface.c>
#endif
