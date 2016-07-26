#include <iostream>
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Person
{
	string name;
	int Birth;
	int Death;
};

class DataIO
{
public:
	DataIO(int);
	list <Person> persons;
	int ReadFromDataFile();

private:
	string DataSetName;
	int maxDataSize;
};
