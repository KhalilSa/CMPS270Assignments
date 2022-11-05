#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "my_graph.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vector);
// driver code
int main()
{
    std::vector<int> start;
    start.emplace_back(0); start.emplace_back(0); start.emplace_back(0);
    start.emplace_back(4); start.emplace_back(4); start.emplace_back(3);

    std::vector<int> end;
    end.emplace_back(1); end.emplace_back(2); end.emplace_back(3);
    end.emplace_back(3); end.emplace_back(1); end.emplace_back(1);
    Graph graph(start, end);
    std::cout << graph;
    std::cout << graph.numOutgoing(0) << std::endl;
    std::cout << graph.adjacent(0) << std::endl;
}

Graph::Graph(const std::vector<int> &start, const std::vector<int> &end) {
    int startSize = start.size();
    int endSize = end.size();
    if (startSize != endSize) {
        throw std::invalid_argument("Start and end vectors must have the same size.");
        exit(1);
    }

    int index = 0;
    for (auto it = start.begin(); it != start.end(); it++) {
        std::cout << *it << ' ' << end[index] << std::endl;
        verticesMap[*it].emplace_back(end[index]);
        index++;
    }
}

int Graph::numOutgoing(const int nodeId) const {
    auto iter = verticesMap.find(nodeId);
    if (iter == verticesMap.end()) {
        throw std::invalid_argument("Node Id was not found.");
        exit(1);
    };
    return iter->second.size();
}

const std::vector<int>& Graph::adjacent(const int nodeId) const {
    auto iter = verticesMap.find(nodeId);
    if (iter == verticesMap.end()) {
        throw std::invalid_argument("Node Id was not found.");
        exit(1);
    };
    return iter->second;
}

std::ostream& operator<<(std::ostream& stream, Graph& graph) {
    for (auto iter = graph.verticesMap.begin(); iter != graph.verticesMap.end(); iter++) {
        std::cout << iter->first << " -> " << iter->second << std::endl;
        
    }
    return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vector) {
    for (int i: vector) {
            std::cout << i << ' ';
    }
    return stream;
}