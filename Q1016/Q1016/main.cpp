//
//  main.cpp
//  Q1016
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Time {
    
    bool operator < (const Time &t) const {
        if (day == t.day) {
            if (hour == t.hour) {
                return minute < t.minute;
            }
            return hour < t.hour;
        }
        return day < t.day;
    }
    
    int operator - (const Time &t) const {
        int start = (day - 1) * 24 * 60 + hour * 60 + minute;
        int end = (t.day - 1) * 24 * 60 + t.hour * 60 + t.minute;
        return start - end;
    }
    
    int day;
    int hour;
    int minute;
};

struct Record {
    
    double costFromMonthStart(int rate[], int sum) {
        double cost = 0.;
        cost += (time.day - 1) * sum;
        
        for (int i=0; i<time.hour; ++i) {
            cost += rate[i] * 60;
        }
        
        cost += rate[time.hour] * time.minute;
        
        return cost / 100;
    }
    
    char name[21];
    int month;
    Time time;
    bool isOnline;
};

bool compareRecord(const Record *r1, const Record *r2) {
    int result = strcmp(r1->name, r2->name);
    if (result == 0) {
        return r1->time < r2->time;
    }
    return result < 0;
}

int main(int argc, const char * argv[])
{
    int rate[24];
    int rateSum = 0;
    for (int i=0; i<24; ++i) {
        scanf("%d", &rate[i]);
        rateSum += rate[i] * 60;
    }
    
    vector<Record *> database;
    
    int nRecord;
    scanf("%d", &nRecord);
    for (int i=0; i<nRecord; ++i) {
        Record *r = new Record;
        
        char status[16];
        scanf("%s %d:%d:%d:%d %s", r->name, &r->month, &r->time.day, &r->time.hour, &r->time.minute, status);
        if (strcmp(status, "on-line") == 0) {
            r->isOnline = true;
        } else {
            r->isOnline = false;
        }
        
        database.push_back(r);
    }
    
    sort(database.begin(), database.end(), compareRecord);
    
    char name[21];
    int start;
    double costSum = 0.;
    bool isPrinted = false;
    for (int i=0; i<nRecord; ++i) {
        Record *r = database[i];
        if (strcmp(name, r->name) != 0) {
            if (i != 0 && isPrinted) {
                printf("Total amount: $%.02lf\n", costSum);
            }
            
            strcpy(name, r->name);

            costSum = 0.;
            start = -1;
            isPrinted = false;
        }
        if (r->isOnline) {
            start = i;
        } else {
            if (start >= 0) {
                if (!isPrinted) {
                    printf("%s %02d\n", r->name, r->month);
                    isPrinted = true;
                }
                
                Record *s = database[start];
                double sum = r->costFromMonthStart(rate, rateSum) - s->costFromMonthStart(rate, rateSum);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02lf\n", s->time.day, s->time.hour, s->time.minute,
                       r->time.day, r->time.hour, r->time.minute, r->time - s->time, sum);
                costSum += sum;
                start = -1;
            }
        }
    }
    if (isPrinted) {
        printf("Total amount: $%.02lf\n", costSum);
    }
    
    return 0;
}

// 题目太长了
// 题目叙述不清，没有匹配记录的用户不能有输出

