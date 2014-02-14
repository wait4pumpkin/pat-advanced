//
//  main.cpp
//  Q1047
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
    char name[5];
};

bool compare(const Student *s1, const Student *s2) {
    return strcmp(s1->name, s2->name) < 0;
}

int main(int argc, const char * argv[])
{
    int nStudent, nCourse;
    scanf("%d %d", &nStudent, &nCourse);
    
    vector<vector<Student *>> database;
    vector<Student *> students;
    for (int i=0; i<nCourse; ++i) {
        database.push_back(vector<Student *>());
    }
    
    char name[5];
    int n;
    for (int i=0; i<nStudent; ++i) {
        scanf("%s %d", name, &n);
        Student *s = new Student();
        strcpy(s->name, name);
        students.push_back(s);
        
        for (int k=0; k<n; ++k) {
            int idx;
            scanf("%d", &idx);
            database[idx - 1].push_back(s);
        }
    }
    
    for (int i=0; i<database.size(); ++i) {
        vector<Student *> &course = database.at(i);
        sort(course.begin(), course.end(), compare);
        printf("%d %ld\n", i + 1, course.size());
        for (int j=0; j<course.size(); ++j) {
            printf("%s\n", course[j]->name);
        }
    }
    
    return 0;
}

