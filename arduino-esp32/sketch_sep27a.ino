#include <WiFi.h>
 
char  ap_ssid[]  = "1202";
char  password[] = "11111111";
int port_no = 10000;

WiFiServer server(port_no);

//tcp/ip
// Set Static IP address, 依據 AP 指定的網址設定
IPAddress local_IP(192,168,201,11); //三位數頻寬要跟路由器依樣
// Set Gateway IP address
IPAddress gateway(192,168,201,183); //路由器ip會改注意
// Set Subnet mask
IPAddress subnet(255, 255, 255, 0);

String ss="";
String s2 = "red//orange//yellow//green//blue//purple//";
 int start = 0;
 int end = 0;
 String delimiter="//";

const int maxTokens = 150; // 假设最多有6个子字符串
String tokens[maxTokens]; 
int tokenIndex = 0;


//servo
#include <analogWrite.h> 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <EEPROM.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //SCL:22、SDA:21

char ch;

const int stepPin = 4;    // 步進馬達的 STEP 腳位
const int dirPin = 0;     // 步進馬達的 DIR 腳位
const int enPin = 2;
// 設定步進角度
const float stepAngle = 1.8;  // 步進馬達的步進角度

// 設定步進馬達的步進模式
int stepsPerRevolution =0;  // 步進馬達每一圈的步數

      int currentAngle1 = 91;
      int increment = 5;   // 逐步轉動的角度增量 
      int currentAngle2 = 10;
      int currentAngle3 = 30;
      int currentAngle4 = 37;
      int currentAngle5 = 0;
      int currentAngle6 = 0;
//color
int out = 18; //紅

int s22 = 17; //橘

int s33 = 16; //灰

int RedColor = 0;

int GreenColor = 0;

int BlueColor = 0;

int onev=1;
int twov=2;
int thv=3;
int fourv=4;
int fivev=5;
int sixv=6;
int rr=0;
int oo=0;
int gg=0;
int yy=0;
int bb=0;
int pp=0;

int targetAngle1 = 50;

int targetAngle3 = 65;

int targetAngle4 = 37;

int targetAngle6 = 104;

int targetAngle8 = 10;


 int targetAngle9 = 0;
 
int targetAngle99 = 180;

 int targetAngle10 = 65;

 int targetAngle12 = 10;

 int targetAngle13 = 91;

 int targetAngle14 = 30;
//--------------可能全刪
int int6;
int int7;
int int8;
int int9;
int int10;
int int11;

int int12;
int int13;
int int14;
int int15;
int int16;
int int17;

int int18;
int int19;
int int20;
int int21;
int int22;
int int23;

int int24;
int int25;
int int26;
int int27;
int int28;
int int29;

int int30;
int int31;
int int32;
int int33;
int int34;
int int35;

int int36;
int int37;
int int38;
int int39;
int int40;
int int41;

int int42;
int int43;
int int44;
int int45;
int int46;
int int47;

int int48;
int int49;
int int50;
int int51;
int int52;
int int53;

int int54;
int int55;
int int56;
int int57;
int int58;
int int59;

int int60;
int int61;
int int62;
int int63;
int int64;
int int65;

int int66;
char int67;
int int68;

int int69;
char int70;
int int71;

int int72;
char int73;
int int74;

int int75;
char int76;
int int77;

int int78;
char int79;
int int80;

int int81;
char int82;
int int83;

int int84;
char int85;
int int86;

int int87;
char int88;
int int89;

int int90;
char int91;
int int92;

int int93;
char int94;
int int95;


//----------------
 
void ScanColor() {

digitalWrite(s22, LOW);

digitalWrite(s33, LOW);

RedColor = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

digitalWrite(s33, HIGH);

BlueColor = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

digitalWrite(s22, HIGH);

GreenColor = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}


void one(){
 digitalWrite(dirPin, LOW); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  
   delay(1000); 
 int  aaa1=7; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle1); 
   if(targetAngle1>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle1)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle1)
          currentAngle3 = targetAngle1;

        pwm.setPWM(aaa1, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

    delay(500);

    //---------------------
      int  aaa3=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle3); 
   if(targetAngle3>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle3)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle3)
          currentAngle2 = targetAngle3;

        pwm.setPWM(aaa3, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(500);
//-----------------------
    int  aaa4=4; 
   Serial.println("目標角度:");

   Serial.println(targetAngle4); 
   if(targetAngle4>currentAngle4){
//120往下
    
      while (currentAngle4 < targetAngle4)
      {
        currentAngle4 += increment;
        if (currentAngle4 > targetAngle4)
          currentAngle4 = targetAngle4;

        pwm.setPWM(aaa4, 0, 110+currentAngle4*2.44);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
    delay(500); 

 //-----------------------
  int  aaa6=7; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle6); 
   if(targetAngle6>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle6)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle6)
          currentAngle3 = targetAngle6;

        pwm.setPWM(aaa6, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }  

    delay(500);
    //----------------
    
    pwm.setPWM(6, 0, 150+120*1.66); //0
    delay(500);
    //-------------
       int  aaa8=2; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle8); 
  if(targetAngle8<currentAngle2){
//往上
      while (currentAngle2 > targetAngle8)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle8)
          currentAngle2 = targetAngle8;

        pwm.setPWM(aaa8, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
    delay(1000);
    //------------
    //轉步進
    digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }

  delay(2000);
    //------
    int  aaa9=1; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle9); 
if(targetAngle9>91){
//120往右
    
      while (currentAngle1 < targetAngle9)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle9)
          currentAngle1 = targetAngle9;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   
   if(targetAngle9<91){
   while (currentAngle1 > targetAngle9)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle9)
          currentAngle1 = targetAngle9;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }

  
    delay(1000);
//-------------
 int  aaa10=2; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle10); 
if(targetAngle10>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle10)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle10)
          currentAngle2 = targetAngle10;

        pwm.setPWM(aaa10, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(1000);
    //-----------
    pwm.setPWM(6, 0, 150+0*1.66); //90
    delay(2000);
    //-----------
 
       int  aaa12=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle12); 
  if(targetAngle12<currentAngle2){
//往上
      while (currentAngle2 > targetAngle12)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle12)
          currentAngle2 = targetAngle12;

        pwm.setPWM(aaa12, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //----------
         int  aaa13=1; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle13); 
 if(targetAngle13==91){
    if(currentAngle1<91){
while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度1.");
      
      }
            if(currentAngle1>91){
         while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
        }
      
      }
      if(targetAngle13>91){
//120往右
    
      while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle13<91){
   while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }
      

    delay(1000);
    
     int  aaa14=7; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle14); 
  if(targetAngle14<currentAngle3){
//往上
      while (currentAngle3 > targetAngle14)
      {
        currentAngle3 -= increment;
        if (currentAngle3 < targetAngle14)
          currentAngle3 = targetAngle14;

        pwm.setPWM(aaa14, 0, 500-currentAngle3*2.22);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    
  }

void two(){
           digitalWrite(dirPin, LOW); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(1000);
  //--------------------
   int  aaa1=7; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle1); 
   if(targetAngle1>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle1)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle1)
          currentAngle3 = targetAngle1;

        pwm.setPWM(aaa1, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

    delay(500);

    //---------------------
      int  aaa3=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle3); 
   if(targetAngle3>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle3)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle3)
          currentAngle2 = targetAngle3;

        pwm.setPWM(aaa3, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(500);
//-----------------------
    int  aaa4=4; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle4); 
   if(targetAngle4>currentAngle4){
//120往下
    
      while (currentAngle4 < targetAngle4)
      {
        currentAngle4 += increment;
        if (currentAngle4 > targetAngle4)
          currentAngle4 = targetAngle4;

        pwm.setPWM(aaa4, 0, 110+currentAngle4*2.44);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
    delay(500); 

 //-----------------------
  int  aaa6=7; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle6); 
   if(targetAngle6>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle6)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle6)
          currentAngle3 = targetAngle6;

        pwm.setPWM(aaa6, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }  

    delay(500);
    //----------------
    
    pwm.setPWM(6, 0, 150+120*1.66); //0
    delay(1000);
    //-------------
       int  aaa8=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle8); 
  if(targetAngle8<currentAngle2){
//往上
      while (currentAngle2 > targetAngle8)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle8)
          currentAngle2 = targetAngle8;

        pwm.setPWM(aaa8, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
    delay(1000);
    //------------
      digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 2500; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }

  delay(2000);
    //-----------------------
   int  aaa9=1; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle9); 
   if(targetAngle9>91){
//120往右
    
      while (currentAngle1 < targetAngle9)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle9)
          currentAngle1 = targetAngle9;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle9<91){
   while (currentAngle1 > targetAngle9)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle9)
          currentAngle1 = targetAngle9;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }

  
    delay(1000);
//-------------
 int  aaa10=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle10); 
if(targetAngle10>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle10)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle10)
          currentAngle2 = targetAngle10;

        pwm.setPWM(aaa10, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(1000);
    //-----------
    pwm.setPWM(6, 0, 150+0*1.66); //90
    delay(2000);
    //-----------
 
       int  aaa12=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle12); 
  if(targetAngle12<currentAngle2){
//往上
      while (currentAngle2 > targetAngle12)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle12)
          currentAngle2 = targetAngle12;

        pwm.setPWM(aaa12, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //----------
         int  aaa13=1; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle13); 
 if(targetAngle13==91){
    if(currentAngle1<91){
while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度1.");
      
      }
            if(currentAngle1>91){
         while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
        }
      
      }
      if(targetAngle13>91){
//120往右
    
      while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle13<91){
   while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }
      

    delay(1000);
    
     int  aaa14=7; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle14); 
  if(targetAngle14<currentAngle3){
//往上
      while (currentAngle3 > targetAngle14)
      {
        currentAngle3 -= increment;
        if (currentAngle3 < targetAngle14)
          currentAngle3 = targetAngle14;

        pwm.setPWM(aaa14, 0, 500-currentAngle3*2.22);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //-----------------
  digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 2300; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }

  delay(2000);
  }

void th(){
  
         digitalWrite(dirPin, LOW); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(1000);
  //----------------------
int  aaa1=7; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle1); 
   if(targetAngle1>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle1)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle1)
          currentAngle3 = targetAngle1;

        pwm.setPWM(aaa1, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

    delay(500);

    //---------------------
      int  aaa3=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle3); 
   if(targetAngle3>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle3)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle3)
          currentAngle2 = targetAngle3;

        pwm.setPWM(aaa3, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(500);
//-----------------------
    int  aaa4=4; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle4); 
   if(targetAngle4>currentAngle4){
//120往下
    
      while (currentAngle4 < targetAngle4)
      {
        currentAngle4 += increment;
        if (currentAngle4 > targetAngle4)
          currentAngle4 = targetAngle4;

        pwm.setPWM(aaa4, 0, 110+currentAngle4*2.44);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
    delay(500); 

 //-----------------------
  int  aaa6=7; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle6); 
   if(targetAngle6>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle6)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle6)
          currentAngle3 = targetAngle6;

        pwm.setPWM(aaa6, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }  

    delay(500);
    //----------------
    
    pwm.setPWM(6, 0, 150+120*1.66); //0
    delay(1000);
    //-------------
       int  aaa8=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle8); 
  if(targetAngle8<currentAngle2){
//往上
      while (currentAngle2 > targetAngle8)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle8)
          currentAngle2 = targetAngle8;

        pwm.setPWM(aaa8, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
    delay(1000);
    //------------

    int  aaa9=1; 
   Serial.println("目標角度:");

   Serial.println(targetAngle9); 
   if(targetAngle9>91){
//120往右
    
      while (currentAngle1 < targetAngle9)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle9)
          currentAngle1 = targetAngle9;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle9<91){
   while (currentAngle1 > targetAngle9)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle9)
          currentAngle1 = targetAngle9;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }

  
    delay(1000);
//-------------
 int  aaa10=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle10); 
if(targetAngle10>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle10)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle10)
          currentAngle2 = targetAngle10;

        pwm.setPWM(aaa10, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(1000);
    //-----------
    pwm.setPWM(6, 0, 150+0*1.66); //90
    delay(2000);
    //-----------
 
       int  aaa12=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle12); 
  if(targetAngle12<currentAngle2){
//往上
      while (currentAngle2 > targetAngle12)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle12)
          currentAngle2 = targetAngle12;

        pwm.setPWM(aaa12, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //----------
         int  aaa13=1; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle13); 
 if(targetAngle13==91){
    if(currentAngle1<91){
while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度1.");
      
      }
            if(currentAngle1>91){
         while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
        }
      
      }
         if(targetAngle13>91){
//120往右
    
      while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle13<91){
   while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }
      

    delay(1000);
    
     int  aaa14=7; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle14); 
  if(targetAngle14<currentAngle3){
//往上
      while (currentAngle3 > targetAngle14)
      {
        currentAngle3 -= increment;
        if (currentAngle3 < targetAngle14)
          currentAngle3 = targetAngle14;

        pwm.setPWM(aaa14, 0, 500-currentAngle3*2.22);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    
    //-----------------------
 digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(2000);
  
  }

  void four(){
    
          digitalWrite(dirPin, LOW); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(1000);
  //------------------------
int  aaa1=7; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle1); 
   if(targetAngle1>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle1)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle1)
          currentAngle3 = targetAngle1;

        pwm.setPWM(aaa1, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

    delay(500);

    //---------------------
      int  aaa3=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle3); 
   if(targetAngle3>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle3)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle3)
          currentAngle2 = targetAngle3;

        pwm.setPWM(aaa3, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(500);
//-----------------------
    int  aaa4=4; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle4); 
   if(targetAngle4>currentAngle4){
//120往下
    
      while (currentAngle4 < targetAngle4)
      {
        currentAngle4 += increment;
        if (currentAngle4 > targetAngle4)
          currentAngle4 = targetAngle4;

        pwm.setPWM(aaa4, 0, 110+currentAngle4*2.44);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
    delay(500); 

 //-----------------------
  int  aaa6=7; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle6); 
   if(targetAngle6>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle6)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle6)
          currentAngle3 = targetAngle6;

        pwm.setPWM(aaa6, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }  

    delay(500);
    //----------------
    
    pwm.setPWM(6, 0, 150+120*1.66); //0
    delay(1000);
    //-------------
       int  aaa8=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle8); 
  if(targetAngle8<currentAngle2){
//往上
      while (currentAngle2 > targetAngle8)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle8)
          currentAngle2 = targetAngle8;

        pwm.setPWM(aaa8, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
    delay(1000);

//------------------
    //轉步進
      digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(2000);

    //------
    int  aaa9=1; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle99); 
     if(targetAngle99<91){

    
      while (currentAngle1 > targetAngle99)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle99)
          currentAngle1 = targetAngle99;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
if(targetAngle99>91){
//120往右
    
      while (currentAngle1 < targetAngle99)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle99)
          currentAngle1 = targetAngle99;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

  
    delay(1000);
//-------------
 int  aaa10=2; 
   Serial.println("目標角度:");

   Serial.println(targetAngle10); 
if(targetAngle10>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle10)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle10)
          currentAngle2 = targetAngle10;

        pwm.setPWM(aaa10, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(1000);
    //-----------
    pwm.setPWM(6, 0, 150+0*1.66); //90
    delay(2000);
    //-----------
 
       int  aaa12=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle12); 
  if(targetAngle12<currentAngle2){
//往上
      while (currentAngle2 > targetAngle12)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle12)
          currentAngle2 = targetAngle12;

        pwm.setPWM(aaa12, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //----------
         int  aaa13=1; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle13); 
 if(targetAngle13==91){
    if(currentAngle1<91){
while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度1.");
      
      }
            if(currentAngle1>91){
         while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
        }
      
      }
      if(targetAngle13>91){
//120往右
    
      while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle13<91){
   while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
   }
      

    delay(1000);
    
     int  aaa14=7; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle14); 
  if(targetAngle14<currentAngle3){
//往上
      while (currentAngle3 > targetAngle14)
      {
        currentAngle3 -= increment;
        if (currentAngle3 < targetAngle14)
          currentAngle3 = targetAngle14;

        pwm.setPWM(aaa14, 0, 500-currentAngle3*2.22);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);

    
    }

    void five(){
             digitalWrite(dirPin, LOW); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(1000);
  //---------------
int  aaa1=7; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle1); 
   if(targetAngle1>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle1)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle1)
          currentAngle3 = targetAngle1;

        pwm.setPWM(aaa1, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

    delay(500);

    //---------------------
      int  aaa3=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle3); 
   if(targetAngle3>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle3)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle3)
          currentAngle2 = targetAngle3;

        pwm.setPWM(aaa3, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(500);
//-----------------------
    int  aaa4=4; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle4); 
   if(targetAngle4>currentAngle4){
//120往下
    
      while (currentAngle4 < targetAngle4)
      {
        currentAngle4 += increment;
        if (currentAngle4 > targetAngle4)
          currentAngle4 = targetAngle4;

        pwm.setPWM(aaa4, 0, 110+currentAngle4*2.44);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
    delay(500); 

 //-----------------------
  int  aaa6=7; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle6); 
   if(targetAngle6>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle6)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle6)
          currentAngle3 = targetAngle6;

        pwm.setPWM(aaa6, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }  

    delay(500);
    //----------------
    
    pwm.setPWM(6, 0, 150+120*1.66); //0
    delay(1000);
    //-------------
       int  aaa8=2; 
   Serial.println("目標角度:");

   Serial.println(targetAngle8); 
  if(targetAngle8<currentAngle2){
//往上
      while (currentAngle2 > targetAngle8)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle8)
          currentAngle2 = targetAngle8;

        pwm.setPWM(aaa8, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
    delay(1000);


    //轉步進-----------------
      digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 2500; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(2000);
    //----------------

    int  aaa9=1; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle99);
        if(targetAngle99<91){

    
      while (currentAngle1 > targetAngle99)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle99)
          currentAngle1 = targetAngle99;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  } 
if(targetAngle99>91){
//120往右
    
      while (currentAngle1 < targetAngle99)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle99)
          currentAngle1 = targetAngle99;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

  
    delay(1000);
//-------------
 int  aaa10=2; 
   Serial.println("目標角度:");

   Serial.println(targetAngle10); 
if(targetAngle10>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle10)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle10)
          currentAngle2 = targetAngle10;

        pwm.setPWM(aaa10, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(1000);
    //-----------
    pwm.setPWM(6, 0, 150+0*1.66); //90
    delay(2000);
    //-----------
 
       int  aaa12=2; 
   Serial.println("目標角度:");

   Serial.println(targetAngle12); 
  if(targetAngle12<currentAngle2){
//往上
      while (currentAngle2 > targetAngle12)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle12)
          currentAngle2 = targetAngle12;

        pwm.setPWM(aaa12, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //----------
         int  aaa13=1; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle13); 
 if(targetAngle13==91){
    if(currentAngle1<91){
while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度1.");
      
      }
            if(currentAngle1>91){
         while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
        }
      
      }
      if(targetAngle13>91){
//120往右
    
      while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle13<91){
   while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }
      
   }
    delay(1000);
    
     int  aaa14=7; 
   Serial.println("目標角度:");

   Serial.println(targetAngle14); 
  if(targetAngle14<currentAngle3){
//往上
      while (currentAngle3 > targetAngle14)
      {
        currentAngle3 -= increment;
        if (currentAngle3 < targetAngle14)
          currentAngle3 = targetAngle14;

        pwm.setPWM(aaa14, 0, 500-currentAngle3*2.22);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //-------------
  digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 2350; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(2000); 
      
      }

      void six(){
             digitalWrite(dirPin, LOW); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }
  delay(1000);
  //------------------------
int  aaa1=7; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle1); 
   if(targetAngle1>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle1)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle1)
          currentAngle3 = targetAngle1;

        pwm.setPWM(aaa1, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

    delay(500);

    //---------------------
      int  aaa3=2; 
   Serial.println("目標角度:");
   
   Serial.println(targetAngle3); 
   if(targetAngle3>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle3)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle3)
          currentAngle2 = targetAngle3;

        pwm.setPWM(aaa3, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(500);
//-----------------------
    int  aaa4=4; 
   Serial.println("目標角度:");

   Serial.println(targetAngle4); 
   if(targetAngle4>currentAngle4){
//120往下
    
      while (currentAngle4 < targetAngle4)
      {
        currentAngle4 += increment;
        if (currentAngle4 > targetAngle4)
          currentAngle4 = targetAngle4;

        pwm.setPWM(aaa4, 0, 110+currentAngle4*2.44);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
    delay(500); 

 //-----------------------
  int  aaa6=7; 
   Serial.println("目標角度:");

   Serial.println(targetAngle6); 
   if(targetAngle6>currentAngle3){
//120往下
    
      while (currentAngle3 < targetAngle6)
      {
        currentAngle3 += increment;
        if (currentAngle3 > targetAngle6)
          currentAngle3 = targetAngle6;

        pwm.setPWM(aaa6, 0, 500-currentAngle3*2.22);//7
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }  

    delay(500);
    //----------------
    
    pwm.setPWM(6, 0, 150+120*1.66); //0
    delay(1000);
    //-------------
       int  aaa8=2; 
   Serial.println("目標角度:");
 
   Serial.println(targetAngle8); 
  if(targetAngle8<currentAngle2){
//往上
      while (currentAngle2 > targetAngle8)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle8)
          currentAngle2 = targetAngle8;

        pwm.setPWM(aaa8, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
    delay(1000);


    //------
    int  aaa9=1; 
   Serial.println("目標角度:");

   Serial.println(targetAngle99); 
        if(targetAngle99<91){

    
      while (currentAngle1 > targetAngle99)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle99)
          currentAngle1 = targetAngle99;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }
if(targetAngle99>91){
//120往右
    
      while (currentAngle1 < targetAngle99)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle99)
          currentAngle1 = targetAngle99;

        pwm.setPWM(aaa9, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }

  
    delay(1000);
//-------------
 int  aaa10=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle10); 
if(targetAngle10>currentAngle2){
//120往下
    
      while (currentAngle2 < targetAngle10)
      {
        currentAngle2 += increment;
        if (currentAngle2 > targetAngle10)
          currentAngle2 = targetAngle10;

        pwm.setPWM(aaa10, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
 
    delay(1000);
    //-----------
//  馬達放東西
  pwm.setPWM(6, 0, 150+0*1.66); //0
    delay(1000);
    //-----------
 
       int  aaa12=2; 
   Serial.println("目標角度:");
  
   Serial.println(targetAngle12); 
  if(targetAngle12<currentAngle2){
//往上
      while (currentAngle2 > targetAngle12)
      {
        currentAngle2 -= increment;
        if (currentAngle2 < targetAngle12)
          currentAngle2 = targetAngle12;

        pwm.setPWM(aaa12, 0, 350+currentAngle2*2.77);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //----------
         int  aaa13=1; 
   Serial.println("目標角度:");

   Serial.println(targetAngle13); 
 if(targetAngle13==91){
    if(currentAngle1<91){
while (currentAngle1 < targetAngle13)
      {
        currentAngle1 += increment;
        if (currentAngle1 > targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度1.");
      
      }
            if(currentAngle1>91){
         while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
        }
      
      }
      if(targetAngle13>91){
//120往右
    
      while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
      
  }
   if(targetAngle13<91){
   while (currentAngle1 > targetAngle13)
      {
        currentAngle1 -= increment;
        if (currentAngle1 < targetAngle13)
          currentAngle1 = targetAngle13;

        pwm.setPWM(aaa13, 0, 150+currentAngle1*2.55);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }
      
   }
    delay(1000);
    
     int  aaa14=7; 
   Serial.println("目標角度:");

   Serial.println(targetAngle14); 
  if(targetAngle14<currentAngle3){
//往上
      while (currentAngle3 > targetAngle14)
      {
        currentAngle3 -= increment;
        if (currentAngle3 < targetAngle14)
          currentAngle3 = targetAngle14;

        pwm.setPWM(aaa14, 0, 500-currentAngle3*2.22);
        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
      }

      Serial.println("馬達已到達目標角度.");
  }

    delay(1000);
    //--------------
    digitalWrite(dirPin, HIGH); 
    for (int i = 0; i < 4900; i++) {
    digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
    delayMicroseconds(500);          // 延遲0.5毫秒
    digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
    delayMicroseconds(500);          // 延遲0.5毫秒
  }

  delay(2000);
        
        }

   
void setup()
{
  Serial.begin(115200);
  
  if (! WiFi.config(local_IP, gateway, subnet))
    Serial.println("STA Failed to configure");

  Serial.print("Connecting AP.");
  WiFi.begin(ap_ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
  
  // start Server
  server.begin();
  
   while(!Serial);
  pwm.begin();
  pwm.setPWMFreq(60);
    pwm.setPWM(1, 0, 150+91*2.55); //150~600
    pwm.setPWM(2, 0, 350+10*2.77); //140~600
    pwm.setPWM(7, 0, 500-30*2.22); //250 >> -90度、500 >> 0度
    pwm.setPWM(4, 0, 110+37*2.44); //110~
    pwm.setPWM(5, 0, 375+0*2.66); //145~615
    pwm.setPWM(6, 0, 150+0*1.66); //150~450

      pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin,OUTPUT);

pinMode(s22, OUTPUT);

pinMode(s33, OUTPUT);

pinMode(out, INPUT);

}
 
void loop()
{
  WiFiClient client;
  byte  data[800];
  
  client = server.available();
  if (client)
  {                   
    Serial.println("new client");         
    /* check client is connected */           
    while (client.connected())
    {          
      if (client.available())
      {
        int len = client.read(data,800);
        if(len <800)
          data[len] = '\0';  
        else  data[800] = '\0';    
        Serial.print("client sent: ");            
        Serial.println((char *)data); 
        
        ss=(char*)data;
 while (end >= 0 && tokenIndex < maxTokens) {
    end = ss.indexOf(delimiter, start);
    if (end >= 0) {
      String token = ss.substring(start, end);
      tokens[tokenIndex] = token; // 将子字符串存储在数组中
      tokenIndex++;
      start = end + delimiter.length();
    }
  }
  Serial.print("red seat:");
  Serial.println(tokens[0]);
  Serial.print("orange seat:");
  Serial.println(tokens[1]);
  Serial.print("yellow seat:");
  Serial.println(tokens[2]);
  Serial.print("green seat:");
  Serial.println(tokens[3]);
  Serial.print("blue seat:");
  Serial.println(tokens[4]);
  Serial.print("purple seat:");
  Serial.println(tokens[5]);
  
   Serial.println("team1:");
  Serial.println(tokens[6]);//91
  Serial.println(tokens[7]);//20
  Serial.println(tokens[8]);//30
  Serial.println(tokens[9]);//20
  Serial.println(tokens[10]);//0
  Serial.println(tokens[11]);//0
  
    Serial.println("team2:");
  Serial.println(tokens[12]);
  Serial.println(tokens[13]);
  Serial.println(tokens[14]);
  Serial.println(tokens[15]);
  Serial.println(tokens[16]);
  Serial.println(tokens[17]);

    Serial.println("team3:");
  Serial.println(tokens[18]);
  Serial.println(tokens[19]);
  Serial.println(tokens[20]);
  Serial.println(tokens[21]);
  Serial.println(tokens[22]);
  Serial.println(tokens[23]);

    Serial.println("team4:");
  Serial.println(tokens[24]);
  Serial.println(tokens[25]);
  Serial.println(tokens[26]);
  Serial.println(tokens[27]);
  Serial.println(tokens[28]);
  Serial.println(tokens[29]);

    Serial.println("team5:");
  Serial.println(tokens[30]);
  Serial.println(tokens[31]);
  Serial.println(tokens[32]);
  Serial.println(tokens[33]);
  Serial.println(tokens[34]);
  Serial.println(tokens[35]);

    Serial.println("team6:");
  Serial.println(tokens[36]);
  Serial.println(tokens[37]);
  Serial.println(tokens[38]);
  Serial.println(tokens[39]);
  Serial.println(tokens[40]);
  Serial.println(tokens[41]);

    Serial.println("team7:");
  Serial.println(tokens[42]);
  Serial.println(tokens[43]);
  Serial.println(tokens[44]);
  Serial.println(tokens[45]);
  Serial.println(tokens[46]);
  Serial.println(tokens[47]);

    Serial.println("team8:");
  Serial.println(tokens[48]);
  Serial.println(tokens[49]);
  Serial.println(tokens[50]);
  Serial.println(tokens[51]);
  Serial.println(tokens[52]);
  Serial.println(tokens[53]);

    Serial.println("team9:");
  Serial.println(tokens[54]);
  Serial.println(tokens[55]);
  Serial.println(tokens[56]);
  Serial.println(tokens[57]);
  Serial.println(tokens[58]);
  Serial.println(tokens[59]);

    Serial.println("team10:");
  Serial.println(tokens[60]);
  Serial.println(tokens[61]);
  Serial.println(tokens[62]);
  Serial.println(tokens[63]);
  Serial.println(tokens[64]);
  Serial.println(tokens[65]);

  Serial.println("step1:");
  Serial.println(tokens[66]);//第幾組後
  Serial.println(tokens[67]);//fb
  Serial.println(tokens[68]);//幾步

    Serial.println("step2:");
  Serial.println(tokens[69]);
  Serial.println(tokens[70]);
  Serial.println(tokens[71]);


    Serial.println("step3:");
  Serial.println(tokens[72]);
  Serial.println(tokens[73]);
  Serial.println(tokens[74]);

    Serial.println("step4:");
  Serial.println(tokens[75]);
  Serial.println(tokens[76]);
  Serial.println(tokens[77]);

    Serial.println("step5:");
  Serial.println(tokens[78]);
  Serial.println(tokens[79]);
  Serial.println(tokens[80]);

    Serial.println("step6:");
  Serial.println(tokens[81]);
  Serial.println(tokens[82]);
  Serial.println(tokens[83]);

    Serial.println("step7:");
  Serial.println(tokens[84]);
  Serial.println(tokens[85]);
  Serial.println(tokens[86]);

    Serial.println("step8:");
  Serial.println(tokens[87]);
  Serial.println(tokens[88]);
  Serial.println(tokens[89]);

    Serial.println("step9:");
  Serial.println(tokens[90]);
  Serial.println(tokens[91]);
  Serial.println(tokens[92]);

    Serial.println("step10:");
  Serial.println(tokens[93]);
  Serial.println(tokens[94]);
  Serial.println(tokens[95]);

  



  

  //-------------------------手動設定10組
//第一組
int tt1=tokens[6].toInt();
Serial.print("tt1=");
Serial.println(tt1);
Serial.print("to6=");
Serial.print(tokens[6]);
if(tt1==500){Serial.println("沒有值");}
      else{
//servo1
        int6=tokens[6].toInt();
          Serial.print("int6=");
              Serial.println(int6);
        //>91
          if(int6>91){
          //120往右
          
            while (currentAngle1 < int6)
            {
              currentAngle1 += increment;
              if (currentAngle1 > int6)
                currentAngle1 = int6;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int6)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int6)
                currentAngle1 = int6;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int6==91){
            if(currentAngle1<91){
            while (currentAngle1 < int6)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int6)
          currentAngle1 = int6;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 > int6)
          {
          currentAngle1 -= increment;
          if (currentAngle1 < int6)
          currentAngle1 = int6;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int6)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int6)
          currentAngle1 = int6;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 < int6)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int6)
          currentAngle1 = int6;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int6<91){

    
          while (currentAngle1 > int6)
          {
            currentAngle1 -= increment;
            if (currentAngle1 < int6)
              currentAngle1 = int6;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 < int6)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int6)
              currentAngle1 = int6;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int7=tokens[7].toInt();
              Serial.print("int7=");
              Serial.println(int7);
          if(int7>currentAngle2){
          //120往下
              
                while (currentAngle2 < int7)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int7)
                    currentAngle2 = int7;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int7<currentAngle2){
            //往上
                  while (currentAngle2 > int7)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int7)
                      currentAngle2 = int7;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int8=tokens[8].toInt(); 
              Serial.print("int8=");
              Serial.println(int8);
              if(int8>currentAngle3){
              //120往下
                  
                    while (currentAngle3 < int8)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int8)
                        currentAngle3 = int8;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int8<currentAngle3){
                //往上
                      while (currentAngle3 >int8)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int8)
                          currentAngle3 =int8;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int9=tokens[9].toInt(); 
              if(int9>currentAngle4){
              //120往下
                  
                    while (currentAngle4 < int9)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int9)
                        currentAngle4 = int9;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int9<currentAngle4){
                //往上
                      while (currentAngle4 >int9)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 < int9)
                          currentAngle4 =int9;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int10=tokens[10].toInt();
                  if(int10>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int10)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int10)
                            currentAngle5 = int10;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int10<currentAngle5){
                    //往上
                          while (currentAngle5 >int10)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int10)
                              currentAngle5 = int10;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int11=tokens[11].toInt();
                    pwm.setPWM(6, 0,150+int11*1.66);
                    delay(500);
                    
                    int66=tokens[66].toInt();
                    Serial.print("int66=");
                    Serial.println(int66);
                    int67=tokens[67].charAt(0);
                    Serial.print("int67=");
                    Serial.println(int67);
                    int68=tokens[68].toInt();
                    Serial.print("int68=");
                    Serial.println(int68);
                    if(int66==1){
                      Serial.print("+++++++++++++++");
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第二組----------------------------
int tt2=tokens[12].toInt();
Serial.print("tt2=");
Serial.println(tt2);
Serial.print("to12=");
Serial.print(tokens[12]);
if(tt2==500){Serial.println("沒有值");}
      else{
//servo1
        int12=tokens[12].toInt();
        //>91
          if(int12>91){
          //120往右
          
            while (currentAngle1 < int12)
            {
              currentAngle1 += increment;
              if (currentAngle1 > int12)
                currentAngle1 = int12;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int12)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int12)
                currentAngle1 = int12;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int12==91){
            if(currentAngle1<91){
            while (currentAngle1 < int12)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int12)
          currentAngle1 =int12;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 > int12)
          {
          currentAngle1 -= increment;
          if (currentAngle1 < int12)
          currentAngle1 = int12;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int12)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int12)
          currentAngle1 = int12;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int12)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int12)
          currentAngle1 =int12;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int12<91){

    
          while (currentAngle1 > int12)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int12)
              currentAngle1 = int12;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 < int12)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int12)
              currentAngle1 =int12;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int13=tokens[13].toInt();
          if(int13>currentAngle2){
          //120往下
              
                while (currentAngle2 <int13)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int13)
                    currentAngle2 = int13;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int13<currentAngle2){
            //往上
                  while (currentAngle2 > int13)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int13)
                      currentAngle2 =int13;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int14=tokens[14].toInt(); 
    
              if(int14>currentAngle3){
              //120往下
                  
                    while (currentAngle3 < int14)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int14)
                        currentAngle3 = int14;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int14<currentAngle3){
                //往上
                      while (currentAngle3 >int14)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int14)
                          currentAngle3 =int14;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int15=tokens[15].toInt(); 
              if(int15>currentAngle4){
              //120往下
                  
                    while (currentAngle4 < int15)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int15)
                        currentAngle4 = int15;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int15<currentAngle4){
                //往上
                      while (currentAngle4 >int15)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int15)
                          currentAngle4 =int15;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int16=tokens[16].toInt();
                  if(int16>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int16)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int16)
                            currentAngle5 =int16;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int16<currentAngle5){
                    //往上
                          while (currentAngle5 >int16)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int16)
                              currentAngle5 = int16;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int17=tokens[17].toInt();
                    pwm.setPWM(6, 0,150+int17*1.66);

                    int69=tokens[69].toInt();
                    Serial.print("int69=");
                    Serial.println(int69);
                    int70=tokens[70].charAt(0);
                    Serial.print("int70=");
                    Serial.println(int70);
                    int71=tokens[71].toInt();
                    Serial.print("int71=");
                    Serial.println(int71);
                    if(int66==2){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==2){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第三組----------------------------
int tt3=tokens[18].toInt();
Serial.print("tt3=");
Serial.println(tt3);
Serial.print("to18=");
Serial.print(tokens[18]);
if(tt3==500){Serial.println("沒有值");}
      else{
//servo1
        int18=tokens[18].toInt();
        //>91
          if(int18>91){
          //120往右
          
            while (currentAngle1 < int18)
            {
              currentAngle1 += increment;
              if (currentAngle1 > int18)
                currentAngle1 = int18;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int18)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int18)
                currentAngle1 = int18;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int18==91){
            if(currentAngle1<91){
            while (currentAngle1 < int18)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int18)
          currentAngle1 =int18;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int18)
          {
          currentAngle1 -= increment;
          if (currentAngle1 < int18)
          currentAngle1 = int18;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int18)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int18)
          currentAngle1 = int18;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int18)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int18)
          currentAngle1 =int18;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int18<91){

    
          while (currentAngle1 > int18)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int18)
              currentAngle1 = int18;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 < int18)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int18)
              currentAngle1 =int18;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int19=tokens[19].toInt();
          if(int19>currentAngle2){
          //120往下
              
                while (currentAngle2 <int19)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int19)
                    currentAngle2 = int19;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int19<currentAngle2){
            //往上
                  while (currentAngle2 > int19)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int19)
                      currentAngle2 =int19;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int20=tokens[20].toInt(); 
    
              if(int20>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int20)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int20)
                        currentAngle3 = int20;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int20<currentAngle3){
                //往上
                      while (currentAngle3 >int20)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int20)
                          currentAngle3 =int20;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int21=tokens[21].toInt(); 
              if(int21>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int21)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int21)
                        currentAngle4 = int21;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int21<currentAngle4){
                //往上
                      while (currentAngle4 >int21)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int21)
                          currentAngle4 =int21;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int22=tokens[22].toInt();
                  if(int22>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int22)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int22)
                            currentAngle5 =int22;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int22<currentAngle5){
                    //往上
                          while (currentAngle5 >int22)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int22)
                              currentAngle5 = int22;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int23=tokens[23].toInt();
                    pwm.setPWM(6, 0,150+int23*1.66);

                    int72=tokens[72].toInt();
                    Serial.print("int72=");
                    Serial.println(int72);
                    int73=tokens[73].charAt(0);
                    Serial.print("int73=");
                    Serial.println(int73);
                    int74=tokens[74].toInt();
                    Serial.print("int74=");
                    Serial.println(int74);
                    if(int66==3){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==3){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==3){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第四組----------------------------
int tt4=tokens[24].toInt();
Serial.print("tt4=");
Serial.println(tt4);
Serial.print("to24=");
Serial.print(tokens[24]);
if(tt4==500){Serial.println("沒有值");}
      else{
//servo1
        int24=tokens[24].toInt();
        //>91
          if(int24>91){
          //120往右
          
            while (currentAngle1 < int24)
            {
              currentAngle1 += increment;
              if (currentAngle1 > int24)
                currentAngle1 = int24;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int24)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int24)
                currentAngle1 = int24;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int24==91){
            if(currentAngle1<91){
            while (currentAngle1 < int24)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int24)
          currentAngle1 =int24;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int24)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int24)
          currentAngle1 = int24;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int24)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int24)
          currentAngle1 = int24;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int24)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int24)
          currentAngle1 =int24;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int24<91){

    
          while (currentAngle1 > int24)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int24)
              currentAngle1 = int24;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int24)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int24)
              currentAngle1 =int24;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int25=tokens[25].toInt();
          if(int25>currentAngle2){
          //120往下
              
                while (currentAngle2 <int25)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int25)
                    currentAngle2 = int25;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int25<currentAngle2){
            //往上
                  while (currentAngle2 > int25)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int25)
                      currentAngle2 =int25;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int26=tokens[26].toInt(); 
    
              if(int26>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int26)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int26)
                        currentAngle3 = int26;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int26<currentAngle3){
                //往上
                      while (currentAngle3 >int26)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int26)
                          currentAngle3 =int26;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int27=tokens[27].toInt(); 
              if(int27>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int27)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int27)
                        currentAngle4 = int27;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int27<currentAngle4){
                //往上
                      while (currentAngle4 >int27)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int27)
                          currentAngle4 =int27;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int28=tokens[28].toInt();
                  if(int28>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int28)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int28)
                            currentAngle5 =int28;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int28<currentAngle5){
                    //往上
                          while (currentAngle5 >int28)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int28)
                              currentAngle5 = int28;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int29=tokens[29].toInt();
                    pwm.setPWM(6, 0,150+int29*1.66);

                    int75=tokens[75].toInt();
                    Serial.print("int75=");
                    Serial.println(int75);
                    int76=tokens[76].charAt(0);
                    Serial.print("int76=");
                    Serial.println(int76);
                    int77=tokens[77].toInt();
                    Serial.print("int77=");
                    Serial.println(int77);
                    if(int66==4){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==4){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==4){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==4){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第五組----------------------------
int tt5=tokens[30].toInt();
Serial.print("tt5=");
Serial.println(tt5);
Serial.print("to30=");
Serial.print(tokens[30]);
if(tt5==500){Serial.println("沒有值");}
      else{
//servo1
        int30=tokens[30].toInt();
        //>91
          if(int30>91){
          //120往右
          
            while (currentAngle1 <int30)
            {
              currentAngle1 += increment;
              if (currentAngle1 >int30)
                currentAngle1 = int30;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int30)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int30)
                currentAngle1 = int30;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int30==91){
            if(currentAngle1<91){
            while (currentAngle1 < int30)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int30)
          currentAngle1 =int30;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int30)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int30)
          currentAngle1 = int30;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int30)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int30)
          currentAngle1 = int30;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int30)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int30)
          currentAngle1 =int30;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int30<91){

    
          while (currentAngle1 > int30)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int30)
              currentAngle1 = int30;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int30)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int30)
              currentAngle1 =int30;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int31=tokens[31].toInt();
          if(int31>currentAngle2){
          //120往下
              
                while (currentAngle2 <int31)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int31)
                    currentAngle2 = int31;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int31<currentAngle2){
            //往上
                  while (currentAngle2 > int31)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int31)
                      currentAngle2 =int31;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int32=tokens[32].toInt(); 
    
              if(int32>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int32)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int32)
                        currentAngle3 = int32;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int32<currentAngle3){
                //往上
                      while (currentAngle3 >int32)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int32)
                          currentAngle3 =int32;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int33=tokens[33].toInt(); 
              if(int33>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int33)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int33)
                        currentAngle4 = int33;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int33<currentAngle4){
                //往上
                      while (currentAngle4 >int33)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int33)
                          currentAngle4 =int33;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int34=tokens[34].toInt();
                  if(int34>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int34)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int34)
                            currentAngle5 =int34;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int34<currentAngle5){
                    //往上
                          while (currentAngle5 >int34)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int34)
                              currentAngle5 = int34;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int35=tokens[35].toInt();
                    pwm.setPWM(6, 0,150+int35*1.66);

                    
                    int78=tokens[78].toInt();
                    Serial.print("int78=");
                    Serial.println(int78);
                    int79=tokens[79].charAt(0);
                    Serial.print("int79=");
                    Serial.println(int79);
                    int80=tokens[80].toInt();
                    Serial.print("int80=");
                    Serial.println(int80);
                    if(int66==5){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==5){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==5){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==5){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int78==5){
                      if(int79=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int79=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int80; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第六組----------------------------
int tt6=tokens[36].toInt();
Serial.print("tt6=");
Serial.println(tt6);
Serial.print("to36=");
Serial.print(tokens[36]);
if(tt6==500){Serial.println("沒有值");}
      else{
//servo1
        int36=tokens[36].toInt();
        //>91
          if(int36>91){
          //120往右
          
            while (currentAngle1 <int36)
            {
              currentAngle1 += increment;
              if (currentAngle1 >int36)
                currentAngle1 = int36;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int36)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int36)
                currentAngle1 = int36;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int36==91){
            if(currentAngle1<91){
            while (currentAngle1 < int36)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int36)
          currentAngle1 =int36;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int36)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int36)
          currentAngle1 = int36;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int36)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int36)
          currentAngle1 = int36;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int36)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int36)
          currentAngle1 =int36;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int36<91){

    
          while (currentAngle1 > int36)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int36)
              currentAngle1 = int36;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int36)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int36)
              currentAngle1 =int36;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int37=tokens[37].toInt();
          if(int37>currentAngle2){
          //120往下
              
                while (currentAngle2 <int37)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int37)
                    currentAngle2 = int37;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int37<currentAngle2){
            //往上
                  while (currentAngle2 > int37)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int37)
                      currentAngle2 =int37;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int38=tokens[38].toInt(); 
    
              if(int38>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int38)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int38)
                        currentAngle3 = int38;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int38<currentAngle3){
                //往上
                      while (currentAngle3 >int38)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int38)
                          currentAngle3 =int38;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int39=tokens[39].toInt(); 
              if(int39>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int39)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int39)
                        currentAngle4 = int39;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int39<currentAngle4){
                //往上
                      while (currentAngle4 >int39)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int39)
                          currentAngle4 =int39;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int40=tokens[40].toInt();
                  if(int40>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int40)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int40)
                            currentAngle5 =int40;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int40<currentAngle5){
                    //往上
                          while (currentAngle5 >int40)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int40)
                              currentAngle5 = int40;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int41=tokens[41].toInt();
                    pwm.setPWM(6, 0,150+int41*1.66);

                    int81=tokens[81].toInt();
                    Serial.print("int81=");
                    Serial.println(int81);
                    int82=tokens[82].charAt(0);
                    Serial.print("int82=");
                    Serial.println(int82);
                    int83=tokens[83].toInt();
                    Serial.print("int83=");
                    Serial.println(int83);
                    if(int66==6){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==6){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==6){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==6){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int78==6){
                      if(int79=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int79=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int80; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                     if(int81==6){
                      if(int82=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int82=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int83; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                    }
                    
                    delay(100);
//第七組----------------------------
int tt7=tokens[42].toInt();
Serial.print("tt7=");
Serial.println(tt7);
Serial.print("to42=");
Serial.print(tokens[42]);
if(tt7==500){Serial.println("沒有值");}
      else{
//servo1
        int42=tokens[42].toInt();
        //>91
          if(int42>91){
          //120往右
          
            while (currentAngle1 <int42)
            {
              currentAngle1 += increment;
              if (currentAngle1 >int42)
                currentAngle1 = int42;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int42)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int42)
                currentAngle1 = int42;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int42==91){
            if(currentAngle1<91){
            while (currentAngle1 < int42)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int42)
          currentAngle1 =int42;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int42)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int42)
          currentAngle1 = int42;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int42)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int42)
          currentAngle1 = int42;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int42)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int42)
          currentAngle1 =int42;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int42<91){

    
          while (currentAngle1 > int42)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int42)
              currentAngle1 = int42;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int42)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int42)
              currentAngle1 =int42;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int43=tokens[43].toInt();
          if(int43>currentAngle2){
          //120往下
              
                while (currentAngle2 <int43)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int43)
                    currentAngle2 = int43;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int43<currentAngle2){
            //往上
                  while (currentAngle2 > int43)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int43)
                      currentAngle2 =int43;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int44=tokens[44].toInt(); 
    
              if(int44>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int44)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int44)
                        currentAngle3 = int44;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int44<currentAngle3){
                //往上
                      while (currentAngle3 >int44)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int44)
                          currentAngle3 =int44;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int45=tokens[45].toInt(); 
              if(int45>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int45)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int45)
                        currentAngle4 = int45;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int45<currentAngle4){
                //往上
                      while (currentAngle4 >int45)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int45)
                          currentAngle4 =int45;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int46=tokens[46].toInt();
                  if(int46>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int46)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int46)
                            currentAngle5 =int46;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int46<currentAngle5){
                    //往上
                          while (currentAngle5 >int46)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int46)
                              currentAngle5 = int46;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int47=tokens[47].toInt();
                    pwm.setPWM(6, 0,150+int47*1.66);

                    int84=tokens[84].toInt();
                    Serial.print("int84=");
                    Serial.println(int84);
                    int85=tokens[85].charAt(0);
                    Serial.print("int85=");
                    Serial.println(int85);
                    int86=tokens[86].toInt();
                    Serial.print("int86=");
                    Serial.println(int86);
                    if(int66==7){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==7){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==7){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==7){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int78==7){
                      if(int79=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int79=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int80; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                     if(int81==7){
                      if(int82=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int82=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int83; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int84==7){
                      if(int85=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int85=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int86; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第八組----------------------------
int tt8=tokens[48].toInt();
Serial.print("tt8=");
Serial.println(tt8);
Serial.print("to48=");
Serial.print(tokens[48]);
if(tt8==500){Serial.println("沒有值");}
      else{
//servo1
        int48=tokens[48].toInt();
        //>91
          if(int48>91){
          //120往右
          
            while (currentAngle1 <int48)
            {
              currentAngle1 += increment;
              if (currentAngle1 >int48)
                currentAngle1 = int48;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int48)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int48)
                currentAngle1 = int48;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int48==91){
            if(currentAngle1<91){
            while (currentAngle1 < int48)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int48)
          currentAngle1 =int48;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int48)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int48)
          currentAngle1 = int48;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int48)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int48)
          currentAngle1 = int48;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int48)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int48)
          currentAngle1 =int48;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int48<91){

    
          while (currentAngle1 > int48)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int48)
              currentAngle1 = int48;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int48)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int48)
              currentAngle1 =int48;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int49=tokens[49].toInt();
          if(int49>currentAngle2){
          //120往下
              
                while (currentAngle2 <int49)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int49)
                    currentAngle2 = int49;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int49<currentAngle2){
            //往上
                  while (currentAngle2 > int49)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int49)
                      currentAngle2 =int49;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int50=tokens[50].toInt(); 
    
              if(int50>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int50)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int50)
                        currentAngle3 = int50;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int50<currentAngle3){
                //往上
                      while (currentAngle3 >int50)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int50)
                          currentAngle3 =int50;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int51=tokens[51].toInt(); 
              if(int51>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int51)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int51)
                        currentAngle4 = int51;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int51<currentAngle4){
                //往上
                      while (currentAngle4 >int51)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int51)
                          currentAngle4 =int51;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int52=tokens[52].toInt();
                  if(int52>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int52)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int52)
                            currentAngle5 =int52;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int52<currentAngle5){
                    //往上
                          while (currentAngle5 >int52)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int52)
                              currentAngle5 = int52;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int53=tokens[53].toInt();
                    pwm.setPWM(6, 0,150+int53*1.66);

                    int87=tokens[87].toInt();
                    Serial.print("int87=");
                    Serial.println(int87);
                    int88=tokens[88].charAt(0);
                    Serial.print("int88=");
                    Serial.println(int88);
                    int89=tokens[89].toInt();
                    Serial.print("int89=");
                    Serial.println(int89);
                    if(int66==8){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==8){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==8){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==8){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int78==8){
                      if(int79=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int79=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int80; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                     if(int81==8){
                      if(int82=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int82=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int83; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int84==8){
                      if(int85=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int85=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int86; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int87==8){
                      if(int88=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int88=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int89; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第九組----------------------------
int tt9=tokens[54].toInt();
Serial.print("tt9=");
Serial.println(tt9);
Serial.print("to54=");
Serial.print(tokens[54]);
if(tt9==500){Serial.println("沒有值");}
      else{
//servo1
        int54=tokens[54].toInt();
        //>91
          if(int54>91){
          //120往右
          
            while (currentAngle1 <int54)
            {
              currentAngle1 += increment;
              if (currentAngle1 >int54)
                currentAngle1 = int54;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int54)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int54)
                currentAngle1 = int54;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int54==91){
            if(currentAngle1<91){
            while (currentAngle1 < int54)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int54)
          currentAngle1 =int54;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int54)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int54)
          currentAngle1 = int54;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int54)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int54)
          currentAngle1 = int54;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int54)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int54)
          currentAngle1 =int54;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int54<91){

    
          while (currentAngle1 > int54)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int54)
              currentAngle1 = int54;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int54)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int54)
              currentAngle1 =int54;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int55=tokens[55].toInt();
          if(int55>currentAngle2){
          //120往下
              
                while (currentAngle2 <int55)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int55)
                    currentAngle2 = int55;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int55<currentAngle2){
            //往上
                  while (currentAngle2 > int55)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int55)
                      currentAngle2 =int55;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int56=tokens[56].toInt(); 
    
              if(int56>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int56)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int56)
                        currentAngle3 = int56;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int56<currentAngle3){
                //往上
                      while (currentAngle3 >int56)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int56)
                          currentAngle3 =int56;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int57=tokens[57].toInt(); 
              if(int57>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int57)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int57)
                        currentAngle4 = int57;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int57<currentAngle4){
                //往上
                      while (currentAngle4 >int57)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int57)
                          currentAngle4 =int57;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int58=tokens[58].toInt();
                  if(int58>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int58)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int58)
                            currentAngle5 =int58;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int58<currentAngle5){
                    //往上
                          while (currentAngle5 >int58)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int58)
                              currentAngle5 = int58;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int59=tokens[59].toInt();
                    pwm.setPWM(6, 0,150+int59*1.66);

                    int90=tokens[90].toInt();
                    Serial.print("int90=");
                    Serial.println(int90);
                    int91=tokens[91].charAt(0);
                    Serial.print("int91=");
                    Serial.println(int91);
                    int92=tokens[92].toInt();
                    Serial.print("int92=");
                    Serial.println(int92);
                    if(int66==9){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==9){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==9){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==9){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int78==9){
                      if(int79=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int79=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int80; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                     if(int81==9){
                      if(int82=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int82=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int83; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int84==9){
                      if(int85=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int85=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int86; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int87==9){
                      if(int88=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int88=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int89; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int90==9){
                      if(int91=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int91=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int92; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//第十組----------------------------
int tt10=tokens[60].toInt();
Serial.print("tt10=");
Serial.println(tt10);
Serial.print("to60=");
Serial.print(tokens[60]);
if(tt10==500){Serial.println("沒有值");}
      else{
//servo1
        int60=tokens[60].toInt();
        //>91
          if(int60>91){
          //120往右
          
            while (currentAngle1 <int60)
            {
              currentAngle1 += increment;
              if (currentAngle1 >int60)
                currentAngle1 = int60;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }

            while (currentAngle1 > int60)
            {
              currentAngle1 -= increment;
              if (currentAngle1 < int60)
                currentAngle1 = int60;
      
              pwm.setPWM(1, 0, 150+currentAngle1*2.55);
              delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
            }
      
            Serial.println("馬達已到達目標角度.");
            
          }
          //=91
            if(int60==91){
            if(currentAngle1<91){
            while (currentAngle1 < int60)
          {
          currentAngle1 += increment;
          if (currentAngle1 > int60)
          currentAngle1 =int60;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 >int60)
          {
          currentAngle1 -= increment;
          if (currentAngle1 <int60)
          currentAngle1 = int60;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
  
          Serial.println("馬達已到達目標角度.");
      
          }
         if(currentAngle1>91){
         while (currentAngle1 > int60)
        {
        currentAngle1 -= increment;
        if (currentAngle1 <int60)
          currentAngle1 = int60;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }

        while (currentAngle1 <int60)
        {
        currentAngle1 += increment;
        if (currentAngle1 > int60)
          currentAngle1 =int60;

          pwm.setPWM(1, 0, 150+currentAngle1*2.55);
          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
         }
 
         Serial.println("馬達已到達目標角度.");
        }
      
        }
        //<91
          if(int60<91){

    
          while (currentAngle1 > int60)
          {
            currentAngle1 -= increment;
            if (currentAngle1 <int60)
              currentAngle1 = int60;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }

          while (currentAngle1 <int60)
          {
            currentAngle1 += increment;
            if (currentAngle1 > int60)
              currentAngle1 =int60;
    
            pwm.setPWM(1, 0, 150+currentAngle1*2.55);
            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
          }
    
          Serial.println("馬達已到達目標角度.");
          }
          
          delay(100);
//servo2
          int61=tokens[61].toInt();
          if(int61>currentAngle2){
          //120往下
              
                while (currentAngle2 <int61)
                {
                  currentAngle2 += increment;
                  if (currentAngle2 > int61)
                    currentAngle2 = int61;
          
                  pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                  delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                }
          
                Serial.println("馬達已到達目標角度.");
                
            }

              if(int61<currentAngle2){
            //往上
                  while (currentAngle2 > int61)
                  {
                    currentAngle2 -= increment;
                    if (currentAngle2 < int61)
                      currentAngle2 =int61;
            
                    pwm.setPWM(2, 0, 350+currentAngle2*2.77);
                    delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                  }
            
                  Serial.println("馬達已到達目標角度.");
              }
              delay(100);

//servo3
              int62=tokens[62].toInt(); 
    
              if(int62>currentAngle3){
              //120往下
                  
                    while (currentAngle3 <int62)
                    {
                      currentAngle3 += increment;
                      if (currentAngle3 >int62)
                        currentAngle3 = int62;
              
                      pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }

                  if(int62<currentAngle3){
                //往上
                      while (currentAngle3 >int62)
                      {
                        currentAngle3 -= increment;
                        if (currentAngle3 < int62)
                          currentAngle3 =int62;
                
                        pwm.setPWM(7, 0, 500-currentAngle3*2.22);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
//servo4
              int63=tokens[63].toInt(); 
              if(int63>currentAngle4){
              //120往下
                  
                    while (currentAngle4 <int63)
                    {
                      currentAngle4 += increment;
                      if (currentAngle4 > int63)
                        currentAngle4 = int63;
              
                      pwm.setPWM(4, 0, 110+currentAngle4*2.44);
                      delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                    }
              
                    Serial.println("馬達已到達目標角度.");
                    
                }
                  if(int63<currentAngle4){
                //往上
                      while (currentAngle4 >int63)
                      {
                        currentAngle4 -= increment;
                        if (currentAngle4 <int63)
                          currentAngle4 =int63;
                
                        pwm.setPWM(4, 0,110+currentAngle4*2.44);
                        delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                      }
                
                      Serial.println("馬達已到達目標角度.");
                  }
                  delay(100);
 //servo5
                  int64=tokens[64].toInt();
                  if(int64>currentAngle5){
                  //120往下
                      
                        while (currentAngle5< int64)
                        {
                          currentAngle5 += increment;
                          if (currentAngle5 >int64)
                            currentAngle5 =int64;
                  
                          pwm.setPWM(5, 0, 375+ currentAngle5*2.66);
                          delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                        }
                  
                        Serial.println("馬達已到達目標角度.");
                        
                    }
                      if(int64<currentAngle5){
                    //往上
                          while (currentAngle5 >int64)
                          {
                            currentAngle5 -= increment;
                            if (currentAngle5< int64)
                              currentAngle5 = int64;
                    
                            pwm.setPWM(5, 0,375+ currentAngle5*2.66);
                            delay(100);  // 控制每個增量的時間，這裡設定為100毫秒
                          }
                    
                          Serial.println("馬達已到達目標角度.");
                      }
                      delay(100);
//servo6
                    int65=tokens[65].toInt();
                    pwm.setPWM(6, 0,150+int65*1.66);

                    int93=tokens[93].toInt();
                    Serial.print("int93=");
                    Serial.println(int93);
                    int94=tokens[94].charAt(0);
                    Serial.print("int94=");
                    Serial.println(int94);
                    int95=tokens[95].toInt();
                    Serial.print("int95=");
                    Serial.println(int95);
                    if(int66==10){
                      if(int67=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int67=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int68; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int69==10){
                      if(int70=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int70=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int71; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int72==10){
                      if(int73=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int73=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int74; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int75==10){
                      if(int76=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int76=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int77; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      
                      if(int78==10){
                      if(int79=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int79=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int80; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                     if(int81==10){
                      if(int82=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int82=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int83; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int84==10){
                      if(int85=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int85=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int86; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }

                      if(int87==10){
                      if(int88=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int88=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int89; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int90==10){
                      if(int91=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int91=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int92; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                      if(int93==10){
                      if(int94=='f'){//步進往前
                        digitalWrite(dirPin, LOW); 
                        }
                      if(int94=='b'){//步進往後
                         digitalWrite(dirPin, HIGH);
                        }
                    for (int i = 0; i < int95; i++) {
                        digitalWrite(stepPin, HIGH);    // 設定 STEP 腳位為高電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        digitalWrite(stepPin, LOW);     // 設定 STEP 腳位為低電位
                        delayMicroseconds(500);          // 延遲0.5毫秒
                        } 
                      }
                    }
                    
                    delay(100);
//結束-----------------

   client.printf("%d個//%d個//%d個//%d個//%d個//%d個//",rr,oo,yy,gg,bb,pp);//回傳資料rpi 改後面的東西應該酒可以傳給rpiX了 還沒試
          
      }
    }

  }


      //color
ScanColor();

Serial.print(" Red: ");

Serial.print(RedColor);

Serial.print(" Green: ");

Serial.print(GreenColor);

Serial.print(" Blue : ");

Serial.println(BlueColor);
delay(1000);
if ((  GreenColor <=25 && GreenColor >= 20)&&(BlueColor <= 38 && BlueColor>=30)) {

Serial.println(" – (yellow Color)");
yy++;
if(tokens[2].toInt()==onev){
  one();
  }
if(tokens[2].toInt()==twov){
  two();
  }
  if(tokens[2].toInt()==thv){
  th();
  }
  if(tokens[2].toInt()==fourv){
  four();
  }
  if(tokens[2].toInt()==fivev){
  five();
  }
  if(tokens[2].toInt()==sixv){ //兩個相等的話會等於0
  six();
  }

}
if ((RedColor <= 20 && RedColor >= 16)&&(  GreenColor <=37 && GreenColor >= 33)&&(BlueColor <= 19 && BlueColor>=16)) {

Serial.println(" – (purple Color)");
pp++;
if(tokens[5].toInt()==onev){
  one();
  }
if(tokens[5].toInt()==twov){
  two();
  }
  if(tokens[5].toInt()==thv){
  th();
  }
  if(tokens[5].toInt()==fourv){
  four();
  }
  if(tokens[5].toInt()==fivev){
  five();
  }
  if(tokens[5].toInt()==sixv){ //兩個相等的話會等於0
  six();
  }

}
if ((RedColor <= 15 && RedColor >= 9)&&(  GreenColor <=20 && GreenColor >= 15)&&(BlueColor <= 15 && BlueColor>=9)) {

Serial.println(" – (blue Color)");
bb++;
if(tokens[4].toInt()==onev){
  one();
  }
if(tokens[4].toInt()==twov){
  two();
  }
  if(tokens[4].toInt()==thv){
  th();
  }
  if(tokens[4].toInt()==fourv){
  four();
  }
  if(tokens[4].toInt()==fivev){
  five();
  }
  if(tokens[4].toInt()==sixv){ //兩個相等的話會等於0
  six();
  }

}
if ((RedColor <= 60 && RedColor >=55 )&&(  GreenColor <=45 && GreenColor >= 40)&&(BlueColor <= 60 && BlueColor>=55)) {

Serial.println(" – (green Color)");
gg++;
if(tokens[3].toInt()==onev){
  one();
  }
if(tokens[3].toInt()==twov){
  two();
  }
  if(tokens[3].toInt()==thv){
  th();
  }
  if(tokens[3].toInt()==fourv){
  four();
  }
  if(tokens[3].toInt()==fivev){
  five();
  }
  if(tokens[3].toInt()==sixv){ //兩個相等的話會等於0
  six();
  }

}
if ((  GreenColor <=55 && GreenColor >= 45)&&(BlueColor <= 55 && BlueColor>=45)) {

Serial.println(" – (orange Color)");
oo++;
if(tokens[1].toInt()==onev){
  one();
  }
if(tokens[1].toInt()==twov){
  two();
  }
  if(tokens[1].toInt()==thv){
  th();
  }
  if(tokens[1].toInt()==fourv){
  four();
  }
  if(tokens[1].toInt()==fivev){
  five();
  }
  if(tokens[1].toInt()==sixv){ //兩個相等的話會等於0
  six();
  }
}

if ((  GreenColor <=85 && GreenColor >= 75)&&(BlueColor <= 60 && BlueColor>=50)) {

Serial.println(" – (red Color)");
rr++;
if(tokens[0].toInt()==onev){
  one();
  }
if(tokens[0].toInt()==twov){
  two();
  }
  if(tokens[0].toInt()==thv){
  th();
  }
  if(tokens[0].toInt()==fourv){
  four();
  }
  if(tokens[0].toInt()==fivev){
  five();
  }
  if(tokens[0].toInt()==sixv){ //兩個相等的話會等於0
  six();
  }

}
  


  


}
