#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class BoundNode{
public:

	BoundNode();
	BoundNode(BoundNode*, int);

	int nodeIndex;
	int nodeLevel;
	int curDis;
	int promValue;

	vector<int>* treeStack;
	//  sociable & lonely
	char nodeKind;

	
	int getCurDis(BoundNode* parent);
	int getpromValue(BoundNode* parent);
	char getNodeKind();
};

class BranchTree{
public:
	BranchTree();
	vector<BoundNode>* treeTraverse;
	
};

