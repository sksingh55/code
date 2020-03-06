#include <bits/stdc++.h>
using namespace std;
class Queue
{
    struct node
    {
        int data;
        int index;
        struct node *next;
    };
    struct node *front = NULL, *rear = NULL, *temp = NULL;

private:
    struct node *getNewNode(int x)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->index=-1;
        temp->next = NULL;
        return temp;
    }
public:
    void enQueue(int x){
        temp = getNewNode(x);
        if(front==NULL){
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            rear = rear->next;
        }
    }
    int dequeue(){
        if(front==NULL){
            return -1;
        }
        struct node *temp = front;
        front = front->next;
        return temp->data;
    }
    int peek(){
        if(front==NULL){
            return -1;
        }
        return front->data;
    }
    int isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    Queue queue;
    while(n--){
        int k;
        cin>>k;
        queue.enQueue(k);
    }

    while(!queue.isEmpty()){
        cout<<queue.peek()<<"\n";
        queue.dequeue();
    }
}