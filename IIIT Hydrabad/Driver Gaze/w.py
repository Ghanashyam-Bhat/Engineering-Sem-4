x = 0
with open("dgaze_proposal.txt","r") as fd:
	l = fd.readlines()
	for i in l:
		x+=len(list(i.split()))
print(x)
