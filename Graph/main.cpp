#include "graph.cpp"

int main(){

    p rumah = point_alocate("rumah", 2, 4, 'H');
    p kampus = point_alocate("Kampus", 5, 5, 'K');
	p spbu = point_alocate("SPBU" , 3, 7, 'S');
	p masjid = point_alocate( "Masjid", 11, 15, 'M');
	p tol = point_alocate( "Tol", 7, 6, 'T');
	
	e jalur_a = edge_alocate(rumah, spbu);
	e jalur_b = edge_alocate(rumah, kampus);
	e jalur_c = edge_alocate(rumah, masjid);
	e jalur_d = edge_alocate( kampus, tol );
	
    graph screen = graph(20, 20);

    screen.insertVertex(rumah);
    screen.insertVertex(kampus);
    screen.insertVertex(spbu);
    screen.insertVertex(masjid);
    screen.insertVertex(tol);

    screen.insertEdge(jalur_a);
    screen.insertEdge(jalur_b);
    screen.insertEdge(jalur_c);
    screen.insertEdge(jalur_d);

    screen.display_map();
    screen.display_matrix();
    
    std::cout << 0%2;
    return 0;
}
