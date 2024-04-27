void CallErrornofilter(){
  if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 1) && (cr2 == 0)) Error = 4;
  else if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 0) && (cr2 == 0)) Error = 3;
  else if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 0) && (cr2 == 1)) Error = 2;
  else if ((cl2 == 1) && (cl == 1) && (cm == 0) && (cr == 0) && (cr2 == 1)) Error = 1;
  else if ((cl2 == 1) && (cl == 1) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = 0;
  else if ((cl2 == 1) && (cl == 0) && (cm == 0) && (cr == 1) && (cr2 == 1)) Error = -1;
  else if ((cl2 == 1) && (cl == 0) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = -2;
  else if ((cl2 == 0) && (cl == 0) && (cm == 1) && (cr == 1) && (cr2== 1)) Error = -3;
  else if ((cl2 == 0) && (cl == 1) && (cm == 1) && (cr == 1) && (cr2 == 1)) Error = -4;
}
void CallError(){
  if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 1) && (cfr2 == 0)) Error = 4;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 0) && (cfr2 == 0)) Error = 3;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 0) && (cfr2 == 1)) Error = 2;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 0) && (cfr == 0) && (cfr2 == 1)) Error = 1;
  else if ((cfl2 == 1) && (cfl == 1) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = 0;
  else if ((cfl2 == 1) && (cfl == 0) && (cfm == 0) && (cfr == 1) && (cfr2 == 1)) Error = -1;
  else if ((cfl2 == 1) && (cfl == 0) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = -2;
  else if ((cfl2 == 0) && (cfl == 0) && (cfm == 1) && (cfr == 1) && (cfr2== 1)) Error = -3;
  else if ((cfl2 == 0) && (cfl == 1) && (cfm == 1) && (cfr == 1) && (cfr2 == 1)) Error = -4;
}

void PID(){
  output = (Kp * Error) + (Ki * Integral) + Kd * (Error - PreError);   

  LeftOutput = LeftSpeed + output;
  RightOutput = RightSpeed - output;
  
  if(output > 255){
    output=255;
  }
  else if(output < -255){
    output=-255;
  }

  Mrun(LeftOutput, true, RightOutput, true,1);
  
  PreError = Error;    
  Integral += Error;

}








