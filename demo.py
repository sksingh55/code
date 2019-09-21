modd = 1000000007
a = [1]*1000005
ans = [1]*1000005
for i in range(2,1000005):
    a[i]=(i%modd*a[i-1]%modd)%modd
    ans[i]=((i%modd*a[i-1]%modd)%modd*ans[i-1]%modd)%modd
t = int(raw_input())
for p in range(0,t):
    n = int(raw_input())
    print(ans[n]%modd)
