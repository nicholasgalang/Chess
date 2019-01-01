#include "piece.hpp"

//#include "board.hpp"
Queen::Queen(int row1,int col1,bool color1){
  row=row1;
  col=col1;
  color=color1;
   moved=false;

}

void Queen::print(){
if(isWhite())
  std::cout<<"Q";
else
	 std::cout<<"q";
}
std::vector<std::tuple<int,int>> Queen::moves(std::vector<std::vector<Piece*> >& board,Piece& king){
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
// void Queen::swap(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	 std::cout<<"Weird";
// 	board[newRow][newCol]=this;
// 	board[row][col]=NULL;
// 	row=newRow;
// 	col=newCol;
// }


 

//bool Queen::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
	//s	// if(newRow==row){
	// 	if(newCol==col){
	// 		std::cout<<row<<std::endl;
	// 		std::cout<<"Invalid move: Can't move to the same position"<<std::endl;
	// 		return false;
	// 	}
	// 	if(newCol>col){
	// 		for(int i=col+1;i<newCol;i++){
	// 			if(board[row][i]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}
	// 		}
	// 		if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
	// 			//board[newRow][newCol]=this;
	// 			//board[row][col]=NULL;
	// 			Piece::swap(newRow,newCol,board);

	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}

	// 	}
	// 	if(newCol<col){
	// 		for(int i=col-1;i>newCol;i--){
	// 			if(board[row][i]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}
	// 		}
	// 		if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
	// 			Piece::swap(newRow,newCol,board);

	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}
	// }
	// //same col
	// if(newCol==col){
	// 	if(newRow>row){
	// 		for(int i=row+1;i<newRow;i++){
	// 			if(board[i][col]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}
	// 		}
	// 			if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
	// 		Piece::swap(newRow,newCol,board);

	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}
	// 	if(newRow<row){
	// 		for(int i=row-1;i>newRow;i--){
	// 			if(board[i][col]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}
	// 		}
	// 					if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
				
	// 		Piece::swap(newRow,newCol,board);

	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}

	// }

	// // /diagonal
	// if(row+col==newRow+newCol){
	// 	if(newRow<row){
	// 		for(int i=1;i<row-newRow;i++){
	// 			if(board[row-i][col+i]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}

	// 		}
	// 				if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
	// 			Piece::swap(newRow,newCol,board);
	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}
	// 	if(newRow>row){
	// 		for(int i=1;i<row-newRow;i++){
	// 			if(board[row+i][col-i]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}

	// 		}
	// 				if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
	// 			Piece::swap(newRow,newCol,board);
	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}
	// }

	// // \diagonal
	// if(newRow-row==newCol-col){
	// 	if(newRow<row){
	// 		for(int i=1;i<row-newRow;i++){
	// 			if(board[row-i][col-i]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}

	// 		}
	// 					if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
	// 			Piece::swap(newRow,newCol,board);
	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}
	// 	if(newRow>row){
	// 		for(int i=1;i<newRow-row;i++){
	// 			if(board[row+i][col+i]!=NULL){
	// 				std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 				return false;
	// 			}

	// 		}
	// 				if(board[newRow][newCol]==NULL||board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
	// 			Piece::swap(newRow,newCol,board);
	// 			return true;
	// 		}
	// 		else{
	// 			std::cout<<"Invalid move: Piece in the way"<<std::endl;
	// 			return false;

	// 		}
	// 	}
	// }

 //  return false;ame row

//