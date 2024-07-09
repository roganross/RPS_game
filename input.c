/** @file   input.c
    @author R. Ross, J. Spiers
    @date   17 October 2023
    @brief  Rock, Paper, Scissors Inputs Module
*/

#include "system.h"
#include "input.h"
#include "navswitch.h"
#include "ir_uart.h"
#include <stdbool.h>
#include "tinygl.h"

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


void rps_input(char* user_action, bool* sent)
/*Takes the users input from the navigation switch and gives a corrsponding action*/
{
    if (navswitch_push_event_p(NAVSWITCH_NORTH))
        {
            *user_action = 'P'; 
        }
        if (navswitch_push_event_p(NAVSWITCH_EAST))
        {
            *user_action = 'S';
        }
        if (navswitch_push_event_p(NAVSWITCH_WEST))
        {
            *user_action = 'R';
        }
        if (navswitch_push_event_p(NAVSWITCH_PUSH))
        {
            ir_uart_putc(*user_action);
            *sent = true;
        }
}


void yes_no_input (char *user_reset, bool *sent_reset)
/*Takes the input from the navswitch and changes the value at the given address*/
{
    if (navswitch_push_event_p(NAVSWITCH_NORTH))
        {
            *user_reset = 'Y';
        }
        if (navswitch_push_event_p(NAVSWITCH_SOUTH))
        {
            *user_reset = 'N';
        }
        if (navswitch_push_event_p(NAVSWITCH_PUSH))
        {
            ir_uart_putc(*user_reset);
            *sent_reset = true;
        }
}