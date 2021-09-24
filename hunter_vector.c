/*	INTERRUPT VECTORS TABLE FOR STM8L101
 *	Copyright (c) 2008 by COSMIC Software
 */
extern void _stext();		/* startup routine */

#pragma section const {vector}

void (* const @vector _vectab[32])() = {
	_stext,			/* RESET       */
	0,			/* TRAP        */
	0,			/* Reserved    */
	0,			/* FLASH       */
	0,0,			/* Reserved    */
	0,			/* AWU         */
	0,			/* Reserved    */
	0,			/* EXTIB       */
	0,			/* EXTID       */
	0,			/* EXTI0       */
	0,			/* EXTI1       */
	0,			/* EXTI2       */
	0,			/* EXTI3       */
	0,			/* EXTI4       */
	0,			/* EXTI5       */
	0,			/* EXTI6       */
	0,			/* EXTI7       */
	0,0,			/* Reserved    */
	0,			/* COMP        */
	0,			/* TIMER 2 OVF */
	0,			/* TIMER 2 CAP */
	0,			/* TIMER 3 OVF */
	0,			/* TIMER 3 CAP */
	0,0,			/* Reserved    */
	0,			/* TIMER 4 OVF */
	0,			/* SPI         */
	0,			/* USART TX    */
	0,			/* USART RX    */
	0,			/* I2C         */
	};
