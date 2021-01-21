// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//#pragma once

#ifndef JOYSTICKDRIVE_H
#define JOYSTICKDRIVE_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"


class JoystickDrive
    : public frc2::CommandHelper<frc2::CommandBase, JoystickDrive> {
 public:
  /**
   * Creates a new DefaultDrive.
   *
   * @param subsystem The drive subsystem this command wil run on.
   * @param forward The control input for driving forwards/backwards
   * @param rotation The control input for turning
   */
 JoystickDrive(DriveTrain* subsystem, std::function<double()> forward,
               std::function<double()> rotation);

  void Execute() override;
  bool IsFinished() override;

 private:
  DriveTrain* m_drive;
  std::function<double()> m_forward;
  std::function<double()> m_rotation;
};

#endif