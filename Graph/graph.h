#ifndef GRAPH_H
#define GRAPH_H

#include <cmath>
#include <iostream>

typedef struct point *p;
typedef struct edge *e;
typedef struct Graph *graph;

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
    p point[2];
    e next;
    double length;
    void calculate_length(p &point_1, p &point_2){
        length = sqrt( pow(abs( point_2->x - point_1->x ), 2) + pow(abs( point_2->y - point_1->y ), 2) );
    }
};

e edge_alocate( p point_1, p point_2 ){
    e new_edge;
    new_edge = new edge;
    new_edge->point[0] = point_1;
    new_edge->point[1] = point_2;
    new_edge->calculate_length( point_1, point_2 );
    return new_edge;
}


struct Graph{
    
    private:
    p top_point = NULL;
    e top_edge = NULL;

    int edge_filled = 0;

    
    public:
    int width, height;
    
    Graph(int Width, int Height){
        width = Width;
        height = Height;
    }

    void insertVertex( p point )
    {
        if (top_point == NULL){
            top_point = point;
        }else{
            point->next = top_point;
            top_point = point;
        }
    }
    void insertEdge( e edge ){
        if (top_edge == NULL){
            top_edge = edge;
        }
        else{
            edge->next = top_edge;
            top_edge = edge;
        }
        edge_filled++;
    }

    void display_map()
    {
        p vertex_index = top_point;
        e edge_index = top_edge;
			
        for (int pixel_y = 1; pixel_y < height+1 ; pixel_y ++ ){
        	
            for( int pixel_x = 1; pixel_x < width+1; pixel_x ++ ){
                
                while ( vertex_index != NULL ){
                   	if( vertex_index->x == pixel_x && vertex_index->y == pixel_y ){
                   		std::cout<< " " << vertex_index->symbol << " ";
                   		break;
					}
					if( vertex_index->next == NULL ){
						std::cout << " . ";
					}
					
					vertex_index = vertex_index->next;
				}
				vertex_index = top_point;
                
            }
            std::cout << "\n";
        }
        
    }

    void display_table(){
        e edge_index = top_edge;
        int number_index = 1;

        for (int i=0; i<edge_filled; i++)
        {
            std::cout << "Jalur " << i+1 << "\n";
            std::cout << "\ttitik pertama: " << edge_index->point[0]->name << " ( " << edge_index->point[0]->symbol << " )\n";
            std::cout << "\ttitik kedua: " << edge_index->point[1]->name << " ( " << edge_index->point[1]->symbol << " )\n";
            std::cout << "\tJarak kedua titik: " << edge_index->length << "Km\n\n";
            edge_index = edge_index->next;
            number_index ++;
        }
        
    }

};

#endif
