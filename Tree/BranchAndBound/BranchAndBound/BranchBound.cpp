#include"TreeTraverse.h"
#include"OuterComponent.h"
#include<algorithm>

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
	configure->cityCount = configure->readCityDistance(cityDistArray);	
	
	//complement data (for searching )
	configure->meanValue = (configure->maxDist+1) - (int)(configure->sumDist / getEdgeCount());
	configure->transCityData(cityDistArray, configure->cityCount);

	//evaluate
	int* evaluationIndex = new int[configure->cityCount]();
	
	//select start index
	int hoguIndex;
	hoguIndex = configure->calculMeanCount(evaluationIndex, cityDistArray);
		
	//construct Tree & add firstNode to Tree
	BranchTree* treeStructure = new BranchTree();
	BoundNode* startNode = new BoundNode(hoguIndex);
	treeStructure->startSetting(startNode, configure->cityCount, configure->meanValue);

	// while tree was empty
	int genIter;
	int currentGotPath = 0;
	BoundNode bestTrip;
	//std::vector<int>::iterator vecIt;
	int initIter;
	int isregist = 0;
	//nodeSearch
	BoundNode* searchNode;
	
	while (!treeStructure->treeTraverse->empty()){

		searchNode = new BoundNode(treeStructure->treeTraverse->top());
		
		//if this node is terminal node
		if (searchNode->nodeLevel == (configure->cityCount)-1){
			//it's bigger than I have
			if (searchNode->curDis >= currentGotPath){
				bestTrip = (*searchNode);
				printf("Best Trip is changing : %d", bestTrip.curDis);
			}
			treeStructure->treeTraverse->pop();
			delete searchNode;

		}

		// if is middle of tree
		else  {
			//if is not promising
			if (searchNode->promValue <= bestTrip.curDis){
				treeStructure->treeTraverse->pop();
				delete searchNode;
			}


			//if is promising
			else{
				// stack pop()
				treeStructure->treeTraverse->pop();

				// insert node that dosn't include present path 
				for (genIter = 0; genIter < configure->cityCount; genIter++){
		
					isregist = 0;
					for (initIter = 0; initIter < treeStructure->treeTraverse->size(); initIter++){

						if (searchNode->treeStack->at(initIter) == genIter){
							isregist = 1;
							break;
						}
					}
					if (!isregist){
						treeStructure->treeTraverse->push(new BoundNode(cityDistArray, searchNode, genIter, configure->meanValue, configure->cityCount));
					}

					}	
				}		
				//dellocation 
				delete searchNode;
			}
		}
	return 0;
	// after searching print minimum value
	}


