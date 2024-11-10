#include "stepper.h"

#include <assert.h>
#include <stddef.h>

void Stepper_Move(Stepper* stepper, const int32_t delta)
{
	assert(stepper != NULL);

	stepper->Target += delta;
}

void Stepper_MoveTo(Stepper* stepper, const int32_t pos)
{
	assert(stepper != NULL);

	stepper->Target = pos;
}

int32_t Stepper_CurrentPosition(const Stepper* stepper)
{
	assert(stepper != NULL);

	return stepper->Position;
}

int32_t Stepper_TargetPosition(const Stepper* stepper)
{
	assert(stepper != NULL);

	return stepper->Target;
}

void Stepper_SetPosition(Stepper* stepper, const int32_t pos)
{
	assert(stepper != NULL);

	stepper->Position = pos;
}

bool Stepper_IsEnabled(const Stepper* stepper)
{
	assert(stepper != NULL);

	return stepper->Enabled;
}

void Stepper_Enable(Stepper* stepper)
{
	assert(stepper != NULL);

	stepper->Enable(true);
	stepper->Enabled = true;
}

void Stepper_Disable(Stepper* stepper)
{
	assert(stepper != NULL);

	stepper->Enable(false);
	stepper->Enabled = false;
}

bool Stepper_IsRunning(const Stepper* stepper)
{
	assert(stepper != NULL);

	return stepper->Position != stepper->Target;
}

void Stepper_SetSpeed(Stepper* stepper, const uint32_t speed)
{
	assert(stepper != NULL);

	stepper->Speed = speed;
}
