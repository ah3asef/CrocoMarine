#define F_CPU 16000000UL
#include <avr/io.h>
#define BAUD 9600
#define MYUBRR ((F_CPU / (16UL * BAUD)) - 1)

void USART_Init(unsigned int ubrr) {
	UBRRH = (unsigned char)(ubrr >> 8);
	UBRRL = (unsigned char)ubrr;

	UCSRB = (1 << RXEN) | (1 << TXEN);  
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); 
}

void USART_Transmit(unsigned char data) {
	while (!(UCSRA & (1 << UDRE)));
	UDR = data;
}

unsigned char USART_Receive(void) {
	while (!(UCSRA & (1 << RXC)));
	return UDR;
}


int main(void) {
	USART_Init(MYUBRR);
    while(1){
	char received_char = USART_Receive();
	char enter = USART_Receive();
	if(enter == '\r'){  
	if (received_char >= '0' && received_char <= '9') {
		int num = received_char - '0';  
		num += 1;
		if(num == 10){
		  USART_Transmit('0');
		  continue;
		}                      
		USART_Transmit(num + '0');
		USART_Transmit('\r');      
	}
	}
	}
	
          
}
