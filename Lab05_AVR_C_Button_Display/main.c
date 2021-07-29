#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRD=0x0;
	PORTD=0xFF;
	DDRC=0x0;
	PORTC=0xFF;
	DDRB=0xFF;
	PORTB=0b00100000;
	while (1){
		if(~PIND & 0b00000001)
		{
			PORTB=0b01111100;
		}
		if(~PIND&0b00000010)
		{
			PORTB=0b00010010;
		}
		if(~PIND&0b00000100)
		{
			PORTB=0b00011000;
		}
		if(~PIND&0b00001000)
		{
			PORTB=0b01001100;
		}
		if(~PIND&0b00010000)
		{
			PORTB=0b00001001;
		}
		if(~PIND&0b00100000)
		{
			PORTB=0b00000001;
		}
		if(~PIND&0b01000000)
		{
			PORTB=0b00111100;
		}
		if(~PINC&0b00001000)
		{
			PORTB=0b00000000;
		}
		if(~PINC&0b00010000)
		{
			PORTB=0b00001000;
		}
		if(~PINC&0b00100000)
		{
			PORTB=0b00100000;
		}
	}
}