z = input().split()
n=int(z[0])
c=int(z[1])
i = 3000
while i<=n :
	print("1 ",i)
	x = int(input())
	if x==1:
		break
	i = i+3000


j = i-3000+100
while j<=n and j<=i:
	print("1 ",j)
	x = int(input())
	if x==1:
		break;
	j = j+100

k=j-99
while k<=j and k<=n:
	print("1 ",k)
	x=int(input())
	if x==1:
		break;
	k=k+1;
print(2)
if k>n:
	print(k-1)
else:
	print(k)