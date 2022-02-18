// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Storage.h"

using namespace neatt;

Storage::Storage() = default;

// This method will be called once per scheduler run
void Storage::Periodic() {}

void Storage::Store(double power)
{
    this->m_motor.Set(power);
}