#ifndef my_graph_h
#define my_graph_h

#include <vector>
#include <unordered_map>
#include <stack>
#include <ostream>

enum Status {UNPROCESSED, IN_STACK, DONE};
struct Cycles {
    bool exist;
    std::vector<std::vector<int>> cycles;
    void printCycle();
};

class Graph {
    friend std::ostream& operator<<(std::ostream& stream, Graph& graph);
    private:
        std::unordered_map<int, std::vector<int>> verticesMap;

    private:
        void getCyclesDFSTree(std::vector<std::vector<int>>& cycles, std::stack<int>& stack, std::unordered_map<int, Status>& visited);
    
    public:
        Graph(const std::vector<int> &start, const std::vector<int> &end);
        int numOutgoing(const int nodeId) const;
        const std::vector<int>& adjacent(const int nodeId) const;
        Cycles hasCycle();
};

#endif