#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdint.h>
#include <stdio.h>
#define MAX_MEMORY 4096

extern uint8_t memory[MAX_MEMORY];

void MemoryMap();

#endif