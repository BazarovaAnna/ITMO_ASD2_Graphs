n=int(input())
a=list()
for i in range(n):
    a.append(list(map(int,input().split()))[:-1])
b=[-1]*n
col=0
b[0]=col
flag=True
for i in range(n):
    if col==0: col=1
    else: col=0
    for j in range(len(a[i])):
        if b[a[i][j]-1]<0:
            b[a[i][j]-1]=col
        elif b[a[i][j]-1]!=col:
            flag=False
if flag:
    for i in b:
        print(i,end='')
else:
    print(-1)
