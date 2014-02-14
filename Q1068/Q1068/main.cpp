//
//  main.cpp
//  Q1068
//
//  Created by Pumpkin Lee on 2/10/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, const char * argv[])
{
    int nCoin, target;
    scanf("%d %d", &nCoin, &target);
    
    vector<int> nums;
    int counter = 0;
    for (int i=0; i<nCoin; ++i) {
        int num;
        scanf("%d", &num);
        if (num > target) {
            ++counter;
        } else {
            nums.push_back(num);
        }
    }
    nCoin -= counter;
    sort(nums.begin(), nums.end(), greater<int>());
    
    vector<vector<int>> memo(nCoin);
    vector<vector<bool>> backTrace(nCoin);
    for (int i=0; i<nCoin; ++i) {
        memo[i] = vector<int>(target+1, 0);
        backTrace[i] = vector<bool>(target+1, false);
    }
    
    bool isFound = false;
    for (int j=1; j<target+1; ++j) {
        if (nums[0] <= j) {
            memo[0][j] = nums[0];
            backTrace[0][j] = true;
        }
        if (memo[0][j] == target) {
            isFound = true;
        }
    }

    for (int i=1; i<nCoin; ++i) {
        for (int j=0; j<target+1; ++j) {
            if (j < nums[i]) {
                memo[i][j] = memo[i-1][j];
            } else {
                int a = memo[i-1][j];
                int b = memo[i-1][j-nums[i]] + nums[i];
                if (b >= a) {
                    memo[i][j] = b;
                    backTrace[i][j] = true;
                } else {
                    memo[i][j] = a;
                }
            }
            if (memo[i][j] == target) {
                isFound = true;
            }
        }
    }
    if (isFound) {
        int k = nCoin - 1;
        bool isFirst = true;
        while (target > 0) {
            if (backTrace[k][target]) {
                target -= nums[k];
                if (isFirst) {
                    printf("%d", nums[k]);
                    isFirst = false;
                } else {
                    printf(" %d", nums[k]);
                }
            }
            --k;
        }
    } else {
        printf("No Solution\n");
    }
    
    return 0;
}

// 递推公式比较容易想到
// 关键是回溯，要取到题目要求的最小序列，必须先降序，不是升序
// 动态规划题目注意初始化以及单个数的情况

