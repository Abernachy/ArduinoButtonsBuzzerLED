// This is basically two buttons connected to a red/green light and a buzzer.  Gonna try and do a thingy where when you push a button its a 50% chance of being the right button
// if right button, green light and victory music
// if wrong button, red light and you go tuck yourself in



// EZ button library
#include <ezButton.h>

//libraries
#include "pitches.h"
#include "helperFunctions.h"

// Constants - doing constants saves on memory
#define buttonAmount 3
#define startButtonPin 2
#define buttonPin1 4
#define buttonPin2 5
#define redLEDPin 12
#define greenLEDPin 11
#define buzzerPin 3

// EZ Button objects
ezButton button1(buttonPin1);
ezButton button2(buttonPin2);
ezButton startButton(startButtonPin);

int successMelody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C7
};

int failMelody[] = {
  NOTE_C4, NOTE_E3, NOTE_GS3, NOTE_A2, NOTE_F3, NOTE_DS3, NOTE_B2, NOTE_C2
};


int successNoteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


int failNoteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

long randomNumber;
int gameStatus;
int button1Rando;
int button2Rando;

void setup() {
  // Get the buttons configured with debounce
  Serial.begin(9600);
  // button1.setDebounceTime(100);
  // button2.setDebounceTime(25);

  // LED pinmode to output
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  // start value
  gameStatus = 0;
}

void loop() {
  // button loop
  button1.loop();
  button2.loop();
  startButton.loop();

  if (startButton.isPressed()) {
    randomNumber = random(1000);
    button1Rando = randomNumber;
    button2Rando = randomNumber + 1;
    Serial.println(button1Rando);
    Serial.println(button2Rando);
  }





  if (button1.isReleased()) {
    if (button1Rando % 2 == 0) {
      //divides by 0 is success
      buttonsBuzzerLED(buzzerPin, successMelody, successNoteDurations, "Good Job", greenLEDPin);
      Serial.println(button1Rando);
      randomNumber = random(1000);
      button1Rando = randomNumber;
      button2Rando = randomNumber;
    } else {
      buttonsBuzzerLED(buzzerPin, failMelody, failNoteDurations, "Fail", redLEDPin);
      Serial.println(button1Rando);
      randomNumber = random(1000);
      button1Rando = randomNumber;
      button2Rando = randomNumber;
    }
  }

  if (button2.isReleased()) {
    if (button2Rando % 2 == 0) {
      //divides by 0 is success
      buttonsBuzzerLED(buzzerPin, successMelody, successNoteDurations, "Good Job", greenLEDPin);
      Serial.println(button2Rando);
      randomNumber = random(1000);
      button1Rando = randomNumber;
      button2Rando = randomNumber;
    } else {
      buttonsBuzzerLED(buzzerPin, failMelody, failNoteDurations, "Fail", redLEDPin);
      Serial.println(button2Rando);
      randomNumber = random(1000);
      button1Rando = randomNumber;
      button2Rando = randomNumber;
    }
  }
}


// Chat GPT suggested isReleased and this execution fixed the problem of the function running twice
// not quite the approach I wanted but it works.

//   if (button1.isReleased()) {
//     // So the ARduino can't do 2 functions at  once.  You can do some split via tasks and timing
//     // playBuzzer(buzzerPin, melody, noteDurations);
//     // answerLight("Correct, good job", greenLEDPin, 3);


//     buttonsBuzzerLED(buzzerPin, successMelody, successNoteDurations, "Good Job", greenLEDPin);
//   }

//   if (button2.isReleased()) {
//     // answerLight("Fail", redLEDPin, 3);
//     buttonsBuzzerLED(buzzerPin, failMelody, failNoteDurations, "Fail", redLEDPin);
//   }
// }


/*****
Pseudo code for the game portion
need to initialize a start game variable that will be set to 0 on Setup

Then on loop the loop if the Start Button is pushed, then it'll start the game , start value = 1

While startValue == 1 {
  I need to generate a random number 
  33

  Then assign that random number to button 1 -
  intbutton1 = 33
  button 2 is + 1 -
  intbutton2 = intbutton1 + 1

  if (button1.isReleased() {
      if (intbutton1 % 2 == 0) {
        "success"
        "Generating new number"
      } else {
        "fail"
        startValue = 0
      }
  })




}



***/