void CallErrornofilter() {
  if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 1) && (cr2 == 0)) Error = 4;
  else if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 0) && (cr2 == 0)) Error = 3;
  else if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 0) && (cr2 == 1)) Error = 2;
  else if ((cl2 == 1) && (cl == 1) && (cm == 0) && (cr == 0) && (cr2 == 1)) Error = 1;
  else if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = 0;
  else if ((cl2 == 1) && (cl == 0) && (cm == 0) && (cr == 1) && (cr2 == 1)) Error = -1;
  else if ((cl2 == 1) && (cl == 0) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = -2;
  else if ((cl2 == 0) && (cl == 0) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = -3;
  else if ((cl2 == 0) && (cl == 1) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = -4;
  else if ((cl2 == 1) && (cl == 1) && (cm == 0) && (cr == 1) && (cr2 == 1)) Error = 100;
}
void CallError() {
  if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 1) && (cfr2 == 0)) Error = 4;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 0) && (cfr2 == 0)) Error = 3;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 0) && (cfr2 == 1)) Error = 2;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 0) && (cfr == 0) && (cfr2 == 1)) Error = 1;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = 0;
  else if ((cfl2 == 1) && (cfl == 0) && (cfm == 0) && (cfr == 1) && (cfr2 == 1)) Error = -1;
  else if ((cfl2 == 1) && (cfl == 0) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = -2;
  else if ((cfl2 == 0) && (cfl == 0) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = -3;
  else if ((cfl2 == 0) && (cfl == 1) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = -4;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 0) && (cfr == 1) && (cfr2 == 1)) Error = 100;
}

void PID() {
  output = (Kp * Error) + (Ki * Integral) + Kd * (Error - PreError);

  LeftOutput = 0 + output;
  RightOutput = 0 - output;
  output = constrain(output, -255, 255);

  if (R == 0) {
      Mrun(50, false, 65, false, 300);
      Mrun(50, false, 65, true, 290);
  }
  else if(L == 0){
      Mrun(50, false, 65, false, 300);
      Mrun(50, true, 65, false, 290);
  }
  else if (Error == 0) {
    Mrun(40, true, 55, true, 1);
  }
  else if(Error == 100){
    Mrun(240, true, 255, true, 1);
  }
  // else if(Error == -4 or Error == -3){
  //   Mrun(100, true, 115, false, 1);
  // }
  // else if(Error == 4 or Error == 3){
  //   Mrun(100, false, 115, true, 1);
  // }
   else {
  Mrun(LeftOutput, true, RightOutput, true, 1);
  }
    PreError = Error;
    Integral += Error;
  }



void PIDNP(){
  ReadSensorFloor();
  ConvertSensornofilter();
  CallErrornofilter();
  PID();
}