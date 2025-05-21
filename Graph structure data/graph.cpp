#include "graph.h"              
#include <queue>                        
#include <climits>                      

void Graph::tambahEdge(string asal, string tujuan, int jarak) {
    adjList[asal].push_back(make_pair(tujuan, jarak)); // Tambahkan tujuan dan jaraknya ke daftar tetangga stasiun asal

    if (adjList.find(tujuan) == adjList.end()) {
        adjList[tujuan] = vector<pair<string, int> >();
    }
}

void Graph::printGraph() {
    std::cout << "Graph:\n";
    for (map<string, vector<pair<string, int> > >::iterator it = adjList.begin(); it != adjList.end(); ++it) {
        std::cout << it->first << " -> ";
        vector<pair<string, int> >& tetangga = it->second;

        if (tetangga.empty()) {
            std::cout << "(tidak ada jalur keluar)";
        } else {
            for (int i = 0; i < tetangga.size(); i++) {
                std::cout << tetangga[i].first << " (" << tetangga[i].second << " km)";
                if (i < tetangga.size() - 1) 
                {
                    std::cout << ", ";
                }
            }
        }
        cout << endl;
    }
}
bool Graph::stasiunAda(string nama) {
    return adjList.find(nama) != adjList.end();
}

map<string, int> Graph::dijkstra(string start) {
    map<string, int> jarak;           
    map<string, bool> dikunjungi;       

    // Inisialisasi semua jarak ke tak hingga dan belum dikunjungi
    for (map<string, vector<pair<string, int> > >::iterator it = adjList.begin(); it != adjList.end(); ++it) {
        jarak[it->first] = INT_MAX;
        dikunjungi[it->first] = false;
    }

    jarak[start] = 0;                    // Jarak dari stasiun awal ke dirinya sendiri adalah 0

    // Priority queue untuk memilih stasiun dengan jarak terkecil (pair<jarak, nama_stasiun>)
    priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
    pq.push(make_pair(0, start));       // Masukkan stasiun awal ke priority queue

    while (!pq.empty()) {
        string sekarang = pq.top().second;  // Ambil stasiun dengan jarak terkecil
        pq.pop();

        if (dikunjungi[sekarang]) continue; // Lewati jika sudah dikunjungi sebelumnya
        dikunjungi[sekarang] = true;        // Tandai sebagai sudah dikunjungi

        // Iterasi seluruh tetangga dari stasiun sekarang
        vector<pair<string, int> >& tetangga = adjList[sekarang];
        for (int i = 0; i < tetangga.size(); i++) {
            string tujuan = tetangga[i].first;    // Ambil nama tetangga
            int bobot = tetangga[i].second;       // Ambil jarak ke tetangga

            // Jika jarak baru lebih kecil dari jarak yang tersimpan sebelumnya, perbarui
            if (jarak[sekarang] + bobot < jarak[tujuan]) {
                jarak[tujuan] = jarak[sekarang] + bobot;
                pq.push(make_pair(jarak[tujuan], tujuan)); // Masukkan ke antrian prioritas
            }
        }
    }

    return jarak;  // Kembalikan hasil jarak terpendek dari stasiun awal ke semua stasiun lainnya
}

