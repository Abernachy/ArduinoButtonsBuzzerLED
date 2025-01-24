// Use me for some helper functions and shit like that

// This function will turn lights on and off and output to the serial monitor.
// Also goes off of the existing value of a light to ensure there is no duplicate
int lightSwitchShit(String mode, int ledPin) {

  int pinVal;
  if (mode == "on") {
    Serial.println("Light On");
    digitalWrite(ledPin, HIGH);
    pinVal = digitalRead(ledPin);
  }

  if (mode == "off") {
    Serial.println("Light Off");
    digitalWrite(ledPin, LOW);
    pinVal = digitalRead(ledPin);
  }
  return pinVal;
}


// I want you to push a button and it activates a light for a set period of time
void answerLight(String response, int ledPin, int seconds) {
  const long interval = 1000 * seconds;
  unsigned long stopMillis;
  unsigned long startMillis;
  digitalWrite(ledPin, HIGH);
  Serial.println(response);
  startMillis = millis();               // snapshot of our start time
  stopMillis = startMillis + interval;  // stop time calculation based on the interval added to start

  // while loop

  while (startMillis <= stopMillis) {
    startMillis = millis();
  }
  digitalWrite(ledPin, LOW);
};


// Buzzer function
// Requires the pin for the buzzer, the list of notes which points to our pitches file, and the durations of each sound
void playBuzzer(int buzzerPin, int noteList[], int secondsToSound[]) {
  // in reading it looks like Arduino has no equivalent to Array.Length()
  // you can't dynamically add or subtract and most folks just put in how many indexes are in their array
  // The approach has you define the size as a constant but can't be done in functions since constants are created at compile
  // Note list is 8
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / secondsToSound[thisNote];
    // tone takes 3 parameters - the pin, tone frequency which we get from our notes and the pitches, and note durations
    tone(buzzerPin, noteList[thisNote], noteDuration);

    // to disinguish the notes, we have to set a time between them
    // guide suggested 30%
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);

    // stop the tone
    noTone(buzzerPin);
  }
}

void buttonsBuzzerLED(int buzzerPin, int noteList[], int secondsToSound[], String message, int ledPin) {
  // Combined approach that turns the light on and leaves it on for the duration of the song
  

  digitalWrite(ledPin, HIGH);
  Serial.println(message);

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / secondsToSound[thisNote];
    // tone takes 3 parameters - the pin, tone frequency which we get from our notes and the pitches, and note durations
    tone(buzzerPin, noteList[thisNote], noteDuration);

    // to disinguish the notes, we have to set a time between them
    // guide suggested 30%
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);

    // stop the tone
    noTone(buzzerPin);
  }
  digitalWrite(ledPin, LOW);
}