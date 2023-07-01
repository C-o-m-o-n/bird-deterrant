
int buzzerPin = 9;   //initialize buzzer
int led = 13;                // the pin that the LED is atteched to
int greenled = 12;                // for user response
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

greenledon = 0;
bool userstate = false;


void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(greenled, INPUT);   
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(buzzerPin, OUTPUT); //addigning pin to Output mode
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    Serial.println(" detecting........!"); 
    tone(buzzerPin, 50);
    delay(550);
    noTone(buzzerPin);
    delay(100);   // delay 100 milliseconds 
    userstate = false;
    
    if (greenled){
      userstate = true;
       digitalWrite(greenled, HIGH);   // turn LED ON
    }
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
         digitalWrite(led, LOW);   // turn LED ON
        state = LOW;       // update variable state to LOW
    }
  }
}
