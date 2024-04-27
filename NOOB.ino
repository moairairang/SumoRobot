void NOOB(bool FilterState) {
  ReadSensorFloor();
  if (FilterState == true){
    ConvertSensor();
  } else {
    ConvertSensornofilter();
    if (R == 0 || L == 0) {
      Mrun(50, false, 65, false, 300);
      Mrun(50, true, 65, false, 290);
    } else {
      Mrun(40, true, 55, true, 1);
    }
    if (cm == 0) {
      Mrun(150, true, 165, true, 1);
    }

    else if (cl == 0 || cl2 == 0) {
      Mrun(100, false, 115, true, 1);
    }

    else if (cr == 0 || cr2 == 0) {
      Mrun(100, true, 115, false, 1);
    }
  }
}
