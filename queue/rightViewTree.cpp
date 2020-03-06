#include <bits/stdc++.h>
using namespace std;

class Queue
{
    struct queues
    {
        int *items;
        int top;
        int back;
        int size;
        int maxSize;
    };
    struct queues *pt=NULL;
    public:
    Queue(int maxSize){
        pt = (struct queues*)malloc(sizeof(struct queues));
        pt->maxSize = maxSize;
        pt->top = 0;
        pt->back = -1;
        pt->size = 0;
        pt->items = (int *)malloc(sizeof(int)*maxSize);
    }
    void enqueue(int x){
        if(pt->size == pt->maxSize){
            cout<<"Queue is full";
            return ;
        }
        pt->size++;
        pt->back = (pt->back+1)%pt->maxSize;
        pt->items[pt->back] = x;
    }
    void dequeue(){
        if(pt->size == 0){
            cout<<"Queue is empty\n";
            return;
        }
        pt->size--;
        pt->top = (pt->top+1)%pt->maxSize;
    }
    int getTop(){
        if(pt->size == 0){
            cout<<"queue is empty";
            return -1;
        }
        return pt->items[pt->top]; 
    }
    bool isFull(){
        if(pt->size==pt->maxSize){
            return true;
        }
        return false;
    }
    int front(){
        if(pt->size==0){
            return -1;
        }
        return pt->items[pt->top];
    }
    int rear(){
        if(pt->size==0){
            return -1;
        }
        return pt->items[pt->back];
    }
    bool isEmpty(){
        if(pt->size==0){
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    Queue queue(n);
    while(n--){
        int k;
        cin>>k;
        queue.enqueue(k);
    }

    while(!queue.isEmpty()){
        cout<<queue.front()<<"\n";
        queue.dequeue();
    }
}
