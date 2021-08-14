void setTimeStart1(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time1();
  lcd.cursor();
  timeStart1.hour = read_num(23, x, y);
  Show_Time1();
  timeStart1.min = read_num(59, x + 3, y);
  Show_Time1();
  Serial.println((String) "timeStart1=" + timeStart1.hour + ":" + timeStart1.min);
  Serial.print(timeStart1.hour);
  Serial.println(timeStart1.min);
  lcd.noCursor();
 
}
void setTimeEnd1(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time1();
  lcd.cursor();
  timeEnd1.hour = read_num(23, x, y);
  Show_Time1();
  timeEnd1.min = read_num(59, x + 3, y);
  Show_Time1();
  Serial.println((String) "timeEnd1=" + timeEnd1.hour + ":" + timeEnd1.min);
  lcd.noCursor();

}
void setTimeStart2(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time2();
  lcd.cursor();
  timeStart2.hour = read_num(23, x, y);
  Show_Time2();
  timeStart2.min = read_num(59, x + 3, y);
  Show_Time2();
  Serial.println((String) "timeStart2=" + timeStart2.hour + ":" + timeStart2.min);
  lcd.noCursor();

 
 
}
void setTimeEnd2(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time2();
  lcd.cursor();
  timeEnd2.hour = read_num(23, x, y);
  Show_Time2();
  timeEnd2.min = read_num(59, x + 3, y);
  Show_Time2();
  Serial.println((String) "timeEnd2=" + timeEnd2.hour + ":" + timeEnd2.min);
  lcd.noCursor();
 
}

//////////////////////////////////   ตั้งเวลา PH /////////////////////////////////////////////////
void setTimePHStart1(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH1();
  lcd.cursor();
  timePHStart1.hour = read_num(23, x, y);
  Show_TimePH1();
  timePHStart1.min = read_num(59, x + 3, y);
  Show_TimePH1();
  Serial.println((String) "timePHStart1=" + timePHStart1.hour + ":" + timePHStart1.min);
  lcd.noCursor();
 
}
void setTimePHEnd1(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH1();
  lcd.cursor();
  timePHEnd1.hour = read_num(23, x, y);
  Show_TimePH1();
  timePHEnd1.min = read_num(59, x + 3, y);
  Show_TimePH1();
  Serial.println((String) "timePHEnd1=" + timePHEnd1.hour + ":" + timePHEnd1.min);
  lcd.noCursor();
  
}
void setTimePHStart2(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH2();
  lcd.cursor();
  timePHStart2.hour = read_num(23, x, y);
  Show_TimePH2();
  timePHStart2.min = read_num(59, x + 3, y);
  Show_TimePH2();
  Serial.println((String) "timePHStart2" + timePHStart2.hour + ":" + timePHStart2.min);
  lcd.noCursor();
  
}

void setTimePHEnd2(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH2();
  lcd.cursor();
  timePHEnd2.hour = read_num(23, x, y);
  Show_TimePH2();
  timePHEnd2.min = read_num(59, x + 3, y);
  Show_TimePH2();
  Serial.println((String) "timePHEnd2" + timePHEnd2.hour + ":" + timePHEnd2.min);
  lcd.noCursor();
 
}
void setTimeStartAuto(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimeAuto();
  lcd.cursor();
  timeStartAuto.hour = read_num(23, x, y);
  Show_TimeAuto();
  timeStartAuto.min = read_num(59, x + 3, y);
  Show_TimeAuto();
  Serial.println((String) "timePHStart2" + timeStartAuto.hour + ":" + timeStartAuto.min);
  lcd.noCursor();
  
}

void setTimeEndAuto(int x, int y)
{
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimeAuto();
  lcd.cursor();
  timeEndAuto.hour = read_num(23, x, y);
  Show_TimeAuto();
  timeEndAuto.min = read_num(59, x + 3, y);
  Show_TimeAuto();
  Serial.println((String) "timeEndAuto" + timeEndAuto.hour + ":" + timeEndAuto.min);
  lcd.noCursor();
 
}
