// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class Conveyor : public frc2::SubsystemBase {
 public:
  Conveyor();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  // ConveyorUp
  // Moves conveyor up
  void ConveyorUp();

  // ConveyorDown
  // Moves conveyor Down
  void ConveyorDown();


  // ResetEncoder
  // Resets encoder to zero
  void ResetEncoder();

  //GetEncoderValue
  //Returns current encoder value
  void GetEncoderValue();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

 // Declares conveyor motor
  frc::PWMTalonFX conveyorMotor;

 // Declares conveyor encoder
  frc::PMWTalonFX conveyorEncoder;
  


};
