#include <xc.h>
#include <math.h>
#include "snipmath.h"
#include "isqrt.c"
#include "cubic.c"

// Configuration bits

#pragma config WDTE = OFF       // Watchdog timer disabled
#pragma config PWRTE = OFF      // Power-up timer disabled
#pragma config MCLRE = OFF      // MCLR pin is digital input
#pragma config CP = OFF         // Code protection disabled
#pragma config CPD = OFF        // Data code protection disabled
#pragma config BOREN = OFF      // Brown-out reset disabled

#define _XTAL_FREQ 8000000      // Internal oscillator frequency

void init_USART() {
    // Configure USART for asynchronous 8-bit transmission, high speed mode
    TXSTAbits.SYNC = 0;         // Asynchronous mode
    TXSTAbits.BRGH = 1;         // High speed mode

    SPBRG = 51;                 // Set Baud rate to 9600 bps
    TXSTAbits.TXEN = 1;         // Enable transmission
}

void USART_TransmitBuffer(char* buffer, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        while (!TXSTAbits.TRMT); // Wait for previous transmission to complete
        TXREG = buffer[i];       // Load character into transmit register
    }
}

char m1[] = "1";
char m2[] = "2";

int main(void){
  OSCCONbits.IRCF = 0b111;    // Internal oscillator frequency set to 8 MHz
    
  init_USART();
    
  // Send "Hello, world!" via USART
  
  USART_TransmitBuffer(m1, strlen(m1));

  double  a1 = 1.0, b1 = -10.5, c1 = 32.0, d1 = -30.0;
  double  a2 = 1.0, b2 = -4.5, c2 = 17.0, d2 = -30.0;
  double  a3 = 1.0, b3 = -3.5, c3 = 22.0, d3 = -31.0;
  double  a4 = 1.0, b4 = -13.7, c4 = 1.0, d4 = -35.0;
  double  x[3];
  double X;
  int     solutions;
  int i;
  unsigned long l = 0x3fed0169L;
  struct int_sqrt q;
  double y;

  /* solve some cubic functions */

  /* should get 3 solutions: 2, 6 & 2.5   */
  SolveCubic(a1, b1, c1, d1, &solutions, x);  

  /* should get 1 solution: 2.5           */
  SolveCubic(a2, b2, c2, d2, &solutions, x);
  SolveCubic(a3, b3, c3, d3, &solutions, x);
  SolveCubic(a4, b4, c4, d4, &solutions, x);

  
  USART_TransmitBuffer(m2, strlen(m2));

  /* Now solve some random equations */
  for(a1=1;a1<10;a1++) {
    for(b1=10;b1>0;b1--) {
      for(c1=5;c1<15;c1+=0.5) {
	for(d1=-1;d1>-11;d1--) {
	  SolveCubic(a1, b1, c1, d1, &solutions, x);  
	}
      }
    }
  }

  
  USART_TransmitBuffer(m2, strlen(m2));
  
  /* perform some integer square roots */
  for (i = 0; i < 1001; ++i)
    {
      usqrt(i, &q);
			// remainder differs on some machines
     // printf("sqrt(%3d) = %2d, remainder = %2d\n",
    }
  usqrt(l, &q);
  //printf("\nsqrt(%lX) = %X, remainder = %X\n", l, q.sqrt, q.frac);

  USART_TransmitBuffer(m2, strlen(m2));
  /* convert some rads to degrees */
  for (X = 0.0; X <= 360.0; X += 1.0)
      y = deg2rad(X);
  for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180))
      y = rad2deg(X);

  char fmess[] = "FIM!";
  USART_TransmitBuffer(fmess, strlen(fmess));
  return 0;
  
}
