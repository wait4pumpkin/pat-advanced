//
//  main.cpp
//  Q1053
//
//  Created by Pumpkin Lee on 2/6/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    vector<Node *> children;
    Node *parent;
    int result;
};

void travel(Node *root) {
    if (root->parent) {
        root->result = root->parent->result + root->value;
    }
    for (int i=0; i<root->children.size(); ++i) {
        travel(root->children[i]);
    }
}

struct Path {
    
    Path(Node *leaf) {
        Node *p = leaf;
        while (p) {
            data.push_back(p->value);
            p = p->parent;
        }
    }
    
    bool operator < (const Path &p) const {
        vector<int>::const_reverse_iterator itA = data.crbegin();
        vector<int>::const_reverse_iterator itB = p.data.crbegin();
        while (itA != data.crend() && itB != p.data.crend()) {
            if (*itA != *itB) {
                return *itA < *itB;
            }
            ++itA;
            ++itB;
        }
        return false;
    }
    
    vector<int> data;
};

int main(int argc, const char * argv[])
{
    Node *root = NULL;
    Node *nodes[100];
    memset(nodes, 0, sizeof(Node *) * 100);
    
    int nNode, nLine, target;
    scanf("%d %d %d", &nNode, &nLine, &target);
    
    for (int i=0; i<nNode; ++i) {
        int value;
        scanf("%d", &value);
        
        nodes[i] = new Node();
        nodes[i]->value = value;
    }
    root = nodes[0];
    root->parent = NULL;
    root->result = root->value;

    
    for (int i=0; i<nLine; ++i) {
        int id, nChild;
        scanf("%d %d", &id, &nChild);
        
        Node *s = nodes[id];
        for (int k=0; k<nChild; ++k) {
            int child;
            scanf("%d", &child);

            nodes[child]->parent = s;
            s->children.push_back(nodes[child]);
        }
    }
    
    travel(root);
    vector<Path> result;
    for (int i=0; i<nNode; ++i) {
        if (!nodes[i]) continue;
        if (nodes[i]->result == target && nodes[i]->children.size() <= 0) result.push_back(Path(nodes[i]));
    }
    sort(result.begin(), result.end());

    for (int i=static_cast<int>(result.size()-1); i>=0; --i) {
        vector<int> &path = result[i].data;
        int pos = static_cast<int>(path.size() - 1);
        printf("%d", path[pos--]);
        for (; pos>=0; --pos) {
            printf(" %d", path[pos]);
        }
        printf("\n");
    }
    
    return 0;
}

// 注意，无法比较时要返回false，否则会运行超时或者段错误
