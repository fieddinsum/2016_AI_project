
#read file
inputf = open('10000Cities.txt','r')
cityCount  = 100;
rawLine = []


#readMap
widthV = 100;
hightV = 100;

disData = [ [ 0 for x in range(widthV)] for y in range(hightV)]

#clusterdistance

clusterMeter = 20
starNodePick = 15
nearDisCount = [0 for x in range(cityCount)]



# O(n^2): readMap
for i in range(0,cityCount):
        rawLine = inputf.readline().split()
        for j in range(0,i+1):
                disData[i] = rawLine

for j in range(0,cityCount):
        for k in range(j+1,cityCount):
                disData[j].append(disData[k][j])  

