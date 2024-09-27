#include "chip8.hpp"


void Chip8::initialize(void) {
	
	std::cout << "initializing \n";
	
	pc		= 0x200;		// program counter start index
	opcode	= 0;			// reset Opcode to 0
	I		= 0;			// reset index register to 0


	// Reset / Rerender Display
	// Clear stack 
	// Clear registers V0-VF
	// clear memory

	// load fontset
	for (int i = 0; i < FONTSET_SIZE; i++) {
		memory[i] = chip8_fontset[i];
	}


	return;
}


// (TODO:) GET working tommorow
void Chip8::load(char appName[]) {
	printf("Loading %s", appName);

	FILE* buffer; // file handle
	buffer					= fopen(appName, "rb");
	int bufferSize			= sizeof(buffer);

	if (!buffer || bufferSize <= 0) {// if file is not null
		printf("Error loading application, something went wrong");
		return;
	}
	
	for (int i = 0; i < bufferSize; ++i) {
		memory[i + APPLICATION_MEM_INDEX] = ((unsigned char)buffer[i]); // FIx
	}
	
	fclose(buffer);
	return;
}

void Chip8::emulateCycle(void) {
	std::cout << "emulating cycle \n";
	return;
}

void Chip8::setKeys(void) {
	std::cout << "pressing key \n";
	return;
}

void Chip8::fetchOpcode(void) {

}
