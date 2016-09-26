/*
 *  count.c
 *
 *  Counter that displays results on the LEDs of Port B
 *  (pins 8 to 13) of the Arduino UNO.
 *
 *  Author: M. J. Cree
 *
 */

#include <avr/io.h>
#include <util/delay.h>


/*
 * delay_ms(delay_in_ms)
 *
 * Delay the specified number of milliseconds.
 *
 * _delay_ms uses a floating point datatype if you call
 * that function in many places in your code then it becomes
 * very fat. An integer is enough for us.
 *
 */
void delay_ms(unsigned int xms)
{
    while (xms) {
        _delay_ms(0.96);
        xms--;
    }
}


/*
 * init_ports()
 *
 * Initialise the ports we will use --- in this case the lowest
 * six bits of PORTB are set to be outputs.
 */
void init_ports(void)
{
    /* Make bits 0 to 6 of PORTB outputs */
    DDRB = 0x03f;
    /* Set outputs to low voltage. */
    PORTB = 0;
}


/*
 * illuminate_leds(leds)
 *
 * Illuminate the six LEDs connected to bits 0 to 6
 * of Port B according to input leds.
 */
void illuminate_leds(int leds)
{
    PORTB = leds & 0x03f;
}


void main(void)
{
    int count;

    /* Initialise I/O Ports for use. */
    init_ports();

    /* Do forever... */
    count = 0;
    while (1) {
        illuminate_leds(count);
        count++;
        if (count > 0x3f)
            count = 0;
        delay_ms(100);
    }

    /* Cannot get here */
}
