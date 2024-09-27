#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

const int MEMORY_SIZE				= 4096;
const int NUMBER_OF_REGISTERS		= 16;
const int SCREEN_WIDTH				= 64;
const int SCREEN_HEIGHT				= 32;
const int STACK_SIZE				= 16;
const int KEY_SIZE					= 16;
const int FONTSET_SIZE				= 80;
const int APPLICATION_MEM_INDEX	= 512; // 0X200


const unsigned char chip8_fontset[FONTSET_SIZE] =
{
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

class Chip8 {
public:
	// init
	void initialize(void);

	// load application code 
	void load(char  appName[]);

	// emulate a cycle
	void emulateCycle(void);

	// set current key press
	void setKeys(void);

	void fetchOpcode(void);

	bool drawFlag;

private:
	// stores 35 opcodes each two bytes long
	unsigned short opcode; // unsigned short is two bytes

	// allocate 4096 bytes for memmory
	unsigned char memory[MEMORY_SIZE];

	// 16 8 bit registers
	unsigned char V[NUMBER_OF_REGISTERS];

	// index register & program counter
	unsigned short I;
	unsigned short pc;

	/*
	* 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
	* 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
	* 0x200-0xFFF - Program ROM and work RAM
	*/

	// graphics for 2048 pixle 
	unsigned char gfx[SCREEN_WIDTH * SCREEN_HEIGHT];

	unsigned char delay_timer; // 60hz delay timer 
	unsigned char sound_timer; // 60hz sound timer 

	// program stack
	unsigned short stack[STACK_SIZE];
	unsigned short sp;

	unsigned char key[KEY_SIZE];
};