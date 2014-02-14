//
//  main.cpp
//  Q1038
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX_LENGTH 9

bool numCompare(const char *a, const char *b) {
    size_t lengthA = strlen(a);
    size_t lengthB = strlen(b);
    char *combineA = new char[lengthA + lengthB + 1];
    char *combineB = new char[lengthA + lengthB + 1];
    strcpy(combineA, a);
    strcpy(combineA + lengthA, b);
    strcpy(combineB, b);
    strcpy(combineB + lengthB, a);
    
    int64_t numA = atol(combineA);
    int64_t numB = atol(combineB);
    
    delete [] combineA;
    delete [] combineB;
    return numA < numB;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    vector<char *>nums;
    for (int i = 0; i < n; ++i) {
        char *num = new char[MAX_LENGTH];
        scanf("%s", num);
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end(), numCompare);
    bool isBegin = false;
    for (int i = 0; i < nums.size(); ++i) {
        if (!isBegin && atoi(nums[i]) == 0) {
            continue;
        } else if (!isBegin) {
            isBegin = true;
            printf("%d", atoi(nums[i]));
            continue;
        }
        printf("%s", nums[i]);
    }
    if (!isBegin) {
        printf("0");
    }
    
    return 0;
}

// 算法的关键在于比较，想到就很非常简单
// 注意前导零的处理
// 注意位数，用atol不是atoi
