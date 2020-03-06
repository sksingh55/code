#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc             \
    long long int t;   \
    scanf("%lld", &t); \
    while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 300005
#define SPEEDUP ios_base::sync_with_stdio(false);
using namespace std;
typedef long long int ll;

struct Machine{
    vector<string> ip;
    int currentIndex=-1;
    int count = 0;
};

map<string,struct Machine> urlToMachineMapping;
map<string,int> machineStatus;
map<string,vector<string>> ans;

bool check(string str,char c){
    bool flag=true;
    if(str.find(c) == string::npos){
        flag = false;
    }
    return flag;
}


vector<string> split(string str, char c)
{
    cout<<str;
    if(check(str,c)==false){
        vector<string> temp;
        temp.push_back(str);
        return temp;
    }
	replace(str.begin(), str.end(), c, ' ');
	vector<string> array;
	stringstream ss(str);
	string temp;
	while (ss >> temp){
        array.push_back(temp);
    }
	return array;
}

string getNextMachine(string url){
    struct Machine machine = urlToMachineMapping[url];
    int count = machine.count;
    int curr = machine.currentIndex;
    if(machine.count == 0){
        return "";
    }
    while(count--){
        curr = (curr+1)%machine.count;
        machine.currentIndex = curr;
        urlToMachineMapping[url]=machine;
        return machine.ip[curr];
    }
}

void addToAns(string url,string fullurl){
    string ip = getNextMachine(url);
    // cout<<ip<<"\n";
    if(ip==""){
        return;
    }
    else{
        ans[ip].push_back(fullurl);
    }
}
void addMachineToUrl(string url,string ip){
    if(urlToMachineMapping.find(url)==urlToMachineMapping.end()){
        struct Machine machine;
        machine.count++;
        machine.currentIndex = -1;
        machine.ip.push_back(ip);
        machineStatus[ip] = 0;
        urlToMachineMapping[url]=machine;
    }
    else{
        struct Machine machine = urlToMachineMapping[url];
        machine.ip.push_back(ip);
        machine.count++;
        machineStatus[ip] = machine.count-1;
        urlToMachineMapping[url]=machine;
    }
    
}

void removeMachine(string url,string ip){
    if(machineStatus[ip]==-1){
        return;
    }
    struct Machine machine = urlToMachineMapping[url];
    int index = machineStatus[ip];
    machine.ip.erase(machine.ip.begin()+index);
    machine.count--;
    urlToMachineMapping[url] = machine;
}

void updateMachineStatus(string url,string ip,bool status){
    if(status){
        addMachineToUrl(url,ip);
    }
    else{
        removeMachine(url,ip);
    }
}

void compileUrl(string fullUrl){
    vector<string> splits = split(fullUrl,'/');
    if(splits.size()==1){
        addToAns(splits[0],fullUrl);
    }
    else if(split(splits[1],'?')[0]=="machine_down"){
        string ip = split(split(splits[1],'?')[1],'=')[1];
        updateMachineStatus(splits[0],ip,false);
    }
    else if(split(splits[1],'?')[0]=="machine_up"){
        string ip = split(split(splits[1],'?')[1],'=')[1];
        updateMachineStatus(splits[0],ip,true);
    }
    else{
        addToAns(splits[0],fullUrl);
    }
}




void getMachine(){
    int n;
    cin>>n;
    while(n--){
        string ip;
        cin>>ip;
        machineStatus[ip]=-1;
        vector<string> out;
        ans[ip] = out;
    }
}

void getMachineMapping(){
    int n;
    cin>>n;
    while(n--){
        string url;
        cin>>url;
        int k;
        cin>>k;
        while(k--){
            string ip;
            cin>>ip;
            addMachineToUrl(url,ip);
        }
    }
}

void query(){
    int n;
    cin>>n;
    while(n--){
        string fullurl;
        cin>>fullurl;
        compileUrl(fullurl);
    }
}

void printAns(){
    for(auto s:ans){
        cout<<s.first<<"\n";
        for(auto ip:s.second){
            cout<<ip<<"\n";
        }
    }
    cout<<"\n";
}

void printMachinMapping(){
    cout<<"Printing Machine Details\n";
    for(auto s:urlToMachineMapping){
        cout<<s.first<<" "<<s.second.count<<"\n";
        for(auto ip:s.second.ip){
            cout<<ip<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    getMachine();
    getMachineMapping();
    // printMachinMapping();
    query();
    printAns();
}