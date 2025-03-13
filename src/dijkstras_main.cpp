#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("/home/ojchu/ICS46/HW9/src/small.txt", G);
    vector<int> previous(G.numVertices);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int num = 0; num < G.numVertices; ++num) {
        vector<int> path = extract_shortest_path(distances, previous, num);
        print_path(path, distances[num]);
    }
}