// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/JoystickDrive.h"

JoystickDrive::JoystickDrive(DriveTrain* subsystem,
                           std::function<double()> forward,
                           std::function<double()> rotation)
    : m_drive{subsystem}, m_forward{forward}, m_rotation{rotation}
{
  AddRequirements({subsystem});
}

void JoystickDrive::Execute()
{
  m_drive->ArcadeDrive(m_forward(), m_rotation());
}

bool JoystickDrive::IsFinished()
{
  return false;
}