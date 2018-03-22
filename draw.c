#include <stdio.h>
#include "sna.h"

int read_impl(draw_obj *obj, node in)
{
    int n = obj->coor[in.x][in.y];
    
    return n;
}

int write_impl(draw_obj *obj, node *list, char ch)
{
    node *reg = list;

    do
    {
        obj->coor[reg->x][reg->y] = ch;
        reg = reg->next;
    }while(reg != list);

    return 0;
}

int print_impl(draw_obj *obj, int score)
{
    int x, y;

    os_clean();
    for(y = 0; y < MAX_Y; y++)
    {
        for(x = 0; x < MAX_X; x++)
            putchar((char)obj->coor[x][y]);
        putchar('\n');
    }
    printf("¤À¼Æ:%d\n", score);

    for(y = 0; y < MAX_Y; y++)      //coor clean
        for(x = 0; x < MAX_X; x++)
            obj->coor[x][y] = ' ';
    
    return 0;
}
