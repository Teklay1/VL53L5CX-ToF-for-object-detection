////////////////////////declare variables and libraries/////////////////////////////
#include <Wire.h>
#include <SparkFun_VL53L5CX_Library.h>
#include <random>

SparkFun_VL53L5CX myImager1;
int sensorAddress1 = 0x08; // New address of unit without a wire. Valid: 0x08 <= address <= 0x77
int sensorReset1 = 14; // GPIO that is connected to the Reset pin on sensor 1
VL53L5CX_ResultsData measurementData1;

int imageResolution = 0; // Used to pretty print output
int imageWidth = 0;      // Used to pretty print output

int minValue1=0;
int minValue2=0;
int minValue3=0;
int minValue4=0;

//////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(2000000);
  delay(0);

  Wire.begin(); // This resets the I2C bus to 100kHz
  Wire.setClock(1000000); // Sensor has a max I2C frequency of 1MHz
  
  pinMode(sensorReset1, OUTPUT);
  digitalWrite(sensorReset1, HIGH); // Reset sensor 1
  delay(0);
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////

  digitalWrite(sensorReset1, LOW); // Sensor 1 should now be available at default address 0x29

  Serial.println(F("Initializing sensor 1. This can take up to 10s. Please wait."));
  if (myImager1.begin() == false) {
    Serial.println(F("Sensor 1 not found. Check wiring. Freezing..."));
    while (1);
  }

  Serial.print(F("Setting sensor 1 address to: 0x"));
  Serial.println(sensorAddress1, HEX);

  if (myImager1.setAddress(sensorAddress1) == false) {
    Serial.println(F("Sensor 1 failed to set a new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress1 = myImager1.getAddress();

  Serial.print(F("New address of sensor 1 is: 0x"));
  Serial.println(newAddress1, HEX);

  ///////////////////////////////////////////////////////////////////////////////////////////////////

  // Configure both sensors the same just to keep things clean
  myImager1.setResolution(4 * 4); // Enable all 64 pads
  imageResolution = myImager1.getResolution(); // Query sensor for current resolution - either 4x4 or 8x8
  imageWidth = sqrt(imageResolution);         // Calculate printing width
  myImager1.setRangingFrequency(15);
  myImager1.startRanging();
}

void loop() {
  
  // Poll sensor for new data
  if (myImager1.isDataReady() == true) {
    if (myImager1.getRangingData(&measurementData1)) {

      Serial.println("Zone 1 Values ");
      int zoneNumberOne[] = {1, 2, 3, 4};
      int distance1[4];

      for (int i = 0; i < 4; i++) {
        int zoneNumber1 = zoneNumberOne[i];
        distance1[i] = measurementData1.distance_mm[zoneNumber1 - 1] / 10; // Divide by 10 to convert to centimeters        
        Serial.print(distance1[i]);
        Serial.print("  ");

        minValue1 = distance1[0];

        if (distance1[i] < minValue1) {
          minValue1 = distance1[i];
          }
      }
      Serial.println();
      Serial.print("Minimum value: ");
      Serial.println(minValue1); 

      Serial.println();

      Serial.println("Zone 2 Values ");
      int zoneNumberTwo[] = {5, 6, 7, 8};
      int distance2[4];

      for (int i = 0; i < 4; i++) {
        int zoneNumber2 = zoneNumberTwo[i];
        distance2[i] = measurementData1.distance_mm[zoneNumber2 - 1] / 10; // Divide by 10 to convert to centimeters        
        Serial.print(distance2[i]);
        Serial.print("  ");

        minValue2 = distance2[0];

        if (distance2[i] < minValue2) {
          minValue2 = distance2[i];
          }
      }
      Serial.println();
      Serial.print("Minimum value: ");
      Serial.println(minValue2); 

      Serial.println();   

      Serial.println("Zone 3 Values ");
      int zoneNumberThree[] = {9, 10, 11, 12};
      int distance3[4];

      for (int i = 0; i < 4; i++) {
        int zoneNumber3 = zoneNumberThree[i];
        distance3[i] = measurementData1.distance_mm[zoneNumber3 - 1] / 10; // Divide by 10 to convert to centimeters        
        Serial.print(distance3[i]);
        Serial.print("  ");

        minValue3 = distance3[0];

        if (distance3[i] < minValue3) {
          minValue3 = distance3[i];
          }
      }
      Serial.println();
      Serial.print("Minimum value: ");
      Serial.println(minValue3); 

      Serial.println(); 

      Serial.println("Zone 4 Values ");
      int zoneNumberFour[] = {13, 14, 15, 16};
      int distance4[4];

      for (int i = 0; i < 4; i++) {
        int zoneNumber4 = zoneNumberFour[i];
        distance4[i] = measurementData1.distance_mm[zoneNumber4 - 1] / 10; // Divide by 10 to convert to centimeters        
        Serial.print(distance4[i]);
        Serial.print("  ");

        minValue4 = distance4[0];

        if (distance4[i] < minValue4) {
          minValue4 = distance4[i];
          }
      }
      Serial.println();
      Serial.print("Minimum value: ");
      Serial.println(minValue4); 

      Serial.println();  



      Serial.println("Obstacle detected at");

      if (minValue1 <= 100) {
        Serial.print("Area 1  ");
      }

      if (minValue2 <= 100) {
        Serial.print("Area 2  ");
      }

      if (minValue3 <= 100) {
        Serial.print("Area 3  ");
      }

      if (minValue4 <= 100) {
        Serial.print("Area 4  ");
      }

      /*// Check if any of the distances in each area are less than 100 cm
      if (distance1[0] < 100 || distance1[1] < 100 || distance1[2] < 100 || distance1[3] < 100) {
        Serial.print("Area 1  ");
      }
      if (distance2[4] < 100 || distance2[5] < 100 || distance2[6] < 100 || distance2[7] < 100) {
        Serial.print("Area 2  ");
      }
      if (distance3[8] < 100 || distance3[9] < 100 || distance3[10] < 100 || distance3[11] < 100) {
        Serial.print("Area 3  ");
      }
      if (distance4[12] < 100 || distance4[13] < 100 || distance4[14] < 100 || distance4[15] < 100) {
        Serial.println("Area 4  ");
      }*/

      Serial.println();
          
/*
int minValue = min(minValue1, min(minValue2, min(minValue3, minValue4)));
Serial.print("Minimum value from all zones: ");
Serial.println(minValue);

*/


      Serial.println("All Distances (CM):");

      // Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0; y <= imageWidth * (imageWidth - 1); y += imageWidth) {
        for (int x = imageWidth - 1; x >= 0; x--) {
          Serial.print("\t");
          Serial.print(measurementData1.distance_mm[x + y] / 10);
        }
        Serial.println();
      }
      Serial.println();
    }
  }

  delay(1000); // Small delay between polling
}