/**
 * interrupt_definitions.h
 * ProtoBlue
 *
 * Created by Lance T. Walker on 10/6/2018 3:44:30 AM.
 * Copyright © 2018 CodeLife-Productions. All rights reserved.
 --------------------------------------------------------------------------------------------
 * Interrupt Service Routines:
	
 */ 

/***************************************************************************************************/
#pragma region - Interrupt Service Routines
/* Registers */ 
/*
#define CHG_INT			INT0		// | Register = EIMSK | Offset = 0x3D | 


#define CHG_PCMSK		PCMSK0
#define CHG_ISR			(1 << PCINT0)

#define NRF_PCMSK		PCMSK0
#define NRF_ISR			(1 << PCINT4)

#define ETH_PCMSK		PCMSK0
#define ETH_ISR			(1 << PCINT5)

#define BTN_PCMSK		PCMSK2
#define BTN_ISR			((1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21) | (1 << PCINT22) | (1 << PCINT23))

#define 
*/
/* Methods */
/*
#define irq_init() do {
	CHG_PCMSK |= CHG_ISR;
	NRF_PCMSK |= NRF_ISR;
	ETH_PCMSK |= ETH_ISR;
	BTN_PCMSK |= BTN_ISR;
	EIMSK |= ((1 << PCIE0) | (1 << PCIE2));
}
*/
#pragma endregion - Interrupt Service Routines
/***************************************************************************************************/