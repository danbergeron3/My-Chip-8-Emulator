#pragma once
# include <string>
class Chip8 {
 public:
	// init
	void initialize(void);

	// load application code 
	void load(std::string appName);

	// emulate a cycle
	void emulateCycle(void);

	// set current key press
	void setKeys(void);

	bool drawFlag;

 private:
	// stores 35 opcodes each two bytes long
	unsigned short opcode; // unsigned short is two bytes

	// allocate 4096 bytes for memmory
	unsigned char memory[4096];

	// 15 8 bit registers
	unsigned char V[16];

	// index register & program counter
	unsigned short I;
	unsigned short pc;

	/*
	* 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
	* 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
	* 0x200-0xFFF - Program ROM and work RAM
	*/

	// graphics for 2048 pixle 
	unsigned char gfx[64 * 32];

	unsigned char delay_timer; // 60hz delay timer 
	unsigned char sound_timer; // 60hz sound timer 

	// program stack
	unsigned short stack[16];
	unsigned short sp;

	unsigned char key[16];
};

