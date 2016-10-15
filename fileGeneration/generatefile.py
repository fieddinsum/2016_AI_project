import random
import os
# = +


CityCount = 600
fileP = open('cityDistance600.txt','w')


for i in range(0,CityCount):
    tempString = ""
    for j in range (0, i):
        tempString += str(random.randint(10,800))
        tempString += " "
    tempString += "0"
    tempString += " \n"

    fileP.write(tempString)

print('done')
fileP.close()
