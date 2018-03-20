#include "sna.h"
#include <stdlib.h>

snake_obj *init_snake()
{
    snake_obj *obj = malloc(sizeof(snake_obj));

    obj->length = 3;
    obj->life = 1;
    obj->score = 0;
    
    obj->body_head = createlist(4);
    //這裡要是起始座標
    setnode(obj->body_head, 0, MAX_X-2, 17);
    setnode(obj->body_head, 1, MAX_X-2, 18);
    setnode(obj->body_head, 2, MAX_X-2, 19);
    setnode(obj->body_head, 3, MAX_X-2, 20);
    obj->dir.x = MAX_X - 2;
    obj->dir.y = 20;
    obj->front = front_impl;
    obj->head = head_impl;
    obj->life_f = life_impl;
    obj->mobile = mobile_impl;

    return obj;
}

draw_obj *init_draw()
{
    draw_obj *obj = malloc(sizeof(draw_obj));
    int x, y;

    for (y = 0; y < MAX_Y; y++)      //coor clean
        for (x = 0; x < MAX_X; x++)
            obj->coor[x][y] = ' ';
    obj->read = read_impl;
    obj->write = write_impl;
    obj->print = print_impl;

    return obj;
}

scenes_obj *init_scenes()
{
    scenes_obj *obj = malloc(sizeof(scenes_obj));
    int i, j = 0;

    obj->food_head = createlist(1);
    setnode(obj->food_head, 0, MAX_X - 5, MAX_Y - 5);
    obj->wall_head = createlist(MAX_X*2 + MAX_Y*2);
    obj->food = food_impl;
    obj->wall = wall_impl;


    for(i = 0; i < MAX_X; i++)
    {
        setnode(obj->wall_head, j++, i, 0);        
        setnode(obj->wall_head, j++, i, MAX_Y - 1);        
    }
    for(i = 0 ; i < MAX_Y; i++)
    {
        setnode(obj->wall_head, j++, 0, i);        
        setnode(obj->wall_head, j++, MAX_X - 1, i);        
    }

    return obj;
}
