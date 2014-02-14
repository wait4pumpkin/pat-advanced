//
//  main.cpp
//  Q1029
//
//  Created by Pumpkin Lee on 2/1/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char *argv[]) {
    
    int nA, nB;
    scanf("%d", &nA);
    vector<long> rowA;
    for (int i=0; i<nA; ++i) {
        long num;
        scanf("%ld", &num);
        rowA.push_back(num);
    }
    sort(rowA.begin(), rowA.end());
    
    scanf("%d", &nB);
    vector<long> rowB;
    for (int i=0; i<nB; ++i) {
        long num;
        scanf("%ld", &num);
        rowB.push_back(num);
    }
    sort(rowB.begin(), rowB.end());
    
    int middle = (nA + nB + 1) / 2;
    long num;
    for (int i=0, j=0, idx=0; idx<middle; ++idx) {
        if (i >= rowA.size()) {
            num = rowB[j++];
        } else if (j >= rowB.size()) {
            num = rowA[i++];
        } else if (rowA[i] < rowB[j]) {
            num = rowA[i++];
        } else {
            num = rowB[j++];
        }
    }
    printf("%ld\n", num);
    
    return 0;
}

// 两个数组一起sort会超出内存，只能分别排序再用megesort
// 建堆会超时
