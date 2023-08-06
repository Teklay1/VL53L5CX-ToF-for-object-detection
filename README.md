# VL53L5CX-ToF-for-object-detection
![main](Images/ToF_Imager_VL53L5CX.JPEG) <br /> 
(SparkFun Mini ToF Distsnce Imager)

## Introduction
Using a I2C connected multiple VL53L5CX distance sensors to detect objects. 

## Steps to detect objects accurately!
Starting from 1 sensor Step by step to get distance data from 8 sensors so that the drone can monitor all its surrounding in all directions. 

First, get a distance data using 4x4 or 8x8 mode of the a single sensor. 
The sensor covers wide area so, section the view in to any parts according to the application, i.e. 2, 4, 8. ...

Accourding to the sections, get the angle and distance information. 

Cascade the Sensors up to 8 and apply this step to all of them. 

then you will get accurate, all round ToF  object detection system for your drone.


