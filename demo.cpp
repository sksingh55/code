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

class PermutationUsingRecursion
{
public: vec(string) ans;
public: 
vector<string> getSol(string s){
	permuteString(s);
	return ans;
}

public:
	void permuteString(string s)
	{
		map<char, int> freq;
		int n = s.length();
		f(i, 0, n)
		{
			freq[s[i]]++;
		}
		vector<char> str;
		int count[freq.size() + 1] = {0};
		map<char, int>::iterator it;
		int index = 0;
		for (it = freq.begin(); it != freq.end(); it++)
		{
			str.pb(it->first);
			count[index] = it->second;
			index++;
		}
		char result[n];
		permute(result, str, count, 0, n);
	}

private:
	void insertAns(char result[], int n)
	{
		string s = "";
		f(i, 0, n)
		{
			s += result[i];
		}
		ans.pb(s);
	}

private:
	void permute(char result[], vector<char> str, int count[], int level, int n)
	{
		if (level == n)
		{
			insertAns(result, n);
			return;
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (count[i] == 0)
			{
				continue;
			}
			count[i]--;
			result[level] = str[i];
			permute(result, str, count, level + 1, n);
			count[i]++;
		}
	}
};

int main()
{
	SPEEDUP
	tc{
	string s;
	cin >> s;
	vec(string)ans = PermutationUsingRecursion().getSol(s);
	f(i,0,ans.size()){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	}
}