/** @file   rps.c
    @author R. Ross, J. Spiers
    @date   17 October 2023
    @brief  Rock, Paper, Scissors Fundamentals

    @defgroup rps RPS module

    This module provides rock, paper, scissors game logic and
    reset function that provide the fundamentals for the game.
    
*/

#ifndef RPS_H
#define RPS_H

#include "system.h"
#include <stdbool.h>

#endif

void game_logic(char *opponent_action, char *user_action, char *state);

void rps_reset (char* user_action, char* opponent_action, char* state, char* user_reset, char* opponent_reset, bool* sent, bool* finished, bool* playagain, 
                bool* sent_reset, bool* answer,bool* reset, int* i);

bool isValidAction(char action);