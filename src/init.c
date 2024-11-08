#include "stepper.h"

void Stepper_Init(Stepper* stepper, Stepper_StepFunction step_callback, Stepper_EnableFunction enable_callback)
{
	stepper->Position     = 0;
	stepper->Target       = 0;
	stepper->Speed        = 0;
	stepper->PrevStepTime = 0;
	stepper->Enabled      = false;
	stepper->Step         = step_callback;
	stepper->Enable       = enable_callback;
}
