// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"

namespace neatt
{
  class Chassis : public frc2::SubsystemBase
  {
  public:
    Chassis();

    /**
     * Will be called periodically whenever the CommandScheduler runs.
     */
    void Periodic() override;

    bool GetIsArcade();

    void ArcadeDrive(double fwd, double rot, bool sqr);
    void TankDrive(double left, double right);

  private:
    WPI_TalonSRX m_rearRightMotor{drv::kRearRightMotorPort};
    WPI_TalonSRX m_frontRightMotor{drv::kFrontRightMotorPort};
    WPI_TalonSRX m_rearLeftMotor{drv::kRearLeftMotorPort};
    WPI_TalonSRX m_frontLeftMotor{drv::kFrontLeftMotorPort};

    frc::MotorControllerGroup m_right{m_rearRightMotor, m_frontRightMotor};
    frc::MotorControllerGroup m_left{m_rearLeftMotor, m_frontLeftMotor};

    frc::DifferentialDrive m_robotDrive{m_left, m_right};
  };
}