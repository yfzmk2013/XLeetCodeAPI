//
// Created by Administrator on 2021/2/4.
//

//Definition for a binary tree node.
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>

using namespace std;
//typedef  struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(0), right(0) {}
//}TreeNode;

struct TreeNode//二叉树的结点数据结构
{
    int val;
    TreeNode *left, *right;
};

int max(int a, int b) {
    if (a > b)return a;
    else return b;
}

//#define NULL (0)
int data[] = {1, 2, 3, 4, 5, '#', 6, '#', '#', 7, 8};

TreeNode *CreateBiTree(int *a, int n, int start)//按层序输入，结点为空时，输入'#'
{
    if (a[start] == '#')return NULL;

    TreeNode *root = new TreeNode;//新建一个根结点
    root->val = a[start];//给根结点 root 的 成员变量 data、left、right 赋初值
    root->left = NULL;
    root->right = NULL;

    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;

    if (lnode > n - 1) root->left = NULL;
    else root->left = CreateBiTree(a, n, lnode);

    if (rnode > n - 1) root->right = NULL;
    else root->right = CreateBiTree(a, n, rnode);

    return root;
}

//先序遍历函数
void PreOrderTraverse(TreeNode *T) {
    if (T) {
        cout << T->val << " ";
        PreOrderTraverse(T->left);
        PreOrderTraverse(T->right);
    }
}

class Solution {
public:
    int h(TreeNode *node) {
        if (!node)return 0;
        int left_d = h(node->left);
        if (left_d == -100) return -100;
        int right_d = h(node->right);
        if (right_d == -100) return -100;

        if (abs(right_d - left_d) > 1)
            return -100;

        return max( left_d,right_d)+1;


    }

    bool isBalanced(TreeNode *root) {

        if (!root) return true;
        return h(root) != -100;

    }
};

int main() {
    TreeNode *root;
    int data[] = {1,2,2,3,3,'#','#',4,4};
    //前序遍历：1 2 4 5 7 8 3 6
    root = CreateBiTree(data, sizeof(data) / sizeof(data[0]), 0);

    printf("The pre order is :   ");
    PreOrderTraverse(root);
    cout << endl;

    Solution sl;
    bool out = sl.isBalanced(root);
    printf("out=%d\n", out);

    std::cout << "108 Hello, World!!" << std::endl;
    return 0;
}