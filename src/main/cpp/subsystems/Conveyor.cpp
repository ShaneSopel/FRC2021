#include "subsystems/Conveyor.h"

using namespace ConveyorConstants;

Conveyor::Conveyor()
    : conveyorMotor{ConveyorMotor1Port},
      conveyorEncoder{ConveyorEncoderPorts[0],ConveyorEncoderPorts[1]}
{
    ResetEncoder();
}

void Conveyor::SetConveyor()
{
    conveyorMotor.Set();
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