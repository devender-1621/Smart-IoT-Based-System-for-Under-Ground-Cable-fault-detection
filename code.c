#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int r1=A0;
int r2=A1;

int y1=A2;
int y2=A3;
 
int g1=A4;
int g2=A5;

int led1=5;
int led2=4;
int led3=3;

String number="6303003717";

#include<SoftwareSerial.h>
SoftwareSerial gps(7,6);
int i=0,k=0;
int  gps_status=0;
float latitude=17.6021744; 
float logitude=78.4876923;  
//float latitude=0; 
//float logitude=0;                     
String Speed="";
String gpsString="";
char *test="$GPRMC";
String location="  http://maps.google.com/maps?&z=15&mrt=yp&t=k&q="+String(latitude,6)+"+"+String(logitude,6);


void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);pinMode(led2,OUTPUT);pinMode(led3,OUTPUT);
digitalWrite(led1,HIGH);digitalWrite(led2,HIGH);digitalWrite(led3,HIGH);
  pinMode(r1,INPUT_PULLUP);pinMode(r2,INPUT_PULLUP);
  pinMode(y1,INPUT_PULLUP);pinMode(y2,INPUT_PULLUP);
  pinMode(g1,INPUT_PULLUP);pinMode(g2,INPUT_PULLUP);
  lcd.begin(16, 2);
 lcd.clear(); lcd.print("UNDERGROUND CABLE");
  lcd.setCursor(0,1);lcd.print("FAULT DETECTION");delay(1000);
 gps.begin(9600);
  lcd.clear();lcd.print("GPS is Ready");delay(1000);
  lcd.clear(); lcd.print("System Ready");delay(1000);
  //get_gps();
  gpsdata();
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("WELCOME MESSAGE FROM UNDERGROUND CABLE FAULT DETECTION SYSTEM ");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 


}

void loop()
{
  int r1val=digitalRead(r1);delay(10);
  int r2val=digitalRead(r2);delay(10);
  int y1val=digitalRead(y1);delay(10);
  int y2val=digitalRead(y2);delay(10);
  int g1val=digitalRead(g1);delay(10);
  int g2val=digitalRead(g2);delay(10);

  if(r1val==LOW)
  {
 lcd.clear();lcd.print("FAULT AT");
 lcd.setCursor(0,1);lcd.print("LINE:RED 1 KM");delay(3000); digitalWrite(led1,HIGH);delay(1000); 
 lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FAULT AT RED LINE:1KM");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 
 
  }

   if(r2val==LOW)
  {
 lcd.clear();lcd.print("FAULT AT");
 lcd.setCursor(0,1);lcd.print("LINE:RED 2 KM");delay(3000); digitalWrite(led1,HIGH);delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FAULT AT RED LINE:2KM");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 
 
  }

  if(y1val==LOW)
  {
 lcd.clear();lcd.print("FAULT AT");
 lcd.setCursor(0,1);lcd.print("LINE:YELLOW 1 KM");delay(3000); digitalWrite(led2,HIGH);delay(1000);
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FAULT AT YELLOW LINE:1KM");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 
  
  }

   if(y2val==LOW)
  {
 lcd.clear();lcd.print("FAULT AT");
 lcd.setCursor(0,1);lcd.print("LINE:YELLOW 2 KM");delay(3000);digitalWrite(led2,HIGH);delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FAULT AT YELLOW LINE:2KM");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 
  
  } 

   if(g1val==LOW)
  {
 lcd.clear();lcd.print("FAULT AT");
 lcd.setCursor(0,1);lcd.print("LINE:GREEN 1 KM");delay(3000); digitalWrite(led3,HIGH);delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FAULT AT GREEN LINE:1KM");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 
 
  }

   if(g2val==LOW)
  {
 lcd.clear();lcd.print("FAULT AT");
 lcd.setCursor(0,1);lcd.print("LINE:GREEN 2 KM");delay(3000); digitalWrite(led3,HIGH);delay(1000); 
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("FAULT AT GREEN LINE:2KM");delay(100);
Serial.print(location);
Serial.write(0x1A);delay(10000); 
 
  }

  if(r1val==HIGH && r2val==HIGH ){lcd.clear();lcd.print("RED LINE:OK");lcd.setCursor(0,1);lcd.print("       NO FAULT");delay(3000);digitalWrite(led1,LOW);}
  if(y1val==HIGH && y2val==HIGH ){lcd.clear();lcd.print("YELLOW LINE:OK");lcd.setCursor(0,1);lcd.print("      NO FAULT");delay(3000);digitalWrite(led2,LOW);}
  if(g1val==HIGH && g2val==HIGH ){lcd.clear();lcd.print("GREEN LINE:OK");lcd.setCursor(0,1);lcd.print("       NO FAULT");delay(3000);digitalWrite(led3,LOW);}
}

void gpsEvent()
{
  gpsString="";
  while(1)
  {
   while (gps.available()>0)            //Serial incoming data from GPS
   {
    char inChar = (char)gps.read();
     gpsString+= inChar;                    //store incoming data from GPS to temparary string str[]
     i++;
    // Serial.print(inChar);
     if (i < 7)                      
     {
      if(gpsString[i-1] != test[i-1])         //check for right string
      {
        i=0;
        gpsString="";
      }
     }
    if(inChar=='\r')
    {
     if(i>60)
     {
       gps_status=1;
       break;
     }
     else
     {
       i=0;
     }
    }
  }
   if(gps_status)
    break;
  }
}
void get_gps()
{
  lcd.clear();
  lcd.print("Getting GPS Data");
  lcd.setCursor(0,1);
  lcd.print("Please Wait.....");
   gps_status=0;
   int x=0;
   while(gps_status==0)
   {
    gpsEvent();
    int str_lenth=i;
    //coordinate2dec();
    i=0;x=0;
    str_lenth=0;
   }
}
void gpsdata()
{
    lcd.clear();
    lcd.print("Lat:");
    lcd.print(latitude);
    lcd.setCursor(0,1);
    lcd.print("Log:");
    lcd.print(logitude);
    delay(2000);
    lcd.clear();
    
}
void coordinate2dec()
{
  String lat_degree="";
    for(i=19;i<=20;i++)         
      lat_degree+=gpsString[i];
      Serial.println(lat_degree);
  String lat_minut="";
     for(i=21;i<=30;i++)         
      lat_minut+=gpsString[i];
      Serial.println(lat_minut);
  String log_degree="";
    for(i=32;i<=34;i++)
      log_degree+=gpsString[i];
      Serial.println(log_degree);
  String log_minut="";
    for(i=35;i<=44;i++)
      log_minut+=gpsString[i];
      Serial.println(log_minut);
    
    Speed="";
    for(i=45;i<48;i++)          //extract longitude from string
      Speed+=gpsString[i];
      
     float minut= lat_minut.toFloat();
     minut=minut/60;
     float degree=lat_degree.toFloat();
     latitude=degree+minut;
     Serial.println(latitude);
     
     minut= log_minut.toFloat();
     minut=minut/60;
     degree=log_degree.toFloat();
     logitude=degree+minut;
     Serial.println(logitude);
}
