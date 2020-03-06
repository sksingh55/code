#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node *> q; 
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while(size--){
                Node *current = q.front();
                q.pop();
                if(size==0 || q.empty()){
                    current->next = NULL;
                }
                else{
                    current->next = q.front();
                }
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
        }
        return root;
        }
};