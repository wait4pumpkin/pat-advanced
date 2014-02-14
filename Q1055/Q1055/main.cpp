//
//  main.cpp
//  Q1055
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

struct Billionaire {
    
    char name[9];
    int age;
    int worths;
};

struct CompareByAge {
    bool operator () (const Billionaire *p1, const Billionaire *p2) {
        if (p1->age == p2->age) {
            if (p1->worths == p2->worths) {
                return strcmp(p1->name, p2->name) < 0;
            }
            return p1->worths < p2->worths;
        }
        return p1->age < p2->age;
    }
};

struct CompareByWorth {
    bool operator () (const Billionaire *p1, const Billionaire *p2) {
        if (p1->worths == p2->worths) {
            if (p1->age == p2->age) {
                return strcmp(p1->name, p2->name) < 0;
            }
            return p1->age < p2->age;
        }
        return p1->worths > p2->worths;
    }
};

int main(int argc, const char * argv[])
{
    int nPerson, nQuery;
    scanf("%d %d", &nPerson, &nQuery);
    
    int counter[256];
    fill(counter, counter + 256, 0);
    vector<Billionaire *> buffer;
    for (int i=0; i<nPerson; ++i) {
        Billionaire *p = new Billionaire();
        scanf("%s %d %d", p->name, &p->age, &p->worths);
        buffer.push_back(p);
    }
    sort(buffer.begin(), buffer.end(), CompareByWorth());
    
    vector<Billionaire *> database;
    for (int i=0; i<buffer.size(); ++i) {
        Billionaire *p = buffer[i];
        if (counter[p->age] > 100) {
            continue;
        } else {
            ++counter[p->age];
            database.push_back(p);
        }
    }
    
    for (int i=0; i<nQuery; ++i) {
        int n, minAge, maxAge;
        scanf("%d %d %d", &n, &minAge, &maxAge);
        
        printf("Case #%d:\n", i+1);
        bool isFound = false;
        for (int i=0, cnt=0; cnt<n && i<database.size(); ++i) {
            Billionaire *p = database[i];
            if (p->age >= minAge && p->age <= maxAge) {
                isFound = true;
                printf("%s %d %d\n", p->name, p->age, p->worths);
                ++cnt;
            }
        }
        if (!isFound) {
            printf("None\n");
        }
    }
    
    return 0;
}

// 分清升序降序
// vector放指针比较简便
// 想复杂了，其实就是直接排序，每次查询直接线性查找
// 超时问题注意题目条件，每次返回结果最多一百，可以直接删除部分数据
