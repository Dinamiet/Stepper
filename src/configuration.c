#include "stepper.h"

void Stepper_Move(Stepper* stepper, int32_t delta) { stepper->Target += delta; }

void Stepper_MoveTo(Stepper* stepper, int32_t pos) { stepper->Target = pos; }

int32_t Stepper_CurrentPosition(Stepper* stepper) { return stepper->Position; }

int32_t Stepper_TargetPosition(Stepper* stepper) { return stepper->Target; }

void Stepper_SetPosition(Stepper* stepper, int32_t pos) { stepper->Position = pos; }

bool Stepper_IsEnabled(Stepper* stepper) { return stepper->Enabled; }

void Stepper_Enable(Stepper* stepper)
{
	stepper->Enable(true);
	stepper->Enabled = true;
}

void Stepper_Disable(Stepper* stepper)
{
	stepper->Enable(false);
	stepper->Enabled = false;
}

bool Stepper_IsRunning(Stepper* stepper) { return stepper->Position != stepper->Target; }

void Stepper_SetSpeed(Stepper* stepper, uint32_t speed) { stepper->Speed = speed; }
