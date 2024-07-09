/** @file   rps.c
    @author R. Ross, J. Spiers
    @date   17 October 2023
    @brief  Rock, Paper, Scissors Module
*/

#include "system.h"
#include "rps.h"
#include <stdbool.h>

bool isValidAction(char action) 
/* Checks that the action entered is valid for Paper, Scissors, Rock*/
{
    return action == 'P' || action == 'R' || action == 'S';
}

void game_logic(char *opponent_action, char *user_action, char *state)
/* Takes the user's action and the opponents action and determines which player is the victor*/
{
    if (*user_action == 'R') {
        if (*opponent_action == 'R') {
            *state = 'D';
            }
        if (*opponent_action == 'S') {
            *state = 'W';
            }
        if (*opponent_action == 'P') {
            *state = 'L';
        }
        }
    if (*user_action == 'P') {
        if (*opponent_action == 'P') {
            *state = 'D';
        }
        if (*opponent_action == 'R') {
            *state = 'W';
        }
        if (*opponent_action == 'S') {
            *state = 'L';
        }
    }
    if (*user_action == 'S') {
        if (*opponent_action == 'S') {
            *state = 'D';
        }
        if (*opponent_action == 'P') {
            *state = 'W';
            }
        if (*opponent_action == 'R') {
            *state = 'L';
        }
    }
}

void rps_reset (char* user_action, char* opponent_action, char* state, char* user_reset, char* opponent_reset, bool* sent, bool* finished, bool* playagain, 
    bool* sent_reset, bool* answer,bool* reset, int* i) 
/* Resets the parameters of the game so a new one may commmence*/
                {
                    *user_action = '?';
                    *opponent_action = '?';
                    *state = '?';
                    *user_reset = '?';
                    *opponent_reset = '?';
                    *sent = false;
                    *finished = false;
                    *playagain = false;
                    *sent_reset = false;
                    *answer = false;
                    *reset = false;
                    *i = 0;
                }