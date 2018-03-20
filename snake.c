#include "sna.h"

int game_start()
{
    snake_obj  *obj_s = init_snake();
    draw_obj   *obj_d = init_draw();
    scenes_obj *obj_c = init_scenes();

    while(obj_s->life_f(obj_s, 1))
    {
        int food = obj_s->mobile(obj_s, obj_d->read(obj_d, obj_s->front(obj_s)));

        obj_d->write(obj_d, obj_c->wall(obj_c), '#');
        obj_d->write(obj_d, obj_s->head(obj_s), '@');
        while (obj_d->read(obj_d, *(obj_c->food(obj_c, food))) != ' ');
        obj_d->write(obj_d, obj_c->food(obj_c, food), '*');
        obj_d->print(obj_d);
        os_sleep(5);
    }

    return 0;
}

int mobile_impl(snake_obj *obj, int ch)
{
    if(ch == ' ')
        obj->body_head = update(obj->body_head, obj->dir);
    else if(ch == '*')
    {
        addnode(&obj->body_head, obj->dir);

        return 0;
    }
    else
        obj->life_f(obj, 0);

    return 1;
}

int life_impl(snake_obj *obj, int n)
{
    return (n)?obj->life:(obj->life = 0);
}

node front_impl(snake_obj *obj)
{
    switch(os_keyboard())
    {
        case UP:
            obj->dir = *(obj->body_head);
            obj->dir.y--;
            break;
        case DOWN:
            obj->dir = *(obj->body_head);
            obj->dir.y++;
            break;
        case LEFT:
            obj->dir = *(obj->body_head);
            obj->dir.x--;
            break;
        case RIGHT:
            obj->dir = *(obj->body_head);
            obj->dir.x++;
            break;
    }

    return obj->dir;
}

node *head_impl(snake_obj *obj)
{
    return obj->body_head;
}
