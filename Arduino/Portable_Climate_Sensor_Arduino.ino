#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C
#define BME280_ADDRESS (0x76)

//bluetooth
#include <SoftwareSerial.h>
int gRxPin = 10; 
int gTxPin = 11; 
SoftwareSerial BTSerial(gRxPin, gTxPin);
float max_v = 4.2; // battery max voltage
float k = 0.58; // correction factor for battery voltage

/* Pin map
 *  Rx pin on 10
 *  Tx pin on 11
 *  battery + on pin A1
 *  SDA pin on A4
 *  SCL pin on A5
 *  Digital pin 9 for connection state check
 */

void setup()
{
    Wire.begin();
    BTSerial.begin(9600);
    Serial.begin(9600);
    pinMode(A1,INPUT);
    pinMode(9,INPUT);
    bool sensor = bme.begin(0x76);
    if(!sensor)
        Serial.print("BME280 no answer");
    delay(500);
} 
 
void loop()
{
    //get data from sensor
    double temp = bme.readTemperature();
    double pressure = bme.readPressure() / 100 * 0.75;
    double hum = bme.readHumidity();
    float voltage = analogRead(1) * 5.0 / 1023.0 - k;
    float charge_level = voltage / max_v * 100.0;
    charge_level = constrain(charge_level,0.0,100.0); // set max 100% and min 0%

    //send data
    if(digitalRead(9) == 1)
    {      
        BTSerial.print("temperature= ");
        BTSerial.print(temp,1); BTSerial.println("°C");
        BTSerial.print("humidity=    ");
        BTSerial.print(hum,1); BTSerial.println(" %");
        BTSerial.print("pressure=    ");
        BTSerial.print(pressure,0); BTSerial.println(" mm");
        BTSerial.print("battery=     ");
        BTSerial.print(charge_level,0); BTSerial.println(" %");
        BTSerial.println("endline");

        delay(1000);
    }
    else
    {
        Serial.println("No connection");
        delay(2000);
    }
}
