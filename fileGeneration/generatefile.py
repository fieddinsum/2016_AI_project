import random
import os
# = +


CityCount = 600
fileP = open('cityDistance600.txt','w')

dis = random.randint(10,300)


for i in range(0,CityCount):
    tempString = ""
    for j in range (0, i):
        tempString += str(random.randint(10,200))
        tempString += " "
    tempString += "0"
    tempString += " \n"

    fileP.write(tempString)

print('done')
fileP.close()
