//
//  main.cpp
//  Q1045
//
//  Created by Pumpkin Lee on 2/10/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    int nFavorite;
    scanf("%d", &nFavorite);
    vector<int> favorite;
    for (int i=0; i<nFavorite; ++i) {
        int c;
        scanf("%d", &c);
        favorite.push_back(c);
    }
    
    int nStripe;
    scanf("%d", &nStripe);
    vector<int> stripe;
    for (int i=0; i<nStripe; ++i) {
        int c;
        scanf("%d", &c);
        stripe.push_back(c);
    }
    
    vector<vector<int>> memo(nFavorite);
    for (int i=0; i<nFavorite; ++i) {
        memo[i] = vector<int>(nStripe, 0);
    }
    
    int count = 0;
    for (int j=0; j<nStripe; ++j) {
        count += favorite[0] == stripe[j] ? 1 : 0;
        memo[0][j] = count;
    }
    
    int max = count;
    for (int i=1; i<nFavorite; ++i) {
        memo[i][0] = favorite[i] == stripe[0] ? 1 : memo[i-1][0];
        if (memo[i][0] > max) {
            max = memo[i][0];
        }
        
        for (int j=1; j<nStripe; ++j) {
            int a = memo[i - 1][j - 1];
            int b = memo[i][j - 1];
            memo[i][j] = a > b ? a : b;
            if (favorite[i] == stripe[j]) {
                ++memo[i][j];
            }
            
            if (memo[i][j] > max) {
                max = memo[i][j];
            }
        }
    }
    printf("%d\n", max);
    
    return 0;
}

// 动态规划的一般题目，关键找到递推公式
// 同时注意初始化，即0的情况
