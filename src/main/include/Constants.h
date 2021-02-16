// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
//#ifndefCONSTANTS_H
//#defineCONSTANTS_H

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants
{

const double kEncoderDistancePerPulse = 0;

const int kLeftMotor1Port  = 0;
const int kLeftMotor2Port  = 1;
const int kRightMotor1Port = 2;
const int kRightMotor2Port = 3;

static const int kRightEncoderPorts[10] = {0,1,2,3,4,5,6,7,8,9};
static const int kLeftEncoderPorts[10]  = {0,1,2,3,4,5,6,7,8,9};

}


//#endif