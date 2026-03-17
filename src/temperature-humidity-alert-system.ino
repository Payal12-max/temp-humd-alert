#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT_PIN     2
#define DHT_TYPE    DHT22
#define GREEN_LED   8
#define RED_LED     9
#define BUZZER      10
#define TEMP_LIMIT  35.0
#define HUM_LIMIT   80.0

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temperature = 0;
float humidity = 0;
bool alertShown = false;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  dht.begin();
  lcd.init();
  lcd.backlight();

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER);

  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  temperature = dht.readTemperature();
  humidity    = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("ERROR: Sensor read failed!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    delay(2000);
    return;
  }

  // Serial Output
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C | Hum: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Display values
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity, 1);
  lcd.print("%");

  // ✅ Alert condition (Temp OR Humidity)
if (temperature >= TEMP_LIMIT || humidity >= HUM_LIMIT) {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  if (!alertShown) {
    alertShown = true;
    if (temperature >= TEMP_LIMIT && humidity >= HUM_LIMIT) {
      Serial.println("ALERT! HIGH TEMPERATURE & HUMIDITY!");
    } 
    else if (temperature >= TEMP_LIMIT) {
      Serial.println("ALERT! HIGH TEMPERATURE!");
    } 
    else {
      Serial.println("ALERT! HIGH HUMIDITY!");
    }
  }

    // Buzzer
    tone(BUZZER, 1000);
    delay(500);
    noTone(BUZZER);

  } 
  else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER);
    alertShown = false;

    lcd.setCursor(0, 1);
    lcd.print("Status: NORMAL");

    Serial.println("Status: NORMAL");
  }

  Serial.println("------------------------");
  delay(2000);
}