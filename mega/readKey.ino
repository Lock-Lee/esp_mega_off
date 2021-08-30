void readKeypad()
{
  key = keypad.getKey();

  if (key == 'B')
  {
    Serial.println("Resetwifi");
    mySerial.println("Resetwifi");
  }
  if (key == 'A')
  {
    key = keypad.getKey();
    while (1)
    {
      lcd.setCursor(0, 0);
      lcd.print("               ");
      lcd.setCursor(2, 0);
      lcd.print("1   TIME Auto");
      lcd.setCursor(2, 1);
      lcd.print("2-5 TIME SOI&PH ");
      lcd.setCursor(2, 2);
      lcd.print("6-7 SET SOI&PH");
      lcd.setCursor(2, 3);
      lcd.print("8   SET MODE");
      key = keypad.getKey();
      if (key == '1')
      {
        x = 1;
        break;
      }
      if (key == '2')
      {
        x = 2;
        break;
      }
      if (key == '3')
      {
        x = 3;
        break;
      }
      if (key == '4')
      {
        x = 4;
        break;
      }
      if (key == '5')
      {
        x = 5;
        break;
      }
      if (key == '6')
      {
        x = 6;
        break;
      }
      if (key == '7')
      {
        x = 7;
        break;
      }
      if (key == '8')
      {
        x = 8;
        break;
      }
      if (key == '9')
      {
        x = 9;
        break;
      }
      if (key == '*')
      {
        x = 0;
        lcd.clear();
        break;
      }
    }
    if (key == '1' || x == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time Start 1");
      lcd.setCursor(2, 2);
      lcd.print("Time End 1");
      setTimeStartAuto(2, 1);
      lcd.print("               ");
      setTimeEndAuto(2, 3);
      lcd.print("               ");
      //break;
      lcd.clear();
    }
    if (key == '2' || x == 2)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time Start 1");
      lcd.setCursor(2, 2);
      lcd.print("Time End 1");
      setTimeStart1(2, 1);
      lcd.print("               ");
      setTimeEnd1(2, 3);
      lcd.print("               ");
      //break;
      lcd.clear();
    }
    else if (key == '3' || x == 3)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time Start 2");
      lcd.setCursor(2, 2);
      lcd.print("Time End 2");
      setTimeStart2(2, 1);
      setTimeEnd2(2, 3);
      lcd.clear();
    }

    else if (key == '4' || x == 4)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time PH Start 1");
      lcd.setCursor(2, 2);
      lcd.print("Time PH End 1");
      setTimePHStart1(2, 1);
      setTimePHEnd1(2, 3);
      lcd.clear();
    }
    else if (key == '5' || x == 5)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time PH Start 2");
      lcd.setCursor(2, 2);
      lcd.print("Time PH End 2");
      setTimePHStart2(2, 1);
      setTimePHEnd2(2, 3);
      lcd.clear();
    }

    else if (key == '6' || x == 6)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Set Start Moisture");
      lcd.setCursor(2, 2);
      lcd.print("Set End Moisture");
      SoilStartINT = read_num(100, 2, 1);
      SoilENDINT = read_num(100, 2, 3);
      lcd.clear();
    }
    else if (key == '7' || x == 7)
    {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Set Start PH");
      lcd.setCursor(2, 2);
      lcd.print("Set End PH");
      lcd.setCursor(2, 1);
      lcd.print("0.0");
      lcd.setCursor(2, 3);
      lcd.print("0.0");
      PHStartInt = read_num(9, 2, 1);
      PHStartfloat = read_num(9, 4, 1);
      String phstart = (String)PHStartInt + "." + PHStartfloat;
      PHstart = phstart.toFloat();

      PHEndInt = read_num(9, 2, 3);
      PHEndfloat = read_num(9, 4, 3);
      String phend = (String)PHEndInt + "." + PHEndfloat;
      PHstop = phend.toFloat();
      lcd.clear();
    }
    else if (key == '8' || x == 8)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("0 Manually  ");
      lcd.setCursor(0, 1);
      lcd.print("1 Auto  ");
      Sw_mode = read_num(1, 2, 2);
      lcd.clear();
    }
  }

  else
  {
    lcd.setCursor(6, 0);
    read_time();
    show_time();
    if (Sw_mode == 0)
    {
      if (realTime.hour == timeEnd1.hour && realTime.min == timeEnd1.min)
      {
        stateTime1 = 0;
        water_state = 0;
        Serial.println("stop 1");
        digitalWrite(pump1, LOW);
        pump1_status = 0;
      }
      else if (realTime.hour == timeStart1.hour && realTime.min == timeStart1.min)
      {
        stateTime1 = 1;
        water_state = 1;
        Serial.println("start 1");
        digitalWrite(pump1, HIGH);
        pump1_status = 1;
      }

      if (realTime.hour == timeEnd2.hour && realTime.min == timeEnd2.min)
      {
        stateTime2 = 0;
        water_state = 0;
        Serial.println("stop 2");
        digitalWrite(pump1, LOW);

        pump1_status = 0;
      }
      else if (realTime.hour == timeStart2.hour && realTime.min == timeStart2.min)
      {
        stateTime2 = 1;
        water_state = 1;
        Serial.println("start 2");
        digitalWrite(pump1, HIGH);

        pump1_status = 1;
      }

      if (realTime.hour == timePHEnd1.hour && realTime.min == timePHEnd1.min)
      {
        stateph1 = 0;
        Serial.println("stop PH 1");
        digitalWrite(pump3, LOW);
        digitalWrite(pump4, LOW);
        pump3_status = 0;
        pump4_status = 0;
      }
      else if (realTime.hour == timePHStart1.hour && realTime.min == timePHStart1.min)
      {
        stateph1 = 1;
        Serial.println("start PH 1");
        digitalWrite(pump3, HIGH);
        digitalWrite(pump4, HIGH);
        pump3_status = 1;
        pump4_status = 1;
      }

      if (realTime.hour == timePHEnd2.hour && realTime.min == timePHEnd2.min)
      {
        stateph2 = 0;
        Serial.println("stop PH 2");
        digitalWrite(pump3, LOW);
        digitalWrite(pump4, LOW);
        pump3_status = 0;
        pump4_status = 0;
      }
      else if (realTime.hour == timePHStart2.hour && realTime.min == timePHStart2.min)
      {
        stateph2 = 1;
        Serial.println("start PH 2");
        digitalWrite(pump3, HIGH);
        digitalWrite(pump4, HIGH);

        pump3_status = 1;
        pump4_status = 1;
      }
    }
    else if (Sw_mode == 1)
    {
      if (realTime.hour == timeEndAuto.hour && realTime.min == timeEndAuto.min)
      {
        status_auto = 0;
        Serial.println("timeEndAuto");
        digitalWrite(pump2, 0);
        digitalWrite(pump3, 0);
        digitalWrite(pump4, 0);
        digitalWrite(pump1, 0);
        pump2_status = 0;
        pump3_status = 0;
        pump4_status = 0;
        pump1_status = 0;
      }
      else if (realTime.hour == timeStartAuto.hour && realTime.min == timeStartAuto.min)
      {
        Serial.println("timeStartAuto");
        status_auto = 1;
      }

      if (status_auto == 1)
      {
        Set_Moisture();
        Set_PH();
      }
      else
      {
        Serial.println("timeEndAuto");
        digitalWrite(pump2, 0);
        digitalWrite(pump3, 0);
        digitalWrite(pump4, 0);
        digitalWrite(pump1, 0);
        pump2_status = 0;
        pump3_status = 0;
        pump4_status = 0;
        pump1_status = 0;
      }
    }

    unsigned long currentMillis = millis();

    Moisture = show_MoistureSensor();
    PH = show_PH();
    if (currentMillis - previousMillis > 2000)
    {
      previousMillis = currentMillis;
      target++;
    }
    if (target == 1)
    {
      mySerial.println((String) "Moisture=" + Moisture);
      delay(100);
    }
    else if (target == 2)
    {
      mySerial.println((String) "PH=" + PH);
      delay(100);
    }
    else if (target == 3)
    {
      mySerial.println((String) "tph1=" + timePHStart1.hour + ":" + timePHStart1.min + "," + timePHEnd1.hour + ":" + timePHEnd1.min);
      delay(100);
    }
    else if (target == 4)
    {

      mySerial.println((String) "tw1=" + timeStart1.hour + ":" + timeStart1.min + "," + timeEnd1.hour + ":" + timeEnd1.min);
      delay(100);
    }
    else if (target == 5)
    {
      mySerial.println((String) "tw2=" + timeStart2.hour + ":" + timeStart2.min + "," + timeEnd2.hour + ":" + timeEnd2.min);
      delay(100);
    }
    else if (target == 6)
    {

      mySerial.println((String) "tph2=" + timePHStart2.hour + ":" + timePHStart2.min + "," + timePHEnd2.hour + ":" + timePHEnd2.min);
      delay(100);
    }
    else if (target == 7)
    {
      mySerial.println((String) "timeauto=" + timeStartAuto.hour + ":" + timeStartAuto.min + "," + timeEndAuto.hour + ":" + timeEndAuto.min);
      delay(100);
    }
    else if (target == 8)
    {

      mySerial.println((String) "tempset=" + SoilStartINT + "," + SoilENDINT);
      delay(100);
    }
    else if (target == 9)
    {
      mySerial.println((String) "phset=" + PHstart + "," + PHstop);
      delay(100);
    }
    else if (target == 11)
    {
      mySerial.println((String) "pump=" + pump1_status + "," + pump2_status + "," + pump3_status + "," + pump4_status);
    }

    else if (target == 12)
    {
      target = 0;
    }

    show_PH();
    show_MoistureSensor();
    setEProm();
  }
}
