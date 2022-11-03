#ifndef CPU_H_
#define CPU_H_

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t A, X, Y;
	uint32_t PC;
	uint8_t SP;
	uint8_t Flag;
	uint16_t address;
	uint8_t* targetData;
	uint8_t instructionWidth;
	void (*targetFunction)();
} CPU;

void CPU_Start();
void CPU_FDE();
void Debug();

//instructions
extern void (*instructionTable[256])();

//load a
void LDA();
//load x
void LDX();
//load y
void LDY();
//store a
void STA();
//store x
void STX();
//store y
void STY();
//transfer a to x
void TAX();
//transfer a to y
void TAY();
//transfer sp to x
void TSX();
//transfer x to a
void TXA();
//transfer x to sp
void TXS();
//transfer y to a
void TYA();

//push a
void PHA();
//push status flag with b set
void PHP();
//pull a
void PLA();
//pull status flag
void PLP();

//decrement
void DEC();
//decrement x
void DEX();
//decrement y
void DEY();
//increment
void INC();
//increment x
void INX();
//incement y
void INY();

//add with carry
void ADC();
//subtract with carry
void SBC();

//and a
void AND();
//exclusive or a
void EOR();
//inclusive or a
void ORA();

//arithmetic shift left
void ASL();
//logical shift right
void LSR();
//rotate left
void ROL();
//rotate right
void ROR();

//clear carry
void CLC();
//clear decimal
void CLD();
//clear interrupt disable
void CLI();
//clear overflow
void CLV();
//set carry
void SEC();
//set decimal
void SED();
//set interrupt disable
void SEI();

//compare a
void CMP();
//compare x
void CPX();
//compare y
void CPY();

//branch on carry clear (c 0)
void BCC();
//branch on carry (c 1)
void BCS();
//branch on equal (z 1)
void BEQ();
//branch on minus (n 1)
void BMI();
//branch on not equal (z 0)
void BNE();
//branch on plus (n 0)
void BPL();
//branch on overflow clear (v 0)
void BVC();
//branch on overflow (v 1)
void BVS();

//jump
void JMP();
//jump subroutine
void JSR();
//return from subroutine
void RTS();

//break
void BRK();
//return from interrupt
void RTI();

//bit test
void BIT();
//no operation
void NOP();

//addressing modes
extern void (*addressingTable[256])();
//operation data is the immediate byte proceeding the opcode
void Immediate();
//operation data is at the absolute address proceeding the opcode
void Absolute();
//operation data is at the zero-page address proceeding the opcode
void ZeroPage();
//operation data is a 2 byte address located at the address proceeding the opcode.
void Indirect();
//operation data is byte proceeding opcode
void Relative();
//operation data is 2byte address added with the X register
void AbsoluteX();
//operation data is 2byte address added with the Y register
void AbsoluteY();
//operation is performed on the accumulator
void Accumulator();
extern CPU processor;

#endif