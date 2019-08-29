  #include <SoftwareSerial.h>

  #include <Servo.h> 

  
char val;



Servo myservo1, myservo2, myservo3, myservo4;

int bluetoothTx = 0;
int bluetoothRx = 1;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(10);
  myservo4.attach(11);
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);


  Serial.println("It's me robot"); 
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos; 
    Serial.println(realservo); 
    
    if (realservo >= 1000 && realservo <1180){
    int servo1 = realservo;
    servo1 = map(servo1, 1000,1180,0,180);
    myservo1.write(servo1);
         digitalWrite(2, LOW);
         digitalWrite(7, LOW);
         digitalWrite(3, LOW);
         digitalWrite(8, LOW);
         digitalWrite(12, LOW);
    Serial.println("servo 1 ON");
    delay(20);

    }
    
    if (realservo >=2000 && realservo <2180){
      int servo2 = realservo;
      servo2 = map(servo2,2000,2180,0,180);
      myservo2.write(servo2);
          digitalWrite(2, LOW);
          digitalWrite(7, LOW);
          digitalWrite(3, LOW);
          digitalWrite(8, LOW);
          digitalWrite(12, LOW);
      Serial.println("servo 2 On");
      delay(20);
      
    }
    
    if (realservo >=3000 && realservo < 3180){
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180,0,180);
      myservo3.write(servo3);

          digitalWrite(2, LOW);
          digitalWrite(7, LOW);
          digitalWrite(3, LOW);
          digitalWrite(8, LOW);
          digitalWrite(12, LOW);
      Serial.println("servo 3 On");
      delay(20);

    }

        if (realservo >=4000 && realservo < 4180){
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180,0,180);
      myservo4.write(servo4);
          digitalWrite(2, LOW);
          digitalWrite(7, LOW);
          digitalWrite(3, LOW);
          digitalWrite(8, LOW);
          digitalWrite(12, LOW);
      Serial.println("servo 4 On");
      delay(20);

    } }
int appdata;


  if( Serial.available() )       // if data is available to read
  {
    ;
  }
  val = Serial.read();         // read it and store it in 'val'

  if( val == 'f' )               // if 'a' was received led 2 is switched off
  {
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
    
  }
 
  if( val == 'F' )               // if 'A' was received led 2 on
  {
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);

  }

  if( val == 'b' )              
  {
    digitalWrite(3, HIGH);
    digitalWrite(8, HIGH);
 
  }
 
  if( val == 'B' )            
  {
    digitalWrite(3, LOW);
    digitalWrite(8, LOW);
 
  
  } 

  if( val == 'l' )               // if 'C' was received led 2 on for 1 second
  {
 digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
 
  }

  if( val == 'L' )               // if 'D' was received led 3 on for 1 second
  {
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);

  }
 
  if( val == 'r' )               // if 'E' was received led 2 on for 5 seconds
  {
    digitalWrite(3, HIGH);
    digitalWrite(7, HIGH);

  }
 
  if( val == 'R' )               // if 'F' was received led 3 on for 5 seconds
  {
    digitalWrite(3, LOW);
    digitalWrite(7, LOW);
 
  }
  
  if( val == 'c' )               // if 'F' was received led 3 on for 5 seconds
  {
    digitalWrite(12, HIGH);
    
 
  }

  if( val == 'C' )               // if 'F' was received led 3 on for 5 seconds
  {
    digitalWrite(12, LOW);
    
 
  }


  }

 
  



