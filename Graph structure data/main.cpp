#include "graph.cpp"

int main() {
    Graph g;

    g.tambahEdge("Tiang", "SPBU", 2);
    g.tambahEdge("SPBU", "Mall", 3);
    g.tambahEdge("Tiang", "Klinik", 5);
    g.tambahEdge("Klinik", "Apotik", 1);
    g.tambahEdge("Minimarket", "Tiang", 2);
    g.tambahEdge("Apotik", "Tiang", 3);
    
    
    g.printGraph();
    cout << endl;

    string awal = "Bundaran HI";
    if (!g.stasiunAda(awal)) {
        cout << "Stasiun tidak ditemukan.\n";
        return 1;
    }

    map<string, int> hasil = g.dijkstra(awal);

    cout << "Jarak terpendek dari " << awal << ":\n";
    for (map<string, int>::iterator it = hasil.begin(); it != hasil.end(); ++it) {
        if (it->first == awal) {
            cout << "-> " << it->first << ": 0 km (stasiun awal)" << endl;
        } else if (it->second == INT_MAX) {
            cout << "-> " << it->first << ": Tidak dapat dijangkau" << endl;
        } else {
            // cout << "-> " << it->first << ": " << it->second << " km" << endl;
        }
    }

    return 0;
}

