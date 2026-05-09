// =================================
// MASTER I2C + SENSOR DHT22
// =================================

#include <Wire.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Wire.begin(); // Master
  Serial.begin(9600);

  dht.begin();

}

void loop() {

  // Membaca suhu dari DHT22
  float suhu = dht.readTemperature();

  // Cek apakah sensor terbaca
  if (isnan(suhu)) {
    Serial.println("Sensor gagal dibaca!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.println(suhu);

  // Kirim data suhu ke slave
  Wire.beginTransmission(8); // alamat slave
  Wire.write((int)suhu);
  Wire.endTransmission();

  delay(2000);
}