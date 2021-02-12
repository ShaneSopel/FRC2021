#pragma once 

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMTalonFX.h>
#include <frc/Encoder.h>
#include "Constants.h"

class Intake : public frc2::SubsystemBase{
    
    public: 
     Intake();

     /**
     * called whenever CommandScheduler runs.
     */

     //void Periodic() override;

     /*
     called when CommandScheduler runs during simulation
     */

     //void SimulationPeriodic() override; 
  
     // ResetEncoders
     // Resets encoders for rake to zero
     void ResetEncoders();

     // return encoder value for rake/pinion  
     frc::Encoder& GetInEncoderValue();

     frc::Encoder& GetPinEncoderValue();

     void SetIntake();
     // sets retractable to default pos.
     // note: rake and pinion run simultaniously - two motors

     void In_exhale();
     //function to take in balls - no value need return
 

     void RakeOrPin();
     // two motors - bumpers control

    private:
 
     // declare motors 
     // declare intake motor
     frc::PWMTalonFX m_intake;

     // declare rake/pinion motors
     frc::PWMTalonFX m_pinion0;
     frc::PWMTalonFX m_pinion1; 

     // declare encoders
     frc::Encoder inEncoder;
     frc::Encoder pin_mEncoder; 

     // one encoder for intake
     // one for both pin motors - run at same time
    double kEncoder = 0;

};