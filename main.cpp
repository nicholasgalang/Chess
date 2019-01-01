#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "board.hpp"
using namespace std;

int main(){
	
	//Piece* p=new Queen(0,4,true);
	//Queen q=Queen(0,4);
	Board board;
	board.print();
	bool turn=true;
	while(true){
		// int oldRow;
		// int oldCol;
		// int newRow;
		// int newCol;
		// cout << "Please enter a row: ";
  // 		cin >> oldRow;
  // 		cout << "Please enter a col: ";
  // 		cin >> oldCol;
  // 		cout << "Please enter a new row: ";
  // 		cin >> newRow;
  // 		cout << "Please enter a new col: ";
  // 		cin >> newCol;
		std::string origin;
		std::string destination;
		cout << "What piece do you want to move (a1-h8): ";
  		cin >> origin;
  		cout << "Where do you want to move it (a1-h8): ";
  		cin >> destination;
  		if(origin.size()!=2||destination.size()!=2){
  			cout << "Invalid input length"<<std::endl;
  		}
  		else{
  			int oldRow=origin[1]-48;
  			oldRow=8-oldRow;
  			int oldCol=origin[0]-97;
  			cout << "oldRow:"<<oldRow<<std::endl;

  			int newRow=destination[1]-48;
  			newRow=8-newRow;
  			int newCol=destination[0]-97;

	  		bool moved=board.move(oldRow,oldCol,newRow,newCol,turn);
	  		//board.move(7,3,7,0);
			std::cout<<std::endl;
			board.print();

			if(moved)
				turn=!turn;
			bool inCheck=board.inCheck(turn);
			if(inCheck){
				if(board.checkmate(turn)){
					if(turn)
						std::cout<<"Black Wins!"<<std::endl;
					else
						std::cout<<"White Wins!"<<std::endl;
					break;
				}
				std::cout<<"Check"<<std::endl;
			}
			else{
				if(board.stalemate(turn)){
					std::cout<<"Draw"<<std::endl;
					break;
				}
			}
		}

  		
	}




	//p->print();
	return 0;
}