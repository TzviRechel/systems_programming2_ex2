// 316289495
// tzvirechel@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
using namespace std;

    TEST_CASE("Test += operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, 1, 3},
        {0, 0, 4}, 
        {2, 5, 0}};   
        g2.loadGraph(graph2);
        g2 += g1;
        vector<vector<int>> expectedGraph = {
        {0, 2, 3},
        {0, 0, 5}, 
        {2, 6, 0}};
        CHECK(g2.getMatrix() == expectedGraph);
        g2 -= g1;
        CHECK(g2.getMatrix() == graph2);
        //addition with empty graph
        ariel::Graph emptyGraph;
        vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0}, 
        {0, 0, 0}};
        emptyGraph.loadGraph(graph);
        g2 += emptyGraph; 
        CHECK(g2.getMatrix() == graph2);  
    }


    TEST_CASE("Test + operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, -1, 0},
        {-1, 0, -1}, 
        {0, -1, 0}};   
        g2.loadGraph(graph2); 
        ariel::Graph g3;
        g3 = g1 + g2;
        ariel::Graph emptyGraph;
        vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0}, 
        {0, 0, 0}};
        emptyGraph.loadGraph(graph);
        CHECK(g3.getMatrix() == graph);
        ariel::Graph g4;
        vector<vector<int>> expectedGraph = {
        {0, 2, -7},
        {0, 0, 5}, 
        {2, 6, 0}};
        g4.loadGraph(expectedGraph);
        ariel::Graph g5;
        g5 = g4 + g3;
        CHECK(g5.getMatrix() == expectedGraph); 
    }

    TEST_CASE("Test -= operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, 1, 3},
        {0, 0, 4}, 
        {2, -3, 0}};   
        g2.loadGraph(graph2);
        g2 -= g1;
        vector<vector<int>> expectedGraph = {
        {0, 1, 3},
        {0, 0, 3}, 
        {2, -4, 0}};
        CHECK(g2.getMatrix() == expectedGraph);
        //-= with empty graph
        ariel::Graph emptyGraph;
        vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0}, 
        {0, 0, 0}};
        emptyGraph.loadGraph(graph);
        g2 -= emptyGraph; 
        CHECK(g2.getMatrix() == expectedGraph);  
    }

    TEST_CASE("Test - operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1); 
        g1 = g1 - g1;
        ariel::Graph emptyGraph;
        vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0}, 
        {0, 0, 0}};
        emptyGraph.loadGraph(graph);
        CHECK(g1.getMatrix() == graph);
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, -1, 0},
        {-1, 0, -1}, 
        {0, -1, 0}};   
        g2.loadGraph(graph2);
        ariel::Graph g3;
        vector<vector<int>> graph3 = {
        {0, 2, -7},
        {0, 0, 5}, 
        {2, 6, 0}};
        g3.loadGraph(graph3);
        ariel::Graph g5;
        g5 = g3 - g2;
        vector<vector<int>> expectedGraph = {
        {0, 3, -7},
        {1, 0, 6}, 
        {2, 7, 0}};
        CHECK(g5.getMatrix() == expectedGraph); 
    }

    TEST_CASE("Test + unary operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        g1 = +g1;
        CHECK(g1.getMatrix() == graph1); 
    }

    TEST_CASE("Test - unary operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, -1, 0},
        {-1, 0, -1}, 
        {0, -1, 0}};   
        g2.loadGraph(graph2);
        g1 = -g1;
        CHECK(g1.getMatrix() == graph2);
    }

    TEST_CASE("Test ++ prefix") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2}, 
        {0, 2, 0}};
        ariel::Graph g2;
        g2 = ++g1;
        CHECK(g1.getMatrix() == expectedGraph);
        CHECK(g2.getMatrix() == expectedGraph);  
    }

    TEST_CASE("Test ++ postfix") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2}, 
        {0, 2, 0}};
        ariel::Graph g2;
        g2 = g1++;
        CHECK(g1.getMatrix() == expectedGraph);
        CHECK(g2.getMatrix() == graph1);  
    }

    TEST_CASE("Test -- prefix") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};
        ariel::Graph g2;
        g2 = --g1;
        CHECK(g1.getMatrix() == expectedGraph);
        CHECK(g2.getMatrix() == expectedGraph);  
    }

    TEST_CASE("Test -- postfix") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};
        ariel::Graph g2;
        g2 = g1--;
        CHECK(g1.getMatrix() == expectedGraph);
        CHECK(g2.getMatrix() == graph1);    
    }

    TEST_CASE("Test < operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0, 4},
        {1, 0, 1, 5},
        {1, 0, 1, 5}, 
        {0, 1, 0, 0}};   
        g1.loadGraph(graph1);
        //g2 is a subgraph of g1
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
        g2.loadGraph(graph2);
        CHECK(g2 < g1);
        //g3 has fewer edges than g1
        ariel::Graph g3;
        vector<vector<int>> graph3 = {
        {0, 0, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
        g3.loadGraph(graph3);
        CHECK(g3 < g1);
        //g4 has the same number of edges but is not a subgraph
        ariel::Graph g4;
        vector<vector<int>> graph4 = {
        {5, 5, 3},
        {1, 7, 1}, 
        {1, 3, 1}};
        g4.loadGraph(graph4);
        CHECK(g4 < g1);
        //g5 has the same size but is not a subgraph
        ariel::Graph g5;
        vector<vector<int>> graph5 = {
        {4, 1, 6, 0},
        {1, 0, 1, 0},
        {1, 1, 1, 0}, 
        {0, 0, 0, 0}};   
        g5.loadGraph(graph5);
        CHECK(g5 < g1);
        CHECK(g5 < g4);//g5 has more vertices but fewer edges than g4
        CHECK_FALSE(g1 < g1); // A graph is not less than itself
    } 

        TEST_CASE("Test == operator") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0, 4},
        {1, 0, 1, 5},
        {1, 0, 1, 5}, 
        {0, 1, 0, 0}};   
        g1.loadGraph(graph1);
        CHECK(g1 == g1);
        // Different size
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
        g2.loadGraph(graph2);
        CHECK(g2 != g1);
        //same size and same number of edges
        ariel::Graph g3;
        vector<vector<int>> graph3 = {
        {0, 0, 0},
        {1, 1, 1}, 
        {1, 0, 1}};
        g3.loadGraph(graph3);
        CHECK(g3 == g2);
        // Different size, same number of edges
        ariel::Graph g4;
        vector<vector<int>> graph4 = {
        {5, 5, 3},
        {1, 7, 1}, 
        {1, 3, 1}};
        g4.loadGraph(graph4);
        CHECK(g4 != g1);
         // Same size as g1, but different number of edges
        ariel::Graph g5;
        vector<vector<int>> graph5 = {
        {4, 1, 6, 0},
        {1, 0, 1, 0},
        {1, 1, 1, 0}, 
        {0, 0, 0, 0}};   
        g5.loadGraph(graph5);
        CHECK(g5 != g1);  
    }

    TEST_CASE("Test <=, >=") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0, 4},
        {1, 0, 1, 5},
        {1, 0, 1, 5}, 
        {0, 1, 0, 0}};   
        g1.loadGraph(graph1);
        //< but no =
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
        g2.loadGraph(graph2);
        CHECK(g2 <= g1);
        //= but no <
        ariel::Graph g3;
        vector<vector<int>> graph3 = {
        {0, 0, 1},
        {1, 0, 1}, 
        {1, 0, 1}};
        g3.loadGraph(graph3);
        CHECK(g3 <= g2);
        //> but no =
        ariel::Graph g4;
        vector<vector<int>> graph4 = {
        {5, 5, 3},
        {1, 7, 1}, 
        {1, 3, 1}};
        g4.loadGraph(graph4);
        CHECK(g4 >= g3);
        //= but no >
        CHECK(g4 >= g4); 
    }


    TEST_CASE("matrix multiplication") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        ariel::Graph g2;
        vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {1, 0, 1}};
        g2.loadGraph(graph2);
        ariel::Graph g3;
        g3 = g1 * g2;
        vector<vector<int>> expectedGraph = {
        {1, 0, 1},
        {1, 1, 1}, 
        {1, 0, 1}};
        CHECK(g3.getMatrix() == expectedGraph);
        ariel::Graph I;
        vector<vector<int>> i = {
        {1, 0, 0},
        {0, 1, 0}, 
        {0, 0, 1}};
        I.loadGraph(i);
        g3 *= I;
        CHECK(g3.getMatrix() == expectedGraph);  
    }

    TEST_CASE("scalar multiplication") {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g1.loadGraph(graph1);
        g1 *= 5;
        vector<vector<int>> expectedGraph = {
        {0, 5, 0},
        {5, 0, 5}, 
        {0, 5, 0}};
        CHECK(g1.getMatrix() == expectedGraph);
        ariel::Graph g2;
        g2 = g1 * 0;
        vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0}, 
        {0, 0, 0}};
        CHECK(g2.getMatrix() == graph);  
    }

    TEST_CASE("Invalid operations")
{
    ariel::Graph unloadGraph;
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK_THROWS(g2 * g1);
    CHECK_THROWS(g2 * unloadGraph);
    CHECK_THROWS(g1 += g2);
    CHECK_THROWS(g1 - unloadGraph);
    CHECK_THROWS(g1 + g2);
    CHECK_THROWS(g1 -= g2);
}









        