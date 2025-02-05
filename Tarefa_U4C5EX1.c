#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Variável de estado para o semáforo
volatile int state = 0;

// Callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (state) {
        case 0:
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            break;
        case 1:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            break;
        case 2:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            break;
    }
    state = (state + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();
    
    // Configuração dos LEDs como saída
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (true) {
        printf("Passou 1 segundo...\n");
        sleep_ms(1000);
    }
}