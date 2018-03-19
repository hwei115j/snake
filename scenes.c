#include "sna.h"
#include <stdlib.h>
#include <time.h>

node *food_impl(scenes_obj *obj, int food)
{
    if(food)
        return obj->food_head;

    srand(time(NULL));
    setnode(obj->food_head, 0, rand()%MAX_X + 1, rand()%MAX_Y + 1); 
    
    return obj->food_head;
}

node *wall_impl(scenes_obj *obj)
{
    return obj->wall_head;
}
