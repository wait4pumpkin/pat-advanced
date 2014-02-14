//
//  main.cpp
//  Q1048
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    long nCoin;
    int target;
    scanf("%ld %d", &nCoin, &target);
    
    int coins[1001];
    memset(coins, 0, sizeof(coins));
    for (long i = 0; i < nCoin; ++i) {
        int coin;
        scanf("%d", &coin);
        if (coin > 1000) continue;
        ++coins[coin];
    }
    
    int i, j;
    bool isFound = false;
    for (i = 1; i < target / 2 + 1; ++i) {
        j = target - i;
        if (i != j && coins[i] > 0 && coins[j] > 0) {
            isFound = true;
            break;
        } else if (i == j && coins[i] > 1) {
            isFound = true;
            break;
        }
    }
    
    if (isFound) {
        printf("%d %d", i, j);
    } else {
        printf("No Solution");
    }
    
    return 0;
}

// 空间换时间，特别注意题目的数量级约束条件