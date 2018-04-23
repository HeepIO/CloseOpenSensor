
#include "HeepDeviceDefinitions.h"

#define OPEN_PIN 14

void InitializeControlHardware(){
  pinMode(OPEN_PIN,INPUT);
}

int ReadOpen(){
  int currentSetting = digitalRead(OPEN_PIN);
  SetControlValueByName("Open",currentSetting);
  return currentSetting;
}

void setup()
{

  Serial.begin(115200);
  InitializeControlHardware();
  AddOnOffControl("Open",HEEP_OUTPUT,0);
  StartHeep(heepDeviceName, 6);

}

void loop()
{
  PerformHeepTasks();
  ReadOpen();

}