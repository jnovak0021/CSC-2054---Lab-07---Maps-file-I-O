#pragma once
#include <iostream>
using namespace std;

//decleration of class Level to hold contents of file

class Level
{
public:
	//constructor to take in length, width and height of the array
	Level(int z, int x, int y);

	//mutator function to populate array3d with values read in from file
	void setArray3d(int z, int x, int y, int value);

	//accesor function to read values of array3d
	void printArray3d();

	//accessor to value of array at index z,x,y
	int getValue3d(int z, int x, int y);

	//accesor for z
	int getZ();

	//accesor for x
	int getX();

	// accesor for y
	int getY();

	//accesor for zStart
	int getZStart();

	//Mutator for zStart
	void setZStart(int valueIn);

	//accesor for xStart
	int getXStart();

	//Mutator for xStart
	void setXStart(int valueIn);

	//accesor for yStart
	int getYStart();

	//Mutator for yStart
	void setYStart(int valueIn);

	//get mapNumber
	string getMapNumber();

	//set mapNumber
	void setMapNumber(string sIn);
	
	
	//delete function to delete array3d;
	~Level();



private:
	//3d array pointer to hold integers of Level data
	int *** array3d;
	//integer z,x,y, to dynamically allocate size of 3d array based off constructor parameter
	int z = 0, x = 0, y = 0;	
	//private integers to store z,x,y start location
	int zStart = 0, xStart = 0, yStart = 0;

	//string to store map#
	string mapNumber = "";
	
};