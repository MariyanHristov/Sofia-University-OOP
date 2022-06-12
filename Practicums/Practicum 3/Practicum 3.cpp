#include <iostream>
#include <fstream>

using namespace std;


const int MAX_PAIRS_SIZE = 25;

struct Pair
{
	int x;
	int y;
};

struct Relation
{
	Pair pairs[MAX_PAIRS_SIZE];
	int size = 0;
};

Pair createPair(int x, int y)
{
	Pair R;
	cin >> R.x >> R.y;
	return R;
}

void writePairToFile(ofstream& writeFile, const Pair& p)
{
	writeFile << p.x << p.y << endl;
}

Pair readPairFromFile()
{
	ifstream relationsFile("relation.txt");

	if (!relationsFile.is_open())
	{
		cout << "Error!";
	}

	int x, y;
	relationsFile >> x >> y;
	return createPair(x, y);
}

Pair writeRelationToFile(ofstream& writeFile, const Pair& p)
{
	
}

int main()
{
	
}

