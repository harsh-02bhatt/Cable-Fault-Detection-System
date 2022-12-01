#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define pm A0
#define relay1 7
#define relay2 6
#define relay3 5
int val = 0;
int dist = 0;

byte symbol[8] = {
        B00000,
        B00100,
        B00100,
        B00100,
        B11111,
        B01110,
        B00100,
        B00000};


void setup()
{
  Serial.begin(9600);
  pinMode(pm, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  
lcd.createChar(1, symbol);   
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0, 0); // set the cursor to column 0, line 2
lcd.print("Welcome to Cable");
lcd.setCursor(0, 1); // set the cursor to column 0, line 2
lcd.print("Fault  Detection");
delay(2000);
lcd.clear();
}

void loop()
{
lcd.setCursor(1,0);
lcd.print("R");
lcd.write(1);  

lcd.setCursor(7,0);
lcd.print("Y");
lcd.write(1); 

lcd.setCursor(13,0);
lcd.print("B");
lcd.write(1);
  
  
  
  
  
  
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,LOW);
  digitalWrite(relay3,LOW);
  delay(10000);
  val = analogRead(pm);
  if (val > 0){
  if(val == 974){
  lcd.setCursor(0,1);
  lcd.print("1 KM ");
  }
  else if(val == 930){
  lcd.setCursor(0,1);
  lcd.print("2 KM ");
  }
  else if(val == 890){
  lcd.setCursor(0,1);
  lcd.print("3 KM ");
  }
  else if(val == 852){
  lcd.setCursor(0,1);
  lcd.print("4 KM ");
  }
  }
  else {
  lcd.setCursor(0,1);
  lcd.print(" NF ");
  }
  delay(500);
  
  
  
  
  
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,LOW);
  delay(500);
  val = analogRead(pm);
  if (val > 0){
  if(val == 974){
  lcd.setCursor(6,1);
  lcd.print("1 KM ");
  }
  else if(val == 930){
  lcd.setCursor(6,1);
  lcd.print("2 KM ");
  }
  else if(val == 890){
  lcd.setCursor(6,1);
  lcd.print("3 KM ");
  }
  else if(val == 852){
  lcd.setCursor(6,1);
  lcd.print("4 KM ");
  }
  }
  else {
  lcd.setCursor(6,1);
  lcd.print(" NF ");
  }
  delay(500);
  
  
  
  
  
  
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(relay3,HIGH);
  delay(500);
  val = analogRead(pm);
  if (val > 0){
  if(val == 974){
  lcd.setCursor(12,1);
  lcd.print("1 KM ");
  }
  else if(val == 930){
  lcd.setCursor(12,1);
  lcd.print("2 KM ");
  }
  else if(val == 890){
  lcd.setCursor(12,1);
  lcd.print("3 KM ");
  }
  else if(val == 852){
  lcd.setCursor(12,1);
  lcd.print("4 KM ");
  }
  }
  else {
  lcd.setCursor(12,1);
  lcd.print(" NF ");
  }
  delay(500);
}
