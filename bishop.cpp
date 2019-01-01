#include "piece.hpp"

Bishop::Bishop(int row1,int col1,bool color1){
  row=row1;
  col=col1;
  color=color1;
   moved=false;

}

void Bishop::print(){
if(isWhite())
  std::cout<<"B";
else
	 std::cout<<"b";

    //std::cout<<std::endl;
}

// void Bishop::swap(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	 std::cout<<"Weird";
// 	board[newRow][newCol]=this;
// 	board[row][col]=NULL;
// 	row=newRow;
// 	col=newCol;
// }
std::vector<std::tuple<int,int>> Bishop::moves(std::vector<std::vector<Piece*> >& board,Piece& king){
std::vector<std::tuple<int,int>> moves;
//diagonals 
	for(int i=1;i<8;i++){
		if(!inBounds(row+i,col+i))
			break;
		if(board[row+i][col+i]!=NULL){
			if(!board[row+i][col+i]->isSameColor(color)){
				addMoveIfNotInCheck(row+i,col+i,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(row+i,col+i,board,king,moves);
	}
	for(int i=1;i<8;i++){
		if(!inBounds(row+i,col-i))
			break;
		if(board[row+i][col-i]!=NULL){
			if(!board[row+i][col-i]->isSameColor(color)){
				addMoveIfNotInCheck(row+i,col-i,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(row+i,col-i,board,king,moves);
	
	}
	for(int i=1;i<8;i++){
		if(!inBounds(row-i,col+i))
			break;
		if(board[row-i][col+i]!=NULL){
			if(!board[row-i][col+i]->isSameColor(color)){
				addMoveIfNotInCheck(row-i,col+i,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(row-i,col+i,board,king,moves);
	
	}
	for(int i=1;i<8;i++){
		if(!inBounds(row-i,col-i))
			break;
		if(board[row-i][col-i]!=NULL){
			if(!board[row-i][col-i]->isSameColor(color)){
				addMoveIfNotInCheck(row-i,col-i,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(row-i,col-i,board,king,moves);
	}
return moves;
}
// bool Bishop::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	// /diagonal
// 	if(row+col==newRow+newCol){
// 		if(newRow<row){
// 			for(int i=1;i<row-newRow;i++){
// 				if(board[row-i][col+i]!=NULL){
// 					return false;
// 				}

// 			}
// 					if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 				Piece::swap(newRow,newCol,board);
// 				return true;
// 			}
// 		}
// 		if(newRow>row){
// 			for(int i=1;i<row-newRow;i++){
// 				if(board[row+i][col-i]!=NULL){
// 					return false;
// 				}

// 			}
// 					if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 				Piece::swap(newRow,newCol,board);
// 				return true;
// 			}
// 		}
// 	}

// 	// \diagonal
// 	if(newRow-row==newCol-col){
// 		if(newRow<row){
// 			for(int i=1;i<row-newRow;i++){
// 				if(board[row-i][col-i]!=NULL){
// 					return false;
// 				}

// 			}
// 						if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 				Piece::swap(newRow,newCol,board);
// 				return true;
// 			}
// 		}
// 		if(newRow>row){
// 			for(int i=1;i<newRow-row;i++){
// 				if(board[row+i][col+i]!=NULL){
// 					return false;
// 				}

// 			}
// 					if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 				Piece::swap(newRow,newCol,board);
// 				return true;
// 			}
// 		}
// 	}

//   return false;
// }