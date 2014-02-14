//
//  main.cpp
//  Q1007
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
    
    vector<int> nums;
    vector<int> memo(n, 0);
    bool isAllNegative = true;
    for (int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
        if (num >= 0) isAllNegative = false;
    }
    
    if (isAllNegative) {
        printf("0 %d %d\n", nums[0], nums[n - 1]);
        return 0;
    }
    
    int max = INT32_MIN;
    int start = INT32_MIN;
    int end = INT32_MIN;
    for (int i=0; i<n; ++i) {
        memo[i] = nums[i];
        if (memo[i] > max) {
            max = memo[i];
            start = i;
            end = i;
        }
        
        for (int j=i+1; j<n; ++j) {
            memo[j] = memo[j-1] + nums[j];
            if (memo[j] > max) {
                max = memo[j];
                start = i;
                end = j;
            }
        }
    }
    printf("%d %d %d\n", max, nums[start], nums[end]);
    
    return 0;
}

// 简单的递推关系
// 注意题目提到的特殊情况，全部是负数
