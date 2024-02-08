#include "heltec_tracker_v11.h"

#include <MicroNMEA.h>

#define GNSS_UPDATE 1000UL

char nmeaBuffer[128];
MicroNMEA nmea(nmeaBuffer, sizeof(nmeaBuffer));
long gnss_lat, gnss_lon, gnss_alt;
uint8_t gnss_hdop;
char gnss_ch;
unsigned long gnss_millis = 0UL;

void setup_gnss() {
  pinMode(VGNSS_CTRL, OUTPUT);
  digitalWrite(VGNSS_CTRL, HIGH);
  Serial1.begin(GNSS_BAUD, SERIAL_8N1, GNSS_TX, GNSS_RX);
}

void init_gnss() {
  Serial1.print(F("$CFGSYS,h35155*68\r\n"));
  Serial.print(F("GNSS initialized.\r\n"));
}

void setup() {
  setup_gnss();
  Serial.begin(460800);
  init_gnss();
  gnss_millis = millis();
}

void print_gnss() {
  gnss_millis = millis();
  gnss_lat = nmea.getLatitude();
  gnss_lon = nmea.getLongitude();
  gnss_hdop = nmea.getHDOP();
  Serial.printf("%04u-%02u-%02u %02u:%02u:%02u.%02u\r\n", nmea.getYear(),
                nmea.getMonth(), nmea.getDay(), nmea.getHour(),
                nmea.getMinute(), nmea.getSecond(), nmea.getHundredths());
  if(nmea.isValid()) {
    Serial.printf("LAT   %3ld.%06ld\r\n", gnss_lat / 1000000L,
                  gnss_lat % 1000000L);
    Serial.printf("LON   %3ld.%06ld\r\n", gnss_lon / 1000000L,
                  gnss_lon % 1000000L);
    Serial.printf("ALT  %4ld.%03ld\r\n", gnss_alt / 1000L, gnss_alt % 1000L);
    Serial.printf("HDOP   %2u.%01u\r\n", gnss_hdop / 10, gnss_hdop % 10);
    Serial.printf("SYS %c #SAT %u\r\n\r\n", nmea.getNavSystem(),
                  nmea.getNumSatellites());
  } else {
    Serial.print(F("NMEA invalid.\r\n\r\n"));
  }
}

void loop() {
  while(Serial1.available() > 0) {
    gnss_ch = Serial1.read();
    nmea.process(gnss_ch);
    if(millis() - gnss_millis > GNSS_UPDATE)
      print_gnss();
  }
}
