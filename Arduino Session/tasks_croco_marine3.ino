const int LDR_PIN = A0;      
const int LED_PIN = 9;       

int lightLevel;
int Threshold = 511;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);        
}

void loop() {
  lightLevel = analogRead(LDR_PIN);  
  Serial.println(lightLevel);        

  if (lightLevel < Threshold) {
    
    analogWrite(LED_PIN, 255);  
  } 
  else if (lightLevel > Threshold) {
    
    analogWrite(LED_PIN, 0);    
  } 
  else {
    
    analogWrite(LED_PIN, 128);  
  }

  delay(50);  
}
