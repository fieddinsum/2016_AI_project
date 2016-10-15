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
	configure->meanValue = (configure->maxDist+1) - (int)(configure->sumDist / getEdgeCount())-50;
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
	BoundNode* bestTrip = new BoundNode();
	//std::vector<int>::iterator vecIt;
	int initIter;
	int tempIter;
	int isregist = 0;
	//nodeSearch
	BoundNode* searchNode;
	//insert Node to Tree 
	BoundNode* tempNode;
	stack<BoundNode>* tempStack = new stack<BoundNode>();
	
	while (!treeStructure->treeTraverse->empty()){

		searchNode = new BoundNode(treeStructure->treeTraverse->top());
		
		//if this node is terminal node
		if (searchNode->nodeLevel == (configure->cityCount)-1){
			//it's bigger than I have
			if (searchNode->curDis >= currentGotPath){
				bestTrip = new BoundNode(searchNode);
				currentGotPath = bestTrip->curDis;
				printf("Best Trip is changing : %d\n", bestTrip->curDis);
			}
			treeStructure->treeTraverse->pop();
			delete searchNode;

		}

		// if is middle of tree
		else  {
			//if is not promising
			if (searchNode->promValue <= bestTrip->curDis){
				treeStructure->treeTraverse->pop();
				delete searchNode;
			}


			//if is promising
			else{
				// insert node that dosn't include present path 
				for (genIter = 0; genIter < configure->cityCount; genIter++){
		
					isregist = 0;
					for (initIter = 0; initIter < searchNode->treeStack->size(); initIter++){

						if (searchNode->treeStack->at(initIter) == genIter){
							isregist = 1;
							break;
						}
					}
					if (!isregist){
						tempStack->push(new BoundNode(cityDistArray, searchNode, genIter, configure->meanValue, configure->cityCount));
					}

					}	
				}

				// stack pop()
			printf("pop Level %d :\n", treeStructure->treeTraverse->top().nodeLevel);
				treeStructure->treeTraverse->pop();
				for (tempIter = 0; tempIter < tempStack->size(); tempIter++){
					tempNode = &tempStack->top();
					treeStructure->treeTraverse->push(tempNode);
					tempStack->pop();
				}

				//dellocation 
				delete searchNode;
			}
		}
	int i ;
	for (i = 0; i < bestTrip->treeStack->size(); i++){
		printf("%d ", bestTrip->treeStack->at(i));
	}
	return 0;
	// after searching print minimum value

	}


