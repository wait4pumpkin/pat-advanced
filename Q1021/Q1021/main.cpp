//
//  main.cpp
//  Q1021
//
//  Created by Pumpkin Lee on 2/1/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Graph {
    
    Graph(int n) {
        this->n = n;
        adj = new vector<int>[n];
    }
    
    ~Graph() {
        delete [] adj;
    }
    
    void addEdge(int s, int d) {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    
    vector<int>& adjTo(int s) {
        return adj[s];
    }
    
    int n;
    vector<int> *adj;
};

struct DFS {
    DFS(Graph *g) {
        this->g = g;
        isVisited = new bool[g->n];
        memset(isVisited, 0, sizeof(bool) * g->n);
        
        distance = new int[g->n];
        
        nComp = 0;
        for (int i=0; i<g->n; ++i) {
            if (!isVisited[i]) {
                memset(distance, 0, sizeof(int) * g->n);
                distance[i] = 0;
                dfs(i);

                ++nComp;
            }
        }
    }
    
    ~DFS() {
        delete [] isVisited;
        delete [] distance;
    }
    
    int run(int src) {
        memset(distance, 0, sizeof(int) * g->n);
        memset(isVisited, 0, sizeof(bool) * g->n);
        maxDistance = 0;
        distance[src] = 0;
        dfs(src);
        return maxDistance;
    }
    
    void dfs(int src) {
        isVisited[src] = true;
        vector<int> &adj = g->adjTo(src);
        for (int i=0; i<adj.size(); ++i) {
            int k = adj[i];
            if (!isVisited[k]) {
                distance[k] = distance[src] + 1;
                if (distance[k] > maxDistance) maxDistance = distance[k];
                dfs(k);
            }
        }
    }
    
    Graph *g;
    bool *isVisited;
    int *distance;
    int maxDistance;
    int nComp;
};

bool compareByDist(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    Graph *g = new Graph(n);
    for (int i=0; i<n-1; ++i) {
        int s, d;
        scanf("%d %d", &s, &d);
        g->addEdge(s - 1, d - 1);
    }
    
    vector<pair<int, int>> memo;
    DFS dfs(g);
    if (dfs.nComp > 1) {
        printf("Error: %d components", dfs.nComp);
    } else {
        for (int i=0; i<n; ++i) {
            memo.push_back(pair<int, int>(i + 1, dfs.run(i)));
        }
    }
    
    if (dfs.nComp <= 1) {
        sort(memo.begin(), memo.end(), compareByDist);
        int dist = memo[0].second;
        for (int i=0; i<memo.size(); ++i) {
            if (memo[i].second < dist) {
                break;
            } else {
                printf("%d\n", memo[i].first);
            }
        }
    }
    
    delete g;
    
    return 0;
}

// DFS
