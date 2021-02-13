#include "subsystems/Conveyor.h"

using namespace ConveyorConstants;

Conveyor::Conveyor()
    : conveyorMotor{ConveyorMotor1Port},
      conveyorEncoder{ConveyorEncoderPorts[0],ConveyorEncoderPorts[1]}
{
    conveyorEncoder.SetDistancePerPulse(0);       
    ResetEncoder();
}

void Conveyor::SetConveyor()
{
    ConveyorMotors.Set(10);
}

  // ResetEncoder
  // Resets encoder to zero
void Conveyor::ResetEncoder()
{
    conveyorEncoder.Reset();
}

  //GetEncoderValue
  //Returns current encoder value
 frc::Encoder& Conveyor::GetEncoderValue()
{
    return conveyorEncoder;
}