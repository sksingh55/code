t = int(input())
for z in range(0,t):
	n = int(input())
	ans = [0 for i in range(0,n+5)]
	print("1 1 2 3")
	a = int(input())
	print("1 2 3 4")
	b = int(input())
	x = a^b
	p=1
	q=4
	count=0
	for i in range(5,n+1):
		print(1,p,q,i)
		k=int(input())
		ans[i]=k^x
		count = count+1
		if count==2:
			count=0
			p=i-1
			q=i
			x=ans[p]^ans[q]

	if n%2==0:
		print(1,n-1,n,2)
		k=int(input())
		ans[2]=k^ans[n-1]^ans[n]
		print(1,n-1,n,3)
		k=int(input())
		ans[3]=k^ans[n-1]^ans[n]
	if n%2!=0:
		print(1,n-1,n,2)
		k=int(input())
		ans[2]=k^ans[n-1]^ans[n]
		print(1,n-2,n,3)
		k=int(input())
		ans[3]=k^ans[n-2]^ans[n]
	ans[1]=ans[2]^ans[3]^a
	ans[4]=ans[2]^ans[3]^b
	s = "2 "
	for i in range(1,n+1):
		s=s+str(ans[i])+" "


	print(s)