#include "linkedlist.h"


void playlist::insertFirst( music item )
{
    if (first == NULL)
    {
        first = item;
        last = item;
    }else{
        item->next = first;
        first->prev = item;
        first = item;
    }
    index_fill ++;
}
void playlist::insertLast( music item )
{
    if( first == NULL )
    {
        first = item;
        last = item;
    }
    else
    {
        last->next = item;
        item->prev = last;
        last = item;
    }
    index_fill ++;
}
void playlist::insertAfter(music target, music item)
{
    item->next = target->next;
    item->prev = target;

    target->next->prev = item;
    target->next = item;
    index_fill ++;
}
void playlist::insertBefore(music target, music item)
{
    item->next = target;
    item->prev = target->prev;

    target->prev->next = item;
    target->prev = item;
    index_fill ++;
}
void playlist::deleteItem(music item)
{
    if( first == item )
    {
        first = item->next;
        first->prev = NULL;
        item->next = NULL;
        delete item;
    }
    else if ( last == item )
    {
        last = item->prev;
        last->next = NULL;
        item->prev = NULL;
        delete item;
    }
    else {
        item->prev->next = item->next;
        item->next->prev = item->prev;

        item->next = NULL;
        item->prev = NULL;

        delete item;
    }
    index_fill --;
}
void playlist::display()
{
    music index = first;

    for(int i = 0; i< index_fill; i++)
    {
        std::cout << i+1 << ". " << index->nama << "\n";
        std::cout << "\tartis: " << index->artis << "\n";
        std::cout << "\tdurasi: " << index->durasi << "\n";
        std::cout << "\tlabel: " << index->label << "\n\n";
        index = index->next;
    }
}