#include "piece.hpp"

Knight::Knight(int row1,int col1,bool color1){
  row=row1;
  col=col1;
  color=color1;
   moved=false;

}

void Knight::print(){
if(isWhite())
  std::cout<<"N";
else
	 std::cout<<"n";

    //std::cout<<std::endl;
}
std::vector<std::tuple<int,int>> Knight::moves(std::vector<std::vector<Piece*> >& board,Piece& king){
std::vector<std::tuple<int,int>> moves;
	std::vector<std::tuple<int,int>> knightMoves;
	//fix Knight Moves

	knightMoves.push_back(std::make_tuple(row-2, col+1));
	knightMoves.push_back(std::make_tuple(row-2, col-1));
	knightMoves.push_back(std::make_tuple(row-1, col+2));
	knightMoves.push_back(std::make_tuple(row-1, col-2));
	knightMoves.push_back(std::make_tuple(row+1, col+2));
	knightMoves.push_back(std::make_tuple(row+1, col-2));
	knightMoves.push_back(std::make_tuple(row+2, col+1));
	knightMoves.push_back(std::make_tuple(row+2, col-1));
	for(int i=0;i<knightMoves.size();i++){
		int tempRow=std::get<0>(knightMoves[i]);
		int tempCol=std::get<1>(knightMoves[i]);

		if(inBounds(tempRow,tempCol)&&(board[tempRow][tempCol]==NULL||!board[tempRow][tempCol]->isSameColor(color))){
			addMoveIfNotInCheck(tempRow,tempCol,board,king,moves);
		}
	}
return moves;
}
// void Knight::swap(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	 std::cout<<"Weird";
// 	board[newRow][newCol]=this;
// 	board[row][col]=NULL;
// 	row=newRow;
// 	col=newCol;
// }
// bool Knight::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	if(abs(newRow-row)==2&&abs(newCol-col)==1){
// 		if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 			Piece::swap(newRow,newCol,board);
// 			return true;
// 		}
// 	}

// 	if(abs(newRow-row)==1&&abs(newCol-col)==2){
// 		if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 			Piece::swap(newRow,newCol,board);
// 			return true;
// 		}
// 	}
	

//   return false;
// }