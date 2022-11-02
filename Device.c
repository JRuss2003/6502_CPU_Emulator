#include "Device.h"
#include "CPU.h"
#include "Memory.h"

int deviceState;

void EmulationLoop() {
	while (processor.PC < MAX_MEMORY) {
		CPU_FDE();
		
	}
}

void LoadProgram() {
	FILE* program_p = fopen("Programs/hello.p65", "rb");
	fread(&memory[0x1FA], sizeof(memory), 1, program_p);
	fclose(program_p);
}