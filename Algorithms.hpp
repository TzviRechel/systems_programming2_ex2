// 316289495
// tzvirechel@gmail.com

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include "Graph.hpp"

namespace ariel{

    class Algorithms{

    private:
        // Private helper function for DFS traversal
        static void dfsVisit(int v, std::vector<std::vector<int>>& mat, std::vector<int>& visited, std::stack<int>& path, bool isDirected);

    public:
        // Check if the graph is connected. If the graph is directed, check if it is strongly connected.
        // Return 1 if connected (or strongly connected), 0 otherwise.
        static int isConnected(Graph g);

        // Find the shortest path between two vertices.
        // Return the path as a string, or "-1" if no path exists.
        static std::string shortestPath(Graph g, int start, int end);

        // Check if the graph contains a cycle.
        // Return the cycle as a string if one exists, "0" otherwise.
        static std::string isContainsCycle(Graph g);

        // Check if the graph is bipartite.
        // Return the bipartition as a string if it is bipartite, "0" otherwise.
        static std::string isBipartite(Graph g);

        // Check if the graph contains a negative cycle.
        // Return the cycle as a string if one exists, "0" otherwise.
        static std::string negativeCycle(Graph g);

    };
}    