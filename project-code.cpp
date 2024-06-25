#include <Arduino.h>

const int alarm = 5;
const int sensor3 = 4;
const int sensor2 = 3;
const int sensor1 = 2;
bool kontrol = true;

void setup()
{
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(alarm, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // dezenfektan kontrolü
    if (digitalRead(sensor1) == HIGH)
    {
        kontrol = false;
        Serial.println("dezenfektan kullanıldı");
    }

    // birinci küvez kontrolü
    if (digitalRead(sensor2) == HIGH)
    {
        if (kontrol)
        {
            while (digitalRead(sensor2) == HIGH)
            {
                digitalWrite(alarm, HIGH);
                Serial.println("1. alarm ötüyor");
            }
            digitalWrite(alarm, LOW);
        }
        else
        {
            while (digitalRead(sensor2) == HIGH)
            {
                Serial.println("1. küvez kullanılıyor");
            }
            kontrol = true;
        }
    }

    // ikinci küvez kontrolü
    if (digitalRead(sensor3) == HIGH)
    {
        if (kontrol)
        {
            while (digitalRead(sensor3) == HIGH)
            {
                digitalWrite(alarm, HIGH);
                Serial.println("2. alarm ötüyor");
            }
            digitalWrite(alarm, LOW);
        }
        else
        {
            while (digitalRead(sensor3) == HIGH)
            {
                Serial.println("2. küvez kullanılıyor");
            }
            kontrol = true;
        }
    }
}