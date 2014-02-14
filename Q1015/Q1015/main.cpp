//
//  main.cpp
//  Q1015
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

bool isPrime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    
    for (int i=2; i<num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int num, d;
    while (true) {
        scanf("%d", &num);
        if (num < 0) break;
        scanf("%d", &d);
        
        if (!isPrime(num)) {
            printf("No\n");
            continue;
        }
        
        char str[32];
        int idx = 0;
        while (num > 0) {
            str[idx++] = num % d + '0';
            num /= d;
        }
        str[idx] = '\0';
        
        int base = 1;
        num = 0;
        while (--idx >= 0) {
            num += (str[idx] - '0') * base;
            base *= d;
        }

        if (!isPrime(num)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    
    return 0;
}

// 题目表述不清，是按D进制反转再转为十进制
// 特殊情况0和1
