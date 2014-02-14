//
//  main.cpp
//  Q1046
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    long *distance = new long[n + 1];
    distance[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int d;
        scanf("%d", &d);
        distance[i] = d + distance[i - 1];
    }
    
    int nQuery;
    scanf("%d", &nQuery);
    for (int i = 0; i < nQuery; ++i) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        
        long dist = abs(distance[dst - 1] - distance[src - 1]);
        printf("%ld\n", min(dist, distance[n] - dist));
    }
    
    delete [] distance;
    
    return 0;
}

// 时间要求严格
// 必需预计算所有距离
