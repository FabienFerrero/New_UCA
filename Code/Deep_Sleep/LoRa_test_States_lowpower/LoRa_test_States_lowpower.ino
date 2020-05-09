/*
  LoRa test States

  The objective of this sketch is to measure the power consumption in different states

  The code was modified from LoRa Duplex from  Tom Igoe
*/
#include <SPI.h>              // include libraries
#include <LoRa.h>
#include "LowPower.h"

//#define debugSerial Serial
//#define SHOW_DEBUGINFO




void setup() {
  
  delay(2000); // wait to be sure that measurement with a DC source will start
  Serial.begin(9600);                   // initialize serial
 // while (!Serial);
 // Serial.println("LoRa States power Consumption");
  pinMode(7, OUTPUT);
digitalWrite(7, HIGH);

 
}

void loop() {
  Serial.begin(9600);     
    do_sleep(2);
  //  Serial.end; 
Serial.end();
      
    do_sleep(2);


    
//    receive = 1;
//  }
//
//  // parse for a packet, and call onReceive with the result:
//  if (receive == 1)
//  {
//  Serial.println("Receiving State ");
//  receive = 0;}
//  onReceive(LoRa.parsePacket());
}



extern volatile unsigned long timer0_millis;
void addMillis(unsigned long extra_millis) {
  uint8_t oldSREG = SREG;
  cli();
  timer0_millis += extra_millis;
  SREG = oldSREG;
  sei();
}

void do_sleep(unsigned int sleepyTime) {
  unsigned int eights = sleepyTime / 8;
  unsigned int fours = (sleepyTime % 8) / 4;
  unsigned int twos = ((sleepyTime % 8) % 4) / 2;
  unsigned int ones = ((sleepyTime % 8) % 4) % 2;

#ifdef SHOW_DEBUGINFO
  Serial.print("Sleeping for ");
  Serial.print(sleepyTime);
  Serial.println(" seconds");  
  delay(100); //Wait for serial to complete
#endif


  for ( int x = 0; x < eights; x++) {
    // put the processor to sleep for 8 seconds
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
  for ( int x = 0; x < fours; x++) {
    // put the processor to sleep for 4 seconds
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
  }
  for ( int x = 0; x < twos; x++) {
    // put the processor to sleep for 2 seconds
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  }
  for ( int x = 0; x < ones; x++) {
    // put the processor to sleep for 1 seconds
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  }
  addMillis(sleepyTime * 1000);
}
