// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterNoPID.h"

using namespace neatt;

ShooterNoPID::ShooterNoPID() = default;

// This method will be called once per scheduler run
void ShooterNoPID::Periodic() {}

void ShooterNoPID::Shoot(double power) {
  m_leftShooterMotor.Set(power);
  m_rightShooterMotor.Set(-power);
}

double ShooterNoPID::GetEncoderRate() {
  return (m_leftEncoder.GetRate() + m_rightEncoder.GetRate()) / 2;
}