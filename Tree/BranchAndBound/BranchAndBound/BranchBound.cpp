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


void clear(std::stack<BoundNode> &q)
{
	std::stack<BoundNode> empty;
	std::swap(q, empty);
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
	
	// while tree was empty
	int genIter;
	int currentGotPath = 0;
	BoundNode bestTrip;
	//std::vector<int>::iterator vecIt;
	int initIter;
	int tempIter;
	int isregist[CITYMAX] = { 0, };
	//nodeSearch
	BoundNode* searchNode;
	//insert Node to Tree 
	BoundNode* tempNode;
	stack<BoundNode>* tempStack = new stack<BoundNode>();

	//select  1/500 value
	int loadselection;

	BoundNode* startNode = new BoundNode(hoguIndex);

	treeStructure->startSetting(startNode, configure->cityCount, configure->meanValue);



	while (!treeStructure->treeTraverse->empty()){
		searchNode = new BoundNode(treeStructure->treeTraverse->top());
		
		//if this node is terminal node
		if (searchNode->nodeLevel == (configure->cityCount)-1){
			//it's bigger than I have
			if (searchNode->curDis > currentGotPath){
				bestTrip = *searchNode;
				currentGotPath = bestTrip.curDis;
				printf("Best Trip is changing : %d\n", bestTrip.curDis);
			}
			treeStructure->treeTraverse->pop();
			delete searchNode;
		

		}

		// if is middle of tree
		else  {
			//if is not promising			
			if (searchNode->promValue <= bestTrip.curDis){
				treeStructure->treeTraverse->pop();
			}


			//if is promising
			else{

				// mark using path 	
				for (initIter = 0; searchNode->treeStack[initIter] != -1; initIter++){
						isregist[(searchNode->treeStack[initIter])] = 1;
						
					}
					for (genIter = 0; genIter < configure->cityCount; genIter++){
						if (!(isregist[genIter])){
							tempStack->push(new BoundNode(cityDistArray, searchNode, genIter, configure->meanValue, configure->cityCount));
						}
					}

					for (int i = 0; i < CITYMAX; i++){
						isregist[i] = 0;
					}

				// stack pop()
				treeStructure->treeTraverse->pop();
				// stack push()
				for (;(!tempStack->empty());){
					treeStructure->treeTraverse->push(tempStack->top());
					tempStack->pop();
				}
			}

				//dellocation 
				delete searchNode;
			}
		}

	int i = 0; 
	for (int i = 0; i < bestTrip.treeStack[i]!=-1; i++){
		printf("%d ", bestTrip.treeStack[i]);
	}
	return 0;
	// after searching print minimum value

	}


