//
//  main.cpp
//  Q1017
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Time {
    
    Time operator + (int min) const {
        Time result = *this;
        result.minute += min;
        result.hour += result.minute / 60;
        result.minute %= 60;
        
        return result;
    }
    
    int operator - (const Time &t) const {
        return hour * 3600 + minute * 60 + second - t.hour * 3600 - t.minute * 60 - t.second;
    }
    
    bool operator < (const Time &t) const {
        if (hour == t.hour) {
            if (minute == t.minute) {
                return second < t.second;
            }
            return minute < t.minute;
        }
        return hour < t.hour;
    }
    
    bool operator >= (const Time &t) const {
        if (hour == t.hour) {
            if (minute == t.minute) {
                return second >= t.second;
            }
            return minute >= t.minute;
        }
        return hour >= t.hour;
    }
    
    int hour;
    int minute;
    int second;
};

struct Customer {
    Time start;
    Time end;
    int serviceTime;
    bool isServered;
};

struct Window {
    Time availableTime;
};

bool compareWindow(const Window *w1, const Window *w2) {
    return w1->availableTime < w2->availableTime;
}

bool compareByStartTime(const Customer *c1, const Customer *c2) {
    return c1->start < c2->start;
}

int main(int argc, const char * argv[])
{
    int nCustomer, nWindow;
    scanf("%d %d", &nCustomer, &nWindow);
    
    vector<Customer *> customers;
    for (int i=0; i<nCustomer; ++i) {
        Customer *c = new Customer();
        memset(c, 0, sizeof(Customer));
        scanf("%d:%d:%d %d", &c->start.hour, &c->start.minute, &c->start.second, &c->serviceTime);
        customers.push_back(c);
    }
    
    vector<Window *> windows;
    for (int i=0; i<nWindow; ++i) {
        Window *w = new Window();
        w->availableTime = Time { 8, 0, 0 };
        windows.push_back(w);
    }
    
    sort(customers.begin(), customers.end(), compareByStartTime);
    for (int i=0; i<nCustomer; ++i) {
        Customer *c = customers[i];
        
        sort(windows.begin(), windows.end(), compareWindow);
        Window *w = windows[0];
        
//        if (c->start >= Time { 17, 0, 0 } || w->availableTime >= Time { 17, 0, 0 } ) {
        if (c->start >= Time { 17, 0, 0 }) {
            break;
        }
        
        if (w->availableTime < c->start) {
            c->end = c->start;
        } else {
            c->end = w->availableTime;
        }
        w->availableTime = c->end + c->serviceTime;
        c->isServered = true;
    }
    
    double sum = 0.;
    int counter = 0;
    for (int i=0; i<nCustomer; ++i) {
        Customer *c = customers[i];
        if (!c->isServered) continue;
        ++counter;
        sum += c->end - c->start;
    }
    
    if (counter > 0) {
        printf("%.01lf", sum / 60 / counter);
    } else {
        printf("0.0");
    }
    
    return 0;
}

// 又是很长的题目
// 除数为零
// 题目有一个歧义的地方，17:00前的顾客均可服务，即使窗口空闲的时间已经超过17:00点，见注释
