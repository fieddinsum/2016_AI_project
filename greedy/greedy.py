#!/usr/bin/python


import random 
 
# 100 x 100 random generation
# 입력: 이름
# 출력: txt 파일로 이루어진 100 x 100 랜덤 파일로 생성

# map read
# 입력: 읽을 파일 이름 
# 출력: map을 읽어서 현재 파일에 저장함

# calculaverage 
#입력: map 자료구조
#출력: 현재 맵의 평균,표준편차를 뽑아냄 

#calcul starNode
#입력: distance 값
#출력: distance 값 이하의 엣지 숫자를 랭킹해서 자료구조에 저장 

#select star node
#입력 : distanct



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

print(disData)

                
#O(n^2) : StarNodeCount
for colCount in range(0,cityCount):
        for rawCount in range(colCount,cityCount):
                if int(disData[rawCount][colCount])<=clusterMeter:
                        nearDisCount[colCount]+=1


#getCertain Number
                        
bridgeIndex = []
fragmentIndex =[]
pathIndex=[]

for t in range(0,cityCount):
        fragmentIndex.append(t)



copyNDC = nearDisCount[:]

for OutstarIter in range(0,starNodePick):
        tempvalue =0
        tmepindex =0
        for InstarIter in range(0,cityCount):
                if copyNDC[InstarIter] > tempvalue:
                        tempvalue=copyNDC[InstarIter]
                        tempindex=InstarIter

        bridgeIndex.append(tempindex)
        fragmentIndex.remove(tempindex)
        copyNDC[tempindex] = 0


# 15 bridge 노드 16 x 5개  마디

#handling factor
FragmentUnit = 5
bridgeNode = 15
FragmentNode = 16


#automatly generated factor
FragmentCount = 
leftover = 100 - (bridgeNode+FragmentUnit*FragmentNode)


#select start point
startPoint = random.choice(fragmentIndex)

#add to the Path
pathIndex.append(startPoint)
#remove from fragment
fragmentIndex.remove(startPoint)

#make 5 node fragment
preTSP = 0;
postTSP =0;
for outloop in range(0,FragmentUnit):
        
#iterate remain city & find Minimum distance
for innerLoop in range(0,cityCount):
        
#make Fragment


#selection bridge

#selection bridge

#TSP




