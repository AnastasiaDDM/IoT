#include <DHT.h>
#include <Time.h>
#include <DS1307RTC.h>
#define DHT1PIN 2
#define DHT2PIN 3

DHT dht1(DHT1PIN, DHT11);
DHT dht2(DHT2PIN, DHT11);

void setup() {
  dht1.begin(); //1 датчик
  dht2.begin(); //2 датчик
  Serial.begin(9600);

  while (!Serial) ; //Ожидание чтения
  setSyncProvider(RTC.get);   //Синхронизация RTC времени
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");     
 
}

void loop() {
  //Первый датчик
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();

  //Второй датчик
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();

  Serial.print("\r\nDate: ");
  Serial.print(day());
  Serial.print(".");
  Serial.print(month());
  Serial.print(".");
  Serial.print(year());
  
  Serial.print("\r\nTime: ");
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());

  Serial.print("\r\nSensor 1: ");
  Serial.print("  Humidity: ");
  Serial.print(h1);
  Serial.print("%");
  Serial.print("  Temperature:");
  Serial.print(t1);
  Serial.print("C");

  Serial.print("\r\nSensor 2: ");
  Serial.print("  Humidity: ");
  Serial.print(h2);
  Serial.print("%");
  Serial.print("  Temperature:");
  Serial.print(t2);
  Serial.print("C");

  delay(5000);
}

void printDigits(int digits){
  //Функция преобразования времени
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}