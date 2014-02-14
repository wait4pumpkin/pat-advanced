//
//  main.cpp
//  Q1036
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    
    bool operator < (const Student &s) const {
        return score < s.score;
    }
    
    char name[11];
    char gender;
    char id[11];
    int score;
};

int main(int argc, const char * argv[])
{
    int nStudent;
    scanf("%d", &nStudent);
    
    vector<Student> males;
    vector<Student> females;
    for (int i = 0; i < nStudent; ++i) {
        Student s;
        scanf("%s %c %s %d", s.name, &s.gender, s.id, &s.score);
        if (s.gender == 'M') {
            males.push_back(s);
        } else {
            females.push_back(s);
        }
    }
    
    bool isAbsent = false;
    int highScore, lowScore;
    if (females.size() <= 0) {
        isAbsent = true;
        printf("Absent\n");
    } else {
        sort(females.begin(), females.end());
        Student s = females.at(females.size() - 1);
        highScore = s.score;
        printf("%s %s\n", s.name, s.id);
    }
    
    if (males.size() <= 0) {
        isAbsent = true;
        printf("Absent\n");
    } else {
        sort(males.begin(), males.end());
        Student s = males.at(0);
        lowScore = s.score;
        printf("%s %s\n", s.name, s.id);
    }
    
    if (isAbsent) {
        printf("NA\n");
    } else {
        printf("%d\n", highScore - lowScore);
    }
    
    return 0;
}

