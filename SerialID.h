/*
  SerialID.h v1.1 - Tags your source code with the filename, build date, and version - which it prints out to serial upon each startup - so you always know what code is in your MCU!
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#ifndef SerialID_h
#define SerialID_h

#define SerialIDset(VER) const char VERSION[] PROGMEM=VER;
#ifndef TEENSYDUINO
#define SerialIDshowNS(BAUD) Serial.begin(BAUD); \
  while((!Serial)&&(micros()<2000000)); \
  if(1){String s=String((__FlashStringHelper*)VERSION);s.replace(" ","_"); \
    Serial.println(s);Serial.flush(); \
  }
#define SerialIDshow(BAUD) Serial.begin(BAUD); \
  while((!Serial)&&(micros()<2000000)); \
  Serial.println((__FlashStringHelper*)VERSION);Serial.flush();
#else
#define SerialIDshow(BAUD) Serial.begin(BAUD); \
  while((!Serial)&&(micros()<2000000)); \
  Serial.println((__FlashStringHelper*)VERSION); \
  delay(5000); \
  Serial.println((__FlashStringHelper*)VERSION);Serial.flush(); // wait 5s for PC to re-connect serial
#endif


/* The following will define your username and the name of your PC, so you can include that in your code builds if you want.
  It requires you to modify your platform.txt file as follows:-

  1. Find this line:   recipe.hooks.prebuild.1.pattern
  2. Insert the following line above it:-

recipe.hooks.prebuild.0.pattern.windows=cmd /c echo #define ENV_USERNAME %USERNAME% > "{build.source.path}\myenv.h" & echo #define ENV_COMPUTERNAME %COMPUTERNAME% >> "{build.source.path}\myenv.h"

  3. Save and restart Arduino.

  For ESP32, the above file is probably located at %USERPROFILE%\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.14\platform.txt
*/
#ifndef NO_MYENV
#if __has_include ("myenv.h")
 #include "myenv.h"
 #define ENV_QUOTED(a)   #a
 #define ENV_QUOTE(a)    ENV_QUOTED(a)
 //#define SERIALID_TAG __DATE__ "_" __TIME__ " " ENV_QUOTE(ENV_USERNAME) "@" ENV_QUOTE(ENV_COMPUTERNAME)
 #define SERIALID_TAG __DATE__ "_" __TIME__ 
#else
 #define ENV_USERNAME "?"
 #define ENV_COMPUTERNAME "?"
 #define SERIALID_TAG __DATE__ "_" __TIME__
#endif
#endif

#endif

