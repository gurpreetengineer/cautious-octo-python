/**A device driver for a mouse typically involves setting up the appropriate interrupts, initializing the mouse hardware, and reading data from the mouse input port. Here is an example device driver for a PS/2 mouse on a 32-bit x86 architecture system:
*/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "io.h"
#include "interrupts.h"

// Mouse input/output ports
#define MOUSE_DATA_PORT 0x60
#define MOUSE_STATUS_PORT 0x64
#define MOUSE_COMMAND_PORT 0x64

// Mouse commands
#define MOUSE_COMMAND_ENABLE 0xA8
#define MOUSE_COMMAND_DISABLE 0xA7
#define MOUSE_COMMAND_RESET 0xFF

// Mouse status flags
#define MOUSE_STATUS_OUTPUT_BUFFER_FULL 0x01
#define MOUSE_STATUS_INPUT_BUFFER_FULL 0x02
#define MOUSE_STATUS_SYSTEM_FLAG 0x04
#define MOUSE_STATUS_MOUSE_DATA 0x20

// Mouse data packet flags
#define MOUSE_PACKET_LEFT_BUTTON 0x01
#define MOUSE_PACKET_RIGHT_BUTTON 0x02
#define MOUSE_PACKET_MIDDLE_BUTTON 0x04
#define MOUSE_PACKET_X_SIGN 0x10
#define MOUSE_PACKET_Y_SIGN 0x20
#define MOUSE_PACKET_X_OVERFLOW 0x40
#define MOUSE_PACKET_Y_OVERFLOW 0x80

// Mouse state variables
int mouse_x = 0;
int mouse_y = 0;
bool mouse_left_button = false;
bool mouse_right_button = false;
bool mouse_middle_button = false;

// Handle a mouse interrupt
void mouse_interrupt_handler() {
    uint8_t status = inb(MOUSE_STATUS_PORT);
    if (status & MOUSE_STATUS_OUTPUT_BUFFER_FULL) {
        uint8_t data = inb(MOUSE_DATA_PORT);
        if ((status & MOUSE_STATUS_MOUSE_DATA) && (data != 0)) {
            // Process mouse data packet
            int dx = data;
            int dy = 0;
            if (status & MOUSE_PACKET_X_SIGN) {
                dx -= 256;
            }
            if (status & MOUSE_PACKET_Y_SIGN) {
                dy -= 256;
            }
            if (status & MOUSE_PACKET_X_OVERFLOW) {
                dx = 0;
            }
            if (status & MOUSE_PACKET_Y_OVERFLOW) {
                dy = 0;
            }
            mouse_x += dx;
            mouse_y += dy;
            mouse_left_button = data & MOUSE_PACKET_LEFT_BUTTON;
            mouse_right_button = data & MOUSE_PACKET_RIGHT_BUTTON;
            mouse_middle_button = data & MOUSE_PACKET_MIDDLE_BUTTON;
        }
    }
}

// Initialize the mouse driver
void mouse_init() {
    // Enable mouse interrupts
    outb(MOUSE_COMMAND_PORT, MOUSE_COMMAND_ENABLE);

    // Reset the mouse
    outb(MOUSE_COMMAND_PORT, MOUSE_COMMAND_RESET);
    uint8_t data = inb(MOUSE_DATA_PORT);

    // Enable mouse data reporting
    outb(MOUSE_DATA_PORT, 0xF4);
}

// Get the current mouse position
void mouse_get_position(int *x, int *y) {
    *x = mouse_x;
    *y = mouse_y;
}

// Get the state of the mouse buttons
void mouse_get_buttons(bool *left, bool *right, bool *middle) {
    *left = mouse_left_button;
    *right = mouse_right_button;
    *middle = mouse_middle_button;
}

/**
 * This code sets up interrupts for the mouse, initializes the mouse hardware, and provides functions for getting the current mouse position and button state. 
 * The `mouse_interrupt_handler` function is called whenever a mouse interrupt is received, and processes the data packet sent by the mouse to update the mouse position and button state.
*/
