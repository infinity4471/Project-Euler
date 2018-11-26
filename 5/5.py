x=1
c=0
s=False
while s==False and c<20:
	for i in range(1,20):
		if x%i==0:
      c+=1
    else:
      c=0
print x-c
