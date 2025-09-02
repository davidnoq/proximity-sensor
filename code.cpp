//Getting started with the HC-SR04 ultrasonic sensor. Arduino Project Hub. (n.d.). Retrieved April 12, 2022, from https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380 
// defines pins numbers, numbers 1-3 correspond to ultrasonic sensors (HC-SR04) 1-3
const int trigPin1 = 13;
const int echoPin1 = 12;
const int greenPin1 = 5;
const int yellowPin1 = 6;
const int redPin1 = 7;

const int trigPin2 = 11;
const int echoPin2 = 10;
const int greenPin2 = 24;
const int yellowPin2 = 22;
const int redPin2 = 23;

const int trigPin3 = 9;
const int echoPin3 = 8;
const int greenPin3 = 31;
const int yellowPin3 = 28;
const int redPin3 = 30;

// defines variables
long duration1;
long duration2;
long duration3;
int distance1;
int distance2;
int distance3;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(greenPin1, OUTPUT);
  pinMode(yellowPin1, OUTPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(yellowPin2, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(yellowPin3, OUTPUT);
  pinMode(redPin3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(4800);  // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(4);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.println(distance1);

//for any distance larger than 60cm none of the leds light up
if(distance1 > 60)
 {
  digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, LOW);
  digitalWrite(greenPin1, LOW);
 }
  //if distance is less than 60cm or greater than 40cm than output green for okay
  elseif(distance <= 60 && distance > 40)
  {digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, LOW);
    digitalWrite(greenPin1, HIGH);
  }
  //if distance is less than 40cm or greater than 15cm than output yellow to signify the sensor is nearing the object
  else if (distance <= 40 && distance > 15)
  {
    digitalWrite(redPin1, LOW);
    digitalWrite(greenPin1, LOW);
    digitalWrite(yellowPin1, HIGH);
  }
  //if distance is less than 15cm then the red led lights up since it is the most urgent color
  else if (distance <= 15)
  {
    digitalWrite(greenPin1, LOW);
    digitalWrite(yellowPin1, LOW);
    digitalWrite(redPin1, HIGH); 
  }

//The same process as above is repeated for sensor 2 and sensor 3
 // SENSOR 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(4);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.println(distance2);
 if(distance2 > 60)
 {
 digitalWrite(redPin2, LOW);
 digitalWrite(yellowPin2, LOW);
 digitalWrite(greenPin2, LOW);
 }
  else if(distance2 <= 60 && distance2 > 40)
  {
  digitalWrite(redPin2, LOW);
  digitalWrite(yellowPin2, LOW);
  digitalWrite(greenPin2, HIGH);
  }
  else if (distance2 <= 40 && distance2 > 15)
  {
    digitalWrite(redPin2, LOW);
    digitalWrite(greenPin2, LOW);
    digitalWrite(yellowPin2, HIGH);
  }
  else if (distance2 < 15)
  {
    digitalWrite(greenPin2, LOW);
    digitalWrite(yellowPin2, LOW);
    digitalWrite(redPin2, HIGH);
  }
 // SENSOR 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(4);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;
  Serial.print("Distance3: ");
  Serial.println(distance3);
 if(distance3 > 60)
 {
  digitalWrite(redPin3, LOW);
 digitalWrite(yellowPin3, LOW);
 digitalWrite(greenPin3, LOW);
 }
  else if(distance3 <= 60 && distance3 > 40)
  {
  digitalWrite(redPin3, LOW);
  digitalWrite(yellowPin3, LOW);
  digitalWrite(greenPin3, HIGH);
  }
  else if (distance3 <= 40 && distance3 > 15)
  {
    digitalWrite(redPin3, LOW);
    digitalWrite(greenPin3, LOW);
    digitalWrite(yellowPin3, HIGH);
  }
  else if (distance3 < 15)
  {
    digitalWrite(greenPin3, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(redPin3, HIGH);
    }
   
//Now we are identifying which sensor is measuring the shortest distance at that given moment and what that distance is 
    int distanceMin = 10000;
distanceMin = (distanceMin > distance1) ? distance1 : distanceMin;
distanceMin = (distanceMin > distance2) ? distance2 : distanceMin;
distanceMin = (distanceMin > distance3) ? distance3 : distanceMin;
Serial.println(distanceMin);

//if the closest object is within the distance range that corresponds to a green led lighting up, a low pitch tone will play from a piezo buzzer because an object is close enough that it is worth considering, but is not urgently close yet.
    if (distanceMin <= 60 && distanceMin > 40)
    {
      tone(2, 220);
    }
//if the closest object is within the distance range that corresponds to a yellow led a higher pitch will play from the piezo buzzer
    else if(distanceMin <= 40 && distanceMin > 15)
    {
      tone(2, 440);
    }
//if the closest object is within a distance that corresponds with the red led then the highest pitch tone will play to give the highest sense of urgency 
    else if(distanceMin <= 15)
    {
      tone(2, 880);
    }
//no tone is played if nothing is closer to the sensors than 60cm
    else
    {
      noTone(2);
    }   
}
