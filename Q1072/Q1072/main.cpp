//
//  main.cpp
//  Q1072
//
//  Created by Pumpkin Lee on 2/10/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    int v, w;
    int distance;
};

struct Graph {
    
    Graph(int v): adjList(v) {
        nV = v;
    }
    
    void addEdge(const Edge &e) {
        adjList[e.v].push_back(e);
        adjList[e.w].push_back(e);
    }
    
    vector<Edge>& edgeTo(int v) {
        return adjList[v];
    }
    
    int nV;
    vector<vector<Edge>> adjList;
};

struct Dijkstra {
    
    Dijkstra(Graph *g, int from) {
        distTo = new int[g->nV];
        fill(distTo, distTo + g->nV, INT32_MAX);
        
        distTo[from] = 0;
        pq.push(pair<int, int>(0, from));
        while (!pq.empty()) {
            int v = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if (distTo[v] < dist) continue;
            vector<Edge> &edges = g->edgeTo(v);
            for (int i=0; i<edges.size(); ++i) {
                Edge &e = edges[i];
                int w = e.v == v ? e.w : e.v;
                
                if (distTo[w] > distTo[v] + e.distance) {
                    distTo[w] = distTo[v] + e.distance;
                    pq.push(pair<int, int>(distTo[w], w));
                }
            }
        }
    }
    
    ~Dijkstra() {
        delete [] distTo;
    }
    
    int *distTo;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
};

int main(int argc, const char * argv[])
{
    int nHouse, nStation, nRoad, threshold;
    scanf("%d %d %d %d", &nHouse, &nStation, &nRoad, &threshold);
    
    Graph *g = new Graph(nHouse + nStation);
    for (int i=0; i<nRoad; ++i) {
        Edge e;
        char a[8], b[8];
        scanf("%s %s %d", a, b, &e.distance);
        if (a[0] == 'G') {
            e.v = nHouse + atoi(a + 1) - 1;
        } else {
            e.v = atoi(a) - 1;
        }
        if (b[0] == 'G') {
            e.w = nHouse + atoi(b + 1) - 1;
        } else {
            e.w = atoi(b) - 1;
        }
        g->addEdge(e);
    }
    
    double minDist = 0.;
    double avgDist = 1e10;
    int result = -1;
    for (int i=nHouse; i<nHouse+nStation; ++i) {
        Dijkstra sp(g, i);
        int *distTo = sp.distTo;
        sort(distTo, distTo + nHouse);
        
        double sum = 0.;
        bool isVaild = true;
        for (int j=0; j<nHouse; ++j) {
            if (distTo[j] > threshold) {
                isVaild = false;
                break;
            } else {
                sum += distTo[j];
            }
        }
        if (isVaild) {
            sum /= nHouse;
            if (distTo[0] > minDist) {
                avgDist = sum;
                minDist = distTo[0];
                result = i;
            } else if (distTo[0] == minDist && sum < avgDist) {
                avgDist = sum;
                result = i;
            }
        }
    }
    if (result > 0) {
        printf("G%d\n", result - nHouse + 1);
        printf("%.01lf %.01lf\n", minDist, avgDist);
    } else {
        printf("No Solution\n");
    }
    
    return 0;
}

// 注意题目，是最小距离最大
// 结果不需要四舍五入
