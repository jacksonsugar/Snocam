#include "LowPower.h"

int Pi_off = 3;
int Pi_on = 4;
int WIFI_SIG = 5;
int LED = 7;

void setup(void)
{
  pinMode(LED, OUTPUT);
  pinMode(Pi_on, OUTPUT); 
  pinMode(Pi_off, OUTPUT); 
  pinMode(WIFI_SIG, INPUT );
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(Pi_on, LOW);
  digitalWrite(LED, LOW);

  digitalWrite(Pi_off, HIGH);
  delay(500);
  digitalWrite(Pi_off, LOW);

  for(int i = 0; i < 3; i++){ 
    digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(100);
  }
}

void loop(void) 
{

  digitalWrite(Pi_on, HIGH);
  delay(500);
  digitalWrite(Pi_on, LOW);

  for (int i = 1; i <= 10; i++){
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
  }

  int sensorVal = digitalRead(WIFI_SIG);

  do {
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
    //delay(4000);
    sensorVal = digitalRead(WIFI_SIG);
  }
  while (sensorVal == HIGH);

  for (int i = 1; i <= 5; i++){
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
  }

  
  digitalWrite(Pi_off, HIGH);
  delay(500);
  digitalWrite(Pi_off, LOW);

  //This is the sleep cycle! Set for 150 cycles of 4 seconds for 10 minutes
  for (int i = 1; i <= 15; i++){
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
  }

}

