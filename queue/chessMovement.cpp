#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    struct node
    {
        int i;
        int j;
        int step;
        struct node *next;
    };
    struct node *front = NULL, *rear = NULL, *temp = NULL;
    struct node *getNewNode(int i, int j, int step)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->i = i;
        temp->j = j;
        temp->step = step;
        temp->next = NULL;
        return temp;
    }
    void enQueue(int i, int j, int step)
    {
        struct node *temp = getNewNode(i, j, step);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        struct node *temp = front;
        front = front->next;
    }
    struct node *peek()
    {
        if (front == NULL)
        {
            return NULL;
        }
        return front;
    }
    int isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};
class Solution
{

    map<pair<int, int>, bool> block;
    map<pair<int, int>, bool> visited;

private:
    bool isvalid(int i, int j)
    {
        if (i < 0 || j < 0 || i > 10e6 || j > 10e6 || block[make_pair(i, j)] || visited[make_pair(i, j)])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int y[8] = {1, -1, 1, -1, 2, -2, 2, -2};

public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        for (int i = 0; i < blocked.size(); i++)
        {
            block[{blocked[i][0], blocked[i][1]}] = true;
        }
        Queue q;
        q.enQueue(source[0], source[1], 0);
        while (!q.isEmpty())
        {
            q.temp = q.peek();
            q.dequeue();
            if (q.temp->i == target[0] && q.temp->j == target[1])
            {
                return true;
            }
            if (q.temp->i > target[0] + 5 && q.temp->j > target[1] + 5)
            {
                return false;
            }
            for (int i = 0; i < 8; i++)
            {
                if (isvalid(q.temp->i + x[i], q.temp->j + y[i]))
                {
                    q.enQueue(q.temp->i + x[i], q.temp->j + y[i], q.temp->step + 1);
                    visited[make_pair(q.temp->i,q.temp->j)]=true;
                }
            }
            if(q.temp->step>=blocked.size()){
                return true;
            }
        }
        return false;
    }
};
int main()
{
}