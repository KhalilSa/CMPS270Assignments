#ifndef my_graph_h
#define my_graph_h

#include <vector>
#include <map>
#include <ostream>

struct Node;

class Graph {
    friend std::ostream& operator<<(std::ostream& stream, Graph& graph);
    private:
        std::map<int, std::vector<int>> verticesMap;
    
    public:
        Graph(const std::vector<int> &start, const std::vector<int> &end);
        int numOutgoing(const int nodeId) const;
        const std::vector<int>& adjacent(const int nodeId) const;
};

#endif