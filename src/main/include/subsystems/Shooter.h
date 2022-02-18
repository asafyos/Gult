// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/PIDSubsystem.h>
#include <ctre/Phoenix.h>
#include <frc/Encoder.h>
#include <frc/controller/SimpleMotorFeedforward.h>

#include "Constants.h"

namespace neatt
{
  class Shooter : public frc2::PIDSubsystem
  {
  public:
    Shooter();
    
    void Shoot(units::volt_t power);

  protected:
    void UseOutput(double output, double setpoint) override;

    double GetMeasurement() override;

  private:
    WPI_VictorSPX m_leftShooterMotor{shtr::kRightMotorPort};
    WPI_VictorSPX m_rightShooterMotor{shtr::kLeftMotorPort};

    frc::Encoder m_leftEncoder{shtr::kLeftEncoderPorts[0], shtr::kLeftEncoderPorts[1]};
    frc::Encoder m_rightEncoder{shtr::kRightEncoderPorts[0], shtr::kRightEncoderPorts[1]};

    frc::SimpleMotorFeedforward<units::turns> m_feedforward{shtr::kS, shtr::kV, shtr::kA};
  };
}