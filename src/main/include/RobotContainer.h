// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#define NO_PID_SHOOT

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"

#ifdef NO_PID_SHOOT
#include "subsystems/ShooterNoPID.h"
#else
#include "subsystems/Shooter.h"
#endif

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();

private:
  // controller
  frc::XboxController m_controller{ctrl::kControllerPort};
  frc2::JoystickButton m_aButton{&m_controller, ctrl::JoystickButtons::A};
  frc2::JoystickButton m_bButton{&m_controller, ctrl::JoystickButtons::B};
  frc2::JoystickButton m_xButton{&m_controller, ctrl::JoystickButtons::X};
  frc2::JoystickButton m_yButton{&m_controller, ctrl::JoystickButtons::Y};
  frc2::JoystickButton m_lbButton{&m_controller, ctrl::JoystickButtons::LEFT_BUMPER};
  frc2::JoystickButton m_rbButton{&m_controller, ctrl::JoystickButtons::RIGHT_BUMPER};
  frc2::JoystickButton m_backButton{&m_controller, ctrl::JoystickButtons::BACK};
  frc2::JoystickButton m_startButton{&m_controller, ctrl::JoystickButtons::START};
  frc2::JoystickButton m_lStickButton{&m_controller, ctrl::JoystickButtons::LEFT_STICK_BUTTON};
  frc2::JoystickButton m_rStickButton{&m_controller, ctrl::JoystickButtons::RIGHT_STICK_BUTTON};

  // subsystems
#ifdef NO_PID_SHOOT
  neatt::ShooterNoPID m_shooterNoPid;
#else
  neatt::Shooter m_shooter;
#endif

  void ConfigureButtonBindings();
};
