//
//  main.cpp
//  Q1031
//
//  Created by Pumpkin Lee on 2/9/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    char buffer[128];
    fgets(buffer, 128, stdin);
    
    int length = static_cast<int>(strlen(buffer));
    buffer[length-1] = 0;
    --length;
    int n1 = (length + 2) / 3;
    int n2 = length + 2 - 2 * n1;
    for (int i=0; i<n1-1; ++i) {
        printf("%c", buffer[i]);
        for (int j=0; j<n2-2; ++j) {
            printf(" ");
        }
        printf("%c\n", buffer[length-1-i]);
    }
    buffer[n1 + n2 - 1] = 0;
    printf("%s", buffer + n1 - 1);
    
    return 0;
}

// 其实是数学题