void setEProm()
{
  address = 0;
  EEPROM.put(address, timeStart1.hour);
  address += sizeof(timeStart1.hour);
  EEPROM.put(address, timeStart1.min);
  address += sizeof(timeStart1.min);
  EEPROM.put(address, timeEnd1.hour);
  address += sizeof(timeEnd1.hour);
  EEPROM.put(address, timeEnd1.min);
  address += sizeof(timeEnd1.min);

  EEPROM.put(address, timeStart2.hour);
  address += sizeof(timeStart2.hour);
  EEPROM.put(address, timeStart2.min);
  address += sizeof(timeStart2.min);
  EEPROM.put(address, timeEnd2.hour);
  address += sizeof(timeEnd2.hour);
  EEPROM.put(address, timeEnd2.min);
  address += sizeof(timeEnd2.min);

  EEPROM.put(address, timePHStart1.hour);
  address += sizeof(timePHStart1.hour);
  EEPROM.put(address, timePHStart1.min);
  address += sizeof(timePHStart1.min);
  EEPROM.put(address, timePHEnd1.hour);
  address += sizeof(timePHEnd1.hour);
  EEPROM.put(address, timePHEnd1.min);
  address += sizeof(timePHEnd1.min);

  EEPROM.put(address, timePHStart2.hour);
  address += sizeof(timePHStart2.hour);
  EEPROM.put(address, timePHStart2.min);
  address += sizeof(timePHStart2.min);
  EEPROM.put(address, timePHEnd2.hour);
  address += sizeof(timePHEnd2.hour);
  EEPROM.put(address, timePHEnd2.min);
  address += sizeof(timePHEnd2.min);

  EEPROM.put(address, timeStartAuto.hour);
  address += sizeof(timeStartAuto.hour);
  EEPROM.put(address, timeStartAuto.min);
  address += sizeof(timeStartAuto.min);
  EEPROM.put(address, timeEndAuto.hour);
  address += sizeof(timeEndAuto.hour);
  EEPROM.put(address, timeEndAuto.min);
  address += sizeof(timeEndAuto.min);

  EEPROM.put(address, SoilStartINT);
  address += sizeof(SoilStartINT);
  EEPROM.put(address, SoilENDINT);
  address += sizeof(SoilENDINT);

  EEPROM.put(address, PHstart);
  address += sizeof(PHstart);
  EEPROM.put(address, PHstop);

  address += sizeof(PHstop);
  EEPROM.put(address, water_state);

  address += sizeof(water_state);
  EEPROM.put(address, ph_state);
  address += sizeof(ph_state);
}
void getEProm()
{
  address = 0;
  EEPROM.get(address, timeStart1.hour);
  address += sizeof(timeStart1.hour);
  EEPROM.get(address, timeStart1.min);
  address += sizeof(timeStart1.min);
  EEPROM.get(address, timeEnd1.hour);
  address += sizeof(timeEnd1.hour);
  EEPROM.get(address, timeEnd1.min);
  address += sizeof(timeEnd1.min);

  EEPROM.get(address, timeStart2.hour);
  address += sizeof(timeStart2.hour);
  EEPROM.get(address, timeStart2.min);
  address += sizeof(timeStart2.min);
  EEPROM.get(address, timeEnd2.hour);
  address += sizeof(timeEnd2.hour);
  EEPROM.get(address, timeEnd2.min);
  address += sizeof(timeEnd2.min);

  EEPROM.get(address, timePHStart1.hour);
  address += sizeof(timePHStart1.hour);
  EEPROM.get(address, timePHStart1.min);
  address += sizeof(timePHStart1.min);
  EEPROM.get(address, timePHEnd1.hour);
  address += sizeof(timePHEnd1.hour);
  EEPROM.get(address, timePHEnd1.min);
  address += sizeof(timePHEnd1.min);

  EEPROM.get(address, timePHStart2.hour);
  address += sizeof(timePHStart2.hour);
  EEPROM.get(address, timePHStart2.min);
  address += sizeof(timePHStart2.min);
  EEPROM.get(address, timePHEnd2.hour);
  address += sizeof(timePHEnd2.hour);
  EEPROM.get(address, timePHEnd2.min);
  address += sizeof(timePHEnd2.min);

  EEPROM.get(address, timeStartAuto.hour);
  address += sizeof(timeStartAuto.hour);
  EEPROM.get(address, timeStartAuto.min);
  address += sizeof(timeStartAuto.min);
  EEPROM.get(address, timeEndAuto.hour);
  address += sizeof(timeEndAuto.hour);
  EEPROM.get(address, timeEndAuto.min);
  address += sizeof(timeEndAuto.min);

  EEPROM.get(address, SoilStartINT);
  address += sizeof(SoilStartINT);
  EEPROM.get(address, SoilENDINT);
  address += sizeof(SoilENDINT);

  EEPROM.get(address, PHstart);
  address += sizeof(PHstart);
  EEPROM.get(address, PHstop);
  address += sizeof(PHstop);
  EEPROM.get(address, water_state);
  address += sizeof(water_state);
  EEPROM.get(address, ph_state);
  address += sizeof(ph_state);

  //  Serial.println((String)"time1="timeStart1.hour + ":" + timeStart1.min + "-" + timeEnd1.hour + ":" + timeEnd1.min);
  //  Serial.println((String)"time2="timeStart2.hour + ":" + timeStart2.min + "-" + timeEnd2.hour + ":" + timeEnd2.min);
  //  Serial.println((String)"time3="timeStart3.hour + ":" + timeStart3.min + "-" + timeEnd3.hour + ":" + timeEnd3.min);
  //
  //  Serial.println((String)"timeph1="timePHStart1.hour + ":" + timePHStart1.min + "-" + timePHEnd1.hour + ":" + timePHEnd1.min);
  //  Serial.println((String)"timeph2="timePHStart2.hour + ":" + timePHStart2.min + "-" + timePHEnd2.hour + ":" + timePHEnd2.min);
  //  Serial.println((String)"timeph3="timePHStart3.hour + ":" + timePHStart3.min + "-" + timePHEnd3.hour + ":" + timePHEnd3.min);
}
