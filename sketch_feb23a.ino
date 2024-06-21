#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN1 7     // Aquí definimos el pin al que está conectado el primer sensor
#define DHTPIN2 8     // Aquí definimos el pin al que está conectado el segundo sensor
#define DHTPIN3 9     // Aquí definimos el pin al que está conectado el tercer sensor
#define DHTTYPE DHT22   // Aquí definimos el tipo de sensor DHT que estás utilizando. Cambia DHT11 a DHT22 si estás utilizando un DHT22.

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
  dht3.begin();
}

void loop() {
  // Esperamos unos segundos entre las mediciones.
  delay(2000);
  String aux;
  // Leemos la humedad relativa y la temperatura de cada sensor
  Serial.println(leerSensor(dht1, "1")+leerSensor(dht2, "2")+leerSensor(dht3, "3"));
  
}

String leerSensor(DHT dht, String nombreSensor) {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  String valor;
  if (isnan(h) || isnan(t))  {
    return nombreSensor + "00000000";
  }
  valor= nombreSensor +String(h)+String(t);
  valor.replace(".","");
  return valor;
}