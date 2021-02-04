// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace IntakeConstants

{
    const int IntakeMotor1Port = 5;
    const int IntakeMotor2Port = 6;
    const int IntakeMotor3Port = 7;

    static const int IntakeEncoderPorts0[10] = {0,1,2,3,4,5,6,7,8,9};
    static const int IntakeEncoderPorts1[10] = {0,1,2,3,4,5,6,7,8,9};
}