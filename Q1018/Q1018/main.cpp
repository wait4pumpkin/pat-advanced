//
//  main.cpp
//  Q1018
//
//  Created by Pumpkin Lee on 2/8/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct Station {
    
    int needed() const {
        return capacity / 2 - nBike;
    }
    
    static int capacity;
    int id;
    int nBike;
};

int Station::capacity = 0;

struct Road {
    int v, w;
    int cost;
};

struct Graph {
    
    Graph(int v) {
        nV = v;
        adjList = new vector<Road *>[v];
    }
    
    void addRoad(Road *r) {
        adjList[r->v].push_back(r);
        adjList[r->w].push_back(r);
    }
    
    vector<Road *>& roadTo(int v) {
        return adjList[v];
    }
    
    int nV;
    vector<Road *> *adjList;
};

struct Dijkstra {
    
    Dijkstra(Graph *g, int s, int to, vector<Station *> &stations) {
        source = s;
        this->stations = stations;
        nBikeTaken = INT32_MAX;
        nBikeBack = INT32_MAX;
        
        distTo = new int[g->nV];
        fill(distTo, distTo + g->nV, INT32_MAX);
        edgeTo = new set<int>[g->nV];
        
        distTo[s] = 0;
        pq.push(pair<int, int>(distTo[s], s));
        while (!pq.empty()) {
            int v = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (distTo[v] < dist) continue;
            
            vector<Road *> roads = g->roadTo(v);
            for (int i=0; i<roads.size(); ++i) {
                Road *r = roads[i];
                int w = r->v == v ? r->w : r->v;
                if (distTo[w] > distTo[v] + r->cost) {
                    distTo[w] = distTo[v] + r->cost;
                    edgeTo[w].clear();
                    edgeTo[w].insert(v);
                    pq.push(pair<int, int>(distTo[w], w));
                } else if (distTo[w] == distTo[v] + r->cost) {
                    edgeTo[w].insert(v);
                    pq.push(pair<int, int>(distTo[w], w));
                }
            }
        }
        
        vector<int> path;
        path.push_back(to);
        getPath(to, path);
    }
    
    void getPath(int pos, vector<int> &path) {
        if (pos == source) {
            int send = 0;
            int nBike = 0;
            for (int i=static_cast<int>(path.size()-2); i>=0; --i) {
                int n = path[i];
                nBike -= stations[n]->needed();
                if (nBike < 0) {
                    send += -nBike;
                    nBike = 0;
                }
            }
            if (send < nBikeTaken || (send == nBikeTaken && nBike < nBikeBack)) {
                nBikeTaken = send;
                nBikeBack = nBike;
                bestPath = path;
            }
            return;
        }
        set<int> &prevs = edgeTo[pos];
        for (set<int>::iterator it=prevs.begin(); it!=prevs.end(); ++it) {
            path.push_back(*it);
            getPath(*it, path);
            path.pop_back();
        }
    }
    
    vector<Station *> stations;
    int source;
    int *distTo;
    set<int> *edgeTo;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> bestPath;
    int nBikeTaken;
    int nBikeBack;
};

int main(int argc, const char * argv[])
{
    int nStation, target, nRoad;
    scanf("%d %d %d %d", &Station::capacity, &nStation, &target, &nRoad);
    
    vector<Station *> stations;
    Station *pbmc = new Station();
    pbmc->id = 0;
    pbmc->nBike = INT32_MAX;
    stations.push_back(pbmc);
    for (int i=1; i<=nStation; ++i) {
        Station *s = new Station();
        s->id = i;
        scanf("%d", &s->nBike);
        stations.push_back(s);
    }
    
    Graph *g = new Graph(nStation + 1);
    for (int i=0; i<nRoad; ++i) {
        Road *r = new Road();
        scanf("%d %d %d", &r->v, &r->w, &r->cost);
        g->addRoad(r);
    }
    
    Dijkstra *sp = new Dijkstra(g, 0, target, stations);
    printf("%d 0", sp->nBikeTaken);
    for (int i=static_cast<int>(sp->bestPath.size()-2); i>=0; --i) {
        printf("->%d", sp->bestPath[i]);
    }
    printf(" %d", sp->nBikeBack);
    
    return 0;
}

// 有一个不合常理的地方，bike只能从src到dst传输，回程时不调整
// 所以send和take back可以均不为零
// 最短路径没什么问题，关键在自行车数计算和路径选择
