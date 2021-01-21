// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//#pragma once

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <frc/ADXRS450_Gyro.h>
#include <frc/Encoder.h>
#include <frc/PWMTalonFX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>
#include <units/voltage.h>

#include "Constants.h"

class DriveTrain : public frc2::SubsystemBase {
public:
DriveTrain();

/**
 * Will be called periodically whenever the CommandScheduler runs.
 */
void Periodic() override;

  /**
 * Drives the robot using arcade controls.
 *
 * @param fwd the commanded forward movement
 * @param rot the commanded rotation
 */
void ArcadeDrive(double fwd, double rot);

/**
 * Resets the drive encoders to currently read a position of 0.
 */
void ResetEncoders();

/**
 * Gets the average distance of the TWO encoders.
 *
 * @return the average of the TWO encoder readings
 */
double GetAverageEncoderDistance();

/**
 * Gets the left drive encoder.
 *
 * @return the left drive encoder
 */
frc::Encoder& GetLeftEncoder();

/**
 * Gets the right drive encoder.
 *
 * @return the right drive encoder
 */
frc::Encoder& GetRightEncoder();

/**
 * Sets the max output of the drive.  Useful for scaling the drive to drive
 * more slowly.
 *
 * @param maxOutput the maximum output to which the drive will be constrained
 */
void SetMaxOutput(double maxOutput);

/**
 * Returns the heading of the robot.
 *
 * @return the robot's heading in degrees, from -180 to 180
 */
units::degree_t GetHeading() const;

/**
 * Returns the turn rate of the robot.
 *
 * @return The turn rate of the robot, in degrees per second
 */
double GetTurnRate();

/**
 * Returns the currently-estimated pose of the robot.
 *
 * @return The pose.
 */
frc::Pose2d GetPose();

/**
 * Returns the current wheel speeds of the robot.
 *
 * @return The current wheel speeds.
 */
frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

/**
 * Resets the odometry to the specified pose.
 *
 * @param pose The pose to which to set the odometry.
 */
  void ResetOdometry(frc::Pose2d pose);

private:
// Components (e.g. motor controllers and sensors) should generally be
// declared private and exposed only through public methods.
frc::PWMTalonFX m_left1;
frc::PWMTalonFX m_left2;
frc::PWMTalonFX m_right1;
frc::PWMTalonFX m_right2;

frc::SpeedControllerGroup m_leftmotors{m_left1, m_left2};
frc::SpeedControllerGroup m_rightmotors{m_right1, m_right2};

frc::DifferentialDrive m_drive{m_leftmotors, m_rightmotors};

// The left-side drive encoder
frc::Encoder m_leftEncoder;

// The right-side drive encoder
frc::Encoder m_rightEncoder;

// The gyro sensor
frc::ADXRS450_Gyro m_gyro;

// Odometry class for tracking robot pose
frc::DifferentialDriveOdometry m_odometry;

double kEncoderDistancePerPulse = 0;

/*int kLeftMotor1Port  = 0;
int kLeftMotor2Port  = 1;
int kRightMotor1Port = 2;
int kRightMotor2Port = 3;

int kRightEncoderPorts[10];
int kLeftEncoderPorts[10];*/

};

#endif