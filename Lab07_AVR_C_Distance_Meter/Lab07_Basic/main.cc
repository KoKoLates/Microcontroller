#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
uint16_t ADCRead(const int);
void USART_putstring(char* StringPtr);
int main(void){
	CLKPR=(1<<CLKPCE);
	CLKPR=0b00000000;
	DDRB=0xFF;
	DDRD=0xFF;
	DDRC = 0;
	ADCSRA |= (1<<ADEN);
	unsigned int BaudR = 9600;
	unsigned int ubrr = (F_CPU / (BaudR*16UL))-1;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
	UCSR0B |= (1<<TXEN0);
	while(1){
		float sumVal = 0;
		char Buffer[]=" ";
		for(int i = 0; i < 10; i++)
		sumVal += (float)ADCRead(0);
		sumVal /= 10; //mean of 10 readings
		sumVal=19408*(pow(sumVal,-1.244));
		int a=(int)sumVal/10;
		int b=(int)sumVal%10;
		if(a==0)
		{
			PORTB=0b01000000;
		}
		else if(a==1)
		{
			PORTB=0b01111001;
		}
		else if(a==2)
		{
			PORTB=0b00100100;
		}
		else if(a==3)
		{
			PORTB=0b00110000;
		}
		else if(a==4)
		{
			PORTB=0b00011001;
		}
		else if(a==5)
		{
			PORTB=0b00010010;
		}
		else if(a==6)
		{
			PORTB=0b00000010;
		}
		else if(a==7)
		{
			PORTB=0b01010010;
		}
		else if(a==8)
		{
			PORTB=0b00000000;
		}
		else if(a==9)
		{
			PORTB=0b00010000;
		}
		if(b==0)
		{
			PORTD=0b10000000;
		}
		if(b==1)
		{
			PORTD=0b11110001;
		}
		else if(b==2)
		{
			PORTD=0b01001000;
		}
		else if(b==3)
		{
			PORTD=0b01100000;
		}
		else if(b==4)
		{
			PORTD=0b00110001;
		}
		else if(b==5)
		{
			PORTD=0b00100100;
		}
		else if(b==6)
		{
			PORTD=0b00000100;
		}
		else if(b==7)
		{
			PORTD=0b10110000;
		}
		else if(b==8)
		{
			PORTD=0b00000000;
		}
		else if(b==9)
		{
			PORTD=0b00100000;
		}
		char *intStr = itoa((int)sumVal, Buffer, 10);
		strcat(intStr, "\n");
		USART_putstring(intStr);
		_delay_ms(500);
	}
}
uint16_t ADCRead(const int channel) {
	ADMUX = 0b01000000;
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC) | (1<<ADIF);
	while ( (ADCSRA & (1<<ADIF)) == 0);
	ADCSRA &= ~(1<<ADSC);
	return ADC;
}
void USART_putstring(char* StringPtr){
	while(*StringPtr != 0x00){
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = *StringPtr;
		StringPtr++;
	}
}
