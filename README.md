# SerialID
Tags your source code with the filename, build date, and version (or whatever else you like) - which it prints out to serial upon each startup - so you always know what code is in your MCU!

This uses no RAM (strings stored in PROGMEM)


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
