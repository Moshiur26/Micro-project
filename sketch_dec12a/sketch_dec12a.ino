float temp;
int tempPin = A1;
float low = 0.0;

float high=100.0;

void setup()

{
pinMode(13, OUTPUT);//green led
pinMode(9, OUTPUT);//red led
Serial.begin(9600);

low = low/0.48828125;  //  500/1024
high = high/0.48828125;

}


void loop()

{


temp = analogRead(tempPin);
// l=5 10   h=40 82
float brightness = 0;
 
//if(temp<=int(low) || temp>=int(high)){
if(temp>=int(high)){


  /*if(temp>=int(high)){
    brightness = (temp - int(high))*(255.0/(206-high));
  }*/
  brightness = (temp - int(high))*(255.0/(1023-high));
  if(temp>=206){
     brightness = 255;
  }
  
  digitalWrite(13, LOW);//green led off
  digitalWrite(9, brightness);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(9, brightness);
  delay(50); 

  Serial.print("TEMPRATURE : ");

  Serial.print(temp);
  Serial.print("  Low : ");
  Serial.print(low);
  Serial.print("  High : ");
  Serial.print(high);
  Serial.print("  Brightness : ");
  Serial.print(brightness);
  //Serial.print(" Degree Celsius");
  Serial.println();
  
  delay(500); 
}
else{
  //brightness = (temp - low)*(255.0/(high-low))+7;
  digitalWrite(9, 0);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  

  Serial.print("TEMPRATURE : ");

  Serial.print(temp);
  Serial.print("  Low : ");
  Serial.print(low);
  Serial.print("  High : ");
  Serial.print(high);
  //Serial.print("  Brightness : ");
  //Serial.print(brightness);
  //Serial.print(" Degree Celsius");
  Serial.println();
  
  
  delay(500); 

}
//temp = temp * 0.48828125;





}

