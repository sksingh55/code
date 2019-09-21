//Count number of subset of an array whose average is k
#include <bits/stdc++.h>
using namespace std;

int dp[100][10000][100];

int countNumber(int index,int sum,int count,int arr[],int k){
	if(index < 0){
		return 0;
	}
	if(index == 0){
		if(count == 0){
			return 0;
		}
		int rem  = sum%count;
		if(rem != 0){
			return 0;
		}
		int avg = sum /count;
		if(avg == k)
			return 1;
	}
	if(dp[index][sum][count]!=-1){
		return dp[index][sum][count];
	}

	int dontPick = countNumber(index-1,sum,count,arr,k);
	int pick = countNumber(index-1,sum+arr[index],count+1,arr,k);
	int total = dontPick + pick;
	dp[index][sum][count] = total;

	return total;
}


int main(){
	int n,k;
	cin>>n>>k;
	int arr[n+1];
	arr[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	
	cout<< countNumber(n,0,0,arr,k);

}