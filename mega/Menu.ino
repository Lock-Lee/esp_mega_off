void Show_Time1()
{ // time pump //
  lcd.setCursor(2, 1);

  lcd.print(timeStart1.hour);
  lcd.print(":");
  lcd.print(timeStart1.min);

  lcd.setCursor(2, 3);

  lcd.print(timeEnd1.hour);
  lcd.print(":");
  lcd.print(timeEnd1.min);
}

void Show_Time2()
{ // time pump //
  lcd.setCursor(2, 1);

  lcd.print(timeStart2.hour);
  lcd.print(":");
  lcd.print(timeStart2.min);

  lcd.setCursor(2, 3);

  lcd.print(timeEnd2.hour);
  lcd.print(":");
  lcd.print(timeEnd2.min);
}

/////  time ph /////
void Show_TimePH1()
{
  lcd.setCursor(2, 1);

  lcd.print(timePHStart1.hour);
  lcd.print(":");
  lcd.print(timePHStart1.min);

  lcd.setCursor(2, 3);

  lcd.print(timePHEnd1.hour);
  lcd.print(":");
  lcd.print(timePHEnd1.min);
}

void Show_TimePH2()
{
  lcd.setCursor(2, 1);
  lcd.print(timePHStart2.hour);
  lcd.print(":");
  lcd.print(timePHStart2.min);
  lcd.setCursor(2, 3);
  lcd.print(timePHEnd2.hour);
  lcd.print(":");
  lcd.print(timePHEnd2.min);
}
void Show_TimeAuto()
{
  lcd.setCursor(2, 1);
  lcd.print(timeStartAuto.hour);
  lcd.print(":");
  lcd.print(timeStartAuto.min);
  lcd.setCursor(2, 3);
  lcd.print(timeEndAuto.hour);
  lcd.print(":");
  lcd.print(timeEndAuto.min);
}
