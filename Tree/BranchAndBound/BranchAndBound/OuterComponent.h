#ifndef OC_H
#define OC_H

#include"TreeTraverse.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


static const int LINESIZE = 4000;
static const int CITYMAX = 600;
//extern int MAXDIST;
//extern int SUMDIST;
//extern int citycount;

typedef class OuterComponent{
	
 


public:
	//constructer
	OuterComponent();
	int meanValue;
	int maxDist;
	double sumDist;
	int cityCount;

	int idle_cost;
	BoundNode* startNode;


	int** makeDisMap();
	int readCityDistance(int**);
	int transCityData(int**, int);
	int calculMeanCount(int* index, int** distArray);

};

#endif