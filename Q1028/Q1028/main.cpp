//
//  main.cpp
//  Q1028
//
//  Created by Pumpkin Lee on 2/10/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    char name[9];
    int grade;
};

bool compareByID(const Student *s1, const Student *s2) {
    return s1->id < s2->id;
}

bool compareByName(const Student *s1, const Student *s2) {
    int result = strcmp(s1->name, s2->name);
    if (result == 0) {
        return s1->id < s2->id;
    }
    return result < 0;
}

bool compareByGrade(const Student *s1, const Student *s2) {
    if (s1->grade == s2->grade) {
        return s1->id < s2->id;
    }
    return s1->grade < s2->grade;
}

int main(int argc, const char * argv[])
{
    int n, query;
    scanf("%d %d", &n, &query);
    
    vector<Student *> students;
    for (int i=0; i<n; ++i) {
        Student *s = new Student();
        scanf("%d %s %d", &s->id, s->name, &s->grade);
        students.push_back(s);
    }
    
    switch (query) {
        case 1:
            sort(students.begin(), students.end(), compareByID);
            break;
            
        case 2:
            sort(students.begin(), students.end(), compareByName);
            break;
            
        case 3:
            sort(students.begin(), students.end(), compareByGrade);
            break;
            
        default:
            break;
    }
    
    for (int i=0; i<n; ++i) {
        Student *s = students[i];
        printf("%06d %s %d\n", s->id, s->name, s->grade);
    }
    
    return 0;
}

// 时间卡得紧，不能用cin
