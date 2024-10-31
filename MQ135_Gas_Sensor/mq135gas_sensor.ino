// Define the pins for LEDs
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

// Define the pin for MQ135 sensor
const int mq135Pin = A0;

// Variable to store the sensor value
int sensorValue = 0;

void setup() {
  // Initialize LED pins as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  // Start the Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from MQ-135 sensor
  sensorValue = analogRead(mq135Pin);
  
  // Print the sensor value to the Serial Monitor
  Serial.print("MQ135 Sensor Value: ");
  Serial.println(sensorValue);
  
  // Control LEDs based on sensor value
  if (sensorValue < 100) {
    // Safe: Green LED ON, Yellow and Red OFF
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  } 
  else if (sensorValue >= 100 && sensorValue <= 800) {
    // Medium: Yellow LED ON, Green and Red OFF
    digitalWrite(13, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  } 
  else if (sensorValue > 800) {
    // High: Red LED ON, Green and Yellow OFF
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  // Add a small delay
  delay(1000);
}
