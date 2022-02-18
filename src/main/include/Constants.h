// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


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