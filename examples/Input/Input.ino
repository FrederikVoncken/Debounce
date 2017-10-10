/*
 * Input example for Debounce
 *
 * Frederik Voncken 2017 - V0.1.0
 *
 */

#include "Ticker.h"

#include "GenPIO.h"
#include "Debounce.h"

/*#include "arduino.h"
#include <stdint.h>
#include "GenPIO.h"*/

GenPIO Indicator(LED_BUILTIN, OUTPUT, OFF, INVERTED);

GenPIO Switch(D6, INPUT, OFF, INVERTED);
Debounce DebounceSwitch(&Switch);

Ticker TickerSwitch;

FunctionalActive_t CurrentState;

void UpdateSwitch(void);

void setup (void)
{
	// Default debounce time is 5*10ms set here
	// (Use DebounceSwitch.SetMinDebounceCount to change the minum number of valid debounce checks)
	TickerSwitch.attach_ms(10, UpdateSwitch);
	CurrentState = DebounceSwitch.GetCurrentInput();
	Indicator.Write(CurrentState);
}

void loop(void)
{
  
}

void UpdateSwitch(void)
{
	FunctionalActive_t NextState;
	NextState = DebounceSwitch.Update();
	if (CurrentState != NextState) {
		CurrentState = NextState;
		Indicator.Write(CurrentState);
	}
}
