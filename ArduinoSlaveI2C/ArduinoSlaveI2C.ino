// =================================
// SLAVE I2C + LCD 16x2
// =================================

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int suhu = 0;

void setup() {

  Wire.begin(8); // alamat slave
  Wire.onReceive(terimaData);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Monitoring Suhu");

}

void loop() {

  lcd.setCursor(0,1);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print((char)223);
  lcd.print("C   ");

  delay(500);
}

// Fungsi menerima data I2C
void terimaData(int jumlahData) {

  while(Wire.available()) {
    suhu = Wire.read();
  }

}