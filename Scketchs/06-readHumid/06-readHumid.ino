#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11 // Change this to DHT22 if you're using DHT22 sensor

DHT dht(DHT_PIN, DHT_TYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(2000);
  float humidity = dht.readHumidity();

  if (isnan(humidity))
  {
    Serial.println("Failed to read humidity from sensor!");
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }
}
