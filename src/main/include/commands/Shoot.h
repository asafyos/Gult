// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <networktables/NetworkTableEntry.h>
#include <frc/Timer.h>

#include "Constants.h"

#include "subsystems/Shooter.h"
#include "subsystems/Storage.h"

namespace neatt
{
  class Shoot
      : public frc2::CommandHelper<frc2::CommandBase, Shoot>
  {
  public:
    Shoot(Storage *storage, Shooter *shooter, nt::NetworkTableEntry *distance, bool timed);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

    double SetPower();

  private:
    frc::Timer m_timer;
    Storage *m_storage;
    Shooter *m_shooter;
    double m_distance;
    bool m_timed;
  };
}