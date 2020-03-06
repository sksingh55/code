#include <bits/stdc++.h>
using namespace std;
struct Node {
	int val;
	Node* next;
};
class Graph
{
    struct Node{
        int data;
        struct Node * next;
    };
    Node **head;
    int N;
    public: 
    Graph(int N)
	{
		head = new Node*[N+1]();
		this->N = N;

		for (int i = 0; i < N; i++)
			head[i] = nullptr;
	}
    struct Node* getLastNode(int u){
        struct Node* temp = head[u];
        while(temp->next){
            temp = temp->next;
        }
        return temp;
    }
    struct Node* newNode(int data){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data =  data;
        temp->next = nullptr;
        return temp;
    }
    void addEdges(int u,int v){
        struct Node *temp = newNode(v);
        if(!head[u]){
            head[u] = temp;
        }
        else{
            struct Node *curr = getLastNode(u);
            curr->next = temp;
        }
    }
    void printGraph(){
        for(int i = 0;i<N;i++){
            struct Node* temp = head[i];
            cout<<"parent : "<<i<<" child : ";
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }
    void getArrivalAndDeparture(int node, vector<bool> &visited,
                                vector<int> &arrive, vector<int> &depart,int &time){
        arrive[node] = ++time;
        visited[node] = true;
        struct Node* curr = head[node];
        while(curr){
            if(!visited[curr->data]){
                getArrivalAndDeparture(curr->data,visited,arrive,depart,time);
            }
            curr = curr->next;
        }
        depart[node] = ++time;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    Graph graph(n);
    while(m--){
        int x,y;
        cin>>x>>y;
        graph.addEdges(x,y);
    }
    graph.printGraph();
    vector<bool> visited(n,false);
    vector<int> arrive(n,-1);
    vector<int> depart(n,-1);
    int time = -1;
    graph.getArrivalAndDeparture(0,visited,arrive,depart,time);
    for(int i =0 ;i<n;i++){
        cout<<arrive[i]<<" "<<depart[i]<<"\n";
    }
}