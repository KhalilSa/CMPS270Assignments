#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <assert.h>
#include <vector>
#include "graph_cycles.hpp"

using namespace std;

template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& vector);
template<typename T>
ostream& operator<<(ostream& stream, stack<T>& stack);

void getCycle(vector<int>& cycle, stack<int>& stack, int vertex);
// driver code
int main()
{
    vector<int> start;
    start.emplace_back(0); start.emplace_back(0); start.emplace_back(0);
    start.emplace_back(4); start.emplace_back(4); start.emplace_back(3);

    vector<int> end;
    end.emplace_back(1); end.emplace_back(2); end.emplace_back(3);
    end.emplace_back(3); end.emplace_back(1); end.emplace_back(1);
    Graph graph(start, end);
    cout << "Printing Graph:" << endl;
    cout << graph;

    assert(graph.numOutgoing(0) == 3);
    assert(graph.numOutgoing(3) == 1);
    assert(graph.numOutgoing(4) == 2);

    cout << "Adjecent Neighbors of Vertex 0: ";
    cout << graph.adjacent(0) << endl;

    /* Exercise 5 Driver Code */
    stack<int> s;
    s.push(0); s.push(1); s.push(2); s.push(3); s.push(0);
    vector<int> cycle;
    getCycle(cycle, s, 0);
    cout << cycle << endl;

    Cycles cycles = graph.hasCycle();
    cycles.printCycle();

    vector<int> start2, end2;
    start2.emplace_back(0); end2.emplace_back(1);
    start2.emplace_back(1); end2.emplace_back(2);
    start2.emplace_back(2); end2.emplace_back(3);
    start2.emplace_back(3); end2.emplace_back(4);
    start2.emplace_back(4); end2.emplace_back(1);
    Graph graph2(start2, end2);
    cout << "Printing Graph 2:" << endl;
    cout << graph2;

    Cycles cycles2 = graph2.hasCycle();
    cycles2.printCycle();

    vector<int> start3, end3;
    start3.emplace_back(0); end3.emplace_back(0);
    start3.emplace_back(0); end3.emplace_back(1);
    start3.emplace_back(0); end3.emplace_back(2);
    start3.emplace_back(2); end3.emplace_back(1);
    start3.emplace_back(2); end3.emplace_back(2);
    Graph graph3(start3, end3);
    cout << "Printing Graph 2:" << endl;
    cout << graph3;

    Cycles cycles3 = graph3.hasCycle();
    cycles2.printCycle();
}

/*
 Description:
    Constructs a Graph with the given set of edges, where starts and ends represent the ordered list of
    edges’ start and endpoints.

*/
Graph::Graph(const vector<int> &start, const vector<int> &end) {
    int startSize = start.size();
    int endSize = end.size();
    if (startSize != endSize) {
        throw invalid_argument("Start and end vectors must have the same size.");
        exit(1);
    }

    int index = 0;
    // create an edge between start[i] and end[i]
    for (auto it = start.begin(); it != start.end(); it++) {
        verticesMap[*it].emplace_back(end[index]);
        index++;
    }

    // add nodes with no edges to the vertices map
    for (auto it = end.begin(); it != end.end(); it++) {
        if (verticesMap.find(*it) == verticesMap.end()) {
            verticesMap[*it] = vector<int>();
        };
    }

}

/*
    Description:
        Returns the number of outgoing edges from nodeID – that is, edges with nodeID as the start point.
*/
int Graph::numOutgoing(const int nodeId) const {
    auto iter = verticesMap.find(nodeId);
    if (iter == verticesMap.end()) {
        throw invalid_argument("Node Id was not found.");
        exit(1);
    };
    return iter->second.size();
}

/*
    Description:
        Returns a reference to the list of nodes to which nodeID has outgoing edges.
*/
const vector<int>& Graph::adjacent(const int nodeId) const {
    auto iter = verticesMap.find(nodeId);
    if (iter == verticesMap.end()) {
        throw invalid_argument("Node Id was not found.");
        exit(1);
    };
    return iter->second;
}

/*
    Description:
        this function will check if the graph has a non-trivial cycles. 
        That is, the graph has a cycle that contains at least 2 vertices.
    returns:
        a list (vector) of all cycles found in the graph
*/
Cycles Graph::hasCycle() {
    vector<vector<int>> cycles;
    unordered_map<int, Status> visited;
    // mark all vertices as unvisited (unprocessed)
    for (auto iter = verticesMap.begin(); iter != verticesMap.end(); ++iter) {
        visited[iter->first] = UNPROCESSED;
    }

    // for each vertex in the graph
    for (auto iter = verticesMap.begin(); iter != verticesMap.end(); ++iter) {
        int vertex = iter->first;
        if (visited[vertex] == UNPROCESSED) {
            std::stack<int> stack;
            stack.push(vertex);
            visited[vertex] = IN_STACK;
            getCyclesDFSTree(cycles, stack, visited);
        }
    }
    Cycles c;
    c.exist = !cycles.empty();
    c.cycles = cycles;
    return c;
}

/*
    returns:
        all cycles in the current DFS tree
*/
void Graph::getCyclesDFSTree(vector<vector<int>>& cycles, stack<int>& stack, unordered_map<int, Status>& visited) {
    for (int vertex: adjacent(stack.top())) {
        if (visited[vertex] == IN_STACK) {
            vector<int> cycle;
            getCycle(cycle, stack, vertex);
            cycles.emplace_back(cycle);
        } else if (visited[vertex] == UNPROCESSED) {
            stack.push(vertex);
            visited[vertex] = IN_STACK;
            getCyclesDFSTree(cycles, stack, visited);
        }
    }
    visited[stack.top()] = DONE;
    stack.pop();
}

/*
    returns:
        An int vector that represents a cycle that lives in the stack starting from a specified vertex
*/
void getCycle(vector<int>& cycle, stack<int>& stack, int vertex) {
    std::stack<int> temp; 
    temp.push(stack.top());
    stack.pop();
    // fill the temp stack with vertices up to the specified vertex
    while (stack.top() != vertex) {
        temp.push(stack.top());
        stack.pop();
    }
    // push the vertex
    temp.push(stack.top());
    stack.pop();
    // fill the cycle
    // while filling back the stack
    while(!temp.empty()) {
        cycle.emplace_back(temp.top());
        stack.push(temp.top());
        temp.pop();
    }
}

/*
    Description:
     Prints a cycles if it exists
*/
void Cycles::printCycle() {
    if (exist) {
        for (auto cycle: cycles) {
            cout << cycle << endl;
        }
    } else {
        cout << "The graph is asyclic!" << endl;
    }
}

/*
    An overload for the << operator for the graph object
*/
ostream& operator<<(ostream& stream, Graph& graph) {
    for (auto iter = graph.verticesMap.begin(); iter != graph.verticesMap.end(); iter++) {
        cout << iter->first << " -> " << iter->second << endl;
    }
    return stream;
}

/*
    A templated overload for the << operator for vector objects
*/
template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& vector) {
    for (int i: vector) {
            cout << i << ' ';
    }
    return stream;
}

template<typename T>
ostream& operator<<(ostream& stream, stack<T>& stack) {
    std::stack<int> temp; 
    while (!stack.empty())  {
        cout << stack.top() << endl;
        temp.push(stack.top());
        stack.pop();
    }
    while (!temp.empty()) {
        stack.push(temp.top());
        temp.pop();
    }

    return stream;
}

