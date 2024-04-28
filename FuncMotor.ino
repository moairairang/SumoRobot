void forward(int speed, int de) {
  analogWrite(11, speed);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  analogWrite(6, speed);
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  delay(de);
}
void backward(int speed, int de) {
  analogWrite(11, speed);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  analogWrite(6, speed);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  delay(de);
}
void left(int speed, int de) {
  analogWrite(11, speed);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  analogWrite(6, speed);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  delay(de);
}
void right(int speed, int de) {
  analogWrite(11, speed);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  analogWrite(6, speed);
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  delay(de);
}

void Mrun(int leftspeed, bool dirleft, int rightspeed, bool dirright,int de) {
  if (dirleft == true and dirright == true) {
    analogWrite(11, leftspeed);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    analogWrite(6, rightspeed);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    delay(de);
  }
  if (dirleft == false and dirright == false) {
    analogWrite(11, leftspeed);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    analogWrite(6, rightspeed);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    delay(de);
  }
  if (dirleft == true and dirright == false) {
    analogWrite(11, leftspeed);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    analogWrite(6, rightspeed);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    delay(de);
  }
  if (dirleft == false and dirright == true) {
    analogWrite(11, leftspeed);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    analogWrite(6, rightspeed);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    delay(de);
  }
}

void backturn(){
  Mrun(50, false, 65, false, 300);
  Mrun(50, true, 65, false, 290);
}