// 316289495
// tzvirechel@gmail.com

#include "Graph.hpp"
#include <iostream>
using namespace std;

void ariel::Graph::loadGraph(vector<vector<int>> graph){
    this->_isDirected = false;
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() != n)
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

    }
    this->_graph = graph;

    // check if the graph is directed
    for (int i = 0; i < n; i++)
    {
        if(_graph[i][i]){_isDirected = true;} // Check for a self-loop at vertex i to determine if the graph is directed
        for (int j = i; j < n; j++){
            if(_graph[i][j]!=_graph[j][i]){
                _isDirected = true;
                break;
            }
        }
        if(_isDirected){break;}
    }

    //count edges
    _edges = 0;
      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                if (_graph[i][j])
            {
                _edges++;
            }
        }
    }
    if(!_isDirected){
        _edges = _edges/2;
    }
}
void ariel::Graph::printGraph()
{
    int v = _graph.size();
    if(!_isDirected){
        cout << "Undirected graph with " << v << " vertices and " << _edges << " edges" << endl;
    }
    else{
    cout << "Directed graph with " << v << " vertices and " << _edges << " edges" << endl;
    }
}

int ariel::Graph::numOfVertices ()const
{
    return this->_graph.size();
}

vector<std::vector<int>> ariel::Graph::getMatrix()
{
    return this->_graph;
}

bool ariel::Graph::isDirected(){
    return this->_isDirected;
}


//operator +=
ariel::Graph & ariel::Graph::operator+=(const Graph &g){
    if(this->numOfVertices() != g.numOfVertices()){
        throw invalid_argument("The matrixes must have the same size");
    }
    size_t n = this->numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            if(this->_graph[i][j] && (this->_graph[i][j] + g._graph[i][j])){ //Sum the edges only when the edges exist
                this->_graph[i][j] += g._graph[i][j];
            }
        }   
    }
    this->loadGraph(this->_graph);

    return *this;
}

ariel::Graph &ariel::Graph::operator-=(const ariel::Graph &g){
    if(this->numOfVertices() != g.numOfVertices()){
        throw invalid_argument("The matrixes must have the same size");
    }
    size_t n = this->numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            if(this->_graph[i][j] && (this->_graph[i][j] - g._graph[i][j])){ //Sum the edges only when the edges exist
                this->_graph[i][j] -= g._graph[i][j];
            }
        }   
    }
    this->loadGraph(this->_graph);
    return *this;
}


ariel::Graph& ariel::Graph::operator++(){
    size_t n = this->numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            // Increment by one only when the edges exist and are not -1
            if(this->_graph[i][j] && (this->_graph[i][j] != -1)){
                ++this->_graph[i][j];
            }
        }   
    }
    this->loadGraph(_graph);
    return *this;
}

ariel::Graph ariel::Graph::operator++(int){
    Graph temp = *this;
    ++(*this);
    return temp;
}

ariel::Graph &ariel::Graph::operator--(){
    size_t n = this->numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            // decrement by one only when the edges exist and are not 1
            if(this->_graph[i][j] && (this->_graph[i][j] != 1)){
                --this->_graph[i][j];
            }
        }   
    }
    this->loadGraph(_graph);
    return *this;
}

ariel::Graph ariel::Graph::operator--(int){
    Graph temp = *this;
    --(*this);
    return temp;
}

ariel::Graph ariel::Graph::operator+(){
    return *this;
}

ariel::Graph ariel::Graph::operator-(){
    size_t n = this->numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
                this->_graph[i][j]*=-1;
            }
        }   
    this->loadGraph(_graph);
    return *this;
}

ariel::Graph ariel::operator+(const ariel::Graph &g1, const ariel::Graph &g2){
    if(g1.numOfVertices() != g2.numOfVertices()){
        throw invalid_argument("The matrixes must have the same size");
    }
    Graph result = g1;
    size_t n = g1.numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
                result._graph[i][j] += g2._graph[i][j];
        }   
    }
    result.loadGraph(result._graph);
    return result;
}

ariel::Graph ariel::operator-(const ariel::Graph &g1, const ariel::Graph &g2){
      if(g1.numOfVertices() != g2.numOfVertices()){
        throw invalid_argument("The matrixes must have the same size");
    }
    Graph result = g1;
    size_t n = g1.numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
                result._graph[i][j] -= g2._graph[i][j];
        }   
    }
    result.loadGraph(result._graph);
    return result;
}

ariel::Graph& ariel::Graph::operator*=(int scalar){

    size_t n = this->numOfVertices();
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
                this->_graph[i][j] *= scalar;
        }   
    }
    this->loadGraph(this->_graph);
    return *this;
}

ariel::Graph ariel::operator*(const ariel::Graph &g, int scalar){

    Graph result = g;
    result*=scalar;
    return result;
}

ariel::Graph &ariel::Graph::operator*=(const ariel::Graph &g){
    if(this->numOfVertices() != g.numOfVertices()){
        throw invalid_argument("The multiplication in this matrix is not defined");
    }
    size_t n = this->numOfVertices();
    vector<vector<int>> mat(n, vector<int>(n));
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            int sum = 0;
            for(size_t p=0;p<n;p++){
                sum = sum + this->_graph[i][p] * g._graph[p][j];
            }
            mat[i][j] = sum;
        }   
    }
    this->loadGraph(mat);

    return *this;
}

ariel::Graph ariel::operator*(const ariel::Graph &g1, const ariel::Graph &g2){

    Graph result = g1;
    result *= g2;
    return result;
}

bool ariel::operator<(const ariel::Graph &g1, const ariel::Graph &g2){
    //case same size
    size_t v1 = g1.numOfVertices();
    size_t v2 = g2.numOfVertices();
    if(v1 == v2){
        return g1._edges < g2._edges;
    }
    if(v1 < v2){
        if(g1._edges < g2._edges){return true;}
        if(g1._edges > g2._edges){return false;}
        return true;   
    }
    //case v1 > v2
    return g1._edges < g2._edges;
}

bool ariel::operator>(const ariel::Graph &g1, const ariel::Graph &g2){
    return g2 < g1;
}

bool ariel::operator==(const ariel::Graph &g1, const ariel::Graph &g2){
    return !(g1 < g2) && !(g1 > g2);
}

bool ariel::operator!=(const ariel::Graph &g1, const ariel::Graph &g2){
    return !(g1 == g2);
}

bool ariel::operator<=(const ariel::Graph &g1, const ariel::Graph &g2){
    return g1 == g2 || g1 < g2;
}

bool ariel::operator>=(const ariel::Graph &g1, const ariel::Graph &g2){
    return g1 == g2 || g1 > g2;
}

std::ostream &ariel::operator<<(std::ostream &os, const ariel::Graph &g){
    int v = g.numOfVertices();
    if(!v){
        return os << "[]" <<endl;
    }
    
    for (int i = 0; i < v; i++)
    {   
        os << "[" << g._graph[i][0];
        for (int j = 1; j < g._graph[i].size(); j++)
        {
            os << ", " << g._graph[i][j];
        }
        os << "]" <<endl;
    }
    return os;
}

