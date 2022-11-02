#include "Device.h"
#include "CPU.h"
#include "Memory.h"

int main(int argc, char* argv[]) {
	CPU_Start();
	LoadProgram();
	EmulationLoop();
	return 0;
}
