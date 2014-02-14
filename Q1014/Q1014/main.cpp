//
//  main.cpp
//  Q1014
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Time {
    
    const Time operator + (const int min) const {
        Time result = *this;
        result.minute += min;
        result.hour += result.minute / 60;
        result.minute %= 60;
        return result;
    }
    
    bool operator > (const Time &t) const {
        if (hour == t.hour) {
            return minute > t.minute;
        }
        return hour > t.hour;
    }
    
    bool operator >= (const Time &t) const {
        if (hour == t.hour) {
            return minute >= t.minute;
        }
        return hour > t.hour;
    }
    
    int hour;
    int minute;
};

struct Customer {
    
    Customer() {
        isProcessed = false;
    }
    
    int cost;
    bool isProcessed;
    Time finish;
};

struct Window {
    
    Window() {
        isProcessing = false;
    }
    
    int firstCost() {
        return line.front()->cost;
    }
    
    void process(Time now, int min) {
        Customer *c = line.front();
        c->cost -= min;
        if (c->cost <= 0) {
            c->finish = now + min;
            c->isProcessed = true;
            line.pop();
            isProcessing = false;
        } else {
            isProcessing = true;
        }
    }
    
    void shutdown(Time now) {
        if (isProcessing) {
            Customer *c = line.front();
            c->finish = now + c->cost;
            c->isProcessed = true;
            line.pop();
            isProcessing = false;
            now = now + c->cost;
        }
        
        while (!line.empty()) {
            if (now >= Time { 17, 0 }) {
                break;
            } else {
                Customer *c = line.front();
                c->finish = now + c->cost;
                c->isProcessed = true;
                line.pop();
                now = now + c->cost;
            }
        }
    }
    
    static int capacity;
    bool isProcessing;
    queue<Customer *> line;
};

int Window::capacity = 0;

int main(int argc, char *argv[]) {
    
    int nWindow, nCustomer, nQuery;
    scanf("%d %d %d %d", &nWindow, &Window::capacity, &nCustomer, &nQuery);
    
    vector<Window *> windows;
    for (int i=0; i<nWindow; ++i) {
        windows.push_back(new Window());
    }
    
    vector<Customer *> customers;
    for (int i=0; i<nCustomer; ++i) {
        Customer *c = new Customer();
        scanf("%d", &c->cost);
        customers.push_back(c);
    }
    
    Time now { 8, 0 };
    for (int i=0; i<nCustomer; ++i) {
        Customer *c = customers[i];
        
        if (now >= Time { 17, 0 }) {
            break;
        }
        
        int idx = 0;
        int minQueue = INT32_MAX;
        for (int i=0; i<nWindow; ++i) {
            Window *w = windows[i];
            if (w->line.size() < minQueue) {
                minQueue = static_cast<int>(w->line.size());
                idx = i;
            }
        }
        if (minQueue < Window::capacity) {
            windows[idx]->line.push(c);
        } else {
            int idx = -1;
            int minCost = INT32_MAX;
            for (int i=0; i<nWindow; ++i) {
                if (windows[i]->firstCost() < minCost) {
                    minCost = windows[i]->firstCost();
                    idx = i;
                }
            }
            for (int i=0; i<nWindow; ++i) {
                Window *w = windows[i];
                w->process(now, minCost);
            }
            windows[idx]->line.push(c);
            now = now + minCost;
        }
    }
    
    for (int i=0; i<nWindow; ++i) {
        windows[i]->shutdown(now);
    }
    
    for (int i=0; i<nQuery; ++i) {
        int idx;
        scanf("%d", &idx);
        --idx;
        Customer *c = customers[idx];
        if (!c->isProcessed) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", c->finish.hour, c->finish.minute);
        }
    }
    
    return 0;
}

// 根据情景模拟，模拟题关键在准确，效率不是优先考虑
