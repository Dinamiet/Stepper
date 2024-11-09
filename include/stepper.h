#ifndef _STEPPER_H_
#define _STEPPER_H_

/** \file
 * Stepper
 *
 * Stepper motor driver logic library
 */

#include <stdbool.h>
#include <stdint.h>

/**
 * Stepper step function template.
 * Interface to step/move the stepper motor
 * \param forward Indicates the direction of movement, true for forward and false for backward
 */
typedef void (*Stepper_StepFunction)(bool forward);

/** Template function to enable/disable motor
 * \param enable True if the motor should be enabled, false otherwise
 */
typedef void (*Stepper_EnableFunction)(bool enable);

/**
 * Stepper storage
 */
typedef struct _Stepper_
{
	int32_t                Position;     /**< Current position, movement tries to match Target and Position */
	int32_t                Target;       /**< Target position, movement tries to match Position and Target */
	uint32_t               Speed;        /**< Step speed, minimum time allowed between steps */
	uint32_t               PrevStepTime; /**< Timestamp of last step taken */
	bool                   Enabled;      /**< Enable indication */
	Stepper_StepFunction   Step;         /**< Callback function to update physical position */
	Stepper_EnableFunction Enable;       /**< Callback function to enabled/disable */
} Stepper;

/** Initializes and sets up a stepper object with the required configuration
 * \param stepper The object to initialize
 * \param stepCallback Interface function to that is called when instructed to take a step
 * \param enableCallback Interface function to enable/disable the stepper
 */
void Stepper_Init(Stepper* stepper, Stepper_StepFunction stepCallback, Stepper_EnableFunction enableCallback);

/**
 * Instruct the stepper to move a relative amount of steps
 * \param stepper The stepper to move
 * \param delta The number of steps to take. Positive for CW and negative for CCW
 */
void Stepper_Move(Stepper* stepper, int32_t delta);

/**
 * Instruct the stepper to move to a absolute position
 * \param stepper The stepper to move
 * \param pos The position to move to
 */
void Stepper_MoveTo(Stepper* stepper, int32_t pos);

/**
 * Get the current position of the stepper
 * \param stepper The stepper of interest
 * \return The current position
 */
int32_t Stepper_CurrentPosition(Stepper* stepper);

/**
 * Get the current target position of the stepper
 * \param stepper THe stepper of intereset
 * \return The target position
 */
int32_t Stepper_TargetPosition(Stepper* stepper);

/**
 * Set the current position of the stepper
 * \param stepper The stepper's position to update
 * \param pos The current position of the stepper
 */
void Stepper_SetPosition(Stepper* stepper, int32_t pos);

/**
 * The current state of the stepper
 * \param stepper The stepper of interest
 * \return True if stepper is enabled, false otherwise
 */
bool Stepper_IsEnabled(Stepper* stepper);

/**
 * Enable stepper
 * \param stepper Stepper to enable
 */
void Stepper_Enable(Stepper* stepper);

/**
 * Disable stepper
 * \param stepper Stepper to disable
 */
void Stepper_Disable(Stepper* stepper);

/**
 * Is the stepper currently moving towards a target position
 * \param stepper The stepper to check
 * \return True if stepper is currently moving towards a target position, false if the stepper is at its target position
 */
bool Stepper_IsRunning(Stepper* stepper);

/** Adjusts the maximum speed of stepper
 * \param stepper Stepper to adjust
 * \param time The minimum time between steps
 */
void Stepper_SetSpeed(Stepper* stepper, uint32_t time);

/**
 * Move and update stepper position should it be neccessary.
 * \note This function needs to be called faster than the desired step speed.
 * \param stepper Stepper to update
 * \param currentTime The current system timestamp. Used to determine step speed.
 */
void Stepper_Run(Stepper* stepper, uint32_t currentTime);

#endif
