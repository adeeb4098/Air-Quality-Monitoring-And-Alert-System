#include <LiquidCrystal.h> //Header file for LCD

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2; //pins of LCD connected to Arduino

LiquidCrystal lcd(rs,en,d4,d5,d6,d7); //lcd function from LiquidCrystal

int buz = 8; //buzzer connected to pin 8
int led = 9; //red led connected to pin 9
int gled = 10; // green led connected to pin 10
const int aqsensor = A0; //output of mq135 connected to A0 pin of Arduino
int threshold = 250; //Threshold level for Air Quality

void setup() {
pinMode (buz ,OUTPUT); // buzzer is connected as Output from Arduino
pinMode (led, OUTPUT); //Red led is connected as output from Arduino
pinMode (gled, OUTPUT); //Green led is connected as output from Arduino
pinMode (aqsensor, INPUT); // MQ135 is connected as INPUT to arduino
Serial.begin (9600); //begin serial communication with baud rate of 9600
digitalWrite(led, HIGH);
digitalWrite(gled, HIGH);
tone(buz,1000, 500);
lcd.clear(); // clear lcd
lcd.begin (16,2); // consider 16,2 lcd
lcd.setCursor(1,0);
lcd.print("AQI MONITORING");
lcd.setCursor(1,1);
lcd.print("& ALERT SYSTEM");
delay(3000);
lcd.clear();14
lcd.setCursor(2,0);
lcd.print("CREATED BY:-");
delay(1000);
lcd.setCursor(2,1);
lcd.print("TEAM UNITED");
delay(3000);
lcd.clear();
lcd.setCursor(5,0);
lcd.print("MOHSIN");
delay(1000);
lcd.setCursor(2,1);
lcd.print("MAAZ ; ADEEB");
delay(3000);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("ECE DEPARTMENT");
delay(1000);
lcd.setCursor(2,1);
lcd.print("MIET, MEERUT");
delay(2000);
digitalWrite(buz,LOW);
digitalWrite(led,LOW);
digitalWrite(gled,LOW);
}

void loop() {
int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A0 and store it in ppm
Serial.print("Air Quality: "); //print message in serail monitor
Serial.println(ppm); //print value of ppm in serial monitor
lcd.setCursor(0,0); // set cursor of lcd to 1st row and 1st column15
lcd.print("Air Quality: "); // print message on lcd
lcd.print(ppm); // print value of MQ135
digitalWrite(gled,HIGH);
if (ppm > threshold) // check is ppm is greater than threshold or not
{
digitalWrite(gled,LOW);
lcd.setCursor(1,1); //jump here if ppm is greater than threshold
lcd.print("AQI Level High");
Serial.println("AQI Level High");
tone(led,1000,100); //blink led with turn on time 1000mS, turn off time 200mS
digitalWrite(buz,HIGH); //Turn ON Buzzer
}
else
{
digitalWrite(led,LOW); //jump here if ppm is not greater than threshold and turn off
LED
digitalWrite(buz,LOW); //Turn off Buzzer
lcd.setCursor(0,1);
lcd.print ("AQI Level Normal");
Serial.println("AQI Level Normal");
}
