# MiBench_AVR_PIC
Code for the benchmark "basicmath" from the MiBench benchmark suit.

All credits to the developers of MiBench.
Read more in: https://vhosts.eecs.umich.edu/mibench/

How to use these examples:
- Download the MiBench automotive benchmark form the official website;
- Place these files in the \basicmath folder;
- Compile and create the .hex files for the microcontroller (atmega328p, atmega2560, pic16f887);
- Upload the .hex file to the microcontroller.

Compilation:
  For the AVR atmega328p:
  avr-gcc -static -O3 -Wall -Os -mmcu=atmega328p -o basicmath_small_clean_328p.elf .\basicmath_small_clean_avr.c -lm
  avr-objcopy -j .text -j .data -O ihex .\basicmath_small_clean_328p.elf basicmath_small_clean_328p.hex
  
  for the AVR atmega2560:
  avr-gcc -static -O3 -Wall -Os -mmcu=atmega2560 -o basicmath_small_clean_2560.elf .\basicmath_small_clean_avr.c -lm
  avr-objcopy -j .text -j .data -O ihex .\basicmath_small_clean_2560.elf basicmath_small_clean_2560.hex
  
  for the PIC16F887:
  xc8 --chip=16F887 -I"path\to\automotive\basicmath" basicmath_small_clean_pic.c
  
  where "path\to\automotive\basicmath" is the full path to \basicmath folder.
