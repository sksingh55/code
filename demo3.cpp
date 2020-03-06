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
    int activeMachineCount=0;
    int currentIndex=-1;
    int count = 0;
};

map<string,struct Machine> urlToMachineMapping;
map<string,bool> machineStatus;
map<string,vector<string>> ans;

void updateMachineStatus(string ip,bool status){
    machineStatus[ip] = status;
}
bool check(string str,char c){
    cout<<"csdcsdcdsc";
    bool flag=true;
    for(int i=0;i<str.length();i++){
        if(str[i]==c){
            flag = false;
        }
    }
    return flag;
}

vector<string> split(string str, char c)
{
    vector<string> array;
	replace(str.begin(), str.end(), c, ' ');

	stringstream ss(str);
	string temp;
	while (ss >> temp)
		array.push_back(temp);
	return array;
}

string getNextMachine(string url){
    struct Machine machine = urlToMachineMapping[url];
    int count = machine.count;
    int curr = machine.currentIndex;
    while(count--){
        curr = (curr+1)%machine.count;
        // cout<<count<<"currIndex = "<<curr<<"\n";
        if(machineStatus[machine.ip[curr]] == true){
            machine.currentIndex = curr;
            urlToMachineMapping[url]=machine;
            return machine.ip[curr];
        }
    }
    return "";
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


void compileUrl(string fullUrl){
    cout<<"csdcsdc";
    if(check(fullUrl,'/')){
         addToAns(fullUrl,fullUrl);
         return;
    }
    vector<string> splits = split(fullUrl,'/');
    if(split(splits[1],'?')[0]=="machine_down"){
        string ip = split(split(splits[1],'?')[1],'=')[1];
        updateMachineStatus(ip,false);
    }
    else if(split(splits[1],'?')[0]=="machine_up"){
        string ip = split(split(splits[1],'?')[1],'=')[1];
        updateMachineStatus(ip,true);
    }
    else{
        addToAns(splits[0],fullUrl);
    }
}


void addMachineToUrl(string url,string ip){
    if(urlToMachineMapping.find(url)==urlToMachineMapping.end()){
        struct Machine machine;
        machine.activeMachineCount++;
        machine.count++;
        machine.currentIndex = -1;
        machine.ip.push_back(ip);
        urlToMachineMapping[url]=machine;
    }
    else{
        struct Machine machine = urlToMachineMapping[url];
        machine.ip.push_back(ip);
        machine.count++;
        machine.activeMachineCount++;
        urlToMachineMapping[url]=machine;
    }
    
}

void getMachine(){
    int n;
    cin>>n;
    while(n--){
        string ip;
        cin>>ip;
        machineStatus[ip]=true;
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
    query();
    printAns();
}