//
//  main.cpp
//  Q1004
//
//  Created by Pumpkin Lee on 2/5/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
//    int id;
    vector<Node *> children;
    bool isLeaf;
    int level;
};

bool compareByLevel(const Node *n1, const Node *n2) {
    return n1->level < n2->level;
}

int main(int argc, const char * argv[])
{
    int nNode, nNonLeafNode;
    scanf("%d %d", &nNode, &nNonLeafNode);
    
    Node **nodes = new Node*[nNode];
    for (int i=0; i<nNode; ++i) {
        nodes[i] = new Node();
        nodes[i]->isLeaf = true;
    }
    for (int i=0; i<nNonLeafNode; ++i) {
        int id;
        scanf("%d", &id);
        Node *n = nodes[id - 1];
        n->isLeaf = false;
        
        int nChild;
        scanf("%d", &nChild);
        for (int k=0; k<nChild; ++k) {
            int child;
            scanf("%d", &child);
            n->children.push_back(nodes[child - 1]);
        }
    }

    queue<Node *> processQueue;
    nodes[0]->level = 1;
    processQueue.push(nodes[0]);
    while (!processQueue.empty()) {
        Node *n = processQueue.front();
        processQueue.pop();
        for (int i=0 ; i<n->children.size(); ++i) {
            n->children[i]->level = n->level + 1;
            processQueue.push(n->children[i]);
        }
    }
    
    sort(nodes, nodes + nNode, compareByLevel);
    if (!nodes[0]->isLeaf) {
        printf("0");
    } else {
        printf("1");
        return 0;
    }
    int sum = 0;
    int level = 1;
    for (int i=0; i<nNode; ++i) {
        Node *n = nodes[i];
        if (n->level != level) {
            if (level != 1) printf(" %d", sum);
            sum = 0;
            level = n->level;
        }
        if (n->isLeaf) {
            ++sum;
        }
    }
    printf(" %d", sum);
    
    return 0;
}

