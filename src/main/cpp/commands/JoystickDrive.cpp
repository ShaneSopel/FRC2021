// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/JoystickDrive.h"

JoystickDrive::JoystickDrive(DriveTrain* subsystem)
    : m_drive{subsystem}
{
  AddRequirements({subsystem});
}

void JoystickDrive::Execute(double forward, double rot)
{
  m_drive->ArcadeDrive(forward, rot);
}

bool JoystickDrive::IsFinished()
{
  return false;
}

//try this later. 
//m_forward{forward}, m_rotation{rotation}