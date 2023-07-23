////////////////////////declare variables and librries/////////////////////////////
#include <Wire.h>

#include <SparkFun_VL53L5CX_Library.h> //http://librarymanager/All#SparkFun_VL53L5CX

int imageResolution1 = 0; //Used to pretty print output
int imageWidth1 = 0; //Used to pretty print output

int imageResolution2 = 0; //Used to pretty print output
int imageWidth2 = 0; //Used to pretty print output

int imageResolution3 = 0; //Used to pretty print output
int imageWidth3 = 0; //Used to pretty print output

int imageResolution4 = 0; //Used to pretty print output
int imageWidth4 = 0; //Used to pretty print output

int imageResolution5 = 0; //Used to pretty print output
int imageWidth5 = 0; //Used to pretty print output

int imageResolution6 = 0; //Used to pretty print output
int imageWidth6 = 0; //Used to pretty print output

int imageResolution7 = 0; //Used to pretty print output
int imageWidth7 = 0; //Used to pretty print output

int imageResolution8 = 0; //Used to pretty print output
int imageWidth8 = 0; //Used to pretty print output

///////////////////////////////////////////////////////////////////////////

SparkFun_VL53L5CX myImager1;
int sensorAddress1 = 0x08; //New address of unit without a wire. Valid: 0x08 <= address <= 0x77
int sensorReset1 = 14; //GPIO that is connected to the Reset pin on sensor 1
VL53L5CX_ResultsData measurementData1;
String ID1 = "10000";

SparkFun_VL53L5CX myImager2;
int sensorAddress2 = 0x11; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset2 = 15; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData2;
String ID2 = "20000";

SparkFun_VL53L5CX myImager3;
int sensorAddress3 = 0x20; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset3 = 27; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData3;
String ID3 = "30000";

SparkFun_VL53L5CX myImager4;
int sensorAddress4 = 0x30; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset4 = 12; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData4;
String ID4 = "40000";

SparkFun_VL53L5CX myImager5;
int sensorAddress5 = 0x40; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset5 = 13; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData5;
String ID5 = "50000";

SparkFun_VL53L5CX myImager6;
int sensorAddress6 = 0x50; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset6 = 17; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData6;
String ID6 = "60000";

SparkFun_VL53L5CX myImager7;
int sensorAddress7 = 0x60; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset7 = 16; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData7;
String ID7 = "70000";

SparkFun_VL53L5CX myImager8;
int sensorAddress8 = 0x70; //Default VL53L5CX - this is the unit we'll hold in reset (has the wire soldered)
int sensorReset8 = 19; //GPIO that is connected to the Reset pin on sensor 2
VL53L5CX_ResultsData measurementData8;
String ID8 = "80000";

//////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("SparkFun VL53L5CX Imager Example");

  Wire.begin(); //This resets I2C bus to 100kHz
  Wire.setClock(1000000); //Sensor has max I2C freq of 1MHz

  pinMode(sensorReset1, OUTPUT);
  digitalWrite(sensorReset1, HIGH); //Reset sensor 1

  pinMode(sensorReset2, OUTPUT);
  digitalWrite(sensorReset2, HIGH); //Hold sensor 2 in reset while we configure sensor 1

  pinMode(sensorReset3, OUTPUT);
  digitalWrite(sensorReset3, HIGH); //Hold sensor 3 in reset while we configure sensor 1
  
  pinMode(sensorReset4, OUTPUT);
  digitalWrite(sensorReset4, HIGH); //Hold sensor 4 in reset while we configure sensor 1
  
  pinMode(sensorReset5, OUTPUT);
  digitalWrite(sensorReset5, HIGH); //Hold sensor 5 in reset while we configure sensor 1
  
  pinMode(sensorReset6, OUTPUT);
  digitalWrite(sensorReset6, HIGH); //Hold sensor 6 in reset while we configure sensor 1
  
  pinMode(sensorReset7, OUTPUT);
  digitalWrite(sensorReset7, HIGH); //Hold sensor 7 in reset while we configure sensor 1
  
  pinMode(sensorReset8, OUTPUT);
  digitalWrite(sensorReset8, HIGH); //Hold sensor 8 in reset while we configure sensor 1

  delay(0);
  

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset1, LOW); //Sensor 1 should now be available at default address 0x29

  Serial.println(F("Initializing sensor 1. This can take up to 10s. Please wait."));
  if (myImager1.begin() == false)
  {
    Serial.println(F("Sensor 1 not found. Check wiring. Freezing..."));
    while (1) ;
  }

  Serial.print(F("Setting sensor 1 address to: 0x"));
  Serial.println(sensorAddress1, HEX);

  if (myImager1.setAddress(sensorAddress1) == false)
  {
    Serial.println(F("Sensor 1 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress1 = myImager1.getAddress();

  Serial.print(F("New address of sensor 1 is: 0x"));
  Serial.println(newAddress1, HEX);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset2, LOW); //Release sensor 2 from reset

  Serial.println(F("Initializing sensor 2. This can take up to 10s. Please wait."));
  if (myImager2.begin() == false)
  {
    Serial.println(F("Sensor 2 not found. Check wiring. Freezing..."));
    while (1) ;
  }
  Serial.print(F("Setting sensor 2 address to: 0x"));
  Serial.println(sensorAddress2, HEX);

  if (myImager2.setAddress(sensorAddress2) == false)
  {
    Serial.println(F("Sensor 2 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress2 = myImager2.getAddress();

  Serial.print(F("New address of sensor 2 is: 0x"));
  Serial.println(newAddress2, HEX);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

digitalWrite(sensorReset3, LOW); //Release sensor 3 from reset

  Serial.println(F("Initializing sensor 3. This can take up to 10s. Please wait."));
  if (myImager3.begin() == false)
  {
    Serial.println(F("Sensor 3 not found. Check wiring. Freezing..."));
    while (1) ;
  }
  Serial.print(F("Setting sensor 3 address to: 0x"));
  Serial.println(sensorAddress3, HEX);

  if (myImager3.setAddress(sensorAddress3) == false)
  {
    Serial.println(F("Sensor 3 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress3 = myImager3.getAddress();

  Serial.print(F("New address of sensor 3 is: 0x"));
  Serial.println(newAddress3, HEX);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

digitalWrite(sensorReset4, LOW); //Release sensor 3 from reset

  Serial.println(F("Initializing sensor 4. This can take up to 10s. Please wait."));
  if (myImager4.begin() == false)
  {
    Serial.println(F("Sensor 4 not found. Check wiring. Freezing..."));
    while (1) ;
  }
  Serial.print(F("Setting sensor 4 address to: 0x"));
  Serial.println(sensorAddress4, HEX);

  if (myImager4.setAddress(sensorAddress4) == false)
  {
    Serial.println(F("Sensor 4 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress4 = myImager4.getAddress();

  Serial.print(F("New address of sensor 4 is: 0x"));
  Serial.println(newAddress4, HEX);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset5, LOW); //Release sensor 5 from reset

  Serial.println(F("Initializing sensor 5. This can take up to 10s. Please wait."));
  if (myImager5.begin() == false)
  {
    Serial.println(F("Sensor 5 not found. Check wiring. Freezing..."));
    while (1) ;
  }
  Serial.print(F("Setting sensor 5 address to: 0x"));
  Serial.println(sensorAddress5, HEX);

  if (myImager5.setAddress(sensorAddress5) == false)
  {
    Serial.println(F("Sensor 5 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress5 = myImager5.getAddress();

  Serial.print(F("New address of sensor 5 is: 0x"));
  Serial.println(newAddress5, HEX);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset6, LOW); //Release sensor 6 from reset

  Serial.println(F("Initializing sensor 6. This can take up to 10s. Please wait."));
  if (myImager6.begin() == false)
  {
    Serial.println(F("Sensor 6 not found. Check wiring. Freezing..."));
    while (1) ;
  }
  Serial.print(F("Setting sensor 6 address to: 0x"));
  Serial.println(sensorAddress6, HEX);

  if (myImager6.setAddress(sensorAddress6) == false)
  {
    Serial.println(F("Sensor 6 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress6 = myImager6.getAddress();

  Serial.print(F("New address of sensor 6 is: 0x"));
  Serial.println(newAddress6, HEX);

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset7, LOW); //release sensor 7 from reset

  Serial.println(F("Initializing sensor 7. This can take up to 10s. Please wait."));
  if (myImager7.begin() == false)
  {
    Serial.println(F("Sensor 7 not found. Check wiring. Freezing..."));
    while (1) ;
  }

  Serial.print(F("Setting sensor 7 address to: 0x"));
  Serial.println(sensorAddress7, HEX);

  if (myImager7.setAddress(sensorAddress7) == false)
  {
    Serial.println(F("Sensor 7 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress7 = myImager7.getAddress();

  Serial.print(F("New address of sensor 7 is: 0x"));
  Serial.println(newAddress7, HEX);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset8, LOW); //release sensor 8 from reset

  Serial.println(F("Initializing sensor 8. This can take up to 10s. Please wait."));
  if (myImager8.begin() == false)
  {
    Serial.println(F("Sensor 8 not found. Check wiring. Freezing..."));
    while (1) ;
  }

  Serial.print(F("Setting sensor 8 address to: 0x"));
  Serial.println(sensorAddress8, HEX);

  if (myImager8.setAddress(sensorAddress8) == false)
  {
    Serial.println(F("Sensor 8 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress8 = myImager8.getAddress();

  Serial.print(F("New address of sensor 8 is: 0x"));
  Serial.println(newAddress8, HEX);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Configure both sensors the same just to keep things clean
  myImager1.setResolution(8 * 8); //Enable all 64 pads
  myImager2.setResolution(8 * 8); //Enable all 64 pads
  myImager3.setResolution(8 * 8); //Enable all 64 pads
  myImager4.setResolution(8 * 8); //Enable all 64 pads
  myImager5.setResolution(8 * 8); //Enable all 64 pads
  myImager6.setResolution(8 * 8); //Enable all 64 pads
  myImager7.setResolution(8 * 8); //Enable all 64 pads
  myImager8.setResolution(8 * 8); //Enable all 64 pads

  imageResolution1 = myImager1.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth1 = sqrt(imageResolution1); //Calculate printing width

  imageResolution2 = myImager2.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth2 = sqrt(imageResolution2); //Calculate printing width

  imageResolution3 = myImager3.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth3 = sqrt(imageResolution3); //Calculate printing width

  imageResolution4 = myImager4.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth4 = sqrt(imageResolution4); //Calculate printing width

  imageResolution5 = myImager5.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth5 = sqrt(imageResolution5); //Calculate printing width

  imageResolution6 = myImager6.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth6 = sqrt(imageResolution6); //Calculate printing width

  imageResolution7 = myImager7.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth7 = sqrt(imageResolution7); //Calculate printing width

  imageResolution8 = myImager8.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  imageWidth8 = sqrt(imageResolution8); //Calculate printing width

  myImager1.setRangingFrequency(1);
  myImager2.setRangingFrequency(1);
  myImager3.setRangingFrequency(1);  
  myImager4.setRangingFrequency(1); 
  myImager5.setRangingFrequency(1); // 12Hz frequency
  myImager6.setRangingFrequency(1); 
  myImager7.setRangingFrequency(1); 
  myImager8.setRangingFrequency(1); 

  myImager1.startRanging();
  myImager2.startRanging();
  myImager3.startRanging();
  myImager4.startRanging();
  myImager5.startRanging();
  myImager6.startRanging();
  myImager7.startRanging();
  myImager8.startRanging();
}



void loop()
//////////////////////////////////print sensor 1 output ////////////////////////////////////////////////////////////////////////
{
  //Poll sensor for new data
  if (myImager1.isDataReady() == true)
  {
    if (myImager1.getRangingData(&measurementData1)) //Read distance data into array
    
    Serial.print(ID1);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth1 * (imageWidth1 - 1) ; y += imageWidth1)
      {
        for (int x = imageWidth1 - 1 ; x >= 0 ; x--)
        {
         
         
          Serial.print(measurementData1.distance_mm[x + y]); 
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

//////////////////////////print sensor 2 output ///////////////////////////////////////////////////////////////////////////////

  if (myImager2.isDataReady() == true)
  {
    if (myImager2.getRangingData(&measurementData2)) //Read distance data into array
    Serial.print(ID2);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth2 * (imageWidth2 - 1) ; y += imageWidth2)
      {
        for (int x = imageWidth2 - 1 ; x >= 0 ; x--)
        {
          
          
          Serial.print(measurementData2.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

  ///////////////////////////////////////////////////////////////////////////

  if (myImager3.isDataReady() == true)
  {
    if (myImager3.getRangingData(&measurementData3)) //Read distance data into array
    Serial.print(ID3);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth3 * (imageWidth3 - 1) ; y += imageWidth3)
      {
        for (int x = imageWidth3 - 1 ; x >= 0 ; x--)
        {
          
          
          Serial.print(measurementData3.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

///////////////////////////////////////////////////////////////////////////

  if (myImager4.isDataReady() == true)
  {
    if (myImager4.getRangingData(&measurementData4)) //Read distance data into array
    Serial.print(ID4);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth4 * (imageWidth4 - 1) ; y += imageWidth4)
      {
        for (int x = imageWidth4 - 1 ; x >= 0 ; x--)
        {
          
          Serial.print(measurementData4.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

  ///////////////////////////////////////////////////////////////////////////

  if (myImager5.isDataReady() == true)
  {
    if (myImager5.getRangingData(&measurementData5)) //Read distance data into array
    Serial.print(ID5);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth5 * (imageWidth5 - 1) ; y += imageWidth5)
      {
        for (int x = imageWidth5 - 1 ; x >= 0 ; x--)
        {
          
          Serial.print(measurementData5.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

  ///////////////////////////////////////////////////////////////////////////

  if (myImager6.isDataReady() == true)
  {
    if (myImager6.getRangingData(&measurementData6)) //Read distance data into array
    Serial.print(ID6);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth6 * (imageWidth6 - 1) ; y += imageWidth6)
      {
        for (int x = imageWidth6 - 1 ; x >= 0 ; x--)
        {
          
          Serial.print(measurementData6.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

  ///////////////////////////////////////////////////////////////////////////

  if (myImager7.isDataReady() == true)
  {
    if (myImager7.getRangingData(&measurementData7)) //Read distance data into array
    Serial.print(ID7);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth7 * (imageWidth7 - 1) ; y += imageWidth7)
      {
        for (int x = imageWidth7 - 1 ; x >= 0 ; x--)
        {
          
          Serial.print(measurementData7.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      //Serial.println();
    }
  }

  ///////////////////////////////////////////////////////////////////////////

  if (myImager8.isDataReady() == true)
  {
    if (myImager8.getRangingData(&measurementData8)) //Read distance data into array
    Serial.print(ID8);
    Serial.print(",");
    {
      //The ST library returns the data transposed from zone mapping shown in datasheet
      //Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0 ; y <= imageWidth8 * (imageWidth8 - 1) ; y += imageWidth8)
      {
        for (int x = imageWidth8 - 1 ; x >= 0 ; x--)
        {
          
          Serial.print(measurementData8.distance_mm[x + y]);
          Serial.print(",");
        }
        //Serial.println();
      }
      Serial.println();
    }
  }
  delay(0); //Small delay between polling
}