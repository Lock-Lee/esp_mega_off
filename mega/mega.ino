#include <SoftwareSerial.h>
SoftwareSerial mySerial(A8, A9); // RX, TX
#include <Wire.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <RealTimeClockDS1307.h>
int x = 0;
//จอ LDC 20*4 จอแสดงผล
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); //ถ้าจอไม่แสดงผลให้เปลี่ยน 0x27 เป็น0x3F
int read_num(int nmax, int x, int y);

bool stateph1 = 0;
bool stateph2 = 0;
bool stateph3 = 0;
bool stateTime1 = 0;
bool stateTime2 = 0;
bool stateTime3 = 0;
const byte ROWS = 4; //four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6};     //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void read_time();
void readKeypad();
char key;
int address = 0;

bool stateph = false;
int starttimeph_m;
int starttimeph_h;

int Moisture;
int SoilStartINT = 0;
int SoilENDINT = 0;
int xx1, xx2;

float PH;

int water_state = 0, ph_state = 0;

int PHStartInt;
int PHStartfloat;
int PHEndInt;
int PHEndfloat;

float PHstart;
float PHstop;

int Sw_togleph1, Sw_togleph2;
int Sw_togle1, Sw_togle2 ;
int Sw_auto;
int t1 = 0;

int pump1 = 14;
int pump2 = 15;
int pump3 = 16;
int pump4 = 17;

//เซ็นเซอร์วัดความชื้นในดิน Soil Moisture Sensor
int MoistureSensor = A1;

//เซ็นเซอร์วัดค่า PH ในดิน
int PHSensor = A2;

typedef struct
{ // the time record
  int hour; // hour
  int min;  // minute
  int sec;  // second
} TIMER;
TIMER realTime;
TIMER timeStart1;
TIMER timeEnd1;
TIMER timeStart2;
TIMER timeEnd2;


TIMER timeStartAuto;
TIMER timeEndAuto;


TIMER timePHStart1;
TIMER timePHEnd1;
TIMER timePHStart2;
TIMER timePHEnd2;



//ทำ map ให้เป็นจุดทศนิยม
double mapf(double val, double in_min, double in_max, double out_min, double out_max)
{
  return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

////////////////////////////////////   ตั้งเวลา น้ำ /////////////////////////////////////////////////

void setTime()
{
  RTC.setHours(23);
  RTC.setMinutes(3);
  RTC.setSeconds(15);
  RTC.setClock();
}
void show_time(void)
{

  lcd.print(realTime.hour);
  lcd.print(":");
  lcd.print(realTime.min);
  lcd.print(":");
  lcd.print(realTime.sec);
  //  Serial.print(RealTime.hour);
  //  Serial.print(RealTime.min);
  //  Serial.println(RealTime.sec);

  //  Serial.print(realTime.hour);
  //  Serial.print(realTime.min);
  //  Serial.println(realTime.sec);
}

void setup()
{

  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.setTimeout(100);
  mySerial.setTimeout(100);

  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
  pinMode(pump4, OUTPUT);

  lcd.init();
  lcd.backlight();

  //setTime();
  getEProm();
}

void loop()
{

  //////// รับค่าจาก nodemcu ///////////
  if (mySerial.available())
  {
    String received = mySerial.readStringUntil('\n');

    Serial.println(received);
    if (!received.indexOf("time1=")) {
      String str = received.substring(6);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      String part3  = splitOfstrng(str, ',', 2);
      timeStart1.hour = splitOfstrng(part1, ':', 0).toInt();
      timeStart1.min = splitOfstrng(part1, ':', 1).toInt();


      timeEnd1.hour = splitOfstrng(part2, ':', 0).toInt();
      timeEnd1.min = splitOfstrng(part2, ':', 1).toInt();

      Sw_togle1 = splitOfstrng(part3, ':', 0).toInt();


    } else if (!received.indexOf("time2=")) {
      String str = received.substring(6);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      String part3  = splitOfstrng(str, ',', 2);
      timeStart2.hour = splitOfstrng(part1, ':', 0).toInt();
      timeStart2.min = splitOfstrng(part1, ':', 1).toInt();

      timeEnd2.hour = splitOfstrng(part2, ':', 0).toInt();
      timeEnd2.min = splitOfstrng(part2, ':', 1).toInt();
      Sw_togle2 = splitOfstrng(part3, ':', 0).toInt();



    }  else if (!received.indexOf("timeph1=")) {
      String str = received.substring(8);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      String part3  = splitOfstrng(str, ',', 2);
      timePHStart1.hour = splitOfstrng(part1, ':', 0).toInt();
      timePHStart1.min = splitOfstrng(part1, ':', 1).toInt();

      timePHEnd1.hour = splitOfstrng(part2, ':', 0).toInt();
      timePHEnd1.min = splitOfstrng(part2, ':', 1).toInt();
      Sw_togleph1 = splitOfstrng(part3, ':', 0).toInt();



    } else if (!received.indexOf("timeph2=")) {

      String str = received.substring(8);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      String part3  = splitOfstrng(str, ',', 2);
      timePHStart2.hour = splitOfstrng(part1, ':', 0).toInt();
      timePHStart2.min = splitOfstrng(part1, ':', 1).toInt();

      timePHEnd2.hour = splitOfstrng(part2, ':', 0).toInt();
      timePHEnd2.min = splitOfstrng(part2, ':', 1).toInt();
      Sw_togleph2 = splitOfstrng(part3, ':', 0).toInt();

    } else if (!received.indexOf("timeauto=")) {

      String str = received.substring(8);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      String part3  = splitOfstrng(str, ',', 2);

      timeStartAuto.hour = splitOfstrng(part1, ':', 0).toInt();
      timeStartAuto.min = splitOfstrng(part1, ':', 1).toInt();

      timeEndAuto.hour = splitOfstrng(part2, ':', 0).toInt();
      timeEndAuto.min = splitOfstrng(part2, ':', 1).toInt();
      Sw_auto = splitOfstrng(part3, ':', 0).toInt();

    }  else if (!received.indexOf("setph=")) {
      String str = received.substring(6);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      PHstart = part1.toFloat();
      PHstop = part2.toFloat();


    }  else if (!received.indexOf("settemp=")) {
      String str = received.substring(8);
      String part1  = splitOfstrng(str, ',', 0);
      String part2  = splitOfstrng(str, ',', 1);
      SoilStartINT = part1.toInt();
      SoilENDINT =  part2.toInt();

    }else if (!received.indexOf("readvalue")) {

      
    }



  }
  readKeypad();
}
//set time
int read_num(int nmax, int x, int y)
{
  int num, i;
  lcd.setCursor(x, y);
  num = 0, i = 0;
  do
  {
    do
    {
      key = keypad.getKey();

    } while (!key);
    if (key == '*' && i > 0)
    { //check key ''
      x = x - 1;
      lcd.setCursor(x, y);
      lcd.print(" ");
      lcd.setCursor(x, y);
      num = num / 10;
      i = i - 1;
    }

    else if (key != '#' && key != '*')
    {
      if ((num * 10 + (key - 0x30)) <= nmax)
      {
        num = num * 10 + (key - 0x30);
        lcd.print(key);
        x = x + 1;
        i = i + 1;
      }
    }
  } while (key != '#'); //&& num !=0);
  return (num);
}

void read_time(void)
{
  RTC.readClock();
  realTime.hour = RTC.getHours();
  realTime.min = RTC.getMinutes();
  realTime.sec = RTC.getSeconds();


}

void Set_Moisture()
{
  unsigned long currentMillis = millis();
  long previousMillis = 0;
  Moisture = show_MoistureSensor();
  if (currentMillis - previousMillis > 3000)
  {
    previousMillis = currentMillis;
    mySerial.println((String) "Moisture=" + Moisture);
  }

  if (Moisture >= SoilStartINT && Moisture <= SoilENDINT )
  {
    digitalWrite(pump1, HIGH);
    //    Serial.println("Start pump1 " );
    mySerial.println((String) "pump1=1");
  }

  else if ((Moisture >= SoilENDINT || Moisture <= SoilStartINT) && SoilENDINT > 0)
  {
    digitalWrite(pump1, LOW);
    Serial.println("END pump1 ");
    mySerial.println((String) "pump1=0");
  }
}

void Set_PH()
{
  PH = show_PH();
  unsigned long currentMillis = millis();
  long previousMillis = 0;
  if (currentMillis - previousMillis > 2000)
  {
    previousMillis = currentMillis;
    mySerial.println((String) "PH=" + PH);
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  if (realTime.min == 58) {
  //    stateph = 0;
  //    starttimeph_h += 1;
  //
  //  }
  //  if (starttimeph_h >= 6) {
  //
  //    stateph = 1;
  //
  //  }
  //  Serial.println(stateph);
  //  if (stateph == 1 && starttimeph_h >= 6) {
  //    starttimeph_m += 1;
  //  }
  //
  //  if (starttimeph_m > 100) {
  //
  //    stateph = 0;
  //    starttimeph_h = 0;
  //    starttimeph_m = 0;
  //  }

  stateph = 1;
  if (stateph == 1)
  {
    if (PHstart < PHstop && PHstop > 0 && PHstart > 0)
    {

      if (PH < PHstart)
      {
        digitalWrite(pump2, HIGH);
        Serial.println("Start  pump2 ");
        mySerial.println((String) "pump2=1");
      }

      if (PH > PHstop)
      {
        digitalWrite(pump3, HIGH);
        digitalWrite(pump4, HIGH);

        mySerial.println((String) "pump3=1");
        mySerial.println((String) "pump4=1");
      }
      else if ((PH > PHstart && PH < PHstop && PHstart > 0 && PHstop > 0) )
      {
        Serial.println("Start pump3 + pump4 ");
        digitalWrite(pump2, 0);
        digitalWrite(pump3, 0);
        digitalWrite(pump4, 0);

      }
    }
  }
  else
  {

    digitalWrite(pump2, 0);
    digitalWrite(pump3, 0);
    digitalWrite(pump4, 0);

  }
}
 void readValue(){
   mySerial.println((String) "auto="+timeStartAuto.hour+":"+timeStartAuto.min+","+timeEndAuto.hour+":"+timeEndAuto.min+");
   delay(200);
   mySerial.println((String) "time="+timeStart1.hour+":"+timeStart1.min+","+timeEnd1.hour+":"+timeEnd1.min+","+timeStart2.hour+":"+timeStart2.min+","+timeEnd2.hour+":"+timeEnd2.min);
   delay(200);
   mySerial.println((String) "timeph="+timePHStart1.hour+":"+timePHStart1.min+","+timePHEnd1.hour+":"+timePHEnd1.min+","+timePHStart2.hour+":"+timePHStart2.min+","+timePHEnd2.hour+":"+timePHEnd2.min);
   delay(200);
   mySerial.println((String) "setph="+PHstart+","+PHstop);
   delay(200);
   mySerial.println((String) "settemp="+SoilStartINT+","+SoilENDINT);
   delay(200);
    
 }
String splitOfstrng(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
