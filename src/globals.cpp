#include "globals.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftDrive({-9, -11, -17}, pros::MotorGears::blue);
pros::MotorGroup rightDrive({10, 19, 20}, pros::MotorGears::blue);

// scoring motors
pros::Motor lift(12, pros::MotorGears::red);
pros::Motor mechanism(18, pros::MotorGears::red);
pros::adi::DigitalOut claw('A', false);

// sensors
pros::Imu imu(13);
pros::Rotation verticalEncoder(2);
pros::Rotation horizontalEncoder(3);

// drivetrain
lemlib::Drivetrain drivetrain(
    &leftDrive,
    &rightDrive,
    11, // 11 inch track width
    lemlib::Omniwheel::NEW_325,
    450, // drivetrain rpm
    2); // horizontal drift

// tracking wheels
lemlib::TrackingWheel verticalTrackingWheel(
    &verticalEncoder,
    lemlib::Omniwheel::NEW_2,
    0 // left - and right + offset
);

lemlib::TrackingWheel horizontalTrackingWheel(
    &horizontalEncoder,
    lemlib::Omniwheel::NEW_2,
    1 // backward - and forward + offset
);  

// odometry sensors
lemlib::OdomSensors sensors(
    &verticalTrackingWheel, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    &horizontalTrackingWheel, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2
    &imu // inertial sensor
);

// PID controllers
lemlib::ControllerSettings lateralController(5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

lemlib::ControllerSettings angularController(4, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              36.3, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// chassis
lemlib::Chassis chassis(
    drivetrain,
    lateralController,
    angularController,
    sensors
);