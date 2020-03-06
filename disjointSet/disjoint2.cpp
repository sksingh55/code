#include<bits/stdc++.h>
using namespace std;


struct Node{
    char data;
    struct Node *parent;
};

struct Node* makeset(char c){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = c;
    temp->parent = temp;
}

struct Node* findParent(struct Node* root){
    if(root->parent == root){
        return root;
    }
    root->parent = findParent(root->parent);
    return root->parent;
}

void unions(struct Node *x , struct Node *y){
    struct Node *parent1, *parent2;
    parent1 = findParent(x);
    parent2 = findParent(y);
    if(parent1 == parent2 ){
        return;
    }
    
    if(parent1->data <= parent2->data){
        parent2->parent = parent1;
    }
    else{
        parent1->parent = parent2;
    }
}

string Solution (string A, string C, string B) {
   // Write your code here
   map<char,struct Node*> m;
   for(int i=0;i<A.length();i++){
       if(!m[A[i]]){
           m[A[i]] = makeset(A[i]);
       }
       if(!m[B[i]]){
           m[B[i]] = makeset(B[i]);
       }
       unions(m[A[i]],m[B[i]]);
   }
   
   for(int i=0;i<C.length();i++){
       if(m[C[i]]){
           struct Node *temp = findParent(m[C[i]]);
           C[i] = temp->data;
       }
   }
   return C;
}

int main() {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<Solution(s1,s3,s2);
}