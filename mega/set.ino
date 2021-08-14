

int show_MoistureSensor() {

  Moisture = analogRead(MoistureSensor);

  lcd.setCursor(2, 1);
  lcd.print("Moisture =   ");
Moisture = map(Moisture, 345, 690, 100, 0);
if(Moisture > 100){
  Moisture = 100;
}else if(Moisture < 0 ){
  Moisture = 0 ;
}
  lcd.setCursor(12, 1);
  lcd.print("       ");
  lcd.setCursor(12, 1);
  lcd.print(Moisture);
  lcd.setCursor(15, 1);
  lcd.print("%");
  return Moisture;
}



float show_PH() {
  int i;

  PH = 0;
  for (i = 0; i < 10; i++) {
    PH  = PH + analogRead(PHSensor);
    delay(10);
  }
  PH       = PH / 10;
  if (PH >= 480) {
    PH = (10 - (PH - 480) / 14);
  } else if (PH >= 360) {
    PH = (20 - (PH - 360) / 12);
  } else if (PH >= 275) {
    PH = (30 - (PH - 275) / 8.5);
  } else if (PH >= 200) {
    PH = (40 - (PH - 200) / 7.5);
  } else if (PH >= 125) {
    PH = (50 - (PH - 125) / 8.5);
  } else if (PH >= 65 ) {
    PH = (60 - (PH - 60) / 6.5);
  } else if (PH >=  0 ) {
    PH = (70 - (PH - 0) / 6.0);
  }
  lcd.setCursor(3, 2);
  lcd.print("PH = ");
  lcd.setCursor(7, 2);
  lcd.print("      ");
  lcd.setCursor(8, 2);
  lcd.print(PH / 10);
  return (PH / 10);

}
