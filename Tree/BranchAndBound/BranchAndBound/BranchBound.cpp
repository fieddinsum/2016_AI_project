#include"OuterComponent.h"
#include"TreeTraverse.h"



int getEdgeCount(){
	int countIter;
	int edgeCount=0;
	for (countIter = 1; countIter < CITYMAX; countIter++){
		edgeCount += countIter;
	}
	return edgeCount;
}


int main(){

	//FILE IOL{
	OuterComponent* configure = new OuterComponent();
	int** cityDistArray = configure->makeDisMap();

	//include MAX / SUMDIS

	int cityCount = configure->readCityDistance(cityDistArray);	
	
	//complement data (for searching )
	int meanValue = (MAXDIST+1) - (int)(SUMDIST / getEdgeCount());
	configure->transCityData(cityDistArray,cityCount);

	//evaluate
	int* evaluation = new int[cityCount]();

	
	
	
	//traverse Tree
	BranchTree* treeTraverse = new BranchTree();

	
	return 0;
	}

