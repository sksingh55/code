#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int rank;
    int count;
    struct Node *parent;
};
map<int, struct Node *> m;
struct Node *makeset(int k)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = k;
    temp->rank = 0;
    temp->count = 1;
    temp->parent = temp;
    return temp;
}
struct Node *findParent(struct Node *root)
{
    if (root->parent == root)
    {
        return root;
    }
    root->parent = findParent(root->parent);
    return root->parent;
}

void unions(int x, int y)
{
    struct Node *parent1 = findParent(m[x]);
    struct Node *parent2 = findParent(m[y]);
    if (parent1 == parent2)
    {
        return;
    }
    if (parent1->rank >= parent2->rank)
    {
        parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
        parent2->parent = parent1;
        parent1->count += parent2->count;
    }
    else
    {
        parent1->parent = parent2;
        parent2->count += parent1->count;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i =1;i<=n;i++){
        m[i] = makeset(i);
    }
    while (k--)
    {
        int x,y;
        cin>>x>>y;
        unions(x,y);
    }
    for(int i=1;i<=n;i++){
        struct Node *temp = findParent(m[i]);
        cout<<temp->count-1<<" ";
    }
}