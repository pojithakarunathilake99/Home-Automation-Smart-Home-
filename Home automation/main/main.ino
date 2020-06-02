//Copyrights Pojitha Karunathilake
//visit my website for more projects www.pojithakarunathilake.com / www.pojithyakarunathilake.tech
#include<SoftwareSerial.h>
int PIR_output=5; // output of pir sensor
int led1=9; // led pin
int sensorPin = A0; // select the input pin for the LDR

int sensorValue = 0; // variable to store the value coming from the sensor

int led = 13; // Output pin for LED

const int sensorMin = 0;     // sensor minimum
const int sensorMax = 580;  // sensor maximum

int soundSensor = 2;
int LED = 3;

void setup() {

// declare the ledPin and buzzer as an OUTPUT:
pinMode(PIR_output, INPUT);// setting pir output as arduino input
pinMode(led1, OUTPUT);//setting led as output
pinMode(led, OUTPUT);
pinMode (soundSensor, INPUT);
pinMode (LED, OUTPUT);


Serial.begin(9600);

}

void loop()

{
 firefunc();
 pirFunc();
 rainFunc();
 soundFunc();
}
void firefunc()
{


sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 500)

{

Serial.println("Fire Detected");

Serial.println("Buzzer on");

digitalWrite(led,HIGH);



delay(1000);

}

digitalWrite(led,LOW);



delay(sensorValue);
 
  
 }

 void pirFunc(){
if(digitalRead(5) == HIGH) // reading the data from the pir sensor
{
 digitalWrite(9, HIGH); // setting led to high

 Serial.println("motion detected");
 
}
else {
 digitalWrite(9, LOW); // setting led to low

 Serial.println("scanning");
}
  }

void rainFunc(){
  // read the sensor on analog A0:
  int sensorReading = analogRead(A1);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 1, 3);
  
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood");
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning");
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining");
    break;
  }
  delay(1);  // delay between reads
}
 void soundFunc()
{
  int statusSensor = digitalRead (soundSensor);
  
  if (statusSensor == 1)
  {
    digitalWrite(LED, LOW);
    
    Serial.println("NO Sound  detected");
  }
  
  else
  {
    digitalWrite(LED, HIGH);
    
    Serial.println("Sound detected");
  }
   
  
}
