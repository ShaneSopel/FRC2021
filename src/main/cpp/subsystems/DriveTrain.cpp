// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

using namespace DriveConstants;

  DriveTrain::DriveTrain()
      : m_left1{kLeftMotor1Port},
        m_left2{kLeftMotor2Port},
        m_right1{kRightMotor1Port},
        m_right2{kRightMotor2Port},
        m_leftEncoder{kLeftEncoderPorts[0], kLeftEncoderPorts[1]},
        m_rightEncoder{kRightEncoderPorts[0], kRightEncoderPorts[1]},
        m_odometry{m_gyro.GetRotation2d()} 
  {
    // Set the distance per pulse for the encoders
    m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
    m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);

    ResetEncoders();

  }

  void DriveTrain::Periodic()
  {
    // Implementation of subsystem periodic method goes here.
    m_odometry.Update(m_gyro.GetRotation2d(),
                      units::meter_t(m_leftEncoder.GetDistance()),
                      units::meter_t(m_rightEncoder.GetDistance()));
  }

  void DriveTrain::ArcadeDrive(double fwd, double rot) 
  {
    m_drive.ArcadeDrive(fwd, rot);
  }

  void DriveTrain::ResetEncoders()
  {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
  }

  double DriveTrain::GetAverageEncoderDistance() 
  {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
  }

  frc::Encoder& DriveTrain::GetLeftEncoder() 
  { 
    return m_leftEncoder; 
  }

  frc::Encoder& DriveTrain::GetRightEncoder() 
  { 
    return m_rightEncoder; 
  }

  void DriveTrain::SetMaxOutput(double maxOutput) 
  {
    m_drive.SetMaxOutput(maxOutput);
  }

  units::degree_t DriveTrain::GetHeading() const 
  {
    return m_gyro.GetRotation2d().Degrees();
  }

  double DriveTrain::GetTurnRate() 
  { 
    return -m_gyro.GetRate(); 
  }

  frc::Pose2d DriveTrain::GetPose() 
  { 
    return m_odometry.GetPose();
  }

  frc::DifferentialDriveWheelSpeeds DriveTrain::GetWheelSpeeds()
  {
    return {units::meters_per_second_t(m_leftEncoder.GetRate()),
            units::meters_per_second_t(m_rightEncoder.GetRate())};
  }

  void DriveTrain::ResetOdometry(frc::Pose2d pose) 
  {
    ResetEncoders();
    m_odometry.ResetPosition(pose, m_gyro.GetRotation2d());
  }