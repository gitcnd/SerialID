/*
  example_SerialID.pde v1.0 - example use of SerialID
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#include <SerialID.h>

  SerialIDset("\n# v1.01 " __FILE__ "\t" __DATE__ " " __TIME__);

void setup() {
  SerialIDshow(115200);
  // Causes something like this to be in your code, and print on your serial at each boot:
  //	# v1.01 /Users/username/Documents/Arduino/libraries/SerialID/examples/example_SerialID/example_SerialID.pde	Dec 22 2018 17:53:37
}

void loop()
{
  delay(3000);
}

