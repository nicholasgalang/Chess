#include "piece.hpp"

Pawn::Pawn(int row1,int col1,bool color1){
  row=row1;
  col=col1;
  color=color1;
  moved=false;

}
// void Pawn::setMoved(){
// 	moved=true;
// }
void Pawn::print(){
if(isWhite())
  std::cout<<"P";
else
	 std::cout<<"p";

    //std::cout<<std::endl;
}

//TODO now
// void Pawn::addMoveIfNotInCheck(int newRow,int newCol,std::vector<std::vector<Piece*> >& board,Piece& king,std::vector<std::tuple<int,int>>& moves){
// 	int oldRow=row;
// 	int oldCol=col;
// 	Piece* temp=board[newRow][newCol];
// 	//moved=true;
	

// 	board[newRow][newCol]=this;
// 	board[row][col]=NULL;
// 	row=newRow;
// 	col=newCol;

// 	if(!inCheck(board,king)){
// 		 std::cout<<"Added Move Row: "<<row<<" Col: "<<col<<std::endl;
// 		moves.push_back(std::make_tuple(row,col));
// 	}

// 	row=oldRow;
// 	col=oldCol;
// 	board[row][col]=this;
// 	board[newRow][newCol]=temp;
// }

std::vector<std::tuple<int,int>> Pawn::moves(std::vector<std::vector<Piece*> >& board,Piece& king){
	//std::cout<<"Got to moves"<<std::endl;
	std::vector<std::tuple<int,int>> moves;
	//move pawn foward one square
	if(isWhite()&&inBounds(row-1,col)&&board[row-1][col]==NULL){
		addMoveIfNotInCheck(row-1,col,board,king,moves);
		// Pawn::swap(row-1,col,board);
		// if(!inCheck(board,king))
		// 	moves.push_back(std::make_tuple(row-1, col));
		// Pawn::swap(row+1,col,board);
		//move pawn foward two squares
		if(!moved&&board[row-2][col]==NULL){
			addMoveIfNotInCheck(row-2,col,board,king,moves);
		// 	Pawn::swap(row-2,col,board);
		// 	if(!inCheck(board,king))
		// 		moves.push_back(std::make_tuple(row-2, col));
		// 	Pawn::swap(row+2,col,board);
		 }


	}

	//capture
	if(isWhite()&&inBounds(row-1,col-1)&&board[row-1][col-1]!=NULL&&!board[row-1][col-1]->isWhite()){
		addMoveIfNotInCheck(row-1,col-1,board,king,moves);
		// Piece* captured=Pawn::swap(row-1,col-1,board);
		// if(!inCheck(board,king))
		// 	moves.push_back(std::make_tuple(row-1, col-1));
		// Pawn::swap(row+1,col+1,board);
		// board[row-1][col-1]=captured;
	}

	if(isWhite()&&inBounds(row-1,col+1)&&board[row-1][col+1]!=NULL&&!board[row-1][col+1]->isWhite()){
		addMoveIfNotInCheck(row-1,col+1,board,king,moves);
		// Piece* captured=Pawn::swap(row-1,col+1,board);
		// if(!inCheck(board,king))
		// 	moves.push_back(std::make_tuple(row-1, col+1));
		// Pawn::swap(row+1,col-1,board);
		// board[row-1][col+1]=captured;
	}
	//empacant
	if(isWhite()&&inBounds(row,col+1)&&board[row][col+1]!=NULL&&!board[row][col+1]->isWhite()&&typeid(*board[row][col+1])==typeid(Pawn)&&dynamic_cast<Pawn*>(board[row][col+1])->isEmPacntalbe()){
		Piece* removedPawn=board[row][col+1];
		board[row][col+1]=NULL;
		addMoveIfNotInCheck(row-1,col+1,board,king,moves);
		board[row][col+1]=removedPawn;

	}
	if(isWhite()&&inBounds(row,col-1)&&board[row][col-1]!=NULL&&!board[row][col-1]->isWhite()&&typeid(*board[row][col-1])==typeid(Pawn)&&dynamic_cast<Pawn*>(board[row][col-1])->isEmPacntalbe()){
		Piece* removedPawn=board[row][col-1];
		board[row][col-1]=NULL;
		addMoveIfNotInCheck(row-1,col-1,board,king,moves);
		board[row][col-1]=removedPawn;

	}


	//move pawn foward one square
	if(!isWhite()&&inBounds(row+1,col)&&board[row+1][col]==NULL){
		addMoveIfNotInCheck(row+1,col,board,king,moves);
		// Pawn::swap(row+1,col,board);
		// if(!inCheck(board,king))
		// 	moves.push_back(std::make_tuple(row+1, col));
		// Pawn::swap(row-1,col,board);

		//move pawn foward two squares
		if(!moved&&board[row+2][col]==NULL){
			addMoveIfNotInCheck(row+2,col,board,king,moves);
			// Pawn::swap(row+2,col,board);
			// if(!inCheck(board,king))
			// 	moves.push_back(std::make_tuple(row+2, col));
			// Pawn::swap(row-2,col,board);
		}


	}

	//capture
	if(!isWhite()&&inBounds(row+1,col-1)&&board[row+1][col-1]!=NULL&&board[row+1][col-1]->isWhite()){
		addMoveIfNotInCheck(row+1,col-1,board,king,moves);
		// Piece* captured=Pawn::swap(row+1,col-1,board);
		// if(!inCheck(board,king))
		// 	moves.push_back(std::make_tuple(row+1, col-1));
		// Pawn::swap(row-1,col+1,board);
		// board[row+1][col-1]=captured;
	}

	if(!isWhite()&&inBounds(row+1,col+1)&&board[row+1][col+1]!=NULL&&board[row+1][col+1]->isWhite()){
		addMoveIfNotInCheck(row+1,col+1,board,king,moves);
		// Piece* captured=Pawn::swap(row+1,col+1,board);
		// if(!inCheck(board,king))
		// 	moves.push_back(std::make_tuple(row+1, col+1));
		// Pawn::swap(row-1,col-1,board);
		// board[row+1][col+1]=captured;
	}


	//empacant
	if(!isWhite()&&inBounds(row,col+1)&&board[row][col+1]!=NULL&&board[row][col+1]->isWhite()&&typeid(*board[row][col+1])==typeid(Pawn)&&dynamic_cast<Pawn*>(board[row][col+1])->isEmPacntalbe()){
		Piece* removedPawn=board[row][col+1];
		board[row][col+1]=NULL;
		addMoveIfNotInCheck(row+1,col+1,board,king,moves);
		board[row][col+1]=removedPawn;

	}
	if(!isWhite()&&inBounds(row,col-1)&&board[row][col-1]!=NULL&&board[row][col-1]->isWhite()&&typeid(*board[row][col-1])==typeid(Pawn)&&dynamic_cast<Pawn*>(board[row][col-1])->isEmPacntalbe()){
		Piece* removedPawn=board[row][col-1];
		board[row][col-1]=NULL;
		addMoveIfNotInCheck(row+1,col-1,board,king,moves);
		board[row][col-1]=removedPawn;

	}
	//std::cout<<"Got past moves"<<std::endl;
	return moves;



}

void Pawn::movedFowardTwo(){
	emPacantable=true;
}
void Pawn::wasntEmPacanted(){
	emPacantable=false;
}

// bool Pawn::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
// 	//move pawn foward two squares
// 	if(!moved&&isWhite()&&newRow+2==row){
// 		if(newCol==col&&board[newRow][newCol]==NULL&&board[newRow-1][newCol]==NULL){
// 			swap(newRow,newCol,board);
// 			return true;
// 		}

// 	}
// 	if(!moved&&!isWhite()&&newRow-2==row){
// 		if(newCol==col&&board[newRow][newCol]==NULL&&board[newRow-1][newCol]==NULL){
// 			swap(newRow,newCol,board);
// 			return true;
// 		}

// 	}

// 	//move pawn foward one
// 	if(isWhite()&&newRow+1==row){
// 		if(newCol==col&&board[newRow][newCol]==NULL){
// 			swap(newRow,newCol,board);
// 			return true;
// 		}

// 		if(abs(newCol-col)==1&&board[newRow][newCol]!=NULL&&board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 			swap(newRow,newCol,board);
// 			return true;
// 		}

// 	}
// 	if(!isWhite()&&newRow-1==row){
// 		if(newCol==col&&board[newRow][newCol]==NULL){
// 			swap(newRow,newCol,board);
// 			return true;
// 		}

// 		if(abs(newCol-col)==1&&board[newRow][newCol]!=NULL&&board[newRow][newCol]->isWhite()!=board[row][col]->isWhite()){
// 			swap(newRow,newCol,board);
// 			return true;
// 		}

// 	}
	

//   return false;
// }