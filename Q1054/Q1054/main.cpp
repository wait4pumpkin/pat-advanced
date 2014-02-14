//
//  main.cpp
//  Q1054
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    
    int nColor = m * n;
    int *colors = new int[nColor];
    for (int i=0; i<nColor; ++i) {
        scanf("%d", &colors[i]);
    }
    
    sort(colors, colors + nColor);
    int idx = -1;
    int lastColor = -1;
    int max = -1;
    int counter = -1;
    for (int i=0; i<nColor; ++i) {
        if (colors[i] != lastColor) {
            lastColor = colors[i];
            counter = 0;
        } else {
            ++counter;
        }
        if (counter > max) {
            max = counter;
            idx = i;
        }
    }
    
    printf("%d\n", colors[idx]);

    return 0;
}

