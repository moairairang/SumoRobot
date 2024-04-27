void ReadSensorFloor(){
  L = digitalRead(2);
  R = digitalRead(4);
}
void ShowSensorFloor(){
  ReadSensorFloor();
  Serial.println(String(L)+"\t"+ String(R));
}