//
//  main.cpp
//  Q1003
//
//  Created by Pumpkin Lee on 2/4/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

struct Edge {
    int v, w;
    double weight;
};

struct Graph {
    Graph(int v): adjList(v) {
        nV = v;
    }
    
    void addEdge(Edge e) {
        adjList[e.v].push_back(e);
        adjList[e.w].push_back(e);
    }
    
    vector<Edge>& adjTo(int v) {
        return adjList[v];
    }
    
    int nV;
    vector<vector<Edge>> adjList;
};

struct Dijkstra {
    Dijkstra(Graph &g, int from, int to): edgeTo(g.nV) {
        distTo = new double[g.nV];
        fill(distTo, distTo + g.nV, INT64_MAX);
        
        distTo[from] = 0;
        pq.push(pair<double, int>(0., from));
        while (!pq.empty()) {
            int v = pq.top().second;
            double dist = pq.top().first;
            pq.pop();
            if (distTo[v] < dist) continue;
            
            vector<Edge> &edges = g.adjTo(v);
            for (int i=0; i<edges.size(); ++i) {
                Edge &e = edges[i];
                int w = e.v == v ? e.w : e.v;
                
                if (distTo[w] > distTo[v] + e.weight) {
                    distTo[w] = distTo[v] + e.weight;
                    edgeTo[w].clear();
                    edgeTo[w].insert(v);
                    pq.push(pair<double, int>(distTo[w], w));
                } else if (distTo[w] == distTo[v] + e.weight) {
                    edgeTo[w].insert(v);
                    pq.push(pair<double, int>(distTo[w], w));
                }
            }
        }
        
        vector<int> path;
        path.push_back(to);
        getPath(to, from, path);
    }
    
    void getPath(int pos, int from, vector<int> &path) {
        if (pos == from) {
            paths.push_back(path);
            return;
        }
        
        set<int> &prevs = edgeTo[pos];
        for (set<int>::iterator it=prevs.begin(); it!=prevs.end(); ++it) {
            path.push_back(*it);
            getPath(*it, from, path);
            path.pop_back();
        }
    }
    
    struct DistCmp{
        bool operator()(const pair<double, int> &p1, const pair<double, int> &p2){
            return p1.first > p2.first;
        }
    };
    
    double *distTo;
    vector<set<int>> edgeTo;
    priority_queue<pair<double, int>, vector<pair<double, int>>, DistCmp> pq;
    vector<vector<int>> paths;
};

using namespace std;

int main(int argc, const char * argv[])
{
    int nCity, nRoad, source, target;
    scanf("%d %d %d %d", &nCity, &nRoad, &source, &target);
    
    vector<int> citys;
    for (int i=0; i<nCity; ++i) {
        int city;
        scanf("%d", &city);
        citys.push_back(city);
    }
    
    Graph g(nCity);
    for (int i=0; i<nRoad; ++i) {
        Edge e;
        scanf("%d %d %lf", &e.v, &e.w, &e.weight);
        g.addEdge(e);
    }
    
    Dijkstra sp(g, source, target);
    int maxHelp = INT32_MIN;
    for (int i=0; i<sp.paths.size(); ++i) {
        vector<int> &path = sp.paths[i];
        int value = 0;
        for (int j=0; j<path.size(); ++j) {
            value += citys[path[j]];
        }
        if (value > maxHelp) {
            maxHelp = value;
        }
    }
    printf("%ld %d\n", sp.paths.size(), maxHelp);
    
    return 0;
}

// Dijkstra修改，把前驱从一个改为set，距离相等时加入set，小于时清空
// 注意，不能用vector，前驱可能会重复
