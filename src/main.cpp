/*
//Code by Vijay Arvind Rao for Vortex IoT
//---------------------------------------
//Battery Charger Debugging  - 23 May 2019, Swansea
//---------------------------------------
//
//This code uses the Serial and I2C (Wire) Arduino libraries to setup I2C diagnostics
//and sends read-outs on the serial port.
//It keeps polling the registers of the LTC4162-L on I2C once every READING_INTERVAL
//amount of time and then sends out these values on the serial terminal.
//The I2C values read out the LSByte first, followed by the MSByte. This needs special
//attention while reading the status and flags.
*/


#include <Arduino.h>
#include <Wire.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initialize the serial port at 9600 baud
  Wire.begin(); //Initialize the I2C bus as a master
  pinMode(13, OUTPUT); //User pin13 as a on-board diagnostic output
  Serial.println("BATTERY MANAGEMENT MONITOR");


  //////
  //0x14
  //Serial.println("Sending 0x15 to write Input Current Limits Register");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x15); //
  Wire.write(0x1F); //
  Wire.endTransmission(); //STOP

  //////
  //0x1A
  //Serial.println("Sending 0x1A to write Input Current Limits Register");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x1A); //
  Wire.write(0x1F); //
  Wire.endTransmission(); //STOP
}

void loop() {
  Serial.println(":00:"); //Start of data
  // put your main code here, to run repeatedly:
  //Serial.println("Debugger to read battery charger parameters"); //Send out a startup notification

  //////
  //0x14
  //Serial.println("Sending 0x14 to read Config Bits Register");
  Serial.print(":14:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x14); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 1);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x15
  //Serial.println("Sending 0x15 to read Input Current Limit Target");
  Serial.print(":15:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x15); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 1);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x1A
  //Serial.println("Sending 0x1A to read Charge Current Setting");
  Serial.print(":1A:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x1A); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 1);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x34
  //Serial.println("Sending 0x34 to read Charger State");
  Serial.print(":34:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x34); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x35
  //Serial.println("Sending 0x35 to read Charge Status");
  Serial.print(":35:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x35); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 1);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x36
  //Serial.println("Sending 0x36 to read Limit Alerts Register");
  Serial.print(":36:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x36); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  /*
  //////
  //0x37
  //Serial.println("Sending 0x37 to read Charger State Alerts Register");
  Serial.print("")
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x37); //
  Wire.endTransmission(); //STOP
  delay(1000);
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    Serial.print("Number of bytes read = ");
    Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
    Serial.println("");
  }
  */

  /*
  //////
  //0x38
  Serial.println("Sending 0x38 to read Charge Status Alerts Register");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x38); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 1);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    Serial.print("Number of bytes read = ");
    Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
    Serial.println("");
  }
  */


  //////
  //0x39
  //Serial.println("Sending 0x39 to read System Status Register");
  Serial.print(":39:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x39); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;
    }
  }
  Serial.println("");


  //////
  //0x3A
  //Serial.println("Sending 0x3A to read Battery Voltage");
  Serial.print(":3A:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3a); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x3B
  //Serial.println("Sending 0x3B to read Input Voltage");
  Serial.print(":3B:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3b); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x3C
  //Serial.println("Sending 0x3C to read Output Voltage");
  Serial.print(":3C:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3C); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x3D
  //Serial.println("Sending 0x3D to read Battery Current");
  Serial.print(":3D:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3D); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x3E
  //Serial.println("Sending 0x3E to read Input Current");
  Serial.print(":3E:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3E); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x43
  //Serial.println("Sending 0x43 to read Programmed Battery Chemistry");
  Serial.print(":43:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x43); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 2);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");


  //////
  //0x4A
  //Serial.println("Sending 0x4A to read Telemetry Status Register");
  Serial.print(":4A:");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x4a); //
  Wire.endTransmission(); //STOP
  Wire.requestFrom(0x68, 1);    // request 1 byte from slave device 0x68
  while(Wire.available())    // slave may send less than requested
  {
    //Serial.print("Number of bytes read = ");
    //Serial.println(Wire.available());
    char reading = Wire.read();    // receive a byte as character
    char index = 7;
    unsigned char Mask = 0x80;
    char bitValue = 0;

    for(index=7; index>=0; index--)
    {
      bitValue = reading & Mask;
      if (bitValue)
        Serial.print('1');
      else
        Serial.print('0');
      Mask = Mask >> 1;

    }
  }
  Serial.println("");



  Serial.println(":FF:"); //End of data
  Serial.println("");
  delay(5000);
}
