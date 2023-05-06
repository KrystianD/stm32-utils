#pragma once

#include "stm32.h"

#include <stdint.h>
#include "public_f1.h"

template<uint32_t PortAddr, uint8_t Pin>
class kGPIO
{
public:
	void inputAnalog() { IO_ANALOG((GPIO_TypeDef*)PortAddr, Pin); }
	void inputDigital() { IO_INPUT((GPIO_TypeDef*)PortAddr, Pin); }
	void inputDigitalPullup() { IO_INPUT_PP((GPIO_TypeDef*)PortAddr, Pin); }
	void pushPull() { IO_PUSH_PULL((GPIO_TypeDef*)PortAddr, Pin); }
	void altPushPull() { IO_ALT_PUSH_PULL((GPIO_TypeDef*)PortAddr, Pin); }
	void high() { IO_HIGH((GPIO_TypeDef*)PortAddr, Pin); }
	void low() { IO_LOW((GPIO_TypeDef*)PortAddr, Pin); }
	void toggle() { IO_TOGGLE((GPIO_TypeDef*)PortAddr, Pin); }

	bool read() { return IO_IS_HIGH((GPIO_TypeDef*)PortAddr, Pin); }
	bool isHigh() { return IO_IS_HIGH((GPIO_TypeDef*)PortAddr, Pin); }
	bool isLow() { return IO_IS_LOW((GPIO_TypeDef*)PortAddr, Pin); }

	uint8_t pin() const { return Pin; }
};

