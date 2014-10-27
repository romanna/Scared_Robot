  /*
  Try to Scare the Robot
   By: 
   Sruti Chigullapalli 
   Shammi Jayaraj
   Romana Flores
   Oliver Chen
   Dustin Bryers
   10/27/2014. 
 
  Objective: Blink led based on touch sensor 

 Analog Input: light sensor 
 Digital Output: LED blinking rapidly
 LCD prints: "Stop scaring me", "Am not scared"
 */
 
  #include <Wire.h>   //does I2C
  #include "rgb_lcd.h" //plug lcd into I2C below D7
  
  
  //digital output
  const int ledPin1=3;
    const int ledPin2=4;

  //use pwm pins 3,5,6,9,10,11
  int buzzerPin=7;
  
  // use Analog  input pins
  const int lightSensorPin=A1;
  //const int soundSensorPin=A1;
  int photoState, photoState_old;
  
  //Servo groveServo; //create a object
  rgb_lcd lcd;
  // set background color of lcd any integer 0-255
  int red= 255;
  int green= 255;
  int blue= 255;
  
  /* 
  // useful commands for lcd
  lcd.begin(numCols,numRows);// set up the LCD's number of columns and rows
  lcd.home();// go to (0,0)
  lcd.setCursor(thisRow,thisCol);// set the cursor position
  lcd.write(thisLetter);// print the letter
  lcd.setRGB(red, green, blue);//set color
  lcd.leftToRight();// go left for the next letter
  lcd.rightToLeft();// go right for the next letter
  */
  
  char dtaUart[15];
  char dtaLen = 0;
  
    
  const int debug=1;  //print data to serial monitor


  void setup() {
    // put your setup code here, to run once:
   
      
  // input pins - analog read
  pinMode(lightSensorPin,INPUT);
  
  //output pins - digital write, pwm
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

  pinMode(buzzerPin,OUTPUT);
    
  
  //groveServo.attach(servoPin);     //the servo is attached to D3

  lcd.begin(16, 2);
  lcd.print(" Scare me if you can!");
  Serial.begin(115200);
  //output pins
  
  delay(2000);
  }
  
  void loop() {
  
// read photoResistorValue
     int photoResistorValue = analogRead(lightSensorPin);  //analog input data range from 0~1023
     if (photoResistorValue < 500){ //blink led if its dark
      digitalWrite(ledPin1,HIGH);
      digitalWrite(ledPin2,HIGH);

      int timedelay=random(10,300);
      delay(timedelay);
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);

      delay(timedelay);
    
    lcd.clear();
    lcd.print("Stop scaring me");
    lcd.setRGB(255, 55, 0); //red 
    photoState=0;photoState_old=1;
}
else{ 
if (photoState!=photoState_old){
   lcd.clear();
    lcd.print("Am not scared");
    lcd.setRGB(0, 255, 0); //green 
    photoState_old=photoState;
}
else{
delay (200);
}
}

if (debug==1){
 Serial.println("photoResistorValue ="+String(photoResistorValue));
}

}
