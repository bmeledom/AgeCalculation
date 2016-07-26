#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <math.h>
#include "DataIO.h"

#define MAX_DATA_SIZE 1500
using namespace std;

int main()
{
	map < int, int > years;

	for (int i = 1900; i <= 2000; i++)
		years.insert(pair<int, int>(i, 0));

	DataIO ObjDataIO(MAX_DATA_SIZE);

	if (ObjDataIO.ReadFromDataFile() < 0)
	{
		cout << "Error Exiting" << endl;
		return -1;
	}

	list < Person >::iterator itl;
	int maxYears = 0, prevmaxYears = 0;
	//iterate over the list and then over the year range and see if we find a match, then increment
	for (itl = ObjDataIO.persons.begin(); itl != ObjDataIO.persons.end(); itl++)
	{
		for (int i = itl->Birth; i <= itl->Death; i++)
		{
			years[i]++;
			maxYears = years[i] > prevmaxYears ? years[i] : prevmaxYears;
			prevmaxYears = maxYears;
		}
	}

	// Plot a vertical histogram
	double plotfactor = maxYears / (20);
	map <int, int>::iterator itm;
	for (itm = years.begin(); itm != years.end(); itm++)
	{
		cout << "Year " << itm->first << " ";
		for (int i = 0; i <= ceil(itm->second / plotfactor); i++)
			cout << "#";
		cout << " " << itm->second << endl;
	}
	cout << "The Highest is " << maxYears << " prev " << prevmaxYears << endl;
	return 0;
}
