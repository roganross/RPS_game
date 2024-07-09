/** @file   input.c
    @author R. Ross, J. Spiers
    @date   19 October 2023
    @brief  Input and character display

    @defgroup input module

    This module provides the input commands and functionality
    for the navswitches being used

    
*/

#ifndef INPUT_H
#define INPUT_H

#include "navswitch.h"
#include "system.h"
#include "ir_uart.h"
#include <stdbool.h>
#include "tinygl.h"

#endif

void display_character (char character);

void rps_input(char* user_action, bool* sent);

void yes_no_input (char *user_reset, bool *sent_reset);