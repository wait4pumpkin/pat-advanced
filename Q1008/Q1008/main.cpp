//
//  main.cpp
//  Q1008
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int nRequest;
    scanf("%d", &nRequest);
    
    int pos = 0;
    int result = 0;
    for (int i=0; i<nRequest; ++i) {
        int floor;
        scanf("%d", &floor);
        
        if (i != 0) {
            result += 5;
        }
        
        int gap = floor - pos;
        if (gap > 0) {
            result += gap * 6;
        } else {
            result += -gap * 4;
        }
        pos = floor;
    }
    
    printf("%d\n", result + 5);
    
    return 0;
}

// 最后一个也要停
