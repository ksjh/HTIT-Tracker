#include "heltec_tracker_v11.h"

#include <Arduino.h>
#include <USB.h>

#define BAUD GNSS_BAUD

// USBCDC USBSerial;
char gnss_ch;

void setup_gnss() {
  pinMode(VGNSS_CTRL, OUTPUT);
  digitalWrite(VGNSS_CTRL, HIGH);
  Serial1.begin(GNSS_BAUD, SERIAL_8N1, GNSS_TX, GNSS_RX);
}

void init_gnss() { Serial1.print(F("$CFGSYS,h35155*68\r\n")); }

void setup() {
  setup_gnss();
  USBSerial.begin(BAUD);
  init_gnss();
}

void loop() {
  while(Serial1.available() > 0) {
    gnss_ch = Serial1.read();
    USBSerial.write(gnss_ch);
  }
  while(USBSerial.available() > 0) {
    gnss_ch = USBSerial.read();
    Serial1.write(gnss_ch);
  }
}
