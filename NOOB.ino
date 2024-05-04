void NOOB() {
  if (R == 0) {
    Mrun(50, false, 65, false, 350);
    Mrun(50, true, 65, false, 290);
  } else if (L == 0) {
    Mrun(50, false, 65, false, 350);
    Mrun(50, false, 65, true, 290);
  } else {
    if (cm == 0) {
      Mrun(240, true, 255, true, 1);
    } else if (cl == 0 || cl2 == 0 || cr == 0 || cr2 == 0) {
      if (cl == 0 || cl2 == 0) {
        Mrun(100, true, 115, false, 1);
      } else {
        Mrun(100, false, 115, true, 1);
      }
    } else {
      Mrun(40, true, 55, true, 1);
    }
  }
}
