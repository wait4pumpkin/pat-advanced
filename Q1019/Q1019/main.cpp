//
//  main.cpp
//  Q1019
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    long num, base;
    scanf("%ld %ld", &num, &base);
    
    if (num == 0) {
        printf("Yes\n0");
        return 0;
    }
    
    long buffer[256];
    int idx = 0;
    while (num > 0) {
        buffer[idx++] = num % base;
        num /= base;
    }
    
    bool isAC = true;
    for (int i=idx-1; i>=idx/2; --i) {
        if (buffer[i] != buffer[idx-i-1]) {
            isAC = false;
            break;
        }
    }
    
    if (isAC) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i=idx-1; i>=0; --i) {
        printf("%ld", buffer[i]);
        if (i != 0) printf(" ");
    }
    
    return 0;
}

// 题目已经提示，0是特殊
