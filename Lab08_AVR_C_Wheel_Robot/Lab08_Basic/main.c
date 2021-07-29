
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	CLKPR=(1<<CLKPCE);
	CLKPR=0b00000011; // set clk to 1Mhz
	DDRD=0xFF; // PORTD as output
	DDRB=0xFF;
	
	TCCR0A=0b10100011; // fast PWM, non-inverted
	TCCR0B=0b00000001; // timer prescaler
	TCCR2A=0b10100011; // fast PWM, non-inverted
	TCCR2B=0b00000001; // timer prescaler
	
	OCR0A=150; // % duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=150; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=0; // 0% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=100; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=150; // 100% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=150; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=0; // 0% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=100; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=150; // 100% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=150; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=0; // 0% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=100; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=150; // 100% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=150; // 100% duty cycle
	OCR2B=0; // 0% duty cycle
	_delay_ms(1000);
	
	OCR0A=0; // 0% duty cycle
	OCR0B=0; // 0% duty cycle
	OCR2A=0; // 0% duty cycle
	OCR2B=0; // 0% duty cycle
}


