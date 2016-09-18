int ldr = 0; //LDR fotorezistor pin
float kwh = 1000;  //Value on electricity meter imp/kWh

int ldr_value = 0; 
uint32_t dtime = 0;
int awarageCount = 4;//Average last count
int currentTick = 0;
int sumDiff = 0;

int ledDelay = 100; //How long LED is ON in ms.
void loop()
{
	ldr_value = analogRead(ldr); //Read LDR photoresistor
	if(ldr_value > 500)  // Greater valie is LED ON, value dependence on resistor.
	{
		if (currentTick >= awarageCount)  //Sum last awarageCount(4) values
		{
			float kwt = float(float(kwh) / float(sumTick/ awarageCount));

      Serial.print("kWh:");
			Serial.println(kwt);
      
      currentTick=0;
			sumTick = 0;
		}
		currentTick++;
		unsigned long oldTime = dtime;
		 dtime = millis();
		unsigned long diff = dtime - oldTime ;
		sumDiff += diff;

		delay(ledDelay); //Need wait, led must turn off
	}
}
