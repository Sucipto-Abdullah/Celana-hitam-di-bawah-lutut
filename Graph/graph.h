#ifndef GRAPH_H
#define GRAPH_H

#include <cmath>
#include <iostream>

typedef struct point *p;
typedef struct edge *e;
typedef struct Graph *graph;

struct point{
    int x;
    int y;
    char symbol;
    p next;
};

p point_alocate(int x, int y, char symbol){
	p pnt;
	pnt = new point;
	pnt->next = NULL;
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

struct point_queue{
    p top;
    p tail;
    

    void create(){
        top = NULL;
        tail = NULL;
    }

    void push( p value ){
        if( top == NULL ){
            top = value;
            tail = value;
        }else{
            tail->next = value;
            tail = value;
        }
    }

    void pop(){
        if( top != NULL ){
            p target = top;
            top = target->next;
            target->next = NULL;
            delete target;
        }
    }
};

struct edge_queue{
    private:
    bool created = false;
    public:
    e top;
    e tail;

    void create(){
        if (!created){
            top = NULL;
            tail = NULL;
            created = true;
        }
    }
    void push( e edge ){
        if( created){
            if( top == NULL ){
                top = edge;
                tail = edge;
            }else{
                tail->next = edge;
                tail = edge;
            }
        }
    }
};

struct Graph{
    int width, height;

    Graph(int Width, int Height){
        width = Width;
        height = Height;
    }

    void render_point(point_queue point_queue, edge_queue edge_queue){

        p render_target = point_queue.top;
        e edge_target = edge_queue.top;
			
        for (int pixel_y = 1; pixel_y < height+1 ; pixel_y ++ ){
        	
            for( int pixel_x = 1; pixel_x < width+1; pixel_x ++ ){
                
                while ( render_target != NULL ){
                   	if( render_target->x == pixel_x && render_target->y == pixel_y ){
                   		std::cout<< " " << render_target->symbol << " ";
                   		break;
					}
					if( render_target->next == NULL ){
						std::cout << " . ";
					}
					
					render_target = render_target->next;
				}
				render_target = point_queue.top;
                
            }
            std::cout << "\n";
        }
        
//        std::cout << edge_target->length << "\n";
           
        while(edge_target != NULL){
            std::cout << edge_target->point[0]->symbol << " - " << edge_target->length << "km - " << edge_target->point[1]->symbol << "\n";
            edge_target = edge_target->next;
        }
    }

};

#endif
