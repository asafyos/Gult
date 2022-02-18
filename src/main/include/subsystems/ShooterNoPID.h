// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

namespace neatt
{
class ShooterNoPID : public frc2::SubsystemBase {
 public:
  ShooterNoPID();
    void Shoot(double power);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
      WPI_VictorSPX m_leftShooterMotor{shtr::kRightMotorPort};
      WPI_VictorSPX m_rightShooterMotor{shtr::kLeftMotorPort};
};
}