//
//  main.cpp
//  Q1071
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LENGTH 1050000

int main(int argc, const char * argv[])
{
    char buffer[MAX_LENGTH];
    fgets(buffer, MAX_LENGTH, stdin);
    
    char *p = buffer;
    while (*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p++ -= 'A' - 'a';
            continue;
        }
        if (!(*p >= 'a' && *p <= 'z') && !(*p >= '0' && *p <= '9')) {
            *p = ' ';
        }
        ++p;
    }
//    printf("%s", buffer);
    
    map<string, int> finder;
    p = strtok(buffer, " ");
    int maxCount = 1;
    while (p) {
//        printf("%s\n", p);
        map<string, int>::iterator it = finder.find(string(p));
        if (it == finder.end()) {
            finder.insert(pair<string, int>(string(p), 1));
        } else {
            ++(it->second);
            if (it->second > maxCount) maxCount = it->second;
        }

        p = strtok(NULL, " ");
    }
    
    vector<string> result;
    for (map<string, int>::iterator it=finder.begin(); it!=finder.end(); ++it) {
        if (it->second < maxCount ) {
            continue;
        } else {
            result.push_back(it->first);
        }
    }
    
    sort(result.begin(), result.end());
    printf("%s %d", result[0].data(), maxCount);
    
    return 0;
}

// 没什么限制，常规题
