//
//  main.cpp
//  Q1026
//
//  Created by Pumpkin Lee on 2/10/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
    
    Time operator + (int min) const {
        Time result;
        result = *this;
        result.minute += min;
        result.hour += result.minute / 60;
        result.minute %= 60;
        return result;
    }
    
    int operator - (const Time &t) const {
        Time result = *this;
        result.second -= t.second;
        if (result.second < 0) {
            result.minute -= 1;
            result.second += 60;
        }
        result.minute -= t.minute;
        if (result.minute < 0) {
            result.hour -= 1;
            result.minute += 60;
        }
        result.hour -= t.hour;
        return result.hour * 60 + result.minute + (result.second >= 30 ? 1 : 0);
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
    
    bool operator <= (const Time &t) const {
        if (hour == t.hour) {
            if (minute == t.minute) {
                return second <= t.second;
            }
            return minute < t.minute;
        }
        return hour < t.hour;
    }
    
    bool operator == (const Time &t) const {
        return hour == t.hour && minute == t.minute && second == t.second;
    }
    
    int hour;
    int minute;
    int second;
};

struct Customer {
    
    Customer() {
        isAssigned = false;
    }
    
    Time arrive;
    Time start;
    int cost;
    int isVip;
    bool isAssigned;
};

bool compareByArrive(const Customer *c1, const Customer *c2) {
    return c1->arrive < c2->arrive;
}

bool compareByStart(const Customer *c1, const Customer *c2) {
    if (c1->start == c2->start) {
        return c1->arrive < c2->arrive;
    }
    return c1->start < c2->start;
}

struct Table {
    
    Table() {
        owner = NULL;
        isVip = false;
        counter = 0;
    }
    
    void assign(Customer *c, const Time &now) {
        owner = c;
        c->start = now;
        c->isAssigned = true;
        ++counter;
    }
    
    void process(Time now) {
        if (!owner) return;
        if (owner->start + owner->cost <= now) {
            owner = NULL;
        }
    }
    
    bool isFree() const {
        return owner == NULL;
    }
    
    Time freeTime() {
        return owner->start + owner->cost;
    }
    
    Customer *owner;
    bool isVip;
    int counter;
};

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);

    vector<Customer *> customers;
    for (int i=0; i<n; ++i) {
        Customer *c = new Customer();
        scanf("%d:%d:%d %d %d", &c->arrive.hour, &c->arrive.minute, &c->arrive.second, &c->cost, &c->isVip);
        if (c->cost > 120) {
            c->cost = 120;
        }
        customers.push_back(c);
    }
    sort(customers.begin(), customers.end(), compareByArrive);
    
    vector<Table *> tables;
    int nTable, nVipTable;
    scanf("%d %d", &nTable, &nVipTable);
    for (int i=0; i<nTable; ++i) {
        tables.push_back(new Table());
    }
    for (int i=0; i<nVipTable; ++i) {
        int idx;
        scanf("%d", &idx);
        tables[idx - 1]->isVip = true;
    }
    
    Time now { 8, 0 };
    vector<Customer *> waiting(customers);
    while (waiting.size() > 0 && now < Time { 21, 0 }) {
        // 首先判断该时刻有多少人等待
        vector<Customer *> buffer;
        for (vector<Customer *>::iterator it=waiting.begin(); it!=waiting.end(); ) {
            Customer *c = *it;
            if (c->isAssigned) {
                it = waiting.erase(it);
                continue;
            }
            if (c->arrive <= now) {
                buffer.push_back(c);
            }
            ++it;
        }
        
        // 如果该时刻没有人到达，则时间前进到第一个人到达
        if (buffer.size() <= 0) {
            now = waiting[0]->arrive;
            continue;
        }
        
        // 该时刻有人在等候，存在buffer里
        
        // 所有桌子的时间同步到now
        for (int i=0; i<nTable; ++i) {
            tables[i]->process(now);
        }
        
        // 查找空闲的桌子
        int idxTable = -1;
        for (int i=0; i<nTable; ++i) {
            if (tables[i]->isFree()) {
                idxTable = i;
                break;
            }
        }
        
        if (idxTable < 0) {
            // 如果没有空闲的桌子，则时间前进到第一张桌子空闲
            Time minTime { 24, 0 };
            for (int i=0; i<nTable; ++i) {
                if (tables[i]->freeTime() < minTime ) {
                    minTime = tables[i]->freeTime();
                }
            }
            now = minTime;
            continue;
        } else {
            // 有空闲的桌子
            // 查找buffer里的vip
            int vipCustomer = -1;
            for (int i=0; i<buffer.size(); ++i) {
                if (buffer[i]->isVip) {
                    vipCustomer = i;
                    break;
                }
            }
            // 查找空闲的vip桌子
            int vipTable = -1;
            for (int i=0; i<nTable; ++i) {
                if (tables[i]->isVip && tables[i]->isFree()) {
                    vipTable = i;
                    break;
                }
            }
            // 没有vip或者没有vip桌子，则最先到的assign
            if (vipCustomer < 0 || vipTable < 0) {
                tables[idxTable]->assign(buffer[0], now);
            } else {
                tables[vipTable]->assign(buffer[vipCustomer], now);
            }
        }
    }
    
    sort(customers.begin(), customers.end(), compareByStart);
    for (int i=0; i<customers.size(); ++i) {
        Customer *c = customers[i];
        if (!c->isAssigned) {
            continue;
        } else {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", c->arrive.hour, c->arrive.minute, c->arrive.second,
                   c->start.hour, c->start.minute, c->start.second, c->start - c->arrive);
        }
    }
    printf("%d", tables[0]->counter);
    for (int i=1; i<nTable; ++i) {
        printf(" %d", tables[i]->counter);
    }
    
    return 0;
}

// 复杂一点的模拟题
// 按常规思路模拟，不要考虑效率
// 注意最多打两个小时
// VIP会优先去VIP桌子，而不是普通桌子
// 最恶心的是秒的round up，是四舍五入，不是直接进位
