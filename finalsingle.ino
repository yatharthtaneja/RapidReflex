 #include <stdio.h>
long randNumber;
unsigned long smillis;
unsigned long cmillis;
const unsigned long period= 60000;
int value = 0;
int pin_p1_b = 13;
int pin_p1_b1 = 22;
int pin_p1_b2 = 23;
int pin_p1_p = A1;
int pin_p1_ldr = A3;
int pin_p1_touch = 12;
int pin_p1_s1=9;//trig
int pin_p1_s = 8;
int p1_leds[7] = {2,3,4,5,6,18,19};
int p1_score = 0;
int p2_score = 0;
int leds_cnt=7;
//function defination
void p1_led0(){                         //button
  do{
    if (digitalRead(pin_p1_b)==1){
      
        analogWrite(p1_leds[0],0);
//         Serial.print("button");
      p1_score++;}
//      Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_b));
  }
  while(digitalRead(p1_leds[0])==HIGH);
}
void p1_led5(){                         //button
  do{
    if (digitalRead(pin_p1_b1)==1){
      
//        analogWrite(p1_leds[5],0);
//         Serial.print("button");
      p1_score++;}
//      Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_b1));
  }
  while(digitalRead(p1_leds[5])==HIGH);
}
void p1_led6(){                         //button
  do{
    if (digitalRead(pin_p1_b2)==1){
      
        analogWrite(p1_leds[6],0);
//         Serial.print("button");
      p1_score++;}
//      Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_b2));
  }
  while(digitalRead(p1_leds[6])==HIGH);
}
void p1_led1(){                                 //touch
    do{
    if (digitalRead(pin_p1_touch)==1)
        {analogWrite(p1_leds[1],0);
//           Serial.println("touched");
      p1_score++;}
//      Serial.println(p1_score);
    }
      while(digitalRead(p1_leds[1])==HIGH);
}
void p1_led2(){                                 //potentiometer
  do {
  if (analogRead(pin_p1_p)>512)
  {
    analogWrite(p1_leds[2],0);
    p1_score++;
//    Serial.println("\n p");
  }
  
//  Serial.print(p1_score);
  }
  while(digitalRead(p1_leds[2])==HIGH);
}
void p1_led3(){                                  //distance
  do{
   long duration, distance;
  digitalWrite(pin_p1_s1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(pin_p1_s1, LOW);
  duration=pulseIn(pin_p1_s, HIGH);
  distance =(duration/2)/29.1;
//  Serial.print(distance);
//  Serial.println("CM");
  delay(10);
 
 if((distance<=10)) 
  {
    digitalWrite(p1_leds[3], LOW);
    p1_score++;
//    Serial.println("distance 1");
//    Serial.println(p1_score);
    }
}
while(digitalRead(p1_leds[3])==HIGH);
}

void p1_led4(){                                  //sound
  do{
  if (digitalRead(pin_p1_ldr)==1){
      
        analogWrite(p1_leds[4],0);
//         Serial.print("button");
      p1_score++;}
//      Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_ldr));
  }

while(digitalRead(p1_leds[4])==HIGH);
}
void setup()
{
  Serial.begin(9600);

  randomSeed(analogRead(A0));
  smillis= millis();
  pinMode(pin_p1_b, INPUT);
  pinMode(pin_p1_b1, INPUT);
  pinMode(pin_p1_b2, INPUT);
  pinMode(pin_p1_p, INPUT);
  pinMode(pin_p1_ldr, INPUT);
  pinMode(pin_p1_touch, INPUT);
  pinMode(pin_p1_s, INPUT);
  pinMode(pin_p1_s1, OUTPUT);
 for (int i = 0; leds_cnt > i; i++) {
    pinMode(p1_leds[i], OUTPUT);
  }

    }
  

  void loop()
{
   cmillis=millis();
  if(cmillis-smillis< period )
  {
    long rand=random(500,3000);
    delay(rand);
 int ran = random(0,7);
 
    switch(ran){ 
      case 0: digitalWrite(p1_leds[0],HIGH);//only button led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);

              p1_led0();
              delay(1000);
              break;
      case 1: digitalWrite(p1_leds[1],HIGH); // only touch led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              p1_led1();
              delay(1000);
              break;
      case 2: digitalWrite(p1_leds[2],HIGH);// only p led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              p1_led2();
              delay(1000);
              break;
      case 3: digitalWrite(p1_leds[3],HIGH); // only sound led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              p1_led3();
              delay(1000);
              break;
     case 4:digitalWrite(p1_leds[4],HIGH); // only ldr led
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              p1_led4();
              delay(1000);
              break;
      case 5: digitalWrite(p1_leds[5],HIGH);//only button led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[6],LOW);

              p1_led5();
              delay(1000);
              break;
      case 6: digitalWrite(p1_leds[6],HIGH);//only button led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p1_leds[0],LOW);

              p1_led6();
              delay(1000);
              break;
      }
 String s1=String(p1_score);
 Serial.println(s1);
    }
 
  }



    
  
