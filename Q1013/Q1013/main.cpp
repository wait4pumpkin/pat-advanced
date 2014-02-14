//
//  main.cpp
//  Q1013
//
//  Created by Pumpkin Lee on 2/6/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Graph {
    
    Graph(int v) {
        nV = v;
        adjList = new vector<int>[v];
    }
    
    ~Graph() {
        delete [] adjList;
    }
    
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
    
    vector<int>& adj(int v) {
        return adjList[v];
    }
    
    int nV;
    vector<int> *adjList;
};

struct DFS {
    DFS(Graph *g, int mask) {
        this->g = g;
        isVisited = new bool[g->nV];
        memset(isVisited, 0, sizeof(bool) * g->nV);
        this->mask = mask;
        
        nComp = 0;
        for (int i=0; i<g->nV; ++i) {
            if (i == mask) continue;
            if (isVisited[i]) continue;
            ++nComp;
            dfs(i);
        }
    }
    
    void dfs(int v) {
        isVisited[v] = true;
        vector<int> adj = g->adj(v);
        for (int i=0; i<adj.size(); ++i) {
            if (adj[i] == mask || isVisited[adj[i]]) continue;
            dfs(adj[i]);
        }
    }
    
    Graph *g;
    int mask;
    int nComp;
    bool *isVisited;
};

int main(int argc, const char * argv[])
{
    int nCity, nHighway, nQuery;
    scanf("%d %d %d", &nCity, &nHighway, &nQuery);
    
    Graph *g = new Graph(nCity);
    for (int i=0; i<nHighway; ++i) {
        int v, w;
        scanf("%d %d", &v, &w);
        g->addEdge(v - 1, w - 1);
    }
    
    for (int i=0; i<nQuery; ++i) {
        int city;
        scanf("%d", &city);
        
        DFS dfs(g, city - 1);
        printf("%d\n", dfs.nComp - 1);
    }
    
    delete g;
    
    return 0;
}

