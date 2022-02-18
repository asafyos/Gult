// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

namespace neatt
{
  class Storage : public frc2::SubsystemBase
  {
  public:
    Storage();
    
    void Periodic() override;
    
    void Store(double power);

  private:
    WPI_TalonSRX m_motor{strg::kMotorPort};

  };
}