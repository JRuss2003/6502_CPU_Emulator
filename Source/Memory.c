#include "Memory.h"

uint8_t memory[MAX_MEMORY];

void MemoryMap() {
	for (int c = 0; c < sizeof(memory); c++) {
		printf("0x%02X, ", memory[c]);
	}
	printf("\n");
}