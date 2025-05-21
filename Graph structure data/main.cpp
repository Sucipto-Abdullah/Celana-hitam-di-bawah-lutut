#include "graph.cpp"

int main() {
    Graph g;

    g.tambahEdge("Tiang", "SPBU", 3);
    g.tambahEdge("SPBU", "Mall", 2);
    g.tambahEdge("Mall", "Tiang", 2);
    g.tambahEdge("Tiang", "Klinik", 5);
    g.tambahEdge("Klinik", "Apotik", 1);
    g.tambahEdge("Minimarket", "Tiang", 2);
    g.tambahEdge("Apotik", "Tiang", 3);
    // g.tambahEdge("Apotik", "Minimarket", 3);
    
    
    g.printGraph();
    cout << endl;

    string awal = "SPBU";
    if ( !g.pointAda(awal)) {
        cout << "Jalur tidak ditemukan.\n";
        return 1;
    }

    map<string, int> hasil = g.dijkstra(awal);

    cout << "Jarak terpendek dari " << awal << ":\n";
    for (map<string, int>::iterator it = hasil.begin(); it != hasil.end(); ++it) {
        if (it->first == awal) {
            cout << "-> " << it->first << ": 0 m (titik awal)" << endl;
        } else if (it->second == INT_MAX) {
            cout << "-> " << it->first << ": Tidak dapat dijangkau" << endl;
        }
    }

    return 0;
}

