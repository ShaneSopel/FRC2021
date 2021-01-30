// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Conveyor.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ConveyorMovement
    : public frc2::CommandHelper<frc2::CommandBase, ConveyorMovement> {
 public:
  /**
   * Creates a new ConveyorMovement.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ConveyorUp(Conveyor* subsystem);

 private:
  Conveyor* m_subsystem;
};