#ifndef TT_H
#define TT_H

#include<iostream>
#include<stack>
#include<vector>


using namespace std;

typedef class BoundNode{
public:
	BoundNode();
	~BoundNode();
	BoundNode(int nodeIndex);

	//it's for copy Best node
	BoundNode(BoundNode*);
	//it's for inheritance
	BoundNode(int** , BoundNode*, int,int,int);

	int nodeIndex;
	int nodeLevel;
	int curDis;
	int promValue;

	vector<int>* treeStack;
	// 'A~D'
	char nodeKind;

	
	int getCurDis(BoundNode* parent);
	int getpromValue(BoundNode* parent);
	char getNodeKind();
};

typedef class BranchTree{
public:
	BranchTree();
	stack<BoundNode>* treeTraverse;
	int startSetting(BoundNode* startNode, int citySize, int meanDis);
};



#endif
