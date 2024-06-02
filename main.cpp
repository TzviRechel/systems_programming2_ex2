// 316289495
// tzvirechel@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <vector>
using ariel::Algorithms;
using namespace std;
using namespace ariel;

int main(){
 
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 4},
        {1, 0, 1, 5},
        {1, 0, 1, 5}, 
        {0, 1, 0, 0}};   
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
    g2.loadGraph(graph2);

    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
    g3.loadGraph(graph3);

    Graph g4;
    vector<vector<int>> graph4 = {
        {5, 5, 3},
        {1, 7, 1}, 
        {1, 3, 1}};
    g4.loadGraph(graph4);

    // output operator
    cout << "Graph g1:" << endl;
    cout << g1 << endl;

    cout << "Graph g2:" << endl;
    cout << g2 << endl;

    cout << "Graph g3:" << endl;
    cout << g3 << endl;

    cout << "Graph g4:" << endl;
    cout << g4 << endl;


    // comparison operators
    cout << "Checking if g2 < g1: " << (g2 < g1) << endl;
    cout << "Checking if g3 < g1: " << (g3 < g1) << endl;
    cout << "Checking if g4 < g1: " << (g4 > g1) << endl;

    // graph addition
    Graph g5 = g2 + g3;
    cout << "Graph g5 (g1 + g2):" << endl;
    cout << g5 << endl;

    // graph subtraction
    Graph g6 = g4 - g3;
    cout << "Graph g6 (g1 - g3):" << endl;
    cout << g6 << endl;

    //  scalar multiplication
    Graph g7 = g1 * 2;
    cout << "Graph g7 (g1 * 2):" << endl;
    cout << g7 << endl;

     //  matrix multiplication
    Graph g8 = g2 * g3;
    cout << "Graph g8 (g1 * g3):" << endl;
    cout << g8 << endl;


    //  equality and inequality
    cout << "Checking if g1 == g1: " << (g1 == g1) << endl;
    cout << "Checking if g1 != g2: " << (g1 != g2) << endl;

    try{
        Graph g9 = g2 * g1;
    }
    catch (const std::invalid_argument &e){
        cout << e.what() << endl; 
    }

    return 0;
}

