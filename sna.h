#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77
#define MAX_X 50
#define MAX_Y 20

typedef struct node   node;
typedef struct snake  snake_obj;
typedef struct draw   draw_obj;
typedef struct scenes scenes_obj;

struct node
{
    int x;
    int y;
	struct node *next;
};

struct snake
{
	int length;
    int life;
    int score;
	node dir;
	node *body_head;
	node (*front)(snake_obj *);
	node *(*head)(snake_obj *);
	int (*life_f)(snake_obj *, int);
	int (*mobile)(snake_obj *, int);
};

struct draw
{
    int coor[MAX_X][MAX_Y];
	int (*read)(draw_obj *, node);
	int (*write)(draw_obj *, node *, char);
    int (*print)(draw_obj *);
};

struct scenes
{
	node *wall_head;
	node *food_head;
    node *(*food)(scenes_obj *, int);
	node *(*wall)(scenes_obj *);
};

//func
int game_start(void);

//linked list
node *createlist(int);
node *update(node *, node);
int setnode(node *, int, int, int);
int addnode(node **, node);
int delnode(node *);

//snake
int mobile_impl(snake_obj *, int);
int life_impl(snake_obj *, int);
node front_impl(snake_obj *);
node *head_impl(snake_obj *obj);

//draw
int read_impl(draw_obj *, node);
int write_impl(draw_obj *, node *, char);
int print_impl(draw_obj *);

//scenes
node *food_impl(scenes_obj *, int);
node *wall_impl(scenes_obj *);

//init
snake_obj  *init_snake(void);
draw_obj   *init_draw(void);
scenes_obj *init_scenes(void);

//os
int  os_keyboard(void);
void os_clean(void);
void os_sleep(int);
