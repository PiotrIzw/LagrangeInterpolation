#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class LagrangeInterpolation {

private:
	string line;
	fstream file;
	float x[100], y[100], searchedValue = 1.0, numberOfNodes[1], result, resultTemp = 0;
	float* loadData(string filename, float array[]);
public:

	float findPolynomial(string filenumberOfNodes,
		string fileInterpolationNodes,
		string fileFunctionValues,
		float x);
};

float* LagrangeInterpolation::loadData(string filename, float array[]) {
	int i = 0;
	file.open(filename, ios::in);
	if (file.good() == true)
	{
		while (!file.eof())
		{
			getline(file, line);
			array[i] = stof(line); // stoi - konwersja string do float
			i++;
		}
		file.close();
	}
	return array;
}


float LagrangeInterpolation::findPolynomial(string filenumberOfNodes,
	string fileInterpolationNodes,
	string fileFunctionValues, float point) {

	loadData(filenumberOfNodes, numberOfNodes);
	loadData(fileInterpolationNodes, x);
	loadData(fileFunctionValues, y);

	for (int i = 0; i < numberOfNodes[0]; i++) {


		for (int j = 0; j < numberOfNodes[0]; j++) {
			if (x[i] != x[j]) {
				searchedValue *= ((point - x[j])) / ((x[i] - x[j]));

			}
		}

		searchedValue *= y[i];
		resultTemp += searchedValue;
		searchedValue = 1.0;
	}
	result = resultTemp;
	resultTemp = 0;
	return result;
}


int main()
{
	LagrangeInterpolation test;

	float x;
	while (true) {
		cout << "Podaj punkt: ";
		cin >> x;
		cout << "Wartosc wielomianu dla punktu " << x << " wynosi: " <<
			test.findPolynomial("numberofnodes.txt", "xvalues.txt", "yvalues.txt", x) << endl;
	}

	system("Pause");
	return 0;
}
