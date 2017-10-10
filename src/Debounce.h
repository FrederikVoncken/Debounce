/*
 * Debounce.h
 *
 * Frederik Voncken 2017 - V0.1.0
 *
 */

#ifndef _DEBOUNCE_H
#define _DEBOUNCE_H

#include "arduino.h"
#include <stdint.h>
#include "GenPIO.h"

#define DEBOUNCE_BIT_OK        0;
#define DEBOUNCE_BIT_NoGenPIO  1<<1;

#define DEBOUNCE_DefaultMinCount 5

class Debounce
{
	public:
		Debounce(GenPIO *Input);
		~Debounce() {;}
		FunctionalActive_t Update(void);
		FunctionalActive_t GetCurrentInput(void);
		FunctionalActive_t GetNextInput(void);
		uint8_t GetDebounceCount(void);
		void SetMinDebounceCount(uint8_t Count);
		uint8_t GetMinDebounceCount(void);
		uint8_t GetBIT(void);
		void ResetBIT(void);
	private:
		GenPIO *DebounceInput;
		FunctionalActive_t CurrentInput;
		FunctionalActive_t NextInput;
		uint8_t DebounceCount;
		uint8_t MinDebounceCount;
		uint8_t BIT;
};

#endif /* _DEBOUNCE_H */
