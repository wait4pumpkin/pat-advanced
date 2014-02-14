//
//  main.cpp
//  Q1043
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node *left;
    Node *right;
};

Node* buildBST(const vector<int> &nums) {
    if (nums.size() <= 0) {
        return NULL;
    }
    
    Node *root = new Node();
    root->num = nums[0];
    
    int left = 1;
    for (int i=1; i<nums.size(); ++i) {
        if (nums[i] < nums[0]) {
            ++left;
        }
    }
    
    vector<int> leftTrees(nums.begin() + 1, nums.begin() + left);
    vector<int> rightTrees(nums.begin() + left, nums.end());
    root->left = buildBST(leftTrees);
    root->right = buildBST(rightTrees);
    return root;
}

Node* buildBSTMirror(const vector<int> &nums) {
    if (nums.size() <= 0) {
        return NULL;
    }
    
    Node *root = new Node();
    root->num = nums[0];
    
    int left = 1;
    for (int i=1; i<nums.size(); ++i) {
        if (nums[i] >= nums[0]) {
            ++left;
        }
    }
    
    vector<int> leftTrees(nums.begin() + 1, nums.begin() + left);
    vector<int> rightTrees(nums.begin() + left, nums.end());
    root->left = buildBSTMirror(leftTrees);
    root->right = buildBSTMirror(rightTrees);
    return root;
}


void inorderTravel(Node *root, vector<int> &travel) {
    if (root->left) {
        inorderTravel(root->left, travel);
    }
    travel.push_back(root->num);
    if (root->right) {
        inorderTravel(root->right, travel);
    }
}

void inorderTravelMirror(Node *root, vector<int> &travel) {
    if (root->right) {
        inorderTravelMirror(root->right, travel);
    }
    travel.push_back(root->num);
    if (root->left) {
        inorderTravelMirror(root->left, travel);
    }
}

void postorderTravel(Node *root, vector<int> &travel) {
    if (root->left) {
        postorderTravel(root->left, travel);
    }
    if (root->right) {
        postorderTravel(root->right, travel);
    }
    travel.push_back(root->num);
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }
    
    Node *root = buildBST(nums);
    Node *mirrorRoot = buildBSTMirror(nums);
    sort(nums.begin(), nums.end());
    vector<int> travel;
    inorderTravel(root, travel);
    bool isBinary = true;
    for (int i=0; i<nums.size(); ++i) {
        if (travel[i] != nums[i]) {
            isBinary = false;
            break;
        }
    }
    
    if (isBinary) {
        printf("YES\n");
        travel.clear();
        postorderTravel(root, travel);
        printf("%d", travel[0]);
        for (int i=1; i<travel.size(); ++i) {
            printf(" %d", travel[i]);
        }
        return 0;
    }
    
    travel.clear();
    inorderTravelMirror(mirrorRoot, travel);
    isBinary = true;
    for (int i=0; i<nums.size(); ++i) {
        if (travel[i] != nums[i]) {
            isBinary = false;
            break;
        }
    }
    if (isBinary) {
        printf("YES\n");
        travel.clear();
        postorderTravel(mirrorRoot, travel);
        printf("%d", travel[0]);
        for (int i=1; i<travel.size(); ++i) {
            printf(" %d", travel[i]);
        }
    } else {
        printf("NO\n");
    }
    
    return 0;
}

// 复制代码一定要小心再小心
