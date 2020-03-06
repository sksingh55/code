[21:52, 02/12/2019] Sumit IIITDM: #include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;



vector<string> stringparse(string add , char ch)
{
	std::replace(add.begin(), add.end(), ch , ' ');
	vector<string> array;
	stringstream ss(add);
	string temp;
	while (ss >> temp)
		array.push_back(temp);
	return array;
}

struct reverseproxy 
{
	queue<string> dns;
	string add;
	string head;
};



int main()
{
	int nIdx;
	std::cin>>nIdx;

	vector<string> strDns;
	for(int i = 0 ; i< nIdx ; i++)
	{
		string str;
		std::cin>>str;
		strDns.push_back(str);
	}

	nIdx = 0;
	std::cin>>nIdx;
	reverseproxy rip[nIdx];

	int nCount = 0;
	map<string,int> mp;

	while(nIdx--)
	{
		string address;
		std::cin>>address;
		mp[address] = nCount;
		rip[nCount].add = address;

		int t;
		cin>>t;
		while(t--)
		{
			string add;
			std::cin>>add;
			rip[nCount].dns.push(add);
		}

		nCount++;
	}

	int q;
	cin>>q;
	map<string,vector<string>> ans;
	while(q--)
	{
		string address;
		std::cin>>address;
		vector<string> arr =  stringparse(address , '/');		
		int mac = mp[arr[0]];
		vector<string> status = stringparse(arr[arr.size()-1],'?');

		if(status[0] == "machine_up" || status[0] == "machine_down")
			{
				if(status.size() > 1)
				{
					vector<string> getip = stringparse(status[1],'=');
					if(status[0] =="machine_down")
					{

                        int tt = rip[mac].dns.size();
                        int kk = 0;
						
						while(!rip[mac].dns.empty())
							{ 
							if(getip
                            [1] == rip[mac].dns.front())
							{	
							   rip[mac].dns.pop();
							   break;

							}
							else
							{
								string pp = rip[mac].dns.front();
								rip[mac].dns.pop();
								rip[mac].dns.push(pp);

							}
                            kk++ ;
                            if(kk == 0)
                             break;
                
								
							}	
						}
					else if(status[0] =="machine_up")
					{
						string ip2 = rip[mac].dns.front();
						if(rip[mac].head == ip2)
						{
							rip[mac].dns.pop();
							rip[mac].dns.push(getip[1]);
							rip[mac].dns.push(ip2);
						}
						else
							rip[mac].dns.push(getip[1]);
					}
				}			
			
			}
		else
		{
			ans[rip[mac].dns.front()].push_back(address);
			string ip = rip[mac].dns.front();
			rip[mac].dns.pop();
			rip[mac].dns.push(ip);
			rip[mac].head = ip;
		}
	}



for(int i = 0 ; i<strDns.size() ; i++)
	{
	std::cout<<strDns[i]<<"\n";
	vector<string > res = ans[strDns[i]];
	for(int j = 0 ; j< res.size() ; j++)
		std::cout<<res[j]<<"\n";
	}

return 0;
}