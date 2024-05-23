int L;
int R;
int l2;
int l;
int m;
int r;
int r2;
float fpl2 = 0.0;
float fl2 = 0.0;
float fpl = 0.0;
float fl = 0.0;
float fpm = 0.0;
float fm = 0.0;
float fpr = 0.0;
float fr = 0.0;
float fpr2 = 0.0;
float fr2 = 0.0;

int cfl2, cfl, cfm, cfr, cfr2;
int cl2, cl, cm, cr, cr2;

int Error;
int output, LeftOutput, RightOutput, RightSpeed, LeftSpeed;
int PreError;
int Integral;

float Kp = 10.0;
float Ki = 0.0;
float Kd = 1.0;

const int s1 = 7;
const int s2 = 8;
const int s3 = 13;

int walkspeedleft;
int walkspeedright;

void setup() {
  Serial.begin(115200);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);

  delay(5000);
  int state7 = digitalRead(s1);
  int state8 = digitalRead(s2);

  if (state7 == HIGH && state8 == LOW) {
    leftstrat();
    walkspeedright = 40;
    walkspeedleft = 55;
  } else if (state7 == LOW && state8 == HIGH) {
    rightstrat();
    walkspeedright = 40;
    walkspeedleft = 55;
  } else if (state7 == LOW && state8 == LOW) {
    walkspeedright = 40;
    walkspeedleft = 55;
  }else{
    walkspeedright = 25;
    walkspeedleft = 35;
  }
}

void loop() {
  ReadSensorFloor();
  ConvertSensornofilter();
  NOOB(walkspeedleft,walkspeedright);
  // Serial.print(digitalRead(s1));
  // Serial.print(" | ");
  // Serial.print(digitalRead(s2));
  // Serial.print(" | ");
  // Serial.println(digitalRead(s3));
}

void leftstrat() {
  Mrun(150, true, 165, true, 125);
  Mrun(100, true, 115, false, 150);
  Mrun(35, true, 170, true, 600);
}
void rightstrat() {
  Mrun(165, true, 180, true, 125);
  Mrun(100, false, 115, true, 150);
  Mrun(170, true, 50, true, 600);
}
