// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootNoPID.h"

using namespace neatt;

ShootNoPID::ShootNoPID(Storage *storage, ShooterNoPID *shooter) : m_storage{storage}, m_shooter{shooter} {
  AddRequirements(m_storage);
  AddRequirements(m_shooter);
}

// Called when the command is initially scheduled.
void ShootNoPID::Initialize() {
  m_storage->Store(0);
  m_shooter->Shoot(0);
  }

// Called repeatedly when this Command is scheduled to run
void ShootNoPID::Execute() {
  m_shooter->Shoot(shtr::kPower);
  if (m_shooter->GetEncoderRate() >= shtr::kPower)
    m_storage->Store(strg::kPower);
}

// Called once the command ends or is interrupted.
void ShootNoPID::End(bool interrupted) {
  m_storage->Store(0);
  m_shooter->Shoot(0);
}

// Returns true when the command should end.
bool ShootNoPID::IsFinished() {
  return false;
}
