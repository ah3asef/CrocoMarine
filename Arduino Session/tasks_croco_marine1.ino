int button_read;
const int button_pin = 7;
const int ledpin1 = 13;
const int ledpin2 = 12;
int buttonBefore = 0;
int buttonNow;
int dt = 100;
int led1Status = 0;
int led2Status = 0;
void setup()
{
  pinMode(button_pin,INPUT);
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  
}

void loop()
{
 buttonNow = digitalRead(button_pin);
  if(buttonBefore == 1 && buttonNow == 0){
    if(led1Status == LOW){
     digitalWrite(ledpin1,HIGH);
     led1Status = 1;
    }
    else if(led2Status == LOW){
     digitalWrite(ledpin2,HIGH);
     led2Status = 1;
    }
    else{
      digitalWrite(ledpin1,LOW);
      digitalWrite(ledpin2,LOW);
      led1Status = led2Status = 0; 
    }
    delay(50);
  }
  buttonBefore = buttonNow;
  
}