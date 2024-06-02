// 316289495
// tzvirechel@gmail.com

#pragma once

#include <vector>
#include <iostream>

namespace ariel{

    class Graph{
        private:
            std::vector<std::vector<int>> _graph;
            bool _isDirected = false;
            size_t _edges = 0;

        public: 
            // Load the graph from the given adjacency matrix  
            void loadGraph(std::vector<std::vector<int>> graph);

            // Print the number of vertices and edges in the graph
            void printGraph();

            // Return the number of vertices in the graph
            int numOfVertices() const;

            // Get the adjacency matrix that represents the graph
            std::vector<std::vector<int>> getMatrix();

            // Check if the graph is directed
            bool isDirected();

            //+=
            Graph &operator+=(const Graph &g);

            //-=
            Graph &operator-=(const Graph &g);            

            //prefix ++
            Graph& operator++();

            //postfix ++
            Graph operator++(int);

            //prefix --
            Graph& operator--();

            //postfix --
            Graph operator--(int);

            //+ unary
            Graph operator+();

            //- unary
            Graph operator-();

            //+
            friend Graph operator+(const Graph &g1, const Graph &g2);

            //-
            friend Graph operator-(const Graph &g1, const Graph &g2);

            //<
            friend bool operator<(const Graph &g1, const Graph& g2);

            //>
            friend bool operator>(const Graph &g1, const Graph& g2);

            //==
            friend bool operator==(const Graph &g1, const Graph& g2);

            //!=
            friend bool operator!=(const Graph &g1, const Graph& g2);

            //<=
            friend bool operator<=(const Graph &g1, const Graph& g2);

            //>=
            friend bool operator>=(const Graph &g1, const Graph& g2);

            //*
            friend Graph operator*(const Graph &g, int scalar);

            //*=
            Graph& operator*=(int scalar);

            //* with Graph
            friend Graph operator*(const Graph &g1, const Graph& g2);

            //*=
            Graph& operator*=(const Graph &g);

            //<<
            friend std::ostream& operator<<(std::ostream& os, const Graph& g);


        





    };
}
