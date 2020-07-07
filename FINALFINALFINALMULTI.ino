 #include <stdio.h>
long randNumber;

int value = 0;
int pin_p1_b = 13;
int pin_p1_b1 = 22;
int pin_p1_b2 = 23;
int pin_p1_p = A1;
int pin_p1_ldr = A3;
int pin_p1_touch = 12;
int pin_p1_s = 8;//echo
int pin_p1_s1=9;//trig
int p1_leds[7] = {2,3,4,5,6,18,19};
int pin_p2_b = 14;
int pin_p2_b1 = 26;
int pin_p2_b2 = 27;
int pin_p2_p = A6;
int pin_p2_ldr = A7;
int pin_p2_touch = 15;
int pin_p2_s = 16;//echo
int pin_p2_s1=17;//trig
int p2_leds[7] = {A8,A9,A10,A11,A12,20,21};
int p1_score = 0;
int p2_score = 0;
int leds_cnt=7;
//function defination
void p_led0(){                         //button
  do{
    if (digitalRead(pin_p1_b)==1){
        analogWrite(p2_leds[0],0);
        analogWrite(p1_leds[0],0);
//         Serial.print("button1");
      p1_score++;
//       Serial.println("\n p1_score");
//       Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_b));

       }

    if (digitalRead(pin_p2_b)==1){
        analogWrite(p1_leds[0],0);
        analogWrite(p2_leds[0],0);
//         Serial.print("button2");
      p2_score++;
      
//      Serial.println(p2_score);
//       Serial.println(digitalRead(pin_p2_b));
       }

  }
  while(digitalRead(p1_leds[0])==HIGH and digitalRead(p2_leds[0])==HIGH);
}
  //button 1
  void p_led5(){
    do{
    if (digitalRead(pin_p1_b1)==1){
        analogWrite(p2_leds[5],0);
        analogWrite(p1_leds[5],0);
//         Serial.print("button11");
      p1_score++;
//       Serial.println("\n p1_score");
//       Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_b1));

       }

    if (digitalRead(pin_p2_b1)==1){
        analogWrite(p1_leds[5],0);
        analogWrite(p2_leds[5],0);
//         Serial.print("button21");
      p2_score++;
      
//      Serial.println(p2_score);
//       Serial.println(digitalRead(pin_p2_b1));
       }

  }
  while(digitalRead(p1_leds[5])==HIGH and digitalRead(p2_leds[5])==HIGH);
  }
//button 2
  void p_led6(){
    do{
    if (digitalRead(pin_p1_b2)==1){
        analogWrite(p2_leds[6],0);
        analogWrite(p1_leds[6],0);
//         Serial.print("button12");
      p1_score++;
//       Serial.println("\n p1_score");
//       Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_b2));

       }

    if (digitalRead(pin_p2_b2)==1){
        analogWrite(p1_leds[6],0);
        analogWrite(p2_leds[6],0);
//         Serial.print("button21");
      p2_score++;
//      
//      Serial.println(p2_score);
//       Serial.println(digitalRead(pin_p2_b2));
       }

  }
  while(digitalRead(p1_leds[6])==HIGH and digitalRead(p2_leds[6])==HIGH);
}
void p_led1(){                                 //touch
    do{
    if (digitalRead(pin_p1_touch)==1)
        {analogWrite(p1_leds[1],0);
        analogWrite(p2_leds[1],0);
//           Serial.println("touched");
      p1_score+=2;
//      Serial.println(p1_score);
      }
      if (digitalRead(pin_p2_touch)==1)
        {analogWrite(p2_leds[1],0);
        analogWrite(p1_leds[1],0);
//           Serial.println("touched2");
      p2_score+=2;
//      Serial.println(p2_score);
      }
    }
      while(digitalRead(p1_leds[1])==HIGH and digitalRead(p2_leds[1])==HIGH);
}
void p_led2(){                                 //potentiometer
  do {
  if (analogRead(pin_p1_p)>512)
  {
    analogWrite(p1_leds[2],0);
    analogWrite(p2_leds[2],0);
    p1_score+=3;
//    Serial.println("\n p1");
//    Serial.print(p1_score);
  }
    if (analogRead(pin_p2_p)>512)
  {
    analogWrite(p2_leds[2],0);
    analogWrite(p1_leds[2],0);
    p2_score+=3;
//    Serial.println("\n p2");
//    Serial.print(p2_score);
  }
  
  }
  while(digitalRead(p1_leds[2])==HIGH and digitalRead(p2_leds[2])==HIGH );
}
void p_led3(){                                  //distance
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
    digitalWrite(p2_leds[3], LOW);
    p1_score+=5;
//    Serial.println("distance 1");
//    Serial.println(p1_score);
    }

  long duration2, distance2;
  digitalWrite(pin_p2_s1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(pin_p2_s1, LOW);
  duration2=pulseIn(pin_p2_s, HIGH);
  distance2 =(duration2/2)/29.1;
//  Serial.print(distance2);
//  Serial.println("CM");
  delay(10);
 
 if((distance2<=10)) 
  {
    digitalWrite(p2_leds[3], LOW);
    digitalWrite(p1_leds[3], LOW);
    p2_score+=5;
//    Serial.println("distance 2");
//    Serial.print(p2_score);
    }
}
while(digitalRead(p1_leds[3])==HIGH and digitalRead(p2_leds[3])==HIGH) ;
}

void p_led4(){                                  //ldr
  do{
//   if(analogRead(pin_p1_ldr)>200)
//     {analogWrite(p1_leds[4],0);
//     analogWrite(p2_leds[4],0);
//     p1_score++;
//     Serial.println("ldr");
//     Serial.print(p1_score);
//     } 
//     if(analogRead(pin_p2_ldr)>200)
//     {analogWrite(p2_leds[4],0);
//     analogWrite(p1_leds[4],0);
//     p2_score++;
//     Serial.println("ldr2");
//     Serial.print(p2_score);
//     } 
if (digitalRead(pin_p1_ldr)==1){
        analogWrite(p2_leds[4],0);
        analogWrite(p1_leds[4],0);
//         Serial.print("buttonldr");
      p1_score++;
//       Serial.println("\n p1_score");
//       Serial.println(p1_score);
//       Serial.println(digitalRead(pin_p1_ldr));

       }

    if (digitalRead(pin_p2_ldr)==1){
        analogWrite(p1_leds[4],0);
        analogWrite(p2_leds[4],0);
//         Serial.print("button21");
      p2_score++;
      
//      Serial.println(p2_score);
//       Serial.println(digitalRead(pin_p2_ldr));
       }

}
while(digitalRead(p1_leds[4])==HIGH and digitalRead(p2_leds[4])==HIGH);
}


//setup
void setup()
{
  Serial.begin(9600);

  randomSeed(analogRead(A0));
  
  pinMode(pin_p1_b, INPUT);
  pinMode(pin_p1_b1, INPUT);
  pinMode(pin_p1_b2, INPUT);
  pinMode(pin_p1_p, INPUT);
  pinMode(pin_p1_ldr, INPUT);
  pinMode(pin_p1_touch, INPUT);
  pinMode(pin_p1_s, INPUT);
  pinMode(pin_p2_b, INPUT);
  pinMode(pin_p2_b1, INPUT);
  pinMode(pin_p2_b2, INPUT);
  pinMode(pin_p2_p, INPUT);
  pinMode(pin_p2_ldr, INPUT);
  pinMode(pin_p2_touch, INPUT);
  pinMode(pin_p2_s, INPUT);
  pinMode(pin_p1_s1, OUTPUT);
  pinMode(pin_p2_s1, OUTPUT);
  
    for (int i = 0; leds_cnt > i; i++) {
    pinMode(p1_leds[i], OUTPUT);
  }
  for (int i = 0; leds_cnt > i; i++) {
    pinMode(p2_leds[i], OUTPUT);
  }
 

    }
  

  void loop()
{
  if(p1_score<51 and p2_score<51 ){
    long rand=random(300,3000);
    delay(rand);
 int ran = random(0,7);
 
    switch(ran){ 
      case 0: digitalWrite(p1_leds[0],HIGH);//only button led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p2_leds[0],HIGH);//only button led
              digitalWrite(p2_leds[4],LOW);
              digitalWrite(p2_leds[1],LOW);
              digitalWrite(p2_leds[2],LOW);
              digitalWrite(p2_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p2_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              digitalWrite(p2_leds[6],LOW);

              p_led0();
              delay(500);
              break;
      case 1: digitalWrite(p1_leds[1],HIGH); // only touch led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p2_leds[1],HIGH); // only touch led
              digitalWrite(p2_leds[4],LOW);
              digitalWrite(p2_leds[0],LOW);
              digitalWrite(p2_leds[2],LOW);
              digitalWrite(p2_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p2_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              digitalWrite(p2_leds[6],LOW);
              p_led1();
              delay(500);
              break;
      case 2: digitalWrite(p1_leds[2],HIGH);// only p led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p2_leds[2],HIGH);// only p led
              digitalWrite(p2_leds[4],LOW);
              digitalWrite(p2_leds[1],LOW);
              digitalWrite(p2_leds[0],LOW);
              digitalWrite(p2_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p2_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              digitalWrite(p2_leds[6],LOW);
              p_led2();
              delay(500);
              break;
      case 3: digitalWrite(p1_leds[3],HIGH); // only sound led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p2_leds[3],HIGH); // only sound led
              digitalWrite(p2_leds[4],LOW);
              digitalWrite(p2_leds[1],LOW);
              digitalWrite(p2_leds[2],LOW);
              digitalWrite(p2_leds[0],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p2_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              digitalWrite(p2_leds[6],LOW);
              p_led3();
              delay(500);
              break;
     case 4:digitalWrite(p1_leds[4],HIGH); // only ldr led
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p2_leds[4],HIGH); // only ldr led
              digitalWrite(p2_leds[3],LOW);
              digitalWrite(p2_leds[1],LOW);
              digitalWrite(p2_leds[2],LOW);
              digitalWrite(p2_leds[0],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p2_leds[5],LOW);
              digitalWrite(p1_leds[6],LOW);
              digitalWrite(p2_leds[6],LOW);
              p_led4();
              delay(500);
              break;
     case 5: digitalWrite(p1_leds[5],HIGH);//only button led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p1_leds[6],LOW);
              digitalWrite(p2_leds[5],HIGH);//only button led
              digitalWrite(p2_leds[4],LOW);
              digitalWrite(p2_leds[1],LOW);
              digitalWrite(p2_leds[2],LOW);
              digitalWrite(p2_leds[3],LOW);
              digitalWrite(p2_leds[6],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p2_leds[0],LOW);

              p_led5();
              delay(500);
              break;
      case 6: digitalWrite(p1_leds[6],HIGH);//only button led
              digitalWrite(p1_leds[4],LOW);
              digitalWrite(p1_leds[1],LOW);
              digitalWrite(p1_leds[2],LOW);
              digitalWrite(p1_leds[3],LOW);
              digitalWrite(p2_leds[6],HIGH);//only button led
              digitalWrite(p2_leds[4],LOW);
              digitalWrite(p2_leds[1],LOW);
              digitalWrite(p2_leds[2],LOW);
              digitalWrite(p2_leds[3],LOW);
              digitalWrite(p1_leds[5],LOW);
              digitalWrite(p2_leds[5],LOW);
              digitalWrite(p1_leds[0],LOW);
              digitalWrite(p2_leds[0],LOW);

              p_led6();
              delay(500);
              break;
      }

    }

     String s1=String(p1_score);
  String s2=String(p2_score); 
Serial.println(s1 + ":" + s2 );
 
  }



    
  
