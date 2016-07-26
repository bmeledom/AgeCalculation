#include "DataIO.h"

//Constrictor Creates a Data file with the given sample size, uses Random numbers
DataIO::DataIO(int DataSize)
{
	int Birth, Death;
	int i = 0;
	DataSetName = "SampleDatFile.Dat";
	maxDataSize = DataSize;
	remove(DataSetName.c_str());
	ofstream Datafile(DataSetName.c_str());
	char name[25];
	
	while (!Datafile.eof())
	{
		int Year1 = 1900 + rand() % 100;
		int Year2 = 2000 - rand() % 100;

		if (Year1 < Year2)
		{
			Birth = Year1;
			Death = Year2;
		}
		else
		{
			Birth = Year2;
			Death = Year1;
		}
		sprintf(name, "SampleName_%d",i);
		//Write Sample Data to the Data File
		Datafile << name << " " << Birth << " " << Death << endl;
		i++;
		if (i > maxDataSize) break;
	}
	Datafile.close();

}

//Method to read the datafile
int DataIO::ReadFromDataFile()
{
	int numoflines = 0;
	ifstream datafile(DataSetName.c_str());
	Person pObj;
	string strArray[3];

	if (datafile.is_open())
	{
		int i = 0, j = 0, k = 0;
		int i1 = 0;
		while (!datafile.eof())
		{
			datafile >> strArray[i1];

			if (i1 < 3)	k = i1 + 3;
			else k = i1;

			if (k % 3 == 0) pObj.name = strArray[i1];
			else if (k % 3 == 1) pObj.Birth = atoi(strArray[i1].c_str());
			else if (k % 3 == 2)
			{
				pObj.Death = atoi(strArray[i1].c_str());
				persons.push_back(pObj);
				j++;
			}
			else
			{
				cout << "Error" << endl;
				return -1;
			}

			if (i1 == 2)
				i1 = 0;
			else if (i1 < 2)
				i1++;
			else
			{
				cout << "Error" << endl;
				return -1;
			}
		}
		numoflines = j;
	}
	return numoflines;
}
