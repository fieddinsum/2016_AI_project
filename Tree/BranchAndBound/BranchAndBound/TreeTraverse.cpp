#include"TreeTraverse.h"

// -> =

BoundNode::~BoundNode(){
	//delete treeStack;
}


BoundNode::BoundNode(){

	treeStack = new vector<int>();
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
	this->curDis = -1;
	this->nodeIndex = nodeIndex;
	this->nodeKind = 'A';
	this->treeStack = new vector<int>();
	this->treeStack->push_back(nodeIndex);
	this->nodeLevel=-1;
	//C
	this->promValue=-1;
}

BoundNode::BoundNode(BoundNode* copyNode){
	this->curDis = copyNode->curDis;
	this->nodeIndex = copyNode->nodeIndex;
	this->nodeKind = copyNode->nodeKind;
	this->nodeLevel = copyNode->nodeLevel;
	this->promValue = copyNode->promValue;
	this->treeStack = new vector<int>(*copyNode->treeStack);
}

// -> =
BoundNode::BoundNode(int** cityDistArray, BoundNode* parent, int nodeIndex, int meanvalue,int citySize){
	
	treeStack = new vector<int>(*parent->treeStack);

	this->nodeIndex = nodeIndex;
	treeStack->push_back(this->nodeIndex);

	this->nodeLevel = parent->nodeLevel + 1;


	this->curDis = parent->curDis + cityDistArray[parent->nodeIndex][nodeIndex];
	this->promValue = this->curDis + (meanvalue)* ((citySize)-(treeStack->size()));

}



//must be implemented
int BoundNode::getCurDis(BoundNode* parent){ return 0; }
int BoundNode::getpromValue(BoundNode* parent){ return 0; }
char BoundNode::getNodeKind(){ return 1; }


int BranchTree::startSetting(BoundNode* startNode,int citySize,int meanDis){

	startNode->nodeLevel = 0;
	startNode->curDis = 0;
	startNode->promValue = (meanDis) * ( (citySize) - (startNode->treeStack->size() ));
	this->treeTraverse->push(*startNode);
	return 0;
}



BranchTree::BranchTree(){

	treeTraverse = new stack<BoundNode>();
}