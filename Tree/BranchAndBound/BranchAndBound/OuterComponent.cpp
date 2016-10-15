#include"OuterComponent.h"

//constructor
OuterComponent::OuterComponent(){
	 meanValue=-1;
	 maxDist=-1;
	 sumDist = -1;
	 cityCount=-1;
	 idle_cost = -1;
	 startNode = new BoundNode();
}

// count(x>=d) d: meanDistance  
int OuterComponent::calculMeanCount(int* index, int** distArray){
	int outerIter, innerIter;

	int loserNodeIndex = 0;
	int minCount = 9999;

	for (outerIter = 0; outerIter < cityCount; outerIter++){
		int tempCount = 0;

		for (innerIter = 0; innerIter < cityCount; innerIter++){
			if (innerIter != outerIter){
				if (distArray[outerIter][innerIter]> meanValue){
					tempCount++;
				}
			}

		}
		if (tempCount <= minCount){
			loserNodeIndex = outerIter;
			minCount = tempCount;
		}
		index[outerIter] = tempCount;

	}
	return loserNodeIndex;
}


int** OuterComponent::makeDisMap(){
	int newiter;
	int** mapdist = new int*[CITYMAX];
	for (newiter = 0; newiter < CITYMAX; newiter++){
		mapdist[newiter] = new int[CITYMAX];
	}

	return mapdist;
}

//out : sumation 
int OuterComponent::transCityData(int ** distArray,int cityCount){
	
	int colIter, rowIter;
	for (colIter = 0; colIter < cityCount; colIter++){
		for (rowIter = 0; rowIter < colIter; rowIter++){
			distArray[colIter][rowIter] = (maxDist + 1) - distArray[colIter][rowIter];
			distArray[rowIter][colIter] = distArray[colIter][rowIter];
		}
	}
	return 0;
}

//out: lineCount
int OuterComponent::readCityDistance(int** distArray){

	ifstream mapfile;
	string stringBuffer;
	string token;
	char* lineBuffer = new char[LINESIZE];
	int lineIter = 0;
	int rowIter;
	mapfile.open("cityDistance600.txt");

	while ((mapfile.getline(lineBuffer, LINESIZE))){
		stringBuffer = string(lineBuffer);
		istringstream ss(stringBuffer);
		rowIter = 0;
		while (getline(ss, token, ' ')){

			distArray[lineIter][rowIter] = stoi(token, nullptr, 10);
			if (distArray[lineIter][rowIter] >= maxDist){
				maxDist = distArray[lineIter][rowIter];
			}
			sumDist += distArray[lineIter][rowIter];
			rowIter++;
		}
		lineIter++;
	}
	return lineIter;
}
