#include <Arduino.h>
#include <Wire.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initialize the serial port at 9600 baud
  Wire.begin(); //Initialize the I2C bus as a master
  pinMode(13, OUTPUT); //User pin13 as a on-board diagnostic output
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Debugger to read battery charger parameters"); //Send out a startup notification



  //////
  //0x34
  Serial.println("Sending 0x34 to read Charger State");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x34); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x35
  Serial.println("Sending 0x35 to read Charge Status");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x35); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x36
  Serial.println("Sending 0x36 to read Limit Alerts Register");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x36); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x37
  Serial.println("Sending 0x37 to read Charger State Alerts Register");
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

  //////
  //0x39
  Serial.println("Sending 0x39 to read System Status Register");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x39); //
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

  //////
  //0x3A
  Serial.println("Sending 0x3A to read Battery Voltage");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3a); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x3B
  Serial.println("Sending 0x3B to read Input Voltage");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3b); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x3C
  Serial.println("Sending 0x3C to read Output Voltage");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3C); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x3D
  Serial.println("Sending 0x3D to read Battery Current");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3D); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x3E
  Serial.println("Sending 0x3E to read Input Current");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x3E); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x43
  Serial.println("Sending 0x43 to read Programmed Battery Chemistry");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x43); //
  Wire.endTransmission(); //STOP
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

  //////
  //0x4A
  Serial.println("Sending 0x4A to read Telemetry Status Register");
  Wire.beginTransmission(0x68); //SLA
  Wire.write(0x4a); //
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



  Serial.println("End of received data");
  Serial.println("");
  delay(5000);
}
