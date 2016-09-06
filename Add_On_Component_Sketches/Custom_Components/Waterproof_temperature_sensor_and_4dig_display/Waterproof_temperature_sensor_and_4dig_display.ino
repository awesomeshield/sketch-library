/*
WIP 1-wire temp sensor displays on 4-digit grove display

temp sensor -->       port2
4-digit display -->   port3
    
*/

#include <Four_Digit_Display.h>
#include <Four_Digit_Display_Arduino.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#include <Awesome.h>


#define ONE_WIRE_BUS A0 // Awesome Shield v0.60 port2 primary pin

// diplay on port3 (AS hw v0.60)
PIN_T displayData = 6; // secondary pin
PIN_T displayClk = A2;  // primary pin


// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

Awesome awesome;


// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}

void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
//  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
//  Serial.println("DONE");

//  Serial.print("Temperature for Device 1 is: ");
//  Serial.print("Temp is: ");
//  Serial.println(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
//  show(sensors.getTempCByIndex(0));
  awesome.port3.fourDigitDisplay.display(sensors.getTempCByIndex(0));

  Serial.println();
  delay(250);
}

