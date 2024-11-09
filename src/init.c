#include "stepper.h"

#include <assert.h>
#include <stddef.h>

void Stepper_Init(Stepper* stepper, Stepper_StepFunction step_callback, Stepper_EnableFunction enable_callback)
{
	assert(stepper != NULL);
	assert(step_callback != NULL);
	assert(enable_callback != NULL);

	stepper->Position     = 0;
	stepper->Target       = 0;
	stepper->Speed        = 0;
	stepper->PrevStepTime = 0;
	stepper->Enabled      = false;
	stepper->Step         = step_callback;
	stepper->Enable       = enable_callback;
}
