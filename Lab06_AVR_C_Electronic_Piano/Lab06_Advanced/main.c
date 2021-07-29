#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void A1();
void B1();
void G1();
void C();
void D();
void E();
void F();
void G();

int main(void)
{
	while(1){
		CLKPR=(1<<CLKPCE);
		CLKPR=0b00000000;
		TCCR0A=0x02;
		DDRC=0xFF;
		DDRB=0xFF;
		
		PORTB=0xFF;
		
		G1();
		_delay_ms(10);
		G1();
		_delay_ms(10);
		A1();
		_delay_ms(10);
		G1();
		_delay_ms(10);
		C();
		_delay_ms(10);
		B1();
		_delay_ms(500);
		
		G1();
		_delay_ms(10);
		G1();
		_delay_ms(10);
		A1();
		_delay_ms(10);
		G1();
		_delay_ms(10);
		D();
		_delay_ms(10);
		C();
		_delay_ms(500);
		
		G1();
		_delay_ms(10);
		G1();
		_delay_ms(10);
		G();
		_delay_ms(10);
		E();
		_delay_ms(10);
		C();
		_delay_ms(10);
		B1();
		_delay_ms(100);
		A1();
		_delay_ms(500);
		
		F();
		_delay_ms(10);
		F();
		_delay_ms(10);
		E();
		_delay_ms(10);
		C();
		_delay_ms(10);
		D();
		_delay_ms(10);
		C();
		_delay_ms(500);
		
		PORTC=0x0;
		PORTB=0xFF;
	}
}


void A1(){
	int n=0;
	
	PORTB=0b00001000;
	OCR0A=70;//n;
	while (n<220){
		TCCR0B=0b00000100; // p=256, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
void B1(){
	int n=0;
	PORTB=0b00000011;
	
	
	OCR0A=62;//n;
	while (n<230){
		TCCR0B=0b00000100; // p=256, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
void G1(){
	int n=0;
	PORTB=0b00010000;
	OCR0A=79;//n;
	
	while (n<210){
		TCCR0B=0b00000100;; // p=256, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
void C(){
	//T();
	int n=0;
	PORTB=0b11000110;


	OCR0A=238;//n;
	while (n<240){
		TCCR0B=0b00000011; // p=64, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
void D(){
	int n=0;
	PORTB=0b10100001;


	OCR0A=212;//n;
	while (n<270){
		TCCR0B=0b00000011; // p=64, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b00100000;
		n++;
	}
}
void E(){
	//T();
	int n=0;
	PORTB=0b10000110;


	OCR0A=46;//n;
	while (n<300){
		TCCR0B=0b00000100; // p=256, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
void F(){
	//T();

	PORTB=0b10001110;
	int n=0;

	OCR0A=178;//n
	while (n<330){
		TCCR0B=0b00000011; // p=64, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
void G(){


	PORTB=0b10010000;
	int n=0;

	OCR0A=39;//n
	while (n<360){
		TCCR0B=0b00000100; // p=256, start Timer
		while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
		TCCR0B=0; // stop Timer
		TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
		PORTC=PORTC^0b000100000;
		n++;
	}
}
