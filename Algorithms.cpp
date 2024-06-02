// 316289495
// tzvirechel@gmail.com


#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "Graph.hpp"
#include "Algorithms.hpp"
#define INF 99999
#define WHITE 0
#define GRAY 1
#define BLACK 2
static int isCycle = 0;

using namespace std;

int ariel::Algorithms::isConnected(Graph g){
    int n = g.numOfVertices();
    if(n == 0){
        throw runtime_error("Graph has no vertices");
    }
    vector<vector<int>> mat = g.getMatrix();
    vector<int> visited(n, 0);
    queue<int> q;

    //Run BFS from vertex 0
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int j=0;j<n;j++){
            if(mat[current][j] && !visited[j]){
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    // If any vertex is not visited, the graph is not strongly connected
    for(int i=0;i<n;i++){
        if(!visited[i]){
            return 0;
        }
        else{ // Reset visited array for the second BFS
            visited[i] = 0;
        }
    }
    // Run BFS from vertex 0 in the transpose of g
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(mat[i][current] && !visited[i]){
                visited[i] = 1;
                q.push(i);
        }
    }
    }
    // If any vertex is not visited, it implies there is no path to vertex 0
    // and the graph is not strongly connected
    for(int i=0;i<n;i++){
        if(!visited[i]){
            return 0;
        }
    } 
       
    return 1; 
}

string ariel::Algorithms::shortestPath(Graph g, int start, int end){
    if(g.numOfVertices() == 0){
        throw runtime_error("Graph has no vertices");
    }

    if(start<0 || start>=g.numOfVertices() || end<0 || end>=g.numOfVertices()){
        throw invalid_argument("at least one of the vertices does not exist");
    }
    if(negativeCycle(g) != "0"){
        cout << "negative cycle detected" << endl;
        return "-1";
    }
    
    vector<vector<int>> mat = g.getMatrix();
    int n = g.numOfVertices();
    vector<vector<int>> prev(n, vector<int>(n)); //Matrix to keep the last vertex in the path

    // Initialize matrix and prev before Floyd Warshall algorithm
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && mat[i][j] == 0){
                mat[i][j] = INF;
                prev[i][j] = -1;
            }
            else{
                prev[i][j] = i;
            }
        }
    }

     // Floyd Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(mat[i][j]>mat[i][k]+mat[k][j]){
                    mat[i][j] = mat[i][k]+mat[k][j];
                    prev[i][j] = prev[k][j];
                }
            }    
        }
    }
    string ans;
    if(mat[start][end]==INF){
        ans += to_string(-1);
        return ans;
    }

    // Print the path using prev
    int p = end;
    stack<int> path;
    while(p!=start){
        path.push(p);
        p = prev[start][p];
    }
    ans += to_string(p);
    while(!path.empty()){
        ans += "->";
        ans += to_string(path.top());
        path.pop();
    }
    return ans; 
}

void ariel::Algorithms::dfsVisit(int v, vector<vector<int>>& mat, vector<int>& visited, stack<int>& path, bool isDirected){
    visited[v] = GRAY;
    path.push(v);
    int n = visited.size();
    for(int j=0;j<n;j++){
        if(mat[v][j]){
            if(visited[j] == GRAY){  // If j is currently being visited (GRAY), there is a cycle
                //Check if the cycle contains more than two vertices
                if(!isDirected){
                    int t = path.top();
                    path.pop();
                    if(j!=path.top()){
                        path.push(t);
                        path.push(j);
                        isCycle = 1;
                        return;
                    }
                    path.push(t);
                }
                else{
                    path.push(j);
                        isCycle = 1;
                        return;
                }    
            }    
            if(visited[j] == WHITE){
                dfsVisit(j, mat, visited, path, isDirected);
                if(isCycle){break;} /// If a cycle is found in the recursive call, stop searching
            }  
        }
    }
    if(isCycle){return;} // If a cycle is found, stop the current DFS traversal
    visited[v] = BLACK;
    path.pop();
    
}

string ariel::Algorithms::isContainsCycle(Graph g){
    if(g.numOfVertices() == 0){
        throw runtime_error("Graph has no vertices");
    }

    vector<vector<int>> mat = g.getMatrix();
    int n = g.numOfVertices();
    vector<int> visited(n, WHITE);
    stack<int> path;
    bool isDirected = g.isDirected();
    //Run DFS to check if there is back edge
    for(int i=0;i<n;i++){
        if(visited[i] == WHITE){
            dfsVisit(i, mat, visited, path, isDirected);
            if(isCycle){break;}      
        }
    }
    string ans;
    if(!isCycle){
        ans += to_string(0);
        return ans;
    }

    // Print the cycle by reversing the path stack
    stack<int> temp;
    int t = path.top();
    path.pop();
    if(g.isDirected() && t == path.top()){return to_string(t) + "->" + to_string(t);}
    path.push(t);
    while(!path.empty()){
        int t = path.top();
        path.pop();
        temp.push(t);
        
    }
    ans += to_string(temp.top());
    temp.pop();
    while(!temp.empty()){
        ans += "->";
        ans += to_string(temp.top());
        temp.pop();
    }
    isCycle = 0; // Reset the flag for the next call

   return ans;
}

string ariel::Algorithms::negativeCycle(Graph g){
    if(g.numOfVertices() == 0){
        throw runtime_error("Graph has no vertices");
    }

    vector<vector<int>> mat = g.getMatrix();
    int n = g.numOfVertices();
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    bool flag = false;
    dist[0] = 0;
    // Relax edges repeatedly n-1 times
     for (int k = 0; k < n; k++) {
        for (int i= 0; i < n; i++) {
            for (int j= 0; j < n; j++) {
                if(g.isDirected()){
                    if(mat[i][j] && dist[j]>dist[i]+mat[i][j]){
                        dist[j] = dist[i]+mat[i][j];
                        prev[j] = i;
                    }
                }
                else{ // If the graph is undirected check if prev[i]!=j
                    if(mat[i][j] && dist[j]>dist[i]+mat[i][j] && prev[i]!=j){
                        dist[j] = dist[i]+mat[i][j];
                        prev[j] = i;
                    }

                }

            }
        }
     }
     // Relax edges one more time to detect if there is a negative cycle
     int i, j;
     for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if(g.isDirected()){
                if(mat[i][j] && dist[j]>dist[i]+mat[i][j]){
                    flag = true;
                    break;
                }
                }
                else{ // If the graph is undirected check if prev[i]!=j
                    if(mat[i][j] && dist[j]>dist[i]+mat[i][j] && prev[i]!=j){
                    flag = true;
                    break;
                    }
                }
            }
            if(flag){break;}
    }

    string ans;
    if(!flag){
        ans += "0";
    }
    else{  

        //Print the negative cycle path using the parent array
        if(prev[j]==j){return to_string(j) + "->" + to_string(j);}
        int p = i;
        for (int k = 0; k < n; k++) {
            p = prev[p];
        }

        stack<int> path;
        for(int temp=p;;temp=prev[temp]){
            path.push(temp);
            if(temp == p && path.size()>1){
                break;
            }
        }
        ans += to_string(path.top());
        path.pop();
        while(!path.empty()){
            ans += "->";
            ans += to_string(path.top());
            path.pop();
       } 
    }
    
    return ans;
}

string ariel::Algorithms::isBipartite(Graph g){
    if(g.numOfVertices() == 0){
        throw runtime_error("Graph has no vertices");
    }
    if(g.numOfVertices() == 1){
        return "0";
    }
    string ans;
    int n = g.numOfVertices();
    vector<vector<int>> mat = g.getMatrix();
    vector<char> color(n, -1);
    queue<int> q;

    //Run BFS from vertex 0
    q.push(0);
    color[0] = WHITE;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int j=0;j<n;j++){
            if(mat[current][j] && color[j]==-1){
                color[j] = !color[current];
                q.push(j);
            }
            if(mat[current][j] && color[j]==color[current]){
                ans += to_string(0);
                return ans;
            }
        }
    }
    
    ans += "The graph is bipartite: A={";
    
    for(int i=0;i<n;i++){
        if(!color[i]){
            ans += to_string(i);
            ans += ", ";
        }
    }
    ans = ans.substr(0, ans.size() - 2);
    ans += "}, B={";
    for(int i=0;i<n;i++){
        if(color[i]){
            ans += to_string(i);
            ans += ", ";
        }
    }
    ans = ans.substr(0, ans.size() - 2);
    ans += "}";
    return ans;
}