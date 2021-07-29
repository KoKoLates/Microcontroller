/*
 * GccApplication3.cpp
 *
 * Created: 4/8/2019 3:34:21 PM
 * Author : user
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>

int main(void)
{

	CLKPR=(1<<CLKPCE);
	CLKPR=0b00000011;
	TCCR0A=0x02;
	DDRD=0x0;
	PORTD=0xFF;
	DDRC=0xFF;
	DDRB=0xFF;
	while (1){
	  
	  if(~PIND&0b00000001){ 
	    TCCR0B=0b00000100; // p=256, start Timer
	    OCR0A=9;//n;
	    while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
	    TCCR0B=0; // stop Timer
	    TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
	    PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b00000010){//A.
	     TCCR0B=0b00000100; // p=256, start Timer
	     OCR0A=8;//n;
	     while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
	     TCCR0B=0; // stop Timer
	     TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
	     PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b00000100){//B.
	     TCCR0B=0b00000100; // p=256, start Timer
  	     OCR0A=7;//n;
	     while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
	     TCCR0B=0; // stop Timer
	     TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
	     PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b00001000){//C 
	    TCCR0B=0b00000011; // p=64, start Timer
   	    OCR0A=29;//n;
	    while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
	    TCCR0B=0; // stop Timer
	    TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
	    PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b00010000){//D
    	  TCCR0B=0b00000010; // p=8, start Timer
    	  OCR0A=212;//n;
    	  while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
    	  TCCR0B=0; // stop Timer
    	  TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
          PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b00100000){//E
    	  TCCR0B=0b00000100; // p=256, start Timer
	      OCR0A=5;//n;
    	  while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
    	  TCCR0B=0; // stop Timer
    	  TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
    	  PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b01000000){//F
    	  TCCR0B=0b00000011; // p=64, start Timer
    	  OCR0A=21;//n
    	  while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
    	  TCCR0B=0; // stop Timer
    	  TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
    	  PORTC=PORTC^0b00100000;
	  }
	  else if(~PIND&0b10000000){// G
    	  TCCR0B=0b00000100; // p=256, start Timer
    	  OCR0A=4;//n
    	  while ((TIFR0&(1<<OCF0A))==0); // wait for flag TOV0=1
    	  TCCR0B=0; // stop Timer
    	  TIFR0=TIFR0|(1<<OCF0A); // clear TOV0
    	  PORTC=PORTC^0b00100000;
	  }
	  else
	  PORTC=0x00;

	  	  if(~PIND&0b00000001){ //G.
		     PORTB=0b00010000;
	  	  }
	  	  else if(~PIND&0b00000010){//A.
		     PORTB=0b00001000;
	  	  }
	  	  else if(~PIND&0b00000100){//B.
	         PORTB=0b00000011;
	  	  }
	  	  else if(~PIND&0b00001000){//C
		     PORTB=0b11000110;
	  	  }
	  	  else if(~PIND&0b00010000){//D
		     PORTB=0b10100001;
	  	  }
	  	  else if(~PIND&0b00100000){//E
		     PORTB=0b10000110;
	  	  }
	  	  else if(~PIND&0b01000000){//F
		     PORTB=0b10001110;
	  	  }
	  	  else if(~PIND&0b10000000){// G
		     PORTB=0b10010000;
	  	  }
		

	}
}

