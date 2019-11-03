#include <bits/stdc++.h>
using namespace std;
int val = 20;
void test(){
	int val = 1;{
		int val = 2;
		cout << ::val << endl;
	}
}
int main()
{
	int x = 5;
	int y = ++x*x--;
	int z = ++y + y--;
	cout << x<<y<<z;
	test();
}


