#include "graph.h"

int main(){

    p rumah = point_alocate(2, 4, 'H');
    p kampus = point_alocate(5, 5, 'K');
	p spbu = point_alocate(3, 7, 'S');
	p masjid = point_alocate(11, 15, 'M');
	p tol = point_alocate(7, 6, 'T');
	
	e jalur_a = edge_alocate(rumah, spbu);
	e jalur_b = edge_alocate(rumah, kampus);
	e jalur_c = edge_alocate(rumah, masjid);
	e jalur_d = edge_alocate( kampus, tol );
	
    point_queue point_queue;
    point_queue.create();
    point_queue.push(rumah);
    point_queue.push(kampus);
    point_queue.push(spbu);
    point_queue.push( masjid );
    point_queue.push(tol);
	
	edge_queue edge_queue;
	edge_queue.create();
	edge_queue.push(jalur_a);
	edge_queue.push(jalur_b);
	edge_queue.push(jalur_c);
	edge_queue.push(jalur_d);
	
    graph screen = new Graph(20, 20);
	
    screen->render_point(point_queue, edge_queue);
    
    std::cout << edge_queue.top->length;

    return 0;
}
