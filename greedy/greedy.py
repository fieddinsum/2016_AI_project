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

#handling factor
startPoint = 1
FragmentUnit = 20
FragmentNode = 4

bridgeNode = 4
PSEUDO_MAX = 99999
clusterMeter = 40


#automatly generated factor
leftover = 100 - (bridgeNode+FragmentUnit*FragmentNode+startPoint)


nearDisCount = [0 for x in range(cityCount)]



# O(n^2): readMap
for i in range(0,cityCount):
        rawLine = inputf.readline().split()
        for j in range(0,i+1):
                disData[i] = rawLine

#copy transparent value
for j in range(0,cityCount):
        for k in range(j+1,cityCount):
                disData[j].append(disData[k][j])  
                


                
#O(n^2) : StarNodeCount
for colCount in range(0,cityCount):
        for rawCount in range(colCount,cityCount):
                if int(disData[rawCount][colCount])<=clusterMeter:
                        nearDisCount[colCount]+=1


#getCertain Number


                        
bridgeIndex = []
fragmentIndex =[]

#To save final result
pathIndex=[]



for t in range(0,cityCount):
        fragmentIndex.append(t)



copyNDC = nearDisCount[:]

for OutstarIter in range(0,bridgeNode):
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





#make 5 node fragment
preTSP = 0;
postTSP =0;

#15회
        #first choice
currentPoint = random.choice(fragmentIndex)
pathIndex.append(currentPoint)
fragmentIndex.remove(currentPoint)


#fragmentation start
for outLoop in range(0,FragmentNode):


        #makeFragment
        for innerloop in range(0,FragmentUnit):
                candIndex_F = -1;
                candValue_F = PSEUDO_MAX
                for fragIter in fragmentIndex:
                        if int(candValue_F) > int(disData[currentPoint][fragIter]):
                                candValue_F = disData[currentPoint][fragIter]
                                candIndex_F = fragIter
                                
                pathIndex.append(candIndex_F)
                fragmentIndex.remove(candIndex_F)
                currentPoint = candIndex_F
        
        #choose bridge Node
        candIndex_B = -1;
        candValue_B = PSEUDO_MAX

        for bridIter in bridgeIndex :
                if int(candValue_B) > int(disData[currentPoint][bridIter]):
                        candValue_B = disData[currentPoint][bridIter]
                        candIndex_B = bridIter

        pathIndex.append(candIndex_B)
        bridgeIndex.remove(candIndex_B)
        currentPoint = candIndex_B


#fragmentation end               
             
#iterate remain city & find Minimum distance

for leftHandle in range(0,leftover):

        leftIndex = -1;
        leftValue = PSEUDO_MAX

        for leftIter in fragmentIndex :
                if int(leftValue) > int(disData[currentPoint][leftIter]):
                        leftValue = disData[currentPoint][leftIter]
                        leftIndex = leftIter
        pathIndex.append(leftIndex)
        fragmentIndex.remove(leftIndex)
        currentPoint = leftIndex

pathDis = 0 
for pathIter in range(0,cityCount-1):
       pathDis += int(disData[pathIndex[pathIter]][pathIndex[pathIter+1]])
print(pathIndex)
print(pathDis)
