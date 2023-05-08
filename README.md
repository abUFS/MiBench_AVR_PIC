# MiBench_AVR_PIC\
Code for the benchmark "basicmath" from the MiBench benchmark suit. <br/>

All credits to the developers of MiBench. <br/>
Read more in: https://vhosts.eecs.umich.edu/mibench/ <br/>

How to use these examples: <br/>
- Download the MiBench automotive benchmark form the official website; <br/>
- Place these files in the \basicmath folder; <br/>
- Compile and create the .hex files for the microcontroller (atmega328p, atmega2560, pic16f887); <br/>
- Upload the .hex file to the microcontroller. <br/>

Compilation: <br/>
  For the AVR atmega328p: <br/>
  avr-gcc -static -O3 -Wall -Os -mmcu=atmega328p -o basicmath_small_clean_328p.elf .\basicmath_small_clean_avr.c -lm <br/>
  avr-objcopy -j .text -j .data -O ihex .\basicmath_small_clean_328p.elf basicmath_small_clean_328p.hex <br/>
  
  for the AVR atmega2560: <br/>
  avr-gcc -static -O3 -Wall -Os -mmcu=atmega2560 -o basicmath_small_clean_2560.elf .\basicmath_small_clean_avr.c -lm <br/>
  avr-objcopy -j .text -j .data -O ihex .\basicmath_small_clean_2560.elf basicmath_small_clean_2560.hex <br/>
  
  for the PIC16F887: <br/>
  xc8 --chip=16F887 -I"path\to\automotive\basicmath" basicmath_small_clean_pic.c <br/>
  
  where "path\to\automotive\basicmath" is the full path to \basicmath folder. <br/>
