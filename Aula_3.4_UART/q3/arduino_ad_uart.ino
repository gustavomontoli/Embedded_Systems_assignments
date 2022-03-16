int ADcount = 0;
int t = 0;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);      
  digitalWrite(LED_BUILTIN, LOW);    
  Serial.begin(9600);
  t = millis();
}

void loop()
{
  if((millis()-t)>=10)
  {
    t = millis();
    int sensorValue = analogRead(A0);
    Serial.write(sensorValue & 0xFF);
    Serial.write(sensorValue >> 8);
    ADcount = (ADcount+1)%50;
    if(ADcount==0)
    {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
  }
}