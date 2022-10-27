#include "Level.h"

//definition of overloaded Level constructor that takes in 3 int parameter
//dynamically creates 3d array using sizes l,w,h
Level::Level(int zIn, int xIn, int yIn) : z(zIn), x(xIn), y(yIn)
{
	//dynamically allocate array3d to hold length ints
	array3d = new int** [z];

	//nested for loop to dynamically allocated 2d array and 3d array with size w and h
	for (int i = 0; i < z; i++)
	{
		//dynamically allocate array3d[i] to hold witdh ints
		array3d[i] = new int* [x];
		
		for (int j = 0; j < x; j++)
		{
			//dynamically allocate array3d[i][j] to hold height ints
			array3d[i][j] = new int[y];
		}
	}
}

//printArray3d containing double nested loop to print array3d[i][j][k]
void Level::printArray3d()
{
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < x; j++)
		{
			
			for (int k = 0; k < y; k++)
			{
				cout << array3d[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int Level::getValue3d(int z, int x, int y)
{
	//return the value of the array at the index [z][x][y]
	return array3d[z][x][y];
}

//set 
void Level::setArray3d(int z, int x, int y, int value)
{
	array3d[z][x][y] = value;
}

//accesor for zStart
int Level::getZStart()
{
	return zStart;
}

//Mutator for zStart
void Level::setZStart(int valueIn)
{
	zStart = valueIn;
}

//accesor for xStart
int Level::getXStart()
{
	return xStart;
}

//Mutator for xStart
void Level::setXStart(int valueIn)
{
	xStart = valueIn;
}

//accesor for yStart
int Level::getYStart()
{
	return yStart;
}

//Mutator for yStart
void Level::setYStart(int valueIn)
{
	yStart = valueIn;
}

//get mapNumber
string Level::getMapNumber()
{
	return mapNumber;
}

//set mapNumber
void Level::setMapNumber(string sIn)
{
	mapNumber = sIn;
}

//accesor for z
int Level::getZ()
{
	return z;
}

//accesor for x
int Level::getX()
{
	return x;
}

// accesor for y
int Level::getY()
{
	return y;
}

//deallocate function
Level::~Level()
{
	delete array3d;
}