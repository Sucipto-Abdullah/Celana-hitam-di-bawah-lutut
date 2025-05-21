#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

typedef struct Element_list *music;
struct Element_list{
    std::string nama, artis, label;
    float durasi;
    music next, prev;

    Element_list(std::string Nama, std::string Artis, std::string Label, int Durasi)
    {
        nama = Nama;
        artis = Artis;
        label = Label;
        durasi = Durasi;

        next = NULL;
        prev = NULL;
    }

};

struct playlist
{
    private:
    int index_fill = 0;
    bool created = false;

    public:
    music first, last;
    std::string name;

    playlist(std::string playlist_name){
        if( !created )
        {
            name = playlist_name;
            first = NULL;
            last = NULL;
            created = true;
        }
    }
    ~playlist()
    {
        if( created ) {
            first = NULL;
            last = NULL;
            created = false;
        }
    }

    void insertFirst(music item);
    void insertLast(music item);
    void insertAfter(music target, music item);
    void insertBefore(music target, music item);
    void deleteItem(music item);
    void display();
};

#endif