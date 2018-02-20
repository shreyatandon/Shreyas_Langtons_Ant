#include<iostream>
#include<opencv2/opencv.hpp>
#include<string>

using namespace cv;
using namespace std;

/*int main(int argc, char** argv)
{
	int rows = 200;
	int cols = 200;

	Mat I(rows, cols, CV_8U);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			I.at<uchar>(i, j) = 255;
		}
	}
			I.at<uchar>(rows/2, cols/2) = 0;*/



//class Board
//{	
//public:
//	int rows;
//	int cols;
//	
//public:
//	Mat collectinitialdata(int rows, int cols);
//};

//Mat Board::collectinitialdata(int rows, int cols)
//{
//	Mat I(rows, cols, CV_8U);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			I.at<uchar>(i, j) = 255;
//		}
//	}
//	I.at<uchar>(rows / 2, cols / 2) = 128;
//	return I;
//	//return Mat();
//}


		
/*Mat collectinitialdata(int rows, int cols)
{
	Mat I(rows, cols, CV_8U);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			I.at<uchar>(i, j) = 255;
		}
	}
	I.at<uchar>(rows / 2, cols / 2) = 0;
	return I;
}*/
/*class Ant
{
		public:
			int x;
			int y;
			enum Ants_directn{north=0,east=1,south=2,west=3};			//NOT REQUIRED 
			//Ant(int x, int y, enum dir);

		public:		
			Mat Ants_movement(int x, int y, enum north);
};*/		



//class Ants_world:public Board

//Mat Ants_world::ants_word_movement(int x, int y, Ants_directn, string colour)
//{
//	Mat I;
//	if (colour == "white")
//	{
//		I.at<uchar>(rows, cols/2 + 1) = 128;
//		I.at<uchar>(rows / 2, cols / 2) = 0;
//	}
//
//	
//	return Mat();
//}

class Ant
{
public:
	int x;
	int y;
	int orientation;
};

class World
{
public:
	Ant cheenti;		//cheenti is data member to class World and Ant is itself a class
	Mat* board; //Board is a pointer to Mat
	World(int rows, int columns, int x, int y, int orientation);

public:
	//Mat ants_word_movement(int x, int y, enum Ants_directn, string colour);
	//int further_steps(int rows,int columns,int x,int y);
	void further_steps();


};


World::World(int rows, int columns, int x, int y, int orientation)
{
	/*we have declared a class world which has two data members Ant cheenti and Mat *board
	and Mat Board(declared previously which will not work kyuki when Mat Board is used we are 
	not able to create the contructor and allocation in same line so we want to declare 
	the Mat *board so that inside main function board->rows in the 2nd line of main function*/
	
	//this->board = new Mat(rows, columns, CV_8U);
	this->board = new Mat(rows, columns, CV_8U);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->board->at<uchar>(i, j) = 255;
		}
	}

	this->cheenti.x = x;
	this->cheenti.y = y;
	this->cheenti.orientation = orientation;
}

//int World::further_steps(int rows,int columns,int x,int y)
//{
//	//if (board->at<uchar>(50, 50) = 255)
//	if (this->board->at<uchar>(rows, columns) = 255)
//		this->cheenti.at<uchar>(x, y) = 0;
//	
//		
//		return 0;
//}


void World::further_steps()
{
	namedWindow("Shreya's Langton's Ant", CV_WINDOW_NORMAL);
	int rows = board->rows;
	int cols = board->cols;
	
	//int orientation = cheenti.orientation;
	int count = 0;
	while (cheenti.x >= 0 && cheenti.y >= 0 && cheenti.x < rows && cheenti.y < cols)
	{
		int x = cheenti.x;
		int y = cheenti.y;
		if (cheenti.orientation == 0)	//NORTH
		{
			if (board->at<uchar>(x, y)== 255)	//IS WHITE SO LEFT i.e 3
			{
				cheenti.orientation = 3;  //WEST
				cheenti.y--;
				board->at<uchar>(x, y) = 0;
			}
			else //Current Tile is Black
			{
				cheenti.orientation = 1;  //EAST
				cheenti.y++;
				board->at<uchar>(x,y)=255;
			}

		}
		else if (cheenti.orientation == 3)
		{
			if (board->at<uchar>(x, y) == 255)
			{
				cheenti.orientation = 2; //SOUTH
				cheenti.x++;
				board->at<uchar>(x, y) = 0;
			}
			else
			{
				cheenti.orientation = 0; //NORTH
				cheenti.x--;
				board->at<uchar>(x, y) = 255;
			}
		}
		else if (cheenti.orientation == 2)
		{
			if (board->at<uchar>(x, y) == 255)
			{
				cheenti.orientation = 1; //EAST
				cheenti.y++;
				board->at<uchar>(x, y) = 0;
			}
			else
			{
				cheenti.orientation = 3; //WEST
				cheenti.y--;
				board->at<uchar>(x, y) = 255;

			}

		}
		else if (cheenti.orientation == 1) //EAST
		{
			if (board->at<uchar>(x, y) == 255)
			{
				cheenti.orientation = 0; //NORTH
				cheenti.x--;
				board->at<uchar>(x, y) = 0;

			}
			else
			{
				cheenti.orientation = 2; //NORTH
				cheenti.x++;
				board->at<uchar>(x, y) = 255;
			}
		}

		imshow("Shreya's Langton's Ant", *board);
		
		waitKey(1);
		
		count = count + 1;
		imwrite(to_string(count) + ".png", *board);
		if (count%1000==0)
		{
			cout << " This Was Iteration Number : " << count << endl;
		}
		
	}
	waitKey(0);
	destroyWindow("langton's_Ant");

}

int main()
{
	//World W(100, 100, 50, 50, 0);

	
	int rows, cols, x, y, orientation;
	cout << "enter no of rows" << endl;
	cin >> rows;
	cout << "enter no of cols" << endl;
	cin >> cols;

	cout << "enter the X co-ordinate of cheenti" << endl;
	cin >> x;
	cout << "enter the  Y co-ordinate of cheenti" << endl;
	cin >> y;
	cout << "enter the orientation of the cheenti" << endl;
	cin >> orientation;


	World W(rows, cols, x, y, orientation);
	W.further_steps();

	getchar();


	
	
	

	return 0;




	

	
		//	Mat I = B.collectinitialdata(rows, cols);
		//	if (I.empty())
		//	{
		//		cout << "ghanta";
		//		return -1;
		//	}

	
	//W.cheenti.x;
	//cout << W.cheenti.x << endl;
	//cout << W.board->rows << endl;	//word is a class and DOT(.) operator is used to access the members and board here is a pointer to class Mat so (->) arrow operator is used to access the data members.
	




}

/*Ant::Ant(int x, int y, dir)
{

	this->x = x;
	this->y = y;
	this->dir = 0

}*/

/*class Ant :public Board, public Mat
{
	Mat Ant::Ants_movement(int x, int y, enum north)
	{
		int x = 200 / 2;
		int y = 200 / 2;
		

			//if(I.at<uchar>(rows/2,cols/2)==0)



			return Mat();
	}
};*/


	/*class Ant :public Mat
		Mat Ant::Ants_movement(int x, int y, north)
	{


		if (I.at<uchar>(rows / 2, cols / 2) == 0)
			cout << "ant is on the black and move it right";
		return Mat;

	}*/

/*Mat Ant::Ants_movement(int x, int y, enum north)			//NOT REQUIRED
{


	return Mat();
}*/


//int main()
//{
//	int rows, cols;
//	cout << "enter no of rows" << endl;
//	cin >> rows;
//	cout << "enter no of cols" << endl;
//	cin >> cols;
//	Board B;
//	Mat I = B.collectinitialdata(rows, cols);
//	if (I.empty())
//	{
//		cout << "ghanta";
//		return -1;
//	}
//
//		namedWindow("Langton's_Ant", CV_WINDOW_NORMAL);
//		imshow("Langton's_Ant", I);
//		waitKey(0);
//		destroyWindow("Langton's_Ant");
//		return 0;
//
//}