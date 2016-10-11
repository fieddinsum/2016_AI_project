#include"TreeTraverse.h"

// -> =
BoundNode::BoundNode(){

}

// -> =
BoundNode::BoundNode(BoundNode* parent,int nodeIndex){
	
	treeStack = new vector<int>(*parent->treeStack);
	treeStack->push_back(this->nodeIndex);

	this->nodeIndex = nodeIndex;
	this->nodeLevel = parent->nodeLevel + 1;
	this->curDis = getCurDis(parent);
	this->promValue = getpromValue(parent);
	this->nodeKind = getNodeKind();

}


//must be implemented
int BoundNode::getCurDis(BoundNode* parent){ return 0; }
int BoundNode::getpromValue(BoundNode* parent){ return 0; }
char BoundNode::getNodeKind(){ return 1; }



BranchTree::BranchTree(){

	treeTraverse = new vector<BoundNode>();
}