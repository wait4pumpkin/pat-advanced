//
//  main.cpp
//  Q1044
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

struct DiamondRange {
    
    bool operator < (const DiamondRange &r) const {
        if (value == r.value) {
            return start < r.start;
        }
        return value < r.value;
    }
    
    int start;
    int end;
    int value;
};

int main(int argc, const char * argv[])
{
    int nDiamond, amount;
    scanf("%d %d", &nDiamond, &amount);
    
    vector<int> nums;
    vector<DiamondRange> result;
    int minValue = INT32_MAX;
    int start = 0;
    int sum = 0;
    for (int i=0; i<nDiamond; ++i) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
        
        sum += num;
        if (sum >= amount) {
            if (sum <= minValue) {
                minValue = sum;
                
                DiamondRange range;
                range.start = start;
                range.end = i;
                range.value = sum;
                result.push_back(range);
            }
            
            while (true) {
                sum -= nums[start];
                ++start;
                if (sum >= amount) {
                    if (sum <= minValue) {
                        minValue = sum;
                        
                        DiamondRange range;
                        range.start = start;
                        range.end = i;
                        range.value = sum;
                        result.push_back(range);
                    }
                } else {
                    break;
                }
            }
        }
    }
    
    sort(result.begin(), result.end());
    int value = result[0].value;
    for (int i=0; i<result.size(); ++i) {
        DiamondRange &r = result[i];
        if (r.value != value) {
            break;
        } else {
            printf("%d-%d\n", r.start + 1, r.end + 1);
        }
    }
    
    return 0;
}

// 一次循环解决，双指针，否则超时
