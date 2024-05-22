void NOOB(int walkspeedleft,int walkspeedright) {
  if (R == 0 or L == 0) {
    Mrun(100, false, 115, false, 175);
    Mrun(100, true, 115, false, 250);
  } else {
    if (cm == 0) {
      Mrun(240, true, 255, true, 1);
    } else if (cl == 0) {
      Mrun(100, true, 115, false, 1);
    } else if (cl2 == 0) {
      Mrun(150, true, 165, false, 1);
    } else if (cr == 0) {
      Mrun(100, false, 115, true, 1);
    } else if (cr2 == 0) {
      Mrun(150, false, 165, true, 1);
    } else {
      Mrun(walkspeedleft, true, walkspeedright, true, 1);
    }
  }
}
