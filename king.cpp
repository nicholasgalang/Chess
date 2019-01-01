#include "piece.hpp"

King::King(int row1,int col1,bool color1){
  row=row1;
  col=col1;
  color=color1;
   moved=false;

}

void King::print(){
if(isWhite())
  std::cout<<"K";
else
	 std::cout<<"k";

    //std::cout<<std::endl;
}

std::vector<std::tuple<int,int>> King::moves(std::vector<std::vector<Piece*> >& board,Piece& king){
	std::vector<std::tuple<int,int>> moves;

	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			bool center=(i==0&&j==0);
			if(!center){
				int newRow=row+i;
				int newCol=col+j;
				
				if(inBounds(newRow,newCol)&&(board[newRow][newCol]==NULL||!board[newRow][newCol]->isSameColor(color)))
					addMoveIfNotInCheck(newRow,newCol,board,king,moves);
			}
		}
	}



	return moves;
}

bool King::canCastleKingSide(std::vector<std::vector<Piece*> >& board,Piece& rook){
	//std::cout<<rook.hasMoved()<<std::endl;

	if(!moved&&!rook.hasMoved()&&board[row][5]==NULL&&board[row][6]==NULL){
		std::cout<<"Why3"<<std::endl;
		if(!inCheck(board,*this)){
			std::cout<<"Why4"<<std::endl;
			board[row][5]=this;
			board[row][4]=NULL;
			col=5;
			if(!inCheck(board,*this)){
				board[row][6]=this;
				board[row][5]=NULL;
				col=6;
				if(!inCheck(board,*this)){
					board[row][4]=this;
					board[row][6]=NULL;
					col=4;
					return true;
				}
			}

		}
		col=4;
		board[row][4]=this;	
		board[row][6]=NULL;
		board[row][5]=NULL;	

	}
	return false;
}
bool King::canCastleQueenSide(std::vector<std::vector<Piece*> >& board,Piece& rook){
	std::cout<<rook.hasMoved()<<std::endl;

	if(!moved&&!rook.hasMoved()&&board[row][3]==NULL&&board[row][2]==NULL&&board[row][1]==NULL){
		std::cout<<"Why3"<<std::endl;
		if(!inCheck(board,*this)){
			std::cout<<"Why4"<<std::endl;
			board[row][3]=this;
			board[row][4]=NULL;
			col=3;
			if(!inCheck(board,*this)){
				board[row][2]=this;
				board[row][3]=NULL;
				col=2;
				if(!inCheck(board,*this)){
					board[row][4]=this;
					board[row][2]=NULL;
					col=4;
					return true;
				}
			}

		}
		col=4;
		board[row][4]=this;	
		board[row][3]=NULL;
		board[row][2]=NULL;	

	}
	return false;
}
// void King::swap(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	 std::cout<<"Weird";
// 	board[newRow][newCol]=this;
// 	board[row][col]=NULL;
// 	row=newRow;
// 	col=newCol;
// }
// bool King::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board,Piece* king){
// 	for(int i=-1;i<2;i++){
// 		for(int j=-1;j<2;j++){
// 			 std::cout<<"why";
// 			if(i!=0||j!=0){
// 				 std::cout<<"bye";
// 				if(row+i==newRow&&col+j==newCol){
// 					 std::cout<<"hi";
// 					if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 						Piece::swap(newRow,newCol,board,color);
// 						return true;
// 					}
// 				}

// 			}
// 		}
// 	}
	

//   return false;
// }