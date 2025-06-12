#include <Alfredo_NoU2.h>
#include <PestoLink-Receive.h>

// 1. Enter the port number of the motor to the corrosponding placement.
// Add the servo port below. If there are none, ignore the line.
NoU_Motor FRMotor(3);
NoU_Motor FLMotor(2);
NoU_Motor BRMotor(4);
NoU_Motor BLMotor(1);


// Ignore this
NoU_Drivetrain drivetrain(&FRMotor, &FLMotor, &BRMotor, &BLMotor);

void setup() { 
    // 2. Change the team number
    PestoLink.begin("27");

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
    throttle =  1 * PestoLink.getAxis(1);

    drivetrain.arcadeDrive(throttle, rotation);

    

    // Ignore this
    if (PestoLink.update()) {
        RSL::setState(RSL_ENABLED);
    } else {
        RSL::setState(RSL_DISABLED);
    }

    PestoLink.update();
    RSL::update();
}