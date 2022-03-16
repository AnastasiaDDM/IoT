# Общие сведения
Работы выполнены в следующих системах:
 * В **Proteus** (система автоматизированного проектирования) создана модель взаимосвязи электронных компонентов, необходимых для выполнения задачи.
 * **Arduino IDE** — интегрированная среда разработки для Windows, MacOS и Linux, предназначенная для создания и загрузки программ на Arduino-совместимые платы, а также на платы других производителей. В этой среде разработан скрипт, который будет регулировать работу датчиков и остальных элементов цепи.
# Задание 1
## Цель работы
Реализовать схему передачи значений датчиков на персональный компьютер по проводному соединению USB.

## Исходные данные
На складе медикаментов производится постоянный мониторинг температуры и влажности. Данные от датчиков считываются каждые 5 секунд и передаются на персональный компьютер, который условно считается сервером микроклимата. В каждом отсчете указывается дата, время, значение влажности и температуры. 

## Схема Proteus
![Схема Задание 1](imgs/task-11.png)

## Скетч Arduino
```
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
```

