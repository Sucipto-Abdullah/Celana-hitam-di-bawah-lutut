#ifndef GRAPH_H
#define GRAPH_H

#include <cmath>
#include <climits>
#include <cstring>
#include <iostream>

typedef struct point *p;
typedef struct edge *e;

const int max_array = 24;
const int INF = INT_MAX;
struct point{
    std::string name;
    int x;
    int y;
    char symbol;
    p next;
};

p point_alocate(std::string name, int x, int y, char symbol){
	p pnt;
	pnt = new point;
	pnt->next = NULL;
    pnt->name = name;
	pnt->x = x;
	pnt->y = y;
	pnt->symbol = symbol;
	return pnt;
}

struct edge{
    p point[2][2];
    e next;
    double length;
    void calculate_length(p &point_1, p &point_2){
        length = sqrt( pow(abs( point_2->x - point_1->x ), 2) + pow(abs( point_2->y - point_1->y ), 2) );
    }
};

e edge_alocate( p point_1, p point_2 ){
    e new_edge;
    new_edge = new edge;
    new_edge->point[0][0] = point_1;
    new_edge->point[0][1] = point_2;

    new_edge->point[1][0] = point_1;
    new_edge->point[1][1] = point_2;

    new_edge->calculate_length( point_1, point_2 );
    return new_edge;
}


struct graph{
    
    private:
    // const int max_array = 24;
    p top_point = NULL;
    e top_edge = NULL;
    int edge_filled = 0;
    // int get_max_width();
    // int get_max_heigth();    
    e* getShortestPath(p start, p finish);
    public:
    int width, height;
    graph(int Width, int Height){
        width = Width;
        height = Height;
    }

    void insertVertex( p point );
    void insertEdge( e edge );
    void display_map();
    void display_table();
    void display_matrix();
    void listAllPath(p from, p to);
};

#endif
