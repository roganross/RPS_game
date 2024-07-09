/*Rock Paper Scissors, By Rogan Ross and Julius Spiers*/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "ir_uart.h"
#include <stdbool.h>
#include "timer.h"
#include "rps.h"
#include "input.h"
#define PACER_RATE 500
#define MESSAGE_RATE 20
#define DELAY_TIME 1000
#define SECOND_DELAY 3100

int main (void)
/* Main function for Paper, Scissors, Rock game*/
{
    char user_action = '?';
    char opponent_action = '?';
    char state = '?';
    char user_reset = '?';
    char opponent_reset = '?';
    bool sent = false;
    bool finished = false;
    bool playagain = false;
    bool sent_reset = false;
    bool answer = false;
    bool reset = false;
    int i = 0;

    system_init ();
    timer_init ();

    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    
    navswitch_init();
    pacer_init(PACER_RATE);
    ir_uart_init ();

    while (1)
    {
        pacer_wait();
        tinygl_update();
        navswitch_update();
        rps_input(&user_action, &sent);

        if (!finished) {
            display_character(user_action);
        }

        if (ir_uart_read_ready_p () && !finished) {
            opponent_action = ir_uart_getc ();
        }
        
        if ((isValidAction(opponent_action)) && (isValidAction(user_action)) && sent && !finished) {
            game_logic(&opponent_action, &user_action, &state);
            finished = true;
            }

        if (finished && !playagain) {
            display_character(state);
            if (i == DELAY_TIME) {
                tinygl_text("Play Again");
                playagain = true;
                i = 0;
            }
            i++;
        }

        if (playagain)
        {
            if (i >= SECOND_DELAY)
            {
                yes_no_input(&user_reset, &sent_reset);
                if (!answer)
                {
                    display_character(user_reset);
                }
                if (ir_uart_read_ready_p () && !answer) 
                {
                    opponent_reset = ir_uart_getc ();
                }
                if ((opponent_reset == 'Y' || opponent_reset == 'N') && sent_reset && !answer)
                {
                    if (user_reset == 'Y' && opponent_reset == 'Y')
                    {
                        rps_reset (&user_action, &opponent_action, &state, &user_reset, &opponent_reset, &sent, &finished, &playagain, &sent_reset, &answer, &reset, &i);
                    }
                    else
                    {
                        reset = true;
                    }
            }

            if (reset)
            {
                tinygl_text(" ");
            }
        }

        i++;

        }    
    }
}
