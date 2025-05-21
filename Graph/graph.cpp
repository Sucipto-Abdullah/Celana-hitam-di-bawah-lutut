#include "graph.h"

void graph::insertVertex( p point )
{
    if (top_point == NULL){
        top_point = point;
    }else{
        point->next = top_point;
        top_point = point;
    }
}
void graph::insertEdge( e edge )
{
    if (top_edge == NULL){
        top_edge = edge;
    }
    else{
        edge->next = top_edge;
        top_edge = edge;
    }
    edge_filled++;
}
void graph::display_map()
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
void graph::display_table(){
    e edge_index = top_edge;
    int number_index = 1;

    for (int i=0; i < edge_filled; i++)
    {
        std::cout << "Jalur " << i+1 << "\n";
        std::cout << "\ttitik pertama: " << edge_index->point[0][0]->name << " ( " << edge_index->point[0][0]->symbol << " )\n";
        std::cout << "\ttitik kedua: " << edge_index->point[0][1]->name << " ( " << edge_index->point[0][1]->symbol << " )\n";
        std::cout << "\tJarak kedua titik: " << edge_index->length << "Km\n\n";
        edge_index = edge_index->next;
        number_index ++;
    }        
}
void graph::display_matrix()
{
    e index = top_edge;
    for( int i=0; i< edge_filled; i++ )
    {
        for(int j=0; j<2; i++)
        {
            std::cout << "| " << index->point[0][j]->x << " " << index->point[0][j]->y << " |\n";
        }
        std::cout << "\n";
        index = index->next;
    }
}
e* graph::getShortestPath(p start, p finish)
{
    static e path[16];
    for(int i=0; i<16; i++){
        path[i] == NULL;
    }

    



}
void graph::listAllPath(p from, p to)
{

}