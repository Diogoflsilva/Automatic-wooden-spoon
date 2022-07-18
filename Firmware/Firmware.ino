#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(2,3);//0,1
int Pmd = 9;
int md1 = 8;
int md2 = 7;

void setup() {    
  pinMode(Pmd, OUTPUT);  
  pinMode(md1,OUTPUT);   
  pinMode(md2,OUTPUT);    
  bt.begin(9600);  
  Serial.begin(9600);
  }
  
  void loop() {  
    while(bt.available()){         
      switch(bt.read()){           
        case '0':      
        return;      
        break;           
        case '1':      
        Serial.write("Stop");      
        Stop();       
        break;           
        case '2':      
        Serial.write("Normal");      
        Normal();      
        break;           
        case '3':      
        Serial.write("Fast");      
        Fast();      
        break;      
        }    
      }
    }

  void Normal() {  
      analogWrite(Pmd,60);          
      delay(100);  
      analogWrite(Pmd,120);   
      digitalWrite(md1, HIGH);  
      digitalWrite(md2, LOW);
        }

  void Stop(){  
    analogWrite(Pmd,80);   
    delay(100);  
    analogWrite(Pmd,40);  
    delay(100);  
    analogWrite(Pmd,0);  
    digitalWrite(md1, LOW);  
    digitalWrite(md2, LOW);
        }

  void Fast(){  
    analogWrite(Pmd,40);  
    delay(100);  
    analogWrite(Pmd,80);  
    delay(100);  
    analogWrite(Pmd,160);    
    digitalWrite(md1, HIGH);
    digitalWrite(md2, LOW);  
        }
