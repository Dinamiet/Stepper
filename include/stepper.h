#ifndef _STEPPER_H_
#define _STEPPER_H_

#include <stdbool.h>
#include <stdint.h>

typedef void (*Stepper_StepFunction)(bool forward);
typedef void (*Stepper_EnableFunction)(bool enable);

typedef struct _Stepper_
{
	int32_t                Position;
	int32_t                Target;
	uint32_t               Speed;
	uint32_t               PrevStepTime;
	bool                   Enabled;
	Stepper_StepFunction   Step;
	Stepper_EnableFunction Enable;
} Stepper;

void Stepper_Init(Stepper* stepper, Stepper_StepFunction stepCallback, Stepper_EnableFunction enableCallback);
void Stepper_Move(Stepper* stepper, int32_t delta);
void Stepper_MoveTo(Stepper* stepper, int32_t pos);

int32_t Stepper_CurrentPosition(Stepper* stepper);
int32_t Stepper_TargetPosition(Stepper* stepper);
void    Stepper_SetPosition(Stepper* stepper, int32_t pos);

bool Stepper_IsEnabled(Stepper* stepper);
void Stepper_Enable(Stepper* stepper);
void Stepper_Disable(Stepper* stepper);

bool Stepper_IsRunning(Stepper* stepper);
void Stepper_SetSpeed(Stepper* stepper, uint32_t speed);

void Stepper_Run(Stepper* stepper, uint32_t currentTime);

#endif
