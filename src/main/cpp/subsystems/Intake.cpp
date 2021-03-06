#include "subsystems/Intake.h"

using namespace IntakeConstants;

Intake::Intake()
    : m_intake{IntakeMotor1Port},
      m_pinion0{IntakeMotor2Port},
      m_pinion1{IntakeMotor3Port},
      inEncoder{IntakeEncoderPorts0[0],IntakeEncoderPorts0[1]},
      pin_mEncoder{IntakeEncoderPorts1[0],IntakeEncoderPorts1[1]}
{
    inEncoder.SetDistancePerPulse(kEncoder);
    pin_mEncoder.SetDistancePerPulse(kEncoder);

    ResetEncoders();
}

void Intake::ResetEncoders()
{
    inEncoder.Reset();
    pin_mEncoder.Reset();
}

frc::Encoder& Intake::GetInEncoderValue()
{
    return inEncoder; 
}

frc::Encoder& Intake::GetPinEncoderValue()
{
    return pin_mEncoder;
}

void Intake::SetIntakeZero()
{
    double val = inEncoder.GetDistance();
    if (val != 0) 
    {
        //Intake_M.Set(0);
    } 
    //sets the intake to choose in or exhale
}

void Intake::In_exhale(IntakePosition Pos)
{
    if (Pos == Inhale)
    {
        Intake_M.Set(10);
    }
    else if (Pos == Exhale)
    {
        Intake_M.Set(-10);
    }
}

void Intake::RakeOrPin()
{
    //stuff
    //could empty function be problem?
}