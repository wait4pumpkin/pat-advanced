//
//  main.cpp
//  Q1002
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int k;
    double sum[2048];
    memset(sum, 0, sizeof(sum));
    
    scanf("%d", &k);
    for (int i=0; i<k; ++i) {
        int n;
        double a;
        scanf("%d %lf", &n, &a);
        sum[n] += a;
    }
    
    scanf("%d", &k);
    for (int i=0; i<k; ++i) {
        int n;
        double a;
        scanf("%d %lf", &n, &a);
        sum[n] += a;
    }
    
    int counter = 0;
    for (int i=0; i<sizeof(sum)/sizeof(sum[0]); ++i) {
        if (fabs(sum[i]) > 1e-9) {
            ++counter;
        }
    }
    printf("%d", counter);
    
    for (int i=sizeof(sum)/sizeof(sum[0])-1; i>=0; --i) {
        if (fabs(sum[i]) > 1e-9) {
            printf(" %d %.1lf", i, sum[i]);
        }
    }
    
    return 0;
}

// 低级错误，数据越界。。。。。。。。。。。
// int i=sizeof(sum)/sizeof(sum[0])-1
// 要减一！！！