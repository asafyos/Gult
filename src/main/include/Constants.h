// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

namespace ctrl
{
    constexpr int kControllerPort = 0;

    enum JoystickButtons {
        A = 1,
        B = 2,
        X = 3,
        Y = 4,
        LEFT_BUMPER = 5,
        RIGHT_BUMPER = 6,
        BACK = 7,
        START = 8,
        LEFT_STICK_BUTTON = 9,
        RIGHT_STICK_BUTTON = 10
    };
} // ctrl

namespace shtr
{
    constexpr int kRightMotorPort = 12;
    constexpr int kLeftMotorPort = 11;

    constexpr int kRightEncoderPorts[] = {6, 7};
    constexpr int kLeftEncoderPorts[] = {8, 9};
} // shtr

namespace drv
{
    // set true for arcade false for tank
    constexpr bool kArcadeMode = true;

    constexpr int kRearRightMotorPort = 1;
    constexpr int kFrontRightMotorPort = 2;
    constexpr int kRearLeftMotorPort = 3;
    constexpr int kFrontLeftMotorPort = 4;

    constexpr double kDrvMinValue = .15;
    
} // drv

namespace strg
{
    constexpr int kMotorPort = 6;
    constexpr double kPower = 0.5;
    constexpr double kStorageTime = 3000.;
}  // strg