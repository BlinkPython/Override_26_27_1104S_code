#ifndef GLOBALS_H
#define GLOBALS_H

#include "auton.h"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"
#include "pros/optical.hpp"
#include "pros/adi.hpp"

extern pros::Controller controller;

// motor groups
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// scoring motors
extern pros::Motor lift;
extern pros::Motor mechanism;
extern pros::adi::DigitalOut claw;

// sensors
extern pros::Imu imu;
extern pros::Rotation verticalEncoder;
extern pros::Rotation horizontalEncoder;

// Lemlib components
extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel verticalTracking;
extern lemlib::TrackingWheel horizontalTracking;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

#endif