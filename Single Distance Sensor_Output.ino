/*This is basically to test the performance of the distance sensor, which is going to use for object detection in my case. 
  however, have different purposes in different areas.
*/
#include <Wire.h>

#include <SparkFun_VL53L5CX_Library.h> //http://librarymanager/All#SparkFun_VL53L5CX

//SparkFun_VL53L5CX myImager;
//VL53L5CX_ResultsData measurementData; // Result data class structure, 

int imageResolution = 0; // Used to pretty print output
int imageWidth = 0;      // Used to pretty print output

SparkFun_VL53L5CX myImager;
int sensorAddress = 0x08; //New address of unit without a wire. Valid: 0x08 <= address <= 0x77
int sensorReset = 14; //GPIO that is connected to the Reset pin on sensor 1/ update with your pin number. 
VL53L5CX_ResultsData measurementData;

//long measurements = 0;         // Used to calculate actual output rate
//long measurementStartTime = 0; // Used to calculate actual output rate

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("SparkFun VL53L5CX Imager Example");

  Wire.begin(); // This resets I2C bus to 100kHz
  Wire.setClock(1000000); //Sensor has max I2C freq of 1MHz

  Serial.println("Initializing sensor board. This can take up to 10s. Please wait.");
  if (myImager.begin() == false)
  {
    Serial.println(F("Sensor not found - check your wiring. Freezing"));
    while (1)
      ;
  }

  Serial.print(F("Setting sensor 1 address to: 0x"));
  Serial.println(sensorAddress, HEX);

  if (myImager.setAddress(sensorAddress) == false)
  {
    Serial.println(F("Sensor 1 failed to set new address. Please try again. Freezing..."));
    while (1);
  }

  int newAddress = myImager.getAddress();

  Serial.print(F("New address of sensor 1 is: 0x"));
  Serial.println(newAddress, HEX);


  myImager.setResolution(8 * 8); // Enable all 64 pads

  imageResolution = myImager.getResolution(); // Query sensor for current resolution - either 4x4 or 8x8
  imageWidth = sqrt(imageResolution);         // Calculate printing width

  // Using 4x4, min frequency is 1Hz and max is 60Hz
  // Using 8x8, min frequency is 1Hz and max is 15Hz
  myImager.setRangingFrequency(15);

  myImager.startRanging();

}

void loop()
{
  // Poll sensor for new data
  if (myImager.isDataReady() == true)
  {
    if (myImager.getRangingData(&measurementData)) // Read distance data into array
    {
      // The ST library returns the data transposed from zone mapping shown in datasheet
      // Pretty-print data with increasing y, decreasing x to reflect reality
      for (int y = 0; y <= imageWidth * (imageWidth - 1); y += imageWidth)
      {
        for (int x = imageWidth - 1; x >= 0; x--)
        {
          Serial.print(measurementData.distance_mm[x + y]);
          Serial.print(",");
        }
      }
      Serial.println();

    }
  }

  delay(5); // Small delay between polling
}
