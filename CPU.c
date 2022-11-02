#include "CPU.h"
#include "Memory.h"

void (*instructionTable[256])();
void (*addressingTable[256])();

void CPU_Start()
{
	instructionTable[0xA9] = &LDA;
	instructionTable[0xAD] = &LDA;
	addressingTable[0xA9] = &Immediate;
	addressingTable[0xAD] = &Absolute;
	processor.PC = 0x200;
	
}

void CPU_FDE()
{
	processor.instructionWidth = 1;
	//Set memory addressing mode of opcode
	processor.targetFunction = addressingTable[memory[processor.PC]];
	if(processor.targetFunction != NULL)
		(processor.targetFunction)();
	//Set instruction to be used by opcode
	processor.targetFunction = instructionTable[memory[processor.PC]];
	if (processor.targetFunction != NULL)
		(processor.targetFunction)();
	Debug();
	processor.PC += processor.instructionWidth;
}

void Debug()
{
	printf("A: 0x%02X, X: 0x%02X, Y: 0x%02X, SP: 0x%02X, PC: 0x%04X | Opcode: 0x%02X, Data: 0x%02X, Address: 0x%04X\n", processor.A, processor.X, processor.Y, processor.SP, processor.PC, memory[processor.PC], *processor.targetData, processor.address);
}

void LDA()
{
	processor.A = *processor.targetData;
}

void LDX()
{
	processor.X = *processor.targetData;
}

void LDY()
{
	processor.Y = *processor.targetData;
}

void STA()
{

}

void STX()
{
}

void STY()
{
}

void TAX()
{
}

void TAY()
{
}

void TSX()
{
}

void TXA()
{
}

void TXS()
{
}

void TYA()
{
}

void PHA()
{
}

void PHP()
{
}

void PLA()
{
}

void PLP()
{
}

void DEC()
{
}

void DEX()
{
}

void DEY()
{
}

void INC()
{
}

void INX()
{
}

void INY()
{
}

void ADC()
{
}

void SBC()
{
}

void AND()
{
}

void EOR()
{
}

void ORA()
{
}

void ASL()
{
}

void LSR()
{
}

void ROL()
{
}

void ROR()
{
}

void CLC()
{
}

void CLD()
{
}

void CLI()
{
}

void CLV()
{
}

void SEC()
{
}

void SED()
{
}

void SEI()
{
}

void CMP()
{
}

void CPX()
{
}

void CPY()
{
}

void BCC()
{
}

void BCS()
{
}

void BEQ()
{
}

void BMI()
{
}

void BNE()
{
}

void BPL()
{
}

void BVC()
{
}

void BVS()
{
}

void JMP()
{
}

void JSR()
{
}

void RTS()
{
}

void BRK()
{
}

void RTI()
{
}

void BIT()
{
}

void NOP()
{
}

void Immediate()
{
	processor.instructionWidth = 2;
	processor.targetData = &memory[processor.PC + 1];
	processor.address = 0;
}

void Absolute()
{
	processor.instructionWidth = 3;
	processor.address = memory[processor.PC + 2];
	processor.address = processor.address << 8;
	processor.address += memory[processor.PC + 1];
	processor.targetData = &memory[processor.address];
}

void ZeroPage()
{
	processor.instructionWidth = 2;
	processor.address = memory[processor.PC + 1];
	processor.targetData = &memory[processor.address];
}

void Indirect()
{
	processor.instructionWidth = 3;
	uint16_t tempAddress = memory[processor.PC + 2];
	tempAddress = tempAddress << 8;
	tempAddress += memory[processor.PC + 1];

	processor.address = memory[tempAddress + 1];
	processor.address << 8;
	processor.address += memory[tempAddress];
	processor.targetData = 0;
}

void Relative()
{
	processor.address = 0;
	processor.targetData = &memory[processor.PC + 1];
}

void Accumulator()
{
	processor.address = 0;
	processor.targetData = &processor.A;
}
CPU processor;