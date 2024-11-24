#include "stepper.h"

#include <assert.h>
#include <stddef.h>

void Stepper_Init(Stepper* stepper, const Stepper_StepInterface step_interface, const Stepper_EnableInterface enable_interface)
{
	assert(stepper != NULL);
	assert(step_interface != NULL);
	assert(enable_interface != NULL);

	stepper->Position     = 0;
	stepper->Target       = 0;
	stepper->Speed        = 0;
	stepper->PrevStepTime = 0;
	stepper->Enabled      = false;
	stepper->Step         = step_interface;
	stepper->Enable       = enable_interface;
}
