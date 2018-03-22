#include "menu.h"
#include "sna.h"

int menu()
{
    while(1)
        switch(print_menu())
        {
            case 0:
                start_game();
                break;
            case 1:
                top();
                break;
            case 2:
                s_exit();
                break;
        }

    return 0;
}

int print_menu()
{
    draw_obj *obj = init_draw();
}
