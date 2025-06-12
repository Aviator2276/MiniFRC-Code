#include <Alfredo_NoU2.h>
#include <PestoLink-Receive.h>

// 1. Enter the port number of the motor to the corrosponding placement.
// Add the servo port below. If there are none, ignore the line.
NoU_Motor FRMotor(1);
NoU_Motor FLMotor(2);
NoU_Motor BRMotor(3);
NoU_Motor BLMotor(4);

NoU_Motor claw(6);

// Ignore this
NoU_Drivetrain drivetrain(&FRMotor, &FLMotor, &BRMotor, &BLMotor);

void setup() { 
    // 2. Change the team number
    PestoLink.begin("Team 64");

    // 3. Invert any motors that need to be inverted.
    FRMotor.setInverted(true);
    FLMotor.setInverted(false);
    BRMotor.setInverted(true);
    BLMotor.setInverted(false);

    RSL::initialize();
    RSL::setState(RSL_ENABLED);
}

void loop() {
    // Ignore this
    float rotation = 0;
    float throttle = 0;

    rotation = 1 * PestoLink.getAxis(0);
    throttle =  -1 * PestoLink.getAxis(1);

    drivetrain.arcadeDrive(throttle, rotation);

    // Set specific servo angles below.
    if (PestoLink.buttonHeld(0)) {
        claw.set(-0.1);
    }
    else {
        claw.set(0.1);
    }

    // Ignore this
    if (PestoLink.update()) {
        RSL::setState(RSL_ENABLED);
    } else {
        RSL::setState(RSL_DISABLED);
    }

    PestoLink.update();
    RSL::update();
}