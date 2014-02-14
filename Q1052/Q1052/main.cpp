//
//  main.cpp
//  Q1052
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int addr;
    int value;
    int next;
};

bool compareByValue(const Node *n1, const Node *n2) {
    return n1->value < n2->value;
}

int main(int argc, const char * argv[])
{
    int nNode, root;
    scanf("%d %d", &nNode, &root);
    
    if (root < 0) {
        printf("0 -1\n");
        return 0;
    }
    
    Node *nodes[102400];
    memset(nodes, 0, sizeof(nodes));
    for (int i=0; i<nNode; ++i) {
        int addr, value, next;
        scanf("%d %d %d", &addr, &value, &next);
        
        Node *s = new Node();
        s->addr = addr;
        s->value = value;
        s->next = next;
        nodes[addr] = s;
    }
    
    vector<Node *> result;
    Node *p = nodes[root];
    while (p) {
        result.push_back(p);
        if (p->next >= 0) {
            p = nodes[p->next];
        } else {
            break;
        }
    }
    
    sort(result.begin(), result.end(), compareByValue);
    printf("%ld %05d\n", result.size(), result[0]->addr);
    for (int i=0; i<result.size(); ++i) {
        printf("%05d %d ", result[i]->addr, result[i]->value);
        if (i < result.size() - 1) {
            printf("%05d\n", result[i+1]->addr);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}

// 注意地址格式
// 不是所有Node都在链表
// 链表为空

