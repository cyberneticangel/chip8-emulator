/* main.cpp */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

#define RAM_SIZE 4096 // 4 KB of RAM
#define PROGRAM_START 0x200 // Programs start at 0x200

const int INSTRUCTIONS_PER_FRAME = 10; // 10 * 60 = 600 hz
const int TARGET_FPS = 60;
const int FRAME_DURATION_MS = 1000 / TARGET_FPS; // 16.67 ms

/* Timers */
uint8_t delay_timer = 0;
uint8_t sound_timer = 0;
uint32_t last_timer_update = 0;

struct Registers { // Registers V0 - VF
    uint8_t V0;
    uint8_t V1;
    uint8_t V2;
    uint8_t V3;
    uint8_t V4;
    uint8_t V5;
    uint8_t V6;
    uint8_t V7;
    uint8_t V8;
    uint8_t V9;
    uint8_t VA;
    uint8_t VB;
    uint8_t VC;
    uint8_t VD;
    uint8_t VE;
    uint8_t VF;
};

void main(void) {
    bool running = true;
    bool draw_flag = false;
    while(running) {
        // Main loop

    }
    running = false;
}