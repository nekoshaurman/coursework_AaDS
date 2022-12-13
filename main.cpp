//Нахождение в неориентированном графе компоненты, изоморфной заданному графу
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

struct Edge {
    int fromV, toV;
};

class Graph {
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int n){
        adjList.resize(n);

        for(auto &E : edges)
        {
            adjList[E.fromV].push_back(E.toV);

            adjList[E.toV].push_back(E.fromV);
        }
    }
};

void outputListV(Graph const &graph, int n) {
    cout << "adjListV: " << endl;
    for (int from = 0; from < n; from++) {
        cout << from << ": ";

        for (int V : graph.adjList[from]) {
            cout << V << " ";
        }
        cout << endl;
    }
}

vector<Edge> inputEdges(int n) {
    vector<Edge> edges;
    edges.resize(n);
    cout << "Enter edges: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> edges[i].fromV;
        cin >> edges[i].toV;
    }
    cout << endl;
    /*for(int i = 0; i < n; i++) {
        cout << edges[i].fromV << "---";
        cout << edges[i].toV;
        cout << endl;
    }*/
    return edges;
}

int main() {

    int nE, nV;
    cout << "Enter count of edges: ";
    cin >> nE;
    cout << "Enter count of vertexes: ";
    cin >> nV;
    //inputEdges(n);
    Graph graph(inputEdges(nE), nE);
    outputListV(graph, nV);
    return 0;
}
