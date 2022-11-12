
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
	printf("PC: 0x%04X, ",processor.PC);
	processor.instructionWidth = 0;
	//Set memory addressing mode of opcode
	processor.addressMode = addressingTable[memory[processor.PC]];
	//Set instruction to be used by opcode
	processor.opcode = instructionTable[memory[processor.PC]];
	processor.PC += 1;
	if(processor.addressMode != NULL)
		(processor.addressMode)();
	if (processor.opcode != NULL)
		(processor.opcode)();
	Debug();
}

void Debug()
{
	printf("A: 0x%02X, X: 0x%02X, Y: 0x%02X, SP: 0x%02X | Opcode: 0x%02X, Data: 0x%02X, Address: 0x%04X\n", processor.A, processor.X, processor.Y, processor.SP, memory[processor.PC], *processor.targetData, processor.address);
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

void Immediate(){
	processor.instructionWidth = 1;
	processor.targetData = &memory[processor.PC];
	processor.address = 0;
	processor.PC += 1;
}

void Absolute(){
	processor.instructionWidth = 2;
	processor.address = memory[processor.PC + 1];
	processor.address = processor.address << 8;
	processor.address += memory[processor.PC];
	processor.targetData = &memory[processor.address];
	processor.PC += 2;
}

void ZeroPage(){
	processor.instructionWidth = 1;
	processor.address = memory[processor.PC];
	processor.targetData = &memory[processor.address];
	processor.PC += 1;
}

void Indirect(){
	processor.instructionWidth = 2;
	uint16_t tempAddress = memory[processor.PC + 1];
	tempAddress = tempAddress << 8;
	tempAddress += memory[processor.PC];

	processor.address = memory[tempAddress + 1];
	processor.address << 8;
	processor.address += memory[tempAddress];
	processor.targetData = 0;
	processor.PC += 2;
}

void Relative(){
	processor.instructionWidth = 1;
	processor.address = 0;
	processor.targetData = &memory[processor.PC];
	processor.PC += 1;
}

void Accumulator(){
	processor.instructionWidth = 0;
	processor.address = 0;
	processor.targetData = &processor.A;
}

void AbsoluteX(){
	processor.instructionWidth = 2;
	processor.address = memory[processor.PC + 1];
	processor.address = processor.address << 8;
	processor.address += memory[processor.PC];
	processor.address += processor.X;
	processor.PC += 2;
}

void AbsoluteY(){
	processor.instructionWidth = 2;
	processor.address = memory[processor.PC + 1];
	processor.address = processor.address << 8;
	processor.address += memory[processor.PC];
	processor.address += processor.Y;
	processor.PC += 2;
}

void IndirectX(){
	processor.instructionWidth = 2;
	uint16_t tempAddress = memory[processor.PC + 1];
	tempAddress = tempAddress << 8;
	tempAddress += memory[processor.PC];
	tempAddress += processor.X;

	processor.address = memory[tempAddress + 1];
	processor.address << 8;
	processor.address += memory[tempAddress];
	processor.targetData = 0;
	processor.PC += 2;
}

void IndirectY(){
	processor.instructionWidth = 2;
	uint16_t tempAddress = memory[processor.PC + 1];
	tempAddress = tempAddress << 8;
	tempAddress += memory[processor.PC];

	processor.address = memory[tempAddress + 1];
	processor.address << 8;
	processor.address += memory[tempAddress];
	processor.address += processor.Y;
	processor.targetData = 0;
	processor.PC += 2;
}

void Implied(){
	//No operation, empty function.
}

void SetBit7(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x80;
	}
	else{
		processor.Flag = processor.Flag & 0x7F;
	}
}

void SetBit6(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x40;
	}
	else{
		processor.Flag = processor.Flag & 0xBF;
	}
}

void SetBit5(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x20;
	}
	else{
		processor.Flag = processor.Flag & 0xDF;
	}
}

void SetBit4(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x10;
	}
	else{
		processor.Flag = processor.Flag & 0xEF;
	}
}

void SetBit3(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x08;
	}
	else{
		processor.Flag = processor.Flag & 0xF7;
	}
}

void SetBit2(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x04;
	}
	else{
		processor.Flag = processor.Flag & 0xFB;
	}
}

void SetBit1(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x02;
	}
	else{
		processor.Flag = processor.Flag & 0xFD;
	}
}

void SetBit0(int bit){
	if(bit == 1){
		processor.Flag = processor.Flag | 0x01;
	}
	else{
		processor.Flag = processor.Flag & 0xFE;
	}
}

CPU processor;