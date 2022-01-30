byte slice_colors[6] = {0, 0, 0, 0, 0, 0};

Timer infect_timer;


void setup() {
}

void loop() {
  
  if(isAlone()) {
      for (byte i = 0; i < 6; i++) {
        if (slice_colors[i] == 0) {
          setValueSentOnFace(0, i); 
        }
        else if (slice_colors[i] == 1) {
          setValueSentOnFace(1, i);
        }
        else if (slice_colors[i] == 2) {
          setValueSentOnFace(2, i);
        }
      }
  }
  else {
    infect_timer.set(100);
    if (infect_timer.isExpired()) {
    	setValueSentOnAllFaces(0);
    }
    for (byte i = 0; i < 6; i++) {
      if (didValueOnFaceChange(i)) {
          byte rec = getLastValueReceivedOnFace(i);
            if (rec == 1) {
              setColorOnFace(YELLOW, i); 
            }
            else if (rec == 2) {
              setColorOnFace(GREEN, i); 
          }
      }
    }
  }
  
  
  
  
  if (buttonMultiClicked()) {
    setColor(YELLOW);
    for (byte i = 0; i < 6; i++) {
      slice_colors[i] = 1;
    }
  }
  
  if (buttonDoubleClicked()) {
    setColor(GREEN);
    for (byte i = 0; i < 6; i++) {
      slice_colors[i] = 2;
    }
  }
}
