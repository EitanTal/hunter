/*	BASIC INTERRUPT VECTOR TABLE FOR STM8 devices
 *	Copyright (c) 2007 STMicroelectronics
 */
#include "time.h"
#include "stm8l10x.h"

typedef void @far (*interrupt_handler_t)(void);

struct interrupt_vector {
	unsigned char interrupt_instruction;
	interrupt_handler_t interrupt_handler;
};

void ack_all_exti(void)
{
	EXTI->SR1 = 0xFF;
	EXTI->SR2 = 0xFF;
}

@far @interrupt void NonHandledInterrupt (void)
{
	/* in order to detect unexpected events during development, 
	   it is recommended to set a breakpoint on the following instruction
	*/
	return;
}


@far @interrupt void IRQ0 (void)
{
	return;
}

@far @interrupt void IRQ1 (void)
{
	return;
}

@far @interrupt void IRQ2 (void)
{
	return;
}

@far @interrupt void IRQ3 (void)
{
	return;
}

@far @interrupt void IRQ4 (void)
{
	return;
}

@far @interrupt void IRQ5 (void)
{
	return;
}

@far @interrupt void IRQ6 (void)
{
	return;
}

@far @interrupt void IRQ7 (void)
{
	return;
}

@far @interrupt void IRQ8 (void)
{
	ack_all_exti(); // light down
	return;
}

@far @interrupt void IRQ9 (void)
{
	ack_all_exti();
	return;
}

@far @interrupt void IRQ10(void)
{
	ack_all_exti();
	return;
}

@far @interrupt void IRQ11(void)
{
	ack_all_exti(); // light up
	return;
}

@far @interrupt void IRQ12(void)
{
	ack_all_exti();
	return;
}

@far @interrupt void IRQ13 (void)
{
	return;
}

extern void _stext();     /* startup routine */


struct interrupt_vector const _vectab[] = {
	{0x82, (interrupt_handler_t)_stext}, /* reset */
	{0x82, NonHandledInterrupt}, /* trap  */
	{0x82, IRQ0}, /* irq0  */
	{0x82, IRQ1}, /* irq1  */
	{0x82, IRQ2}, /* irq2  */
	{0x82, IRQ3}, /* irq3  */
	{0x82, IRQ4}, /* irq4  */
	{0x82, IRQ5}, /* irq5  */
	{0x82, IRQ6}, /* irq6  */
	{0x82, IRQ7}, /* irq7  */
	{0x82, IRQ8}, /* irq8  */
	{0x82, IRQ9}, /* irq9  */
	{0x82, IRQ10}, /* irq10 */
	{0x82, IRQ11}, /* irq11 */
	{0x82, IRQ12}, /* irq12 */
	{0x82, IRQ13}, /* irq13 */
	{0x82, IRQ13}, /* irq14 */
	{0x82, NonHandledInterrupt}, /* irq15 */
	{0x82, NonHandledInterrupt}, /* irq16 */
	{0x82, NonHandledInterrupt}, /* irq17 */
	{0x82, NonHandledInterrupt}, /* irq18 */
	{0x82, NonHandledInterrupt}, /* irq19 */
	{0x82, NonHandledInterrupt}, /* irq20 */
	{0x82, NonHandledInterrupt}, /* irq21 */
	{0x82, NonHandledInterrupt}, /* irq22 */
	{0x82, NonHandledInterrupt}, /* irq23 */
	{0x82, NonHandledInterrupt}, /* irq24 */
	{0x82, NonHandledInterrupt}, /* irq25 */
	{0x82, NonHandledInterrupt}, /* irq26 */
	{0x82, NonHandledInterrupt}, /* irq27 */
	{0x82, NonHandledInterrupt}, /* irq28 */
	{0x82, NonHandledInterrupt}, /* irq29 */
};
