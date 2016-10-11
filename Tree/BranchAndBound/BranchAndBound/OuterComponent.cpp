#include"OuterComponent.h"



int MAXDIST;
int SUMDIST;



//constructor
OuterComponent::OuterComponent(){

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
			distArray[colIter][rowIter] = (MAXDIST + 1) - distArray[colIter][rowIter];
			distArray[rowIter][colIter] = distArray[colIter][rowIter];
		}
	}
	return 0;
}

//out: lineCount
int OuterComponent::readCityDistance(int** distArray){


	MAXDIST=0;
	SUMDIST=0;

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
			if (distArray[lineIter][rowIter] >= MAXDIST){
				MAXDIST = distArray[lineIter][rowIter];
			}
			SUMDIST += distArray[lineIter][rowIter];
			rowIter++;
		}
		lineIter++;
	}
	return lineIter;
}
