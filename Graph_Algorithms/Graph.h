#include "common.h"
#include "Edge.h"
template <typename T>
class Graph {
public:
    typedef T value_type;
    int V;
    unordered_map<int, vector<Edge<T>>> edges;
    unordered_set<int> vertices;
    unordered_set<int> visited;
    Graph<T> (int V)
    {
        this->V = V;
        this->edges.clear();
        this->visited.clear();
    }
    ~Graph<T> (void) {}
    void AddVertex(int v)
    {
        vertices.insert(v);
    }
    void AddEdge(int v1, int v2, T wgt, bool is_directed)
    {
        for (auto & edge : edges[v1])
            if (edge.destination() == v2)
                return;
        
    }
};