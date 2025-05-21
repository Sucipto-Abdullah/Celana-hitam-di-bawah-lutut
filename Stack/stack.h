#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef struct node_stack *dosa;
struct node_stack
{
    std::string kelakuan, waktu;
    int point;
    bool jariah;
    dosa next;

    node_stack( std::string Kelakuan, int Point, std::string Waktu, bool Jariah )
    {
        next = NULL;
        kelakuan = Kelakuan;
        waktu = Waktu;
        jariah = Jariah;
        point = Point;
    }
};

struct stack
{
    dosa top;

    stack();
    void push(dosa dosa);
    void tobat();
    void display();
};

#endif