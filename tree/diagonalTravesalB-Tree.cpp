#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 
unordered_map<int,vector<int>> mapp;
void traversal(Node *root ,int level){
    if(!root){
        return;
    }
    mapp[level].push_back(root->data);
    traversal(root->left,level+1);
    traversal(root->right,level);
}
void diagonalPrint(Node *root)
{
   traversal(root,0);
   for(int i=0;i<mapp.size();i++){
       for(int j : mapp[i]){
           cout<<j<<" ";
       }
   }
   mapp.clear();
}