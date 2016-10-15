#include"TreeTraverse.h"

// -> =

BoundNode::~BoundNode(){

	delete treeStack;
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

	treeStack = new vector<int>();
	this->nodeIndex= nodeIndex;
	nodeLevel=-1;

	//A
	curDis=-1;
	//C
	promValue=-1;
	nodeKind = 'A';
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
BoundNode::BoundNode(int** cityDistArray, BoundNode* parent, int nodeIndex, int meanvalue){
	
	treeStack = new vector<int>(*parent->treeStack);
	treeStack->push_back(this->nodeIndex);

	this->nodeIndex = nodeIndex;
	this->nodeLevel = parent->nodeLevel + 1;


	this->curDis = parent->curDis; // + [p,c] Dis
	this->promValue = parent->promValue - meanvalue;

}



//must be implemented
int BoundNode::getCurDis(BoundNode* parent){ return 0; }
int BoundNode::getpromValue(BoundNode* parent){ return 0; }
char BoundNode::getNodeKind(){ return 1; }


int BranchTree::startSetting(BoundNode* startNode,int citySize,int meanDis){

	startNode->nodeLevel = 0;
	startNode->curDis = 0;
	startNode->treeStack->push_back(startNode->nodeIndex);
	startNode->promValue = (meanDis) * ( (citySize) - (startNode->treeStack->size() ));
	this->treeTraverse->push(*startNode);
	return 0;
}



BranchTree::BranchTree(){

	treeTraverse = new stack<BoundNode>();
}