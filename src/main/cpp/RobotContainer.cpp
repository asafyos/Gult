// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here
  this->m_chassis.SetDefaultCommand(frc2::RunCommand([this]
                                                     {
    if (drv::kArcadeMode){ //arcade

      double power = this->m_controller.GetLeftY();
      if (abs(power) < drv::kDrvMinValue)
        power = 0; 

      double rotation = -this->m_controller.GetLeftX();
      if (abs(rotation) < drv::kDrvMinValue)
        rotation = 0;

      this->m_chassis.ArcadeDrive(power, rotation, this->m_controller.GetLeftStickButton() );

    } else { // tank

      double powerLeft = this->m_controller.GetLeftY();
      if (abs(powerLeft) < drv::kDrvMinValue)
        powerLeft = 0;

      double powerRight = this->m_controller.GetRightY();
      if (abs(powerRight) < drv::kDrvMinValue)
        powerRight = 0;
        
      this->m_chassis.TankDrive(
        powerLeft,
        powerRight);

    } }));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // An example command will be run in autonomous
  return nullptr;
}
