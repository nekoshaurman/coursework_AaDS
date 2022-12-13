// Нахождение в неориентированном графе компоненты, изоморфной заданному графу
/*
 * 8
 * 6
0 1
0 3
0 4
1 2
1 5
2 3
3 4
3 5
 *
 * 2
 * 3
0 1
1 2
 */
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Edge {
    int fromV, toV;
};

class Graph {
public:
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;

    int countV, countE;
    //int adjMatrix[][];
    Graph(vector<Edge> const &edges, int nE, int nV){
        countV = nV;
        countE = nE;

        adjList.resize(countV);

        adjMatrix.resize(countV);
        for(int i = 0; i < countV; i++) {
            adjMatrix[i].resize(countV);
            for(int k = 0; k < countV; k++) {
                adjMatrix[i][k] = 0;
            }
        }

        for(auto &E : edges)
        {
            adjMatrix[E.fromV][E.toV] = 1;
            adjMatrix[E.toV][E.fromV] = 1;
            adjList[E.fromV].push_back(E.toV);
            adjList[E.toV].push_back(E.fromV);
        }
    }
};

int factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

void outputListV(Graph const &graph) {
    cout << "adjListV: " << endl;
    for (int from = 0; from < graph.countV; from++) {
        cout << from << ": ";

        for (int V : graph.adjList[from]) {
            cout << V << " ";
        }
        cout << endl;
    }
}

void outputMatrixV(Graph const &graph) {
    int i, k;
    cout << "adjMatrixV: " << endl;
    cout << "   ";
    for(i = 0; i < graph.countV; i++) {
        cout << i << " ";
    }
    cout << endl;
    cout << "-+-------------";

    cout << endl;
    for(i = 0; i < graph.countV; i++) {
        cout << i << "| ";
        for(k = 0; k < graph.countV; k++) {
            cout << graph.adjMatrix[i][k] << " ";
        }
        cout << endl;
    }
}

vector<Edge> inputEdges(int nE) {
    vector<Edge> edges;
    edges.resize(nE);
    cout << "Enter edges: " << endl;
    for(int i = 0; i < nE; i++) {
        cin >> edges[i].fromV;
        cin >> edges[i].toV;
    }
    cout << endl;
    return edges;
}

bool is_isomorphic(Graph const &graphA, Graph const &graphB) {
    unsigned long long degA, degB;
    int degreeA[graphA.countV], degreeB[graphB.countV];
    vector<vector<int>> adjMatrixTemp;
    adjMatrixTemp.resize(graphA.countV);
    memset(degreeA, 0, sizeof(degreeA));
    memset(degreeB, 0, sizeof(degreeB));


    if ((graphA.countV != graphB.countV) or (graphA.countE != graphB.countE)) return false;

    for(int i = 0; i < graphA.countV; i++) {
        degA = degA + graphA.adjList[i].size();
        degB = degB + graphB.adjList[i].size();
        degreeA[graphA.adjList[i].size()] = degreeA[graphA.adjList[i].size()] + 1;
        degreeB[graphB.adjList[i].size()] = degreeB[graphB.adjList[i].size()] + 1;
    }

    if(degA != degB) return false;

    for(int i = 0; i < graphA.countV; i++){
        if(degreeA[graphA.adjList[i].size()] != degreeB[graphB.adjList[i].size()]) return false;
    }

    for(int i = 0; i < graphA.adjList.size(); i++) {
        adjMatrixTemp[i].resize(graphA.countV);
        adjMatrixTemp[i] = graphB.adjMatrix[i];
    }

    for(int i = 0; i < factorial(graphA.countV); i++) {
        // Сделать перестановки и сверять их с матрицей графа А
    }
}

int main() {

    int nE, nV, i, k;
    cout << "Enter count of edges:";
    cin >> nE;
    cout << "Enter count of vertexes:";
    cin >> nV;

    Graph big_graph(inputEdges(nE), nE, nV);

    outputListV(big_graph);

    outputMatrixV(big_graph);

    return 0;
}
