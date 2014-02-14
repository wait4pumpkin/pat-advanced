//
//  main.cpp
//  Q1039
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
    vector<int> courses;
};

int hashName(const char name[]) {
    int hash = 0;
    hash += (name[0] - 'A' + 1) * 30 * 30 * 30;
    hash += (name[1] - 'A' + 1) * 30 * 30;
    hash += (name[2] - 'A' + 1) * 30;
    hash += name[3] - '0';
    return hash;
}

int main(int argc, const char * argv[])
{
    int nStudent, nCourse;
    scanf("%d %d", &nStudent, &nCourse);
    
    Student* finder[30 * 30 * 30 * 30];
    memset(finder, 0, sizeof(finder));
    
    for (int i=0; i<nCourse; ++i) {
        int id, n;
        scanf("%d %d", &id, &n);
        
        for (int k=0; k<n; ++k) {
            char name[5];
            scanf("%s", name);
            
            int hash = hashName(name);
            Student *s = finder[hash];
            if (!s) {
                s = new Student();
                finder[hash] = s;
            }
            s->courses.push_back(id);
        }
    }

    for (int i=0; i<nStudent; ++i) {
        char name[5];
        scanf("%s", name);
        printf("%s", name);
        
        Student *s = finder[hashName(name)];
        if (!s) {
            printf(" 0\n");
            continue;
        }
        vector<int> &result = s->courses;
        printf(" %ld", result.size());
        sort(result.begin(), result.end());
        for (int i=0; i<result.size(); ++i) {
            printf(" %d", result[i]);
        }
        printf("\n");
    }
    
    return 0;
}

// multimap内存超限，用int代替string
// multimap超时，换成数组
