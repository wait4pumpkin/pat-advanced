//
//  main.cpp
//  Q1032
//
//  Created by Pumpkin Lee on 2/6/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int rootA, rootB, nNode;
    scanf("%d %d %d", &rootA, &rootB, &nNode);
    
    int table[100000];
    for (int i=0; i<nNode; ++i) {
        int addr, next;
        char value;
        scanf("%d %c %d", &addr, &value, &next);
        
        table[addr] = next;
    }
    
    stack<int> stackA, stackB;
    int pos = rootA;
    while (pos >= 0) {
        stackA.push(pos);
        pos = table[pos];
    }
    pos = rootB;
    while (pos >= 0) {
        stackB.push(pos);
        pos = table[pos];
    }
    
    int result = -1;
    while (!stackA.empty() && !stackB.empty()) {
        if (stackA.top() != stackB.top()) {
            break;
        } else {
            result = stackA.top();
        }
        stackA.pop();
        stackB.pop();
    }
    
    if (result > 0) {
        printf("%05d", result);
    } else {
        printf("-1");
    }
    
    
    return 0;
}

