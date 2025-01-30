#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

void init_pins();
bool repeating_timer_callback(struct repeating_timer);


struct repeating_timer timer;



int main()
{
    stdio_init_all();
    init_pins();

    add_repeating_timer_ms(3000,repeating_timer_callback,NULL,&timer);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("Abrorbora");
    return true;
}