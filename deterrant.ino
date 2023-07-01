
int buzzerPin = 9;   //initialize buzzer
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int button = 12;
int buttonVal = 0;

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output 
  pinMode(button, INPUT);      // initalize LED as an output 
  pinMode(sensor, INPUT);    // initialize button as an input
  pinMode(buzzerPin, OUTPUT); //addigning pin to Output mode
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  buttonVal = digitalRead(button);
  
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    Serial.println(" detecting........!"); 
    tone(buzzerPin, 50);
    delay(550);
    noTone(buzzerPin);
    delay(100);   // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
    if (buttonVal == HIGH){
      digitalWrite(led, LOW);   // turn LED ON
      Serial.print("farmer responded\n");
      delay(5000); // delay for 5 secs and continues buzzing
      tone(buzzerPin, 0); //buzzer stops                          
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
