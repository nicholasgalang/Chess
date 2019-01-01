#include "piece.hpp"

Rook::Rook(int row1,int col1,bool color1){
  row=row1;
  col=col1;
  color=color1;
   moved=false;

}

void Rook::print(){
if(isWhite())
  std::cout<<"R";
else
	 std::cout<<"r";

 
}
std::vector<std::tuple<int,int>> Rook::moves(std::vector<std::vector<Piece*> >& board,Piece& king){
std::vector<std::tuple<int,int>> moves;
//same col
	for(int i=row+1;i<8;i++){
		if(board[i][col]!=NULL){
			if(!board[i][col]->isSameColor(color)){
				addMoveIfNotInCheck(i,col,board,king,moves);			
			}
			break;
		}
		addMoveIfNotInCheck(i,col,board,king,moves);
	}
	for(int i=row-1;i>-1;i--){
		if(board[i][col]!=NULL){
			if(!board[i][col]->isSameColor(color)){
				addMoveIfNotInCheck(i,col,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(i,col,board,king,moves);
	}

	//same row
	for(int i=col+1;i<8;i++){
		if(board[row][i]!=NULL){
			if(!board[row][i]->isSameColor(color)){
				addMoveIfNotInCheck(row,i,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(row,i,board,king,moves);
	}
	for(int i=col-1;i>-1;i--){
		if(board[row][i]!=NULL){
			if(!board[row][i]->isSameColor(color)){
				addMoveIfNotInCheck(row,i,board,king,moves);
			}
			break;
		}
		addMoveIfNotInCheck(row,i,board,king,moves);
	}
return moves;
}
// void Rook::swap(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	 std::cout<<"Weird";
// 	board[newRow][newCol]=this;
// 	board[row][col]=NULL;
// 	row=newRow;
// 	col=newCol;
// }

// bool Rook::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	//same row
// 	if(newRow==row){
// 		if(newCol==col){
// 			return false;
// 		}
// 		if(newCol>col){
// 			for(int i=col+1;i<newCol;i++){
// 				if(board[row][i]!=NULL){
// 					return false;
// 				}
// 			}
// 			if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
// 				//board[newRow][newCol]=this;
// 				//board[row][col]=NULL;
// 				Piece::swap(newRow,newCol,board);

// 				return true;
// 			}

// 		}
// 		if(newCol<col){
// 			for(int i=col-1;i>newCol;i--){
// 				if(board[row][i]!=NULL){
// 					return false;
// 				}
// 			}
// 			if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
// 				Piece::swap(newRow,newCol,board);

// 				return true;
// 			}
// 		}
// 	}
// 	//same col
// 	if(newCol==col){
// 		if(newRow>row){
// 			for(int i=row+1;i<newRow;i++){
// 				if(board[i][col]!=NULL){
// 					return false;
// 				}
// 			}
// 				if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
// 			Piece::swap(newRow,newCol,board);

// 				return true;
// 			}
// 		}
// 		if(newRow<row){
// 			for(int i=row-1;i>newRow;i--){
// 				if(board[i][col]!=NULL){
// 					return false;
// 				}
// 			}
// 			if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
// 			Piece::swap(newRow,newCol,board);

// 				return true;
// 			}
// 		}

// 	}
// 	return false;
// }