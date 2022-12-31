#include "Device.h"
#include "CPU.h"
#include "Memory.h"

int deviceState;

void EmulationLoop() {
	while (processor.PC < MAX_MEMORY && deviceState == 1) {
		CPU_FDE();
		
	}
}

void LoadProgram() {
	FILE* program_p = fopen("Programs/6502_opcode_test.bin", "rb");
	fread(&memory[0x00], sizeof(memory), 1, program_p);
	fclose(program_p);
}