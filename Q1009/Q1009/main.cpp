//
//  main.cpp
//  Q1009
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    pair<int, double> a[16];
    double result[2048];
    memset(result, 0, sizeof(result));
    
    int ka = 0;
    scanf("%d", &ka);
    for (int i=0; i<ka; ++i) {
        int k;
        double c;
        scanf("%d %lf", &k, &c);
        a[i].first = k;
        a[i].second = c;
    }
    
    int kb = 0;
    scanf("%d", &kb);
    for (int i=0; i<kb; ++i) {
        int k;
        double c;
        scanf("%d %lf", &k, &c);
        
        for (int j=0; j<ka; ++j) {
            result[a[j].first + k] += a[j].second * c;
        }
    }
    
    int counter = 0;
    for (int i=0; i<sizeof(result)/sizeof(result[0]); ++i) {
        if (fabs(result[i]) > 1e-9) {
            ++counter;
        }
    }
    printf("%d", counter);
    for (int i=sizeof(result)/sizeof(result[0])-1; i>=0; --i) {
        if (fabs(result[i]) > 1e-9) {
            printf(" %d %.01lf", i, result[i]);
        }
    }
    
    return 0;
}

// 注意数组大小
