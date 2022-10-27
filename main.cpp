#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

#include "Level.h"
using namespace std;

//ints to keep track of size of 3d array for input
int z, x, y;

//string temp to temporarily hold file names
string temp;

//map of strings/Level*
map <string, Level*> myMap;

//create an ifstream object to read from files
ifstream myFile1;

//ofstream object to read Level data to files
ofstream toFile;

//preview of writeLevel - parameters string to store file mame, and Level pointer
void writeLevel(string fileName, Level*);


//preview of readLevel - parameter string fileName to store name of file -- returns Level *
Level* readLevel(string fileName);



int main()
{

	//vector of strings to contain file names
	vector <string> fileNameVector;

	//create an ifstream object to read from files
	ifstream myFile1;

	//open Level1.txt, read in the first string, add to end of fileNameVector, close ifStream 
	myFile1.open("Level1.txt");
	myFile1 >> temp;
	fileNameVector.push_back(temp);
	myFile1.close();

	//open Level2.txt, read in the first string, add to end of fileNameVector, close ifStream 
	myFile1.open("Level2.txt");
	myFile1 >> temp;
	fileNameVector.push_back(temp);
	myFile1.close();

	//open Level3.txt, read in the first string, add to end of fileNameVector, close ifStream 
	myFile1.open("Level3.txt");
	myFile1 >> temp;
	fileNameVector.push_back(temp);
	myFile1.close();

	//for loop to print out the contents of fileNameVector
	for (int i = 0; i < fileNameVector.size(); i++)
	{
		cout << fileNameVector.at(i) << endl;
	}

	//for loop to read in the value of fileNameVector into readLevel -> return Level*
	//add pair of fileNameVector.at(i) and Level* to map
	for (int i = 0; i < fileNameVector.size(); i++)
	{
		if (fileNameVector.at(i) == "map1")
		{
			//set map pair to be fileNameVector.at(i) and the Level* object containing file "Level1.txt"
			myMap[fileNameVector.at(i)] = readLevel("Level1.txt");
			writeLevel("Level1.txt", myMap[fileNameVector.at(i)]);
		}
		if (fileNameVector.at(i) == "map2")
		{
			//set map pair to be fileNameVector.at(i) and the Level* object containing file "Level2.txt"
			myMap[fileNameVector.at(i)] = readLevel("Level2.txt");
			writeLevel("Level2.txt", myMap[fileNameVector.at(i)]);
		}

		if (fileNameVector.at(i) == "map3")
		{

			//set map pair to be fileNameVector.at(i) and the Level* object containing file "Level3.txt"
			myMap[fileNameVector.at(i)] = readLevel("Level3.txt");
			writeLevel("Level3.txt", myMap[fileNameVector.at(i)]);
		}


	}

	//read Level1.txt_OUT back in
	myMap["map1"] = readLevel("Level1.txt_OUT");
	//myMap["map1"]->printArray3d();

	//deallocate map memory level pointer
	for (int i = 0; i < fileNameVector.size(); i++)
	{
		delete myMap.at(fileNameVector.at(i));
	}



}


//Non member function writeLevel
//parameters string to store file mame, and Level pointer
void writeLevel(string fileName, Level* l)
{
	//use ofstream object to read to file
	toFile.open(fileName + "_OUT");

	//print the mapName, z,y,z to the new file
	toFile << l->getMapNumber() << endl << endl;
	toFile << l->getZ() << endl << l->getX() << endl << l->getY() << endl << endl;

	//double nested for loop to read data from Level object l array3d to file
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < x; k++)
			{
				toFile << l->getValue3d(i, j, k) << " ";
			}
			toFile << endl;
		}
		toFile << endl;
	}
	toFile << endl << endl;
	toFile << l->getZStart() << endl << l->getXStart() << endl << l->getYStart();

	//close ofStream
	toFile.close();
}


//Non member function readLevel
//parameter string fileName to store name of file -- returns Level *
Level* readLevel(string fileName)
{
	//temp int
	int value;

	//use ifStream object myFile1 to open paramater file
	myFile1.open(fileName);

	//eat file name -- already read and stored in vector fileNameVector
	myFile1 >> temp;

	//get the size of 3d array from file
	myFile1 >> z;
	myFile1 >> x;
	myFile1 >> y;

	//create a new level with arrray3d member of size [z][x][y]
	Level* newLevel = new Level(z, x, y);

	//set mapNumber data type to temp
	newLevel->setMapNumber(temp);
	//double nested for loop to read values from myFile1 into the array3d member of Level object
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < x; k++)
			{
				//store value of file 
				myFile1 >> value;
				//set value of array3d[i][j][k] to value using setArray3d
				newLevel->setArray3d(i, j, k, value);
			}
		}
	}
	
	//read in values for members of Level zStart, xStart, yStart
	//zStart
	myFile1 >> value;
	newLevel->setZStart(value);

	//xStart
	myFile1 >> value;
	newLevel->setXStart(value);

	//yStart
	myFile1 >> value;
	newLevel->setYStart(value);
	

	//close ifStream object myFile
	myFile1.close();

	//return newLevel object
	return newLevel;
}
