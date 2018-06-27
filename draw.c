#include <stdio.h>
#include "sna.h"

void print_xy(int x, int y, int ch)
{
    gotoxy(x,y);
    printf("%c", ch);
}

int read_impl(draw_obj *obj, node in)
{
    int n = obj->coor[in.x][in.y];
    
    return n;
}

int write_impl(draw_obj *obj, node *list, int ch)
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
    static int coor_reg[MAX_X][MAX_Y] = {0};

#if 0
    os_clean();
    //print_xy(0, 0, ' ');
    for(y = 0; y < MAX_Y; y++)
    {
        for(x = 0; x < MAX_X; x++)
            putchar((char)obj->coor[x][y]);
        putchar('\n');
    }
    printf("分數:%d\n", score);
#endif
#if 1
    for(y = 0; y < MAX_Y; y++)
        for(x = 0; x < MAX_X; x++)
            if(obj->coor[x][y] != coor_reg[x][y]) 
                print_xy(x, y, (char)obj->coor[x][y]);
    for(y = 0; y < MAX_Y; y++)
        for(x = 0; x < MAX_X; x++)
            coor_reg[x][y] = obj->coor[x][y];
    print_xy(0, MAX_Y, ' ' );
    printf("分數:%d\n", score);
#endif
    for(y = 0; y < MAX_Y; y++)      //coor clean
        for(x = 0; x < MAX_X; x++)
            obj->coor[x][y] = ' ';
    
    return 0;
}
