//On Off state led
int ledCheck = 6;

//Output LED
int led1_pin = 8;
int led2_pin = 9;
int led3_pin = 10;
int led4_pin = 11;

int brightnessLed = 0;
int fadeAmount = 5;

//Pushbutton
const int button_pin = 26; //24
int buttonState = 0;      // variable for reading the pushbutton status
int buttonCounter = 0;
int lastButtonState = 0;

//Reading Sensors
int sensorPin1 = A0;    //LDR 1 
int sensorPin2 = A1;    //LDR 2
int sensorPin3 = A2;    //LDR 3
int sensorPin4 = A3;    //LDR 4
int sensorPin5 = A4;    //LDR 5
int sensorPin6 = A5;    //LDR 6

//LED
int ledPin1 = 40;       //LED 1 
int ledPin2 = 38;       //LED 2
int ledPin3 = 36;       //LED 3
int ledPin4 = 34;       //LED 4
int ledPin5 = 32;       //LED 5
int ledPin6 = 30;       //LED 6

//Distance values
int sensorValueA = 0;  
int sensorValueB = 0;
int sensorValueC = 0;
int sensorValueD = 0;
int sensorValueE = 0;
int sensorValueF = 0;


//***************************************************************************************

void setup() {
  
  Serial.begin(9600); //19200
  
  //On Off led state
  pinMode(ledCheck, OUTPUT); 
  
}

//***************************************************************************************

void loop() {
  
  startDistanceSensors(); //turn led on and read data from the ldr
  
  printData(); //print data on the serial port
  
  delay(10);
  
}

//***************************************************************************************

void startDistanceSensors() {
  
  // turn led on
  digitalWrite(ledPin1, HIGH); 
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH); 
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
  
  // read the value from the sensor:
  sensorValueA = analogRead(sensorPin1);  
  sensorValueB = analogRead(sensorPin2);
  sensorValueC = analogRead(sensorPin3);
  sensorValueD = analogRead(sensorPin4);
  sensorValueE = analogRead(sensorPin5);
  sensorValueF = analogRead(sensorPin6);
  
}

//***************************************************************************************

void printData() {
  
  //Serial print to pd
  Serial.print(F("A "));
  
  //Values  
  //Distance sensors
  Serial.print(sensorValueA, DEC); //Distance sensors
  Serial.print(F(" "));
  Serial.print(sensorValueB, DEC); 
  Serial.print(F(" "));
  Serial.print(sensorValueC, DEC);
  Serial.print(F(" "));
  Serial.print(sensorValueD, DEC); 
  Serial.print(F(" "));
  Serial.print(sensorValueE, DEC); 
  Serial.print(F(" "));
  Serial.print(sensorValueF, DEC); 
  Serial.print(F(" "));
  
  Serial.println();
  
}

//***************************************************************************************
/*  
    Mapping of the distance sensors (ldr + led)

    SensorValue A = sensorPin1 + ledPin5
    SensorValue B = sensorPin2 + ledPin2
    SensorValue C = sensorPin3 + ledPin6
    SensorValue D = sensorPin4 + ledPin3
    SensorValue E = sensorPin5 + ledPin1
    SensorValue F = sensorPin6 + ledPin4   
                                             */
//***********************
