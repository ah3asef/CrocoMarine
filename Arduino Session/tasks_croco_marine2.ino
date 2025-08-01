const int ledpin = 13;
const int buttonpin = 7;
int count_of_push = 0;
int buttonNow;
int buttonBefore = 0;
void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
}

void loop()
{
  buttonNow = digitalRead(buttonpin);
  if(buttonBefore == 1 && buttonNow == 0){
    count_of_push++;
    if(count_of_push == 10){
      digitalWrite(ledpin,HIGH);
    }
    else if(count_of_push == 11){
      digitalWrite(ledpin,LOW);
      count_of_push = 0;
    }
    delay(50);
  }
  buttonBefore = buttonNow; 
}