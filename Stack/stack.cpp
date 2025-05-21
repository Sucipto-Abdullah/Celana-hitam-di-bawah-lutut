#include "stack.h"

stack::stack()
{
    top = NULL;
}

void stack::push(dosa dosa)
{
    if( top == NULL )
    {
        top = dosa;
    }
    else{
        dosa->next = top;
        top = dosa;
    }
}

void stack::tobat()
{
    if( top != NULL )
    {
        dosa target = top;
        top = target->next;
        target->next = NULL;
        delete target;
    }
}

void stack::display()
{
    dosa index = top;
    int index_number = 1;
    while (index != NULL)
    {
        std::cout << index_number << ". " << index->kelakuan << "\n";
        std::cout << "\tPoint" << index->point << "\n";
        std::cout << "\tWaktu" << index->waktu << "\n";
        std::cout << "\tStatus" << index->jariah << "\n";
        index = index->next;
        index_number ++;
    }
}