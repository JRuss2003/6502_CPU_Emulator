
#include "CPU.h"
#include "Memory.h"

void (*instructionTable[256])();
void (*addressingTable[256])();

void CPU_Start()
{
	//Populate instruction table
	instructionTable[0x00] = &BRK;
	instructionTable[0x01] = &ORA;
	instructionTable[0x05] = &ORA;
	instructionTable[0x06] = &ASL;
	instructionTable[0x08] = &PHP;
	instructionTable[0x09] = &ORA;
	instructionTable[0x0A] = &ASL;
	instructionTable[0x0D] = &ORA;
	instructionTable[0x0E] = &ASL;

	instructionTable[0x10] = &BPL;
	instructionTable[0x11] = &ORA;
	instructionTable[0x15] = &ORA;
	instructionTable[0x16] = &ASL;
	instructionTable[0x18] = &CLC;
	instructionTable[0x19] = &ORA;
	instructionTable[0x1D] = &ORA;
	instructionTable[0x1E] = &ASL;

	instructionTable[0x20] = &JSR;
	instructionTable[0x21] = &AND;
	instructionTable[0x24] = &BIT;
	instructionTable[0x25] = &AND;
	instructionTable[0x26] = &ROL;
	instructionTable[0x28] = &PLP;
	instructionTable[0x29] = &AND;
	instructionTable[0x2A] = &ROL;
	instructionTable[0x2C] = &BIT;
	instructionTable[0x2D] = &AND;
	instructionTable[0x2E] = &ROL;

	instructionTable[0x30] = &BMI;
	instructionTable[0x31] = &AND;
	instructionTable[0x35] = &AND;
	instructionTable[0x36] = &ROL;
	instructionTable[0x38] = &SEC;
	instructionTable[0x39] = &AND;
	instructionTable[0x3D] = &AND;
	instructionTable[0x3E] = &ROL;

	instructionTable[0x40] = &RTI;
	instructionTable[0x41] = &EOR;
	instructionTable[0x45] = &EOR;
	instructionTable[0x46] = &LSR;
	instructionTable[0x48] = &PHA;
	instructionTable[0x49] = &EOR;
	instructionTable[0x4A] = &LSR;
	instructionTable[0x4C] = &JMP;
	instructionTable[0x4D] = &EOR;
	instructionTable[0x4E] = &LSR;

	instructionTable[0x50] = &BVC;
	instructionTable[0x51] = &EOR;
	instructionTable[0x55] = &EOR;
	instructionTable[0x56] = &LSR;
	instructionTable[0x58] = &CLI;
	instructionTable[0x59] = &EOR;
	instructionTable[0x5D] = &EOR;
	instructionTable[0x5E] = &LSR;

	instructionTable[0x60] = &RTS;
	instructionTable[0x61] = &ADC;
	instructionTable[0x65] = &ADC;
	instructionTable[0x66] = &ROR;
	instructionTable[0x68] = &PLA;
	instructionTable[0x69] = &ADC;
	instructionTable[0x6A] = &ROR;
	instructionTable[0x6C] = &JMP;
	instructionTable[0x6D] = &ADC;
	instructionTable[0x6E] = &ROR;

	instructionTable[0x70] = &BVS;
	instructionTable[0x71] = &ADC;
	instructionTable[0x75] = &ADC;
	instructionTable[0x76] = &ROR;
	instructionTable[0x78] = &SEI;
	instructionTable[0x79] = &ADC;
	instructionTable[0x7D] = &ADC;
	instructionTable[0x7E] = &ROR;

	instructionTable[0x81] = &STA;
	instructionTable[0x84] = &STY;
	instructionTable[0x85] = &STY;
	instructionTable[0x86] = &STX;
	instructionTable[0x88] = &DEY;
	instructionTable[0x8A] = &TXA;
	instructionTable[0x8C] = &STY;
	instructionTable[0x8D] = &STA;
	instructionTable[0x8E] = &STX;

	instructionTable[0x90] = &BCC;
	instructionTable[0x91] = &STA;
	instructionTable[0x94] = &STY;
	instructionTable[0x95] = &STA;
	instructionTable[0x96] = &STX;
	instructionTable[0x98] = &TYA;
	instructionTable[0x99] = &STA;
	instructionTable[0x9A] = &TXS;
	instructionTable[0x9D] = &STA;

	instructionTable[0xA0] = &LDY;
	instructionTable[0xA1] = &LDA;
	instructionTable[0xA2] = &LDX;
	instructionTable[0xA4] = &LDY;
	instructionTable[0xA5] = &LDA;
	instructionTable[0xA6] = &LDX;
	instructionTable[0xA8] = &TAY;
	instructionTable[0xA9] = &LDA;
	instructionTable[0xAA] = &TAX;
	instructionTable[0xAC] = &LDY;
	instructionTable[0xAD] = &LDA;
	instructionTable[0xAE] = &LDX;

	instructionTable[0xB0] = &BCS;
	instructionTable[0xB1] = &LDA;
	instructionTable[0xB4] = &LDY;
	instructionTable[0xB5] = &LDA;
	instructionTable[0xB6] = &LDX;
	instructionTable[0xB8] = &CLV;
	instructionTable[0xB9] = &LDA;
	instructionTable[0xBA] = &TSX;
	instructionTable[0xBC] = &LDY;
	instructionTable[0xBD] = &LDA;
	instructionTable[0xBE] = &LDX;

	instructionTable[0xC0] = &CPY;
	instructionTable[0xC1] = &CMP;
	instructionTable[0xC4] = &CPY;
	instructionTable[0xC5] = &CMP;
	instructionTable[0xC6] = &DEC;
	instructionTable[0xC8] = &INY;
	instructionTable[0xC9] = &CMP;
	instructionTable[0xCA] = &DEX;
	instructionTable[0xCC] = &CPY;
	instructionTable[0xCD] = &CMP;
	instructionTable[0xCE] = &DEC;

	instructionTable[0xD0] = &BNE;
	instructionTable[0xD1] = &CMP;
	instructionTable[0xD5] = &CMP;
	instructionTable[0xD6] = &DEC;
	instructionTable[0xD8] = &CLD;
	instructionTable[0xD9] = &CMP;
	instructionTable[0xDD] = &CMP;
	instructionTable[0xDE] = &DEC;

	instructionTable[0xE0] = &CPX;
	instructionTable[0xE1] = &SBC;
	instructionTable[0xE4] = &CPX;
	instructionTable[0xE5] = &SBC;
	instructionTable[0xE6] = &INC;
	instructionTable[0xE8] = &INX;
	instructionTable[0xE9] = &SBC;
	instructionTable[0xEA] = &NOP;
	instructionTable[0xEC] = &CPX;
	instructionTable[0xED] = &SBC;
	instructionTable[0xEE] = &INC;

	instructionTable[0xF0] = &BEQ;
	instructionTable[0xF1] = &SBC;
	instructionTable[0xF5] = &SBC;
	instructionTable[0xF6] = &INC;
	instructionTable[0xF8] = &SED;
	instructionTable[0xF9] = &SBC;
	instructionTable[0xFD] = &SBC;
	instructionTable[0xFE] = &INC;

	//Populate address table
	addressingTable[0x00] = &Implied;
	addressingTable[0x01] = &IndirectX;
	addressingTable[0x05] = &ZeroPage;
	addressingTable[0x06] = &ZeroPage;
	addressingTable[0x08] = &Implied;
	addressingTable[0x09] = &Immediate;
	addressingTable[0x0A] = &Accumulator;
	addressingTable[0x0D] = &Absolute;
	addressingTable[0x0E] = &Absolute;

	addressingTable[0x10] = &Relative;
	addressingTable[0x11] = &IndirectY;
	//addressingTable[0x15] = &;
	//addressingTable[0x16] = &ASL;
	addressingTable[0x18] = &Implied;
	addressingTable[0x19] = &AbsoluteY;
	addressingTable[0x1D] = &AbsoluteX;
	addressingTable[0x1E] = &AbsoluteX;

	addressingTable[0x20] = &Absolute;
	addressingTable[0x21] = &IndirectX;
	addressingTable[0x24] = &ZeroPage;
	addressingTable[0x25] = &ZeroPage;
	addressingTable[0x26] = &ZeroPage;
	addressingTable[0x28] = &Implied;
	addressingTable[0x29] = &Immediate;
	addressingTable[0x2A] = &Accumulator;
	addressingTable[0x2C] = &Absolute;
	addressingTable[0x2D] = &Absolute;
	addressingTable[0x2E] = &Absolute;

	addressingTable[0x30] = &Relative;
	addressingTable[0x31] = &IndirectY;
	//addressingTable[0x35] = &AND;
	//addressingTable[0x36] = &ROL;
	addressingTable[0x38] = &Implied;
	addressingTable[0x39] = &AbsoluteY;
	addressingTable[0x3D] = &AbsoluteX;
	addressingTable[0x3E] = &AbsoluteX;

	addressingTable[0x40] = &Implied;
	addressingTable[0x41] = &IndirectX;
	addressingTable[0x45] = &ZeroPage;
	addressingTable[0x46] = &ZeroPage;
	addressingTable[0x48] = &Implied;
	addressingTable[0x49] = &Immediate;
	addressingTable[0x4A] = &Accumulator;
	addressingTable[0x4C] = &Absolute;
	addressingTable[0x4D] = &Absolute;
	addressingTable[0x4E] = &Absolute;

	addressingTable[0x50] = &Relative;
	addressingTable[0x51] = &IndirectY;
	//addressingTable[0x55] = &EOR;
	//addressingTable[0x56] = &LSR;
	addressingTable[0x58] = &Implied;
	addressingTable[0x59] = &AbsoluteY;
	addressingTable[0x5D] = &AbsoluteX;
	addressingTable[0x5E] = &AbsoluteX;

	addressingTable[0x60] = &Implied;
	addressingTable[0x61] = &IndirectX;
	addressingTable[0x65] = &ZeroPage;
	addressingTable[0x66] = &ZeroPage;
	addressingTable[0x68] = &Implied;
	addressingTable[0x69] = &Immediate;
	addressingTable[0x6A] = &Accumulator;
	addressingTable[0x6C] = &Indirect;
	addressingTable[0x6D] = &Absolute;
	addressingTable[0x6E] = &Absolute;

	addressingTable[0x70] = &Relative;
	addressingTable[0x71] = &IndirectY;
	//addressingTable[0x75] = &ADC;
	//addressingTable[0x76] = &ROR;
	addressingTable[0x78] = &Implied;
	addressingTable[0x79] = &AbsoluteY;
	addressingTable[0x7D] = &AbsoluteX;
	addressingTable[0x7E] = &AbsoluteX;

	addressingTable[0x81] = &IndirectX;
	addressingTable[0x84] = &ZeroPage;
	addressingTable[0x85] = &ZeroPage;
	addressingTable[0x86] = &ZeroPage;
	addressingTable[0x88] = &Implied;
	addressingTable[0x8A] = &Implied;
	addressingTable[0x8C] = &Absolute;
	addressingTable[0x8D] = &Absolute;
	addressingTable[0x8E] = &Absolute;

	addressingTable[0x90] = &Relative;
	addressingTable[0x91] = &IndirectY;
	//addressingTable[0x94] = &STY;
	//addressingTable[0x95] = &STA;
	//addressingTable[0x96] = &STX;
	addressingTable[0x98] = &Implied;
	addressingTable[0x99] = &AbsoluteY;
	addressingTable[0x9A] = &Implied;
	addressingTable[0x9D] = &AbsoluteX;

	addressingTable[0xA0] = &Immediate;
	addressingTable[0xA1] = &IndirectX;
	addressingTable[0xA2] = &Immediate;
	addressingTable[0xA4] = &ZeroPage;
	addressingTable[0xA5] = &ZeroPage;
	addressingTable[0xA6] = &ZeroPage;
	addressingTable[0xA8] = &Implied;
	addressingTable[0xA9] = &Immediate;
	addressingTable[0xAA] = &Implied;
	addressingTable[0xAC] = &Absolute;
	addressingTable[0xAD] = &Absolute;
	addressingTable[0xAE] = &Absolute;

	addressingTable[0xB0] = &Relative;
	addressingTable[0xB1] = &IndirectY;
	//addressingTable[0xB4] = &LDY;
	//addressingTable[0xB5] = &LDA;
	//addressingTable[0xB6] = &LDX;
	addressingTable[0xB8] = &Implied;
	addressingTable[0xB9] = &AbsoluteY;
	addressingTable[0xBA] = &Implied;
	addressingTable[0xBC] = &AbsoluteX;
	addressingTable[0xBD] = &AbsoluteX;
	addressingTable[0xBE] = &AbsoluteY;

	addressingTable[0xC0] = &Immediate;
	addressingTable[0xC1] = &IndirectX;
	addressingTable[0xC4] = &ZeroPage;
	addressingTable[0xC5] = &ZeroPage;
	addressingTable[0xC6] = &ZeroPage;
	addressingTable[0xC8] = &Implied;
	addressingTable[0xC9] = &Immediate;
	addressingTable[0xCA] = &Implied;
	addressingTable[0xCC] = &Absolute;
	addressingTable[0xCD] = &Absolute;
	addressingTable[0xCE] = &Absolute;

	addressingTable[0xD0] = &Relative;
	addressingTable[0xD1] = &IndirectY;
	//addressingTable[0xD5] = &CMP;
	//addressingTable[0xD6] = &DEC;
	addressingTable[0xD8] = &Implied;
	addressingTable[0xD9] = &AbsoluteY;
	addressingTable[0xDD] = &AbsoluteX;
	addressingTable[0xDE] = &AbsoluteX;

	addressingTable[0xE0] = &Immediate;
	addressingTable[0xE1] = &IndirectX;
	addressingTable[0xE4] = &ZeroPage;
	addressingTable[0xE5] = &ZeroPage;
	addressingTable[0xE6] = &ZeroPage;
	addressingTable[0xE8] = &Implied;
	addressingTable[0xE9] = &Immediate;
	addressingTable[0xEA] = &Implied;
	addressingTable[0xEC] = &Absolute;
	addressingTable[0xED] = &Absolute;
	addressingTable[0xEE] = &Absolute;

	addressingTable[0xF0] = &Relative;
	addressingTable[0xF1] = &IndirectY;
	//addressingTable[0xF5] = &SBC;
	//addressingTable[0xF6] = &INC;
	addressingTable[0xF8] = &Implied;
	addressingTable[0xF9] = &AbsoluteY;
	addressingTable[0xFD] = &AbsoluteX;
	addressingTable[0xFE] = &AbsoluteX;

	//Init registers
	processor.PC = 0x200;
	processor.Flag = 0x00;
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
	processor.instructionWidth = 1;
	uint16_t tempAddress = memory[processor.PC];
	tempAddress += processor.X;

	processor.address = memory[tempAddress + 1];
	processor.address << 8;
	processor.address += memory[tempAddress];

	processor.targetData = 0;
	processor.PC += 1;
}

void IndirectY(){
	processor.instructionWidth = 1;
	uint16_t tempAddress = memory[processor.PC];

	processor.address = memory[tempAddress + 1];
	processor.address << 8;
	processor.address += memory[tempAddress];
	processor.address += processor.Y;

	processor.targetData = 0;
	processor.PC += 1;
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