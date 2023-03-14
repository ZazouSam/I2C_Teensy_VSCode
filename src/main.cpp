#include <Arduino.h>

// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <Wire.h>

int led = LED_BUILTIN;
int xEncore = 0;
int flag = 0;

void setup()
{
  pinMode(led, OUTPUT);
  Wire.begin();         // join i2c bus (address optional for master)
  Serial.begin(115200); // start serial for output
}

void loop()
{

  digitalWrite(led, HIGH); // briefly flash the LED
  Wire.requestFrom(2, 8);  // request 6 bytes from slave device #8

  while (Wire.available())
  {                      // slave may send less than requested
    int i = Wire.read(); // receive a byte as character
    if (i == 0x69 || i == 0xE1 || i == 0xE2 || i == 0xE3 || i == 0xE4 || i == 0xE5 || i == 0xE6 || i == 0xEE)
    {
      // Serial.print("Rien"); // print the character
    }
    else
    {
      // prints the value of the variable i in hexadecimal format
      Serial.printf("%x\n\r", i);
    }
  }

  digitalWrite(led, LOW);
  delay(5);
}
