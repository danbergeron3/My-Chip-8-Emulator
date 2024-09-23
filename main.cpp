#include "chip8.hpp"

Chip8 chip8;

int main(int argc, char** argv) {

	// setup graphics
	//setupGraphics();
	//setupInput();

	// Initialize the Chip8 system and laod the game into the memory 
	chip8.initialize();
	chip8.load("pong");

	// for (;;) {
		// emulate one cycle 
		chip8.emulateCycle();

		if (chip8.drawFlag) {
			//drawGraphics();
		}

		// store key press state (press and release)
		chip8.setKeys();
	// }

	return 0;
}