//bool D4_state = LOW;
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

int cfl2,cfl,cfm,cfr,cfr2;
int cl2,cl,cm,cr,cr2;

int Error;
int output,LeftOutput,RightOutput,RightSpeed,LeftSpeed;
int PreError;
int Integral;
float Kp = 1.0;
float Ki = 0.0;
float Kd = 0.0;


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
  
  // PCICR |= B00000100;   //Bit2 = 1 -> "PCIE2" enabeled (PCINT16 to PCINT23)
  // PCMSK2 |= B00110000;  //D4 and D5 will trigger interrupt
  // attachInterrupt(digitalPinToInterrupt(2), ddd, RISING);
}

void loop() {
  NOOB(false);
}


// ISR(PCINT2_vect) {
//   if (digitalRead(4) && D4_state) {
//     D4_state = HIGH;
//      //Serial.println("Interrupt on1");
//     // digitalWrite(5,HIGH);
//     // digitalWrite(6,LOW);
//     // analogWrite(9,50);
//     //Serial.end();
//     //Pin D4 triggered the ISR
//   } else if (digitalRead(4) && !D4_state) {
//     D4_state = LOW;
//     Serial.println("Interrupt on2");
//   //   digitalWrite(5,LOW);
//   // digitalWrite(6,HIGH);
//   // analogWrite(9,30);
//   // delay(500);
//   }
// }

// void ddd(){
//   Serial.println("Interrupt on");
// }

