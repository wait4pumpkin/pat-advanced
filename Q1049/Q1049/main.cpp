//
//  main.cpp
//  Q1049
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int num;
    scanf("%d", &num);
//    long counter = 0;
//    char buffer[10];
//    for (int i=1; i<=num; ++i) {
//        sprintf(buffer, "%d", i);
//        char *p = buffer;
//        do {
//            if (*p++ == '1') ++counter;
//        } while (*p);
//    }
//    
//    printf("%ld\n", counter);
    
    int src = num;
    long maxCounter[10];
    long partCounter[10];
    memset(maxCounter, 0, sizeof(maxCounter));
    memset(partCounter, 0, sizeof(partCounter));
    maxCounter[0] = 1;
    if (num % 10 >= 1) partCounter[0] = 1;
    num /= 10;
    int i = 1;
    for (; num > 0; num /= 10, ++i) {
        maxCounter[i] = 10 * maxCounter[i-1] + pow(10, i);
        if (num % 10 > 1) {
            partCounter[i] = (num % 10 - 1) * maxCounter[i-1] + partCounter[i-1] + pow(10, i) + maxCounter[i-1];
        } else if (num % 10 == 1) {
            int base = pow(10, i);
            partCounter[i] += maxCounter[i-1] + src % base + partCounter[i-1] + 1;
        } else {
            partCounter[i] = partCounter[i-1];
        }
    }
    printf("%ld", partCounter[i-1]);
    
    return 0;
}

// 处理好递归公式
