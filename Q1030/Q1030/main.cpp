//
//  main.cpp
//  Q1030
//
//  Created by Pumpkin Lee on 2/9/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <map>

using namespace std;

struct Edge {
    int v, w;
    int weight;
    int cost;
};

struct Graph {
    
    Graph(int v): adjList(v) {
        nV = v;
    }
    
    void addEdge(const Edge &e) {
        adjList[e.v].push_back(e);
        adjList[e.w].push_back(e);
        edges.insert(pair<pair<int, int>, Edge>(pair<int, int>(e.v, e.w), e));
    }
    
    vector<Edge>& adjTo(int v) {
        return adjList[v];
    }
    
    int nV;
    vector<vector<Edge>> adjList;
    map<pair<int, int>, Edge> edges;
};

struct Dijkstra {
    
    Dijkstra(Graph *g, int from, int to): edgeTo(g->nV) {
        this->g = g;
        distanceTo = new int[g->nV];
        fill(distanceTo, distanceTo + g->nV, INT32_MAX);
        
        distanceTo[from] = 0;
        pq.push(pair<int, int>(0, from));
        while (!pq.empty()) {
            int v = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if (distanceTo[v] < dist) continue;
            vector<Edge> &edges = g->adjTo(v);
            for (int i=0; i<edges.size(); ++i) {
                Edge &e = edges[i];
                int w = e.v == v ? e.w : e.v;
                
                if (distanceTo[w] > distanceTo[v] + e.weight) {
                    distanceTo[w] = distanceTo[v] + e.weight;
                    edgeTo[w].clear();
                    edgeTo[w].insert(v);
                    pq.push(pair<int, int>(distanceTo[w], w));
                } else if (distanceTo[w] == distanceTo[v] + e.weight) {
                    edgeTo[w].insert(v);
                    pq.push(pair<int, int>(distanceTo[w], w));
                }
            }
        }
        
        lowestCost = INT32_MAX;
        vector<int> path;
        int cost = 0;
        path.push_back(to);
        getPath(to, from, path, cost);
    }
    
    void getPath(int pos, int from, vector<int> &path, int &cost) {
        if (pos == from) {
            if (cost < lowestCost) {
                lowestCost = cost;
                bestPath = path;
            }
            return;
        }
        
        for (set<int>::iterator it=edgeTo[pos].begin(); it!=edgeTo[pos].end(); ++it) {
            path.push_back(*it);
            map<pair<int, int>, Edge>::iterator itE =
                g->edges.find(pair<int, int>(pos < *it ? pos : *it, pos < *it ? *it : pos));
            cost += itE->second.cost;
            getPath(*it, from, path, cost);
            cost -= itE->second.cost;
            path.pop_back();
        }
    }

    Graph *g;
    int *distanceTo;
    vector<set<int>> edgeTo;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int lowestCost;
    vector<int> bestPath;
};

int main(int argc, const char * argv[])
{
    int nCity, nHighway, from, to;
    scanf("%d %d %d %d", &nCity, &nHighway, &from, &to);
    
    Graph *g = new Graph(nCity);
    for (int i=0; i<nHighway; ++i) {
        int v, w;
        Edge e;
        scanf("%d %d %d %d", &v, &w, &e.weight, &e.cost);
        e.v = (v < w ? v : w);
        e.w = (v < w ? w : v);
        g->addEdge(e);
    }
    
    Dijkstra sp(g, from, to);
    vector<int> &path = sp.bestPath;
    printf("%d", from);
    for (int i=static_cast<int>(path.size()-2); i>=0; --i) {
        printf(" %d", path[i]);
    }
    printf(" %d %d", sp.distanceTo[to], sp.lowestCost);
    
    return 0;
}

