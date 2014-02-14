//
//  main.cpp
//  Q1012
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct Student {
    
    Student(char *id, int c, int m, int e) {
        this->id = id;
        code = c;
        math = m;
        eng = e;
        avg = (c + m + e) / 3.;
    }

    ~Student() {
        delete[] id;
    }
    
    void printBestRank() {
        if (rankA <= rankC && rankA <= rankM && rankA <= rankE) {
            printf("%d %c\n", rankA, 'A');
        } else if (rankC <= rankM && rankC <= rankE) {
            printf("%d %c\n", rankC, 'C');
        } else if (rankM <= rankE) {
            printf("%d %c\n", rankM, 'M');
        } else {
            printf("%d %c\n", rankE, 'E');
        }
    }
    
    char *id;
    int code, rankC;
    int math, rankM;
    int eng, rankE;
    double avg;
    int rankA;
};

bool compareByAvg(const Student *s1, const Student *s2) {
    if (s1->avg == s2->avg) {
        return strcmp(s1->id, s2->id) < 0;
    } else {
        return s1->avg > s2->avg;
    }
}

bool compareByCode(const Student *s1, const Student *s2) {
    if (s1->code == s2->code) {
        return strcmp(s1->id, s2->id) < 0;
    } else {
        return s1->code > s2->code;
    }
}

bool compareByMath(const Student *s1, const Student *s2) {
    if (s1->math == s2->math) {
        return strcmp(s1->id, s2->id) < 0;
    } else {
        return s1->math > s2->math;
    }
}

bool compareByEng(const Student *s1, const Student *s2) {
    if (s1->eng == s2->eng) {
        return strcmp(s1->id, s2->id) < 0;
    } else {
        return s1->eng > s2->eng;
    }
}

int main(int argc, const char * argv[])
{
    int nStudent = 0, nQuery = 0;
    scanf("%d %d", &nStudent, &nQuery);
    
    map<int, Student *> database;
    vector<Student *> students;
    for (int i = 0; i < nStudent; ++i) {
        char *id = new char[7];
        int c, m, e;
        scanf("%s %d %d %d", id, &c, &m, &e);
        Student *s = new Student(id, c, m, e);
        students.push_back(s);
        database.insert(pair<int, Student *>(atoi(id), s));
    }
    
    sort(students.begin(), students.end(), compareByAvg);
    double avg = -1;
    int rank = 1;
    for (int i = 0; i < students.size(); ++i) {
        Student *s = students.at(i);
        if (s->avg != avg) {
            avg = s->avg;
            rank = i + 1;
        }
        s->rankA = rank;
    }
    
    sort(students.begin(), students.end(), compareByCode);
    int score = -1;
    rank = 1;
    for (int i = 0; i < students.size(); ++i) {
        Student *s = students.at(i);
        if (s->code != score) {
            score = s->code;
            rank = i + 1;
        }
        s->rankC = rank;
    }
    
    sort(students.begin(), students.end(), compareByMath);
    score = -1;
    rank = 1;
    for (int i = 0; i < students.size(); ++i) {
        Student *s = students.at(i);
        if (s->math != score) {
            score = s->math;
            rank = i + 1;
        }
        s->rankM = rank;
    }
    
    sort(students.begin(), students.end(), compareByEng);
    score = -1;
    rank = 1;
    for (int i = 0; i < students.size(); ++i) {
        Student *s = students.at(i);
        if (s->eng != score) {
            score = s->eng;
            rank = i + 1;
        }
        s->rankE = rank;
    }
    
    for (int i = 0; i < nQuery; ++i) {
        int query;
        scanf("%d", &query);
        map<int, Student *>::iterator it = database.find(query);
        if (it == database.end()) {
            printf("N/A\n");
        } else {
            (*it).second->printBestRank();
        }
    }

    return 0;
}

