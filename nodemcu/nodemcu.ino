#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <MicroGear.h>
#include <WiFiManager.h>
///  รับค่าจาก nodemcu
#include <SoftwareSerial.h>
SoftwareSerial mySerial(D2, D3); // RX, TX
const char *ssid = "@RMUTI-One";
const char *password = "";
String ipAddr = "";
String RMUTi_Username = "";
String RMUTi_Password = "";
#define APPID "NUTTACIT"
#define KEY "xv4HY6mKMhDkP2a"
#define SECRET "Dfgf23P2QIqPy7M4tGUVuf6a7"
#define ALIAS "esp8266"

WiFiManager wm;

WiFiClient client;
String phRead = "";
String humiRead = "";
String timestart1 = "";
String timestart2 = "";
String timestart3 = "";
String timeEnd1 = "";
String timeEnd2 = "";
String timeEnd3 = "";

float PhWrite;
int humiWrite;

String timeauto = "";
String timewater = "";
String timeph = "";
String setph = "";
String settemp = "";
int timer = 0;
MicroGear microgear(client);
String pump1, pump2, pump3, pump4;

void onMsghandler(char *topic, uint8_t *msg, unsigned int msglen)
{
  String top = (String)topic;
  msg[msglen] = '\0';
  String message = (String)(char *)msg;
  // ---------------------------------------------------------- //
  Serial.print(top);
  Serial.print(" --> ");
  Serial.println(message);

  if (top == "/NUTTACIT/ionic/time1") {
    mySerial.println((String) "time1=" + message);
  }
  else if (top == "/NUTTACIT/ionic/time2") {
    mySerial.println((String) "time2=" + message);
  }
  else if (top == "/NUTTACIT/ionic/timeph1") {
    mySerial.println((String) "timeph1=" + message);
  }
  else if (top == "/NUTTACIT/ionic/timeph2") {
    mySerial.println((String) "timeph2=" + message);
  }
  else if (top == "/NUTTACIT/ionic/timeauto") {
    mySerial.println((String) "timeauto=" + message);
  }
  else if (top == "/NUTTACIT/ionic/setph") {
    mySerial.println((String) "setph=" + message);
  }
  else if (top == "/NUTTACIT/ionic/settemp") {
    mySerial.println((String) "settemp=" + message);
  }
  else if (top == "/NUTTACIT/ionic/read_data") {

    microgear.publish("/esp/write_data",  timeauto + "," + timewater + "," + timeph + "," + setph + "," + settemp );
  }

}

void onConnected(char *attribute, uint8_t *msg, unsigned int msglen)
{
  Serial.println("Connected to NETPIE...");
  microgear.subscribe("/ionic/+");
  microgear.setAlias(ALIAS);
}

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  bool res;
  res = wm.autoConnect("AutoConnectAP"); // password protected ap

  if (!res)
  {
    Serial.println("Failed to connect");
    // ESP.restart();
  }
  else
  {
    //if you get here you have connected to the WiFi

    Serial.println("connected...yeey :)");
    microgear.on(MESSAGE, onMsghandler);
    microgear.on(CONNECTED, onConnected);
    microgear.init(KEY, SECRET, ALIAS);
    microgear.connect(APPID);
  }

  pinMode(D5, INPUT_PULLUP);

  Serial.println("Starting...");
}

void loop()
{

  if (mySerial.available())
  {
    String received = mySerial.readStringUntil('\n');
    //Serial.println(received);

    String received1 = received;
    //Serial.println(received1);
    if (!received1.indexOf("Moisture="))
    {

      humiWrite = received1.substring(9).toInt();
    }
    else if (!received1.indexOf("PH="))
    {

      PhWrite = received1.substring(3).toFloat();
    }
    else if (!received1.indexOf("Resetwifi"))
    {

      wm.resetSettings();
      ESP.restart();
    }
    else if (!received1.indexOf("pump1="))
    {
      String str = received1.substring(6);
      pump1 = str;
    }
    else if (!received1.indexOf("pump2="))
    {
      String str = received1.substring(6);
      pump2 = str;
    }
    else if (!received1.indexOf("pump3="))
    {
      String str = received1.substring(6);
      pump3 = str;
    }
    else if (!received1.indexOf("pump4="))
    {
      String str = received1.substring(6);
      pump4 = str;
    }
    else if (!received1.indexOf("auto="))
    {
      String str = received1.substring(6);
      timeauto = str;
    }
    else if (!received1.indexOf("time="))
    {
      String str = received1.substring(6);
      timewater = str;
    }
    else if (!received1.indexOf("timeph="))
    {
      String str = received1.substring(6);
      timeph = str;
    }
    else if (!received1.indexOf("setph="))
    {
      String str = received1.substring(6);
      setph = str;
    }
    else if (!received1.indexOf("settemp="))
    {
      String str = received1.substring(6);
      settemp = str;
    }






  }

  if (microgear.connected())
  {
    microgear.loop();
    if (timer >= 2500)
    {
      microgear.publish("/esp/th", "" + String(PhWrite) + "," + humiWrite);
      delay(200);
      microgear.publish("/esp/th/pump", (String)pump1 + "," + pump2 + "," + pump3 + "," + pump4); delay(200);

    }
    else
      timer += 100;
  }
  else
  {
    if (timer >= 5000)
    {
      microgear.connect(APPID);
      timer = 0;
    }
    else
      timer += 100;
  }
  delay(100);
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
