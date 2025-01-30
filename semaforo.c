#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

void init_pins();
bool repeating_timer_callback(struct repeating_timer *);
uint8_t actual_state();
void next_state();

#define LED_PIN_GREEN 11
#define LED_PIN_BLUE 12
#define LED_PIN_RED 13

uint8_t state = LED_PIN_RED;

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
    gpio_put(LED_PIN_RED, 1);
}
bool repeating_timer_callback(struct repeating_timer *t)
{
    next_state();
    return true;
}
uint8_t actual_state(){
    if (gpio_get(LED_PIN_RED))
        return LED_PIN_RED;
    if (gpio_get(LED_PIN_BLUE))
        return LED_PIN_BLUE;
    if (gpio_get(LED_PIN_GREEN))
        return LED_PIN_GREEN;
}
void next_state(){
    state = actual_state();
    switch (state)
    {
    case LED_PIN_RED:
        gpio_put(LED_PIN_RED,0);
        gpio_put(LED_PIN_BLUE,1);
        break;
    case LED_PIN_BLUE:
        gpio_put(LED_PIN_BLUE,0);
        gpio_put(LED_PIN_GREEN,1);
        break;
    case LED_PIN_GREEN:
        gpio_put(LED_PIN_GREEN,0);
        gpio_put(LED_PIN_RED,1);
        break;
    default:
        printf("[ERRO]");
        break;
    }
    
}