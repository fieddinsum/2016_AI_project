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
	std::vector<int>::iterator vecIt;
	//for making node
	BoundNode* tempNode;
	//nodeSearch
	BoundNode* searchNode;
	
	while (!treeStructure->treeTraverse->empty()){

		searchNode = &(treeStructure->treeTraverse->top());
		
		//if this node is terminal node
		if (searchNode->nodeLevel == (configure->cityCount)-1){
			//it's bigger than I have
			if (searchNode->curDis >= currentGotPath){
				bestTrip = (*searchNode);
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
					vecIt = find(searchNode->treeStack->begin(), searchNode->treeStack->end(),genIter );
					// if this node use => remove from list 
					if (vecIt == searchNode->treeStack->end()){
						//enroll the node
						tempNode = new BoundNode(cityDistArray,searchNode, genIter,configure->meanValue);
					}
					
				}
				
				//dellocation 
				delete searchNode;


			}
		}

		

	}
	// after searching print minimum value

	return 0;
	}

