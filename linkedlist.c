#include <stdio.h>
#include <stdlib.h>
#include "sna.h"

node *createlist(int n)
{
    node *head = malloc(sizeof(node));
    node *reg = head;
    head->next = head;

    while(--n)
    {
        reg->next = malloc(sizeof(node));
        reg = reg->next;
        reg->next = head;
    }

    return head;
}

int addnode(node **head, node in)    //新增節點，節點內容為in
{
    node *reg = *head;
    
    while(reg->next != *head)
        reg = reg->next;
    
    reg->next = malloc(sizeof(node));
    reg = reg->next;
    *reg = in;
    reg->next = *head;
    *head = reg;

    return 0;
}

int delnode(node *head)
{
    node *reg = head;

    while(reg->next->next != head)
        reg = reg->next;
    free(reg->next);
    reg->next = head;

    return 0;
}

node *update(node *head, node in)   //將最尾端的節點內容改為in，且將head指向尾端，傳回新head
{
    node *reg = head;

    while(reg->next != head)
        reg = reg->next;
    *reg = in;
    reg->next = head;
    
    return reg;
}

int setnode(node *head, int n, int x, int y)
{
    node *reg = head;

    while(n--)
        reg = reg->next;
    
    reg->x = x;
    reg->y = y;

    return 0;
}

