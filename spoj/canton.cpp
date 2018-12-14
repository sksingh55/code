#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/* Prints the n-th fraction in Cantor's enumeration. */
void print_fraction(ll n)
{
    ll d = (-1 + sqrt(1 + 8 * n)) / 2;  /* Diagonals to skip */
    ll e = n - d * (d + 1) / 2;         /* Extra steps after the skip.
*/
    ll v1 = e <= 1 ? d + e : d + 2 - e;
    ll v2 = e <= 1 ?     1 : e;


    printf("TERM %lld IS %lld/%lld\n", n,d % 2 == 0 ? v1 : v2,
                        d % 2 == 0 ? v2 : v1);
}


int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
   	ll k;
   	cin>>k;
   	print_fraction(k);
   }
    
}
