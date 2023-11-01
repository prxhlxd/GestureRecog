#include "model_multiclass.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
Eloquent::ML::Port::SVM classifier;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t a, g ,temp; //instanciate the sensors's reading object 
  mpu.getEvent(&a, &g , &temp);//register the read values to the object declared before

  float features[] = {a.acceleration.x, a.acceleration.y, a.acceleration.z, g.gyro.x, g.gyro.y, g.gyro.z}; //create the array containing the read values size is : 1x3 same as defined in google colab
  String output_str = classifier.predictLabel(features); //run inference

  Serial.println(output_str);//print the resulting orientation
  Serial.println("You have 3 seconds to change orientation.");
  Serial.print("3 , ");
  delay(1000);
  Serial.print("2 , ");
  delay(1000);
  Serial.println("1");
  delay(1000);
}