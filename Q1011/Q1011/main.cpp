//
//  main.cpp
//  Q1011
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[])
{
    double sum = 1.;
    char tag[3];
    for (int i = 0; i < 3; ++i) {
        double w, t, l;
        scanf("%lf %lf %lf", &w, &t, &l);
        if (w > t && w > l) {
            tag[i] = 'W';
            sum *= w;
        } else if (t > l) {
            tag[i] = 'T';
            sum *= t;
        } else {
            tag[i] = 'L';
            sum *= l;
        }
    }
    
    printf("%c %c %c %.2lf", tag[0], tag[1], tag[2], (sum * 0.65 - 1) * 2);

    return EXIT_SUCCESS;
}

// 题目有问题，四舍五入会出错