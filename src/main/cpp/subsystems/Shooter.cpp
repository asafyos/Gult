// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

using namespace neatt;

Shooter::Shooter()
    : PIDSubsystem(
          frc2::PIDController(shtr::kP, shtr::kI, shtr::kD))
{

  m_controller.SetTolerance(shtr::kTolerance.to<double>());
  m_leftEncoder.SetDistancePerPulse(shtr::kEncoderDistancePerPulse);
  m_rightEncoder.SetDistancePerPulse(shtr::kEncoderDistancePerPulse);
  m_rightEncoder.SetReverseDirection(true);
}

void Shooter::Shoot(units::volt_t power)
{
  m_leftShooterMotor.SetVoltage(power);
  m_rightShooterMotor.SetVoltage(-power);
}

void Shooter::UseOutput(double output, double setpoint)
{
  Shoot(units::volt_t(output) + m_feedforward.Calculate(units::angular_velocity::turns_per_second_t(setpoint)));
}

double Shooter::GetMeasurement()
{
  return (m_leftEncoder.GetRate() + m_rightEncoder.GetRate()) / 2;
}
