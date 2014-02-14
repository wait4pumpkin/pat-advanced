//
//  main.cpp
//  Q1059
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>

bool isPrime(long num) {
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    long num;
    scanf("%ld", &num);
    
    printf("%ld=", num);
    if (num == 1) {
        printf("1");
        return 0;
    }
    
    bool isFirst = true;
    for (long i = 2; i <= num; ++i) {
        if (isPrime(i)) {
            int k = 0;
            while (num % i == 0) {
                num /= i;
                ++k;
            }
            if (k > 0) {
                if (isFirst) {
                    isFirst = false;
                } else {
                    printf("*");
                }
                if (k > 1) {
                    printf("%ld^%d", i, k);
                } else {
                    printf("%ld", i);
                }
            }
        }
    }
    
    return 0;
}

// 特殊情况1