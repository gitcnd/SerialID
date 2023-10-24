# SerialID
Tags your source code with the filename, build date, version, username and build pcname (or whatever else you like) - which it prints out to serial upon each startup - so you always know what code is in your MCU! (who who built it, from what, on where)

This uses no RAM (strings stored in PROGMEM) on atmel


# SYNOPSIS

```C
  #include <SerialID.h>

  SerialIDset("\n# v1.00 " __FILE__ "\t" __DATE__ " " __TIME__);

  void setup() {                
     SerialIDshow(115200);
  }

  void loop() {
    // ...
  }
```

## Example Output

```text
# v1.01 /Users/username/Documents/Arduino/libraries/SerialID/examples/example_SerialID/example_SerialID.pde	Dec 22 2018 19:05:24
```

# MACROS

```C
  SerialIDset("Version string to print");	// Put this at the top of your code, so the compiler knows to build your strings into the PROGMEM flash area
  SerialIDshow(Serial_baud_rate_to_setup);	// Put this in your setup() code, to print the above string out to serial
  SerialIDshowNS()				// Same as SerialIDshow - except with No Spaces: does a s.replace(" ","_")
  ENV_QUOTE					// Puts quotes around literals (see SERIALID_TAG)
```
# CONSTANTS
```C
  ENV_USERNAME					// The logged-in username of the person currently compiling the code. Use this like:  ENV_QUOTE(ENV_USERNAME) 
  ENV_COMPUTERNAME				// The name of the machine the code is compiling on
  SERIALID_TAG					// __DATE__ "_" __TIME__ " " ENV_QUOTE(ENV_USERNAME) "@" ENV_QUOTE(ENV_COMPUTERNAME)
```


# HOW TO INSTALL

(Method 1)

1. Open a terminal (commandline, bash shell, whatever)
2. Change into your Arduino folder
```bash
   cd ~/Arduino/libraries
```
3. grab and install this code
```bash
   git clone https://github.com/gitcnd/SerialID.git
```
4. restart your arduino IDE
5. Choose File => Examples => SerialID => hello
6. Hit the "build" button an enjoy!

(Method 2) - see https://www.arduino.cc/en/Guide/Libraries

1. Download the ZIP of this repo: https://github.com/gitcnd/SerialID/archive/master.zip
2. In your IDE, select Sketch -> Include Library -> Add .ZIP Library
3. Choose File => Examples => SerialID => hello
4. Hit the "build" button an enjoy!

(To use ENV_USERNAME/ENV_COMPUTERNAME - do this)
1. Locate the platform.txt for the board you're using (e.g. %USERPROFILE%\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.14\platform.txt)
2. Find the line starting with this:   recipe.hooks.prebuild.1.pattern
3. Insert the following line above it:-

recipe.hooks.prebuild.0.pattern.windows=cmd /c echo #define ENV_USERNAME %USERNAME% > "{build.source.path}\myenv.h" & echo #define ENV_COMPUTERNAME %COMPUTERNAME% >> "{build.source.path}\myenv.h"

4. Save and restart Arduino.
5. Note: this will create the new file myenv.h alongside every sketch you build
6. If you do NOT want this feature, put this above the include:  #define NO_MYENV

