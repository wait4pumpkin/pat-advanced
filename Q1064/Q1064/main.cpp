//
//  main.cpp
//  Q1064
//
//  Created by Pumpkin Lee on 2/5/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

Node* extractRoot(vector<int> &nums, int height) {
    if (nums.size() <= 0) {
        return NULL;
    }
    
    Node *root = new Node();
    if (height == 1) {
        root->value = nums[0];
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    int left = 0;
    size_t remain = nums.size() - 1;
    for (int i=1; i<height-1; ++i) {
        left += pow(2., i - 1);
        remain -= pow(2., i);
    }
    left += remain - pow(2., height - 2) > 0 ? pow(2., height - 2) : remain;
    
    root->value = nums[left];
    vector<int> leftNums(nums.begin(), nums.begin() + left);
    vector<int> rightNums(nums.begin() + left + 1, nums.end());
    root->left = extractRoot(leftNums, height - 1);
    root->right = extractRoot(rightNums, height - 1);
    return root;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    Node *root = extractRoot(nums, floor(log(n) / log(2) + 1));
    bool *isVisited = new bool[n];
    queue<Node *> nextNode;
    nextNode.push(root);
    printf("%d", root->value);
    
    while (!nextNode.empty()) {
        Node *n = nextNode.front();
        nextNode.pop();
        if (n->left) {
            printf(" %d", n->left->value);
            nextNode.push(n->left);
        }
        if (n->right) {
            printf(" %d", n->right->value);
            nextNode.push(n->right);
        }
    }
    
    
    delete [] isVisited;
    
    return 0;
}

// 排序好之后放入二叉树
