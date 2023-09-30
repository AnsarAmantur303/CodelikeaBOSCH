#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define LED 12
#define buzzer 7


#define relay 5


LiquidCrystal_I2C lcd(0x27,16,2);




DHT dht(DHTPIN, DHTTYPE);
int chk;
int hum;
int temp;


void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.clear();        
  lcd.backlight();
  lcd.setCursor(2,0);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);


    delay(2000);


}


void loop(){
hum = dht.readHumidity();
temp = dht.readTemperature();
lcd.setCursor(0,0);  
lcd.print("Humidity: ");
lcd.print(hum);
lcd.setCursor(0,1);  
lcd.print("Temperature: ");
lcd.print(temp);


Serial.print("Humidity: ");
Serial.println(hum);
Serial.print("Temperature: ");
Serial.println(temp);


if( temp>30 || temp < -20 ||  hum>60 || hum<30)
 {  
  if( temp>40 || temp < -20 ||  hum>75 || hum<10)
  {
    digitalWrite(buzzer,HIGH);
  }
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  if( temp>50 || temp < -20 ||  hum>75 || hum<10)
    digitalWrite(buzzer,LOW);
  delay(1000);
  digitalWrite(relay, HIGH);
  }
else
  digitalWrite(relay,LOW);




}
