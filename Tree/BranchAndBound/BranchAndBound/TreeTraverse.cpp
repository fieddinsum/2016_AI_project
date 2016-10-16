#include"TreeTraverse.h"

// -> =

BoundNode::~BoundNode(){
	//delete treeStack;
}


BoundNode::BoundNode(){

	int iter = 0;
	for (iter = 0; iter < CITYMAX; iter++){
		treeStack[iter] = -1;
	}
	this->nodeIndex = -1;
	nodeLevel = -1;
	
	//A
	curDis = -1;
	//C
	promValue = -1;
	nodeKind = 'A';

}

BoundNode::BoundNode(int nodeIndex){
	//A
	int iter;
	this->curDis = -1;
	this->nodeIndex = nodeIndex;
	this->nodeKind = 'A'; 

	for (iter = 0; iter < CITYMAX; iter++){
		treeStack[iter] = -1;
	}
	for (iter = 0; iter < CITYMAX; iter++){
		if (treeStack[iter] == -1){
			treeStack[iter] = nodeIndex;
			break;
		}
	}

	this->nodeLevel=-1;
	//C
	this->promValue=-1;
}

BoundNode::BoundNode(BoundNode* copyNode){
	int iter;
	this->curDis = copyNode->curDis;
	this->nodeIndex = copyNode->nodeIndex;
	this->nodeKind = copyNode->nodeKind;
	this->nodeLevel = copyNode->nodeLevel;
	this->promValue = copyNode->promValue;
	for (iter = 0; iter < CITYMAX; iter++){
		treeStack[iter] = -1;
	}

	for (iter = 0; copyNode->treeStack[iter] != -1; iter++){
		this->treeStack[iter] = copyNode->treeStack[iter];
	}
}

// -> =
BoundNode::BoundNode(int** cityDistArray, BoundNode* parent, int nodeIndex, int meanvalue,int citySize){
	
	int iter;
	for (iter = 0; iter < CITYMAX; iter++){
		treeStack[iter] = -1;
	}

	for (iter = 0; parent->treeStack[iter] != -1; iter++){
		this->treeStack[iter] = parent->treeStack[iter];
	}

	this->nodeIndex = nodeIndex;
	treeStack[iter] = this->nodeIndex;

	this->nodeLevel = parent->nodeLevel + 1;


	this->curDis = parent->curDis + cityDistArray[parent->nodeIndex][nodeIndex];
	this->promValue = this->curDis + (meanvalue)* ((citySize)-(iter+1));

}



//must be implemented
int BoundNode::getCurDis(BoundNode* parent){ return 0; }
int BoundNode::getpromValue(BoundNode* parent){ return 0; }
char BoundNode::getNodeKind(){ return 1; }


int BranchTree::startSetting(BoundNode* startNode,int citySize,int meanDis){

	startNode->nodeLevel = 0;
	startNode->curDis = 0;
	startNode->promValue = (meanDis) * (citySize);
	this->treeTraverse->push(*startNode);
	return 0;
}



BranchTree::BranchTree(){

	treeTraverse = new stack<BoundNode>();
}