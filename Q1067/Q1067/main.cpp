//
//  main.cpp
//  Q1067
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    vector<int> nums;
    int *numPos = new int[n];
    for (int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
        
        numPos[num] = i;
    }
    
    int counter = 0;
    int sortPos = 0;
    while (true) {
        if (numPos[0] == 0) {
            int i = sortPos;
            for (; i<n; ++i) {
                if (nums[i] != i) break;
            }
            if (i == n) break;
            sortPos = i;
            
            nums[0] = nums[i];
            numPos[nums[i]] = 0;
            nums[i] = 0;
            numPos[0] = i;
            ++counter;
        } else {
            int *zeroPos = &numPos[0];
            int target = numPos[*zeroPos];
            nums[*zeroPos] = *zeroPos;
            numPos[*zeroPos] = *zeroPos;
            nums[target] = 0;
            *zeroPos = target;
            ++counter;
        }
    }
    
    printf("%d\n", counter);
    
    delete [] numPos;
    
    return 0;
}


// 看错题了，第一个数不是序列的，是代表N
// 题目其实很简单
// 加快速度，增加索引，记录已排序的位置
