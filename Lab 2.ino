#define tempPin A0
#define lightPin A1
// Define pins for LEDs
int greenLedPin = 10;
int redLedPin = 11;
int tempLimit = 24;
int lightLimit = 203;

void setup() {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Read the analog voltage from the temperature sensor
  int readingTemp = analogRead(tempPin);
  // Convert the analog reading into voltage
  float voltage = readingTemp * (5.0 / 1024.0);
  // Convert voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;
  // Print temperature in Celsius to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // Display the degree symbol

  Serial.print("C");
  // Check if temperature is below the limit
  if (temperatureC <= tempLimit) {
    Serial.print(", Green LED is ON");
    digitalWrite(greenLedPin, HIGH);
  }
  // Check if temperature is above the limit
  else if (temperatureC > tempLimit) {
    Serial.print(", Green LED is OFF");
    digitalWrite(greenLedPin, LOW);
  }
  // Read the analog value from the light sensor
  int readingL = analogRead(lightPin);
  // Print light value to the serial monitor
  Serial.print(", Light value is ");
  Serial.print(readingL);
  // Delay for a short period
  delay(500);
  // Check if light value is above the limit
  if (readingL > lightLimit) {
    Serial.println(", Red LED is ON!");
    digitalWrite(redLedPin, HIGH);
  }
  // Check if light value is below the limit
  else if (readingL <= lightLimit) {
    Serial.println(", Red LED is OFF");
    digitalWrite(redLedPin, LOW);
  }
  // Delay for 0.5 seconds
  delay(500);  // 500 ms
}