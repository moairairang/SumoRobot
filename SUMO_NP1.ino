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

float Kp = 10.0;
float Ki = 0.0;
float Kd = 1.0;


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
  
  delay(5000);
}

void loop() {
  ReadSensorFloor();
  ConvertSensornofilter();
  NOOB();
  //PIDNP();
  
}

