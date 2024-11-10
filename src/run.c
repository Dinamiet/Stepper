#include "stepper.h"

#include <assert.h>
#include <stddef.h>

void Stepper_Run(Stepper* stepper, const uint32_t currentTime)
{
	assert(stepper != NULL);

	int32_t delta = (int32_t)(currentTime - stepper->PrevStepTime);
	if (delta < (int32_t)stepper->Speed)
		return;

	if (!Stepper_IsRunning(stepper))
		return;

	bool forward = stepper->Target < stepper->Position;
	stepper->Step(forward);
	stepper->Target += forward ? 1 : -1;

	stepper->PrevStepTime = currentTime;
}
