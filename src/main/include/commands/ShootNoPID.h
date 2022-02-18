// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Constants.h"

#include "subsystems/ShooterNoPID.h"
#include "subsystems/Storage.h"

namespace neatt
{
class ShootNoPID
    : public frc2::CommandHelper<frc2::CommandBase, ShootNoPID> {
 public:
  ShootNoPID(Storage *storage, ShooterNoPID *shooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  private:
    Storage *m_storage;
    ShooterNoPID *m_shooter;
};
}