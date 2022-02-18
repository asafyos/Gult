// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shoot.h"

using namespace neatt;

Shoot::Shoot(Storage *storage, Shooter *shooter, nt::NetworkTableEntry *distance, bool timed) : m_storage{storage}, m_shooter{shooter}, m_distance{distance->GetDouble(0.)}, m_timed{timed}
{
  AddRequirements(m_shooter);
  AddRequirements(m_storage);
}

// Called when the command is initially scheduled.
void Shoot::Initialize()
{
  m_storage->Store(0);
  m_shooter->SetSetpoint(SetPower());
  if (m_timed)
  {
    m_timer.Reset();
    m_timer.Start();
  }
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute()
{
  m_shooter->Enable();
  if (m_shooter->GetController().AtSetpoint())
    m_storage->Store(strg::kPower);
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted)
{
  m_shooter->Disable();
  if (m_timed)
    m_timer.Stop();
}

// Returns true when the command should end.
bool Shoot::IsFinished()
{
  return m_timed && (double)m_timer.Get() > shtr::kShootTime;
}

double Shoot::SetPower()
{
  // Enter relation between distance and power
  return m_distance * shtr::kPower; // voltage
}