//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// File: ArduinoTimer.ino
// Author: Shane Brown
// Description: Code to control LEDs for bomb countdown VIA arduino
// Date: 30/12/17
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#define PINS_SIZE 8

// 8 LEDS starting from pin 13 ending at pin 6
int pins[] = {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {
  // Enable serial communication at 9600 baud
  Serial.begin(9600);

  // Set all pins output
  for(int i = 0; i < PINS_SIZE; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  byte recvByte = 0;

  // Incoming data
  if(Serial.available() > 0){
    recvByte = Serial.read();
    if(recvByte == 1){
      countdown();
    }else if(recvByte == 0){
      clearPins();
    }
  }
}

// Begin bomb countdown
void countdown(){
  // Turn on all LEDs
  for(int i = 0; i < PINS_SIZE; i++){
    digitalWrite(pins[i], HIGH);
  }

  // In increments of 5 seconds turn LEDs off
  for(int i = 0; i < PINS_SIZE; i++){
    delay(5000);
    digitalWrite(pins[i], LOW);
  }

  // Flash all LEDs on and off (BOOM!)
  for(int i = 0; i < 10; i++){
    for(int k = 0; k < PINS_SIZE; k++){
      digitalWrite(pins[k], HIGH);
    }
    delay(100);
    for(int k = 0; k < PINS_SIZE; k++){
      digitalWrite(pins[k], LOW);
    }
    delay(100);
  }
}

// Turn off all LEDs
void clearPins(){
  for(int i = 0; i < PINS_SIZE; i++){
    digitalWrite(pins[i], LOW);
  }
}

