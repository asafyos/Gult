// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chassis.h"

Chassis::Chassis() = default;

// This method will be called once per scheduler run
void Chassis::Periodic() {}

void Chassis::ArcadeDrive(double fwd, double rot, bool sqr) {
  if (abs(fwd) > drv::kDrvMinValue || abs(rot) > drv::kDrvMinValue) {
    m_robotDrive.ArcadeDrive(fwd, rot, true);
  }
}

void Chassis::TankDrive(double left, double right) {
  if (abs(left) > drv::kDrvMinValue || abs(right) > drv::kDrvMinValue) {
    m_robotDrive.TankDrive(left, right);
  }
}