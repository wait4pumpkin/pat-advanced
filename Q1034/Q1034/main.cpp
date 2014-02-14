//
//  main.cpp
//  Q1034
//
//  Created by Pumpkin Lee on 2/6/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Edge {
    int v, w;
    int weight;
};

struct Graph {
    
    Graph(int v): adjList(v), degree(v, 0) {
        nV = v;
    }
    
    void addEdge(Edge *e) {
        adjList[e->v].push_back(e);
        adjList[e->w].push_back(e);
        
        degree[e->v] += e->weight;
        degree[e->w] += e->weight;
    }

    int nV;
    vector<vector<Edge *>> adjList;
    vector<int> degree;
};

struct DFS {
    
    DFS(Graph *g) {
        this->g = g;
        isVisited = new bool[g->nV];
        memset(isVisited, 0, sizeof(bool) * g->nV);
        
        for (int i=0; i<g->nV; ++i) {
            if (!isVisited[i]) {
                set<int> comp;
                dfs(i, comp);
                components.push_back(comp);
            }
        }
    }
    
    void dfs(int v, set<int> &comp) {
        comp.insert(v);
        isVisited[v] = true;
        vector<Edge *> &adj = g->adjList[v];
        for (int i=0; i<adj.size(); ++i) {
            Edge *e = adj[i];
            int w = e->v == v ? e->w : e->v;
            if (!isVisited[w]) {
                dfs(w, comp);
            }
        }
    }
    
    Graph *g;
    vector<set<int>> components;
    bool *isVisited;
};

int main(int argc, const char * argv[])
{
    int nRecord, threshold;
    scanf("%d %d", &nRecord, &threshold);
    
    map<string, int> nameTable;
    vector<string> names;
    vector<Edge *> edges;
    for (int i=0; i<nRecord; ++i) {
        Edge *e = new Edge();
        string a, b;
        cin >> a >> b >> e->weight;
        
        map<string, int>::iterator it = nameTable.find(a);
        if (it == nameTable.end()) {
            e->v = static_cast<int>(names.size());
            nameTable.insert(pair<string, int>(a, e->v));
            names.push_back(a);
        } else {
            e->v = it->second;
        }
        it = nameTable.find(b);
        if (it == nameTable.end()) {
            e->w = static_cast<int>(names.size());
            nameTable.insert(pair<string, int>(b, e->w));
            names.push_back(b);
        } else {
            e->w = it->second;
        }
        
        edges.push_back(e);
    }
    
    Graph *g = new Graph(static_cast<int>(names.size()));
    for (int i=0; i<edges.size(); ++i) {
        g->addEdge(edges[i]);
    }
    
    DFS dfs(g);
    vector<pair<string, int>> result;
    for (int i=0; i<dfs.components.size(); ++i) {
        set<int> &comp = dfs.components[i];
        if (comp.size() <= 2) continue;
        int sum = 0;
        int maxPos = -1;
        int max = INT32_MIN;
        for (set<int>::iterator it=comp.begin(); it!=comp.end(); ++it) {
            int degree = g->degree[*it];
            sum += degree;
            if (degree > max) {
                max = degree;
                maxPos = *it;
            }
        }
        sum /= 2;
        if (sum > threshold) {
            result.push_back(pair<string, int>(names[maxPos], comp.size()));
        }
    }
    
    printf("%ld\n", result.size());
    sort(result.begin(), result.end());
    for (int i=0; i<result.size(); ++i) {
        printf("%s %d\n", result[i].first.data(), result[i].second);
    }
    
    return 0;
}

// 理清思路，用好数据结构
