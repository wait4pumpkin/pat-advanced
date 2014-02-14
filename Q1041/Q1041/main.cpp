//
//  main.cpp
//  Q1041
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    vector<int> nums;
    int marker[10000];
    bool *flag = new bool[n];
    memset(marker, -1, sizeof(marker));
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
        
        if (marker[num - 1] >= 0) {
            flag[marker[num - 1]] = false;
            marker[num - 1] = i;
            flag[i] = false;
        } else {
            marker[num - 1] = i;
            flag[i] = true;
        }
    }
    
    int i = 0;
    for (; i < n; ++i) {
        if (flag[i]) {
            printf("%d\n", nums.at(i));
            break;
        }
    }
    if (i >= n) {
        printf("None\n");
    }

    delete []flag;
    
    return 0;
}

//用空间换时间，不能用map