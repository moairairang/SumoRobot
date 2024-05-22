void ReadSensor(){
  l2 = analogRead(A0);
  l = analogRead(A1);
  m = analogRead(A2);
  r = analogRead(A4);
  r2 = analogRead(A5);
}
void ShowSensor(){
  ReadSensor();
  Serial.println(String(l2) + "\t" + String(l) + "\t" + String(m) + "\t" + String(r) + "\t"+ String(r2));
}
void ShowFilterSensor(){
  Sensorfilter();
  Serial.println(String(fl2) + "\t" + String(fl) + "\t" + String(fm) + "\t" + String(fr) + "\t"+ String(fr2));
}
void Sensorfilter(){
  ReadSensor();
  fl2 = 0.854 * fl2 + 0.0728 * l2 + 0.0728 * fpl2;
  fpl2 = l2;
  fl = 0.854 * fl + 0.0728 * l + 0.0728 * fpl;
  fpl = l;
  fm = 0.854 * fm + 0.0728 * m + 0.0728 * fpm;
  fpm = m;
  fr = 0.854 * fr + 0.0728 * r + 0.0728 * fpr;
  fpr = r;
  fr2 = 0.854 * fr2 + 0.0728 * r2 + 0.0728 * fpr2;
  fpr2 = r2;
}
void ConvertSensor(){
  Sensorfilter();
  if (fl2 > 150) cfl2 = 0; else cfl2 = 1;
  if (fl > 150) cfl = 0; else cfl = 1;
  if (fm > 150) cfm = 0; else cfm = 1;
  if (fr > 150) cfr = 0; else cfr = 1;
  if (fr2 > 150) cfr2 = 0; else cfr2 = 1;
  //Serial.println(String(cfl2) + "\t" + String(cfl) + "\t" + String(cfm) + "\t" + String(cfr) + "\t"+ String(cfr2));
}
void ConvertSensornofilter(){
  ReadSensor();
  if (l2 > 200) cl2 = 0; else cl2 = 1;
  if (l > 200) cl = 0; else cl = 1;
  if (m > 200) cm = 0; else cm = 1;
  if (r > 200) cr = 0; else cr = 1;
  if (r2 > 200) cr2 = 0; else cr2 = 1;
  //Serial.println(String(cl2) + "\t" + String(cl) + "\t" + String(cm) + "\t" + String(cr) + "\t"+ String(cr2));
}