import matplotlib.pyplot as plt
data=[]
var=[]
count=0
with open('output.txt') as f:
    var = f.readlines()
for x in var:
	data.append(float(x.rstrip()))
	count+=1
f.close()
days=[]
for x in range(1,count+1):
	days.append(x)
plt.plot(days,data,'r-')
plt.ylabel('Portfolio wealth')
plt.xlabel('Days')
plt.show()
