#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


static const int LINESIZE = 4000;
static const int CITYMAX = 600;
extern int MAXDIST;
extern int SUMDIST;
extern int citycount;

class OuterComponent{

public:
	OuterComponent();

	int** makeDisMap();
	int readCityDistance(int**);
	int transCityData(int**, int);
};