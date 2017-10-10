/*
 * Debounce.cpp
 *
 * Frederik Voncken 2017 - V0.1.0
 *
 */

#include "Debounce.h"

Debounce::Debounce(GenPIO *Input)
{
	DebounceInput = Input;
	CurrentInput = DebounceInput->Read();
	NextInput = CurrentInput;
	DebounceCount = 0;
	MinDebounceCount = DEBOUNCE_DefaultMinCount;
	BIT = DEBOUNCE_BIT_OK;
}

FunctionalActive_t Debounce::Update(void)
{
	FunctionalActive_t Input;
	if (DebounceInput != NULL) {
		Input = DebounceInput->Read();
		if (Input == NextInput) {
			if (DebounceCount < MinDebounceCount) {
				DebounceCount++;
			} 
			if (DebounceCount == MinDebounceCount) {
				CurrentInput = Input;
			}
		} else {
			DebounceCount = 0;
			NextInput = Input;
		}
	} else {
		BIT |= DEBOUNCE_BIT_NoGenPIO;
	}

	return CurrentInput;
}

FunctionalActive_t Debounce::GetCurrentInput(void)
{
	return CurrentInput;
}

FunctionalActive_t Debounce::GetNextInput(void)
{
	return NextInput;
}

uint8_t Debounce::GetDebounceCount(void)
{
	return DebounceCount;
}

void Debounce::SetMinDebounceCount(uint8_t Count)
{
	if (Count == 0) {
		Count = 1;
	}
	MinDebounceCount = Count;
}

uint8_t Debounce::GetMinDebounceCount(void)
{
	return MinDebounceCount;
}

uint8_t Debounce::GetBIT(void)
{
	return BIT;
}

void Debounce::ResetBIT(void)
{
	BIT = DEBOUNCE_BIT_OK;
}
