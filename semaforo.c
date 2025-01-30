#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

void init_pins();
bool repeating_timer_callback(struct repeating_timer *);

#define LED_PIN_GREEN 11
#define LED_PIN_BLUE 12
#define LED_PIN_RED 13

int main()
{
    stdio_init_all(); //Inicializa entrada e saída padrão
    init_pins(); //Inicializa os Pinos
    struct repeating_timer timer; // Declaração de uma struct de temporizador de repetição.

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
void init_pins()
{
    //Inicializa os pinos dos leds
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_put(LED_PIN_GREEN, 0);

    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_put(LED_PIN_BLUE, 0);

    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_put(LED_PIN_RED, 0);
}
bool repeating_timer_callback(struct repeating_timer *t)
{
    
    return true;
}