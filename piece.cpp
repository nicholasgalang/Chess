
#include "piece.hpp"
bool Piece::inCheck(std::vector<std::vector<Piece*> >& board,Piece &king){
	int krow=king.getRow();
	int kcol=king.getCol();
	std::vector<std::tuple<int,int>> knightMoves;

	knightMoves.push_back(std::make_tuple(krow-2, kcol+1));
	knightMoves.push_back(std::make_tuple(krow-2, kcol-1));
	knightMoves.push_back(std::make_tuple(krow-1, kcol+2));
	knightMoves.push_back(std::make_tuple(krow-1, kcol-2));
	knightMoves.push_back(std::make_tuple(krow+1, kcol+2));
	knightMoves.push_back(std::make_tuple(krow+1, kcol-2));
	knightMoves.push_back(std::make_tuple(krow+2, kcol+1));
	knightMoves.push_back(std::make_tuple(krow+2, kcol-1));

	for(int i=0;i<knightMoves.size();i++){
		int tempRow=std::get<0>(knightMoves[i]);
		int tempCol=std::get<1>(knightMoves[i]);
		
		if(inBounds(tempRow,tempCol)&&board[tempRow][tempCol]!=NULL&&typeid(*board[tempRow][tempCol])==typeid(Knight)&&board[tempRow][tempCol]->isWhite()!=color){
			
			return true;
		}
		
	}

	//same col
	for(int i=krow+1;i<8;i++){
		if(board[i][kcol]!=NULL){
			if(board[i][kcol]->isWhite()!=color){
				if(typeid(*board[i][kcol])==typeid(Queen)||typeid(*board[i][kcol])==typeid(Rook))
					return true;
			}
			break;
		}
	}
	for(int i=krow-1;i>-1;i--){
		if(board[i][kcol]!=NULL){
			if(board[i][kcol]->isWhite()!=color){
				if(typeid(*board[i][kcol])==typeid(Queen)||typeid(*board[i][kcol])==typeid(Rook))
					return true;
			}
			break;
		}
	}

	//same row
	for(int i=kcol+1;i<8;i++){
		if(board[krow][i]!=NULL){
			if(board[krow][i]->isWhite()!=color){
				if(typeid(*board[krow][i])==typeid(Queen)||typeid(*board[krow][i])==typeid(Rook))
					return true;
			}
			break;
		}
	}
	for(int i=kcol-1;i>-1;i--){
		if(board[krow][i]!=NULL){
			if(board[krow][i]->isWhite()!=color){
				if(typeid(*board[krow][i])==typeid(Queen)||typeid(*board[krow][i])==typeid(Rook))
					return true;
			}
			break;
		}
	}

	//diagonals 
	for(int i=1;i<8;i++){
		if(!inBounds(krow+i,kcol+i))
			break;
		if(board[krow+i][kcol+i]!=NULL){
			if(board[krow+i][kcol+i]->isWhite()!=color){
				if(typeid(*board[krow+i][kcol+i])==typeid(Queen)||typeid(*board[krow+i][kcol+i])==typeid(Bishop))
					return true;
			}
			break;
		}
	
	}
	for(int i=1;i<8;i++){
		if(!inBounds(krow+i,kcol-i))
			break;
		if(board[krow+i][kcol-i]!=NULL){
			if(board[krow+i][kcol-i]->isWhite()!=color){
				if(typeid(*board[krow+i][kcol-i])==typeid(Queen)||typeid(*board[krow+i][kcol-i])==typeid(Bishop))
					return true;
			}
			break;
		}
	
	}
	for(int i=1;i<8;i++){
		if(!inBounds(krow-i,kcol+i))
			break;
		if(board[krow-i][kcol+i]!=NULL){
			if(board[krow-i][kcol+i]->isWhite()!=color){
				if(typeid(*board[krow-i][kcol+i])==typeid(Queen)||typeid(*board[krow-i][kcol+i])==typeid(Bishop))
					return true;
			}
			break;
		}
	
	}
	for(int i=1;i<8;i++){
		if(!inBounds(krow-i,kcol-i))
			break;
		if(board[krow-i][kcol-i]!=NULL){
			if(board[krow-i][kcol-i]->isWhite()!=color){
				if(typeid(*board[krow-i][kcol-i])==typeid(Queen)||typeid(*board[krow-i][kcol-i])==typeid(Bishop))
					return true;
			}
			break;
		}

	}

	//pawn
	if(isWhite()){
	std::vector<std::tuple<int,int>> pawnMoves;

	pawnMoves.push_back(std::make_tuple(krow-1, kcol+1));
	pawnMoves.push_back(std::make_tuple(krow-1, kcol-1));
	for(int i=0;i<pawnMoves.size();i++){
		int pawnRow=std::get<0>(pawnMoves[i]);
		int pawnCol=std::get<1>(pawnMoves[i]);

		if(inBounds(pawnRow,pawnCol)&&board[pawnRow][pawnCol]!=NULL&&typeid(*board[pawnRow][pawnCol])==typeid(Pawn)&&board[pawnRow][pawnCol]->isWhite()!=color){
			return true;
		}
	}

	}
	if(!isWhite()){
	std::vector<std::tuple<int,int>> pawnMoves;

	pawnMoves.push_back(std::make_tuple(krow+1, kcol+1));
	pawnMoves.push_back(std::make_tuple(krow+1, kcol-1));
	for(int i=0;i<pawnMoves.size();i++){
		int pawnRow=std::get<0>(pawnMoves[i]);
		int pawnCol=std::get<1>(pawnMoves[i]);

		if(inBounds(pawnRow,pawnCol)&&board[pawnRow][pawnCol]!=NULL&&typeid(*board[pawnRow][pawnCol])==typeid(Pawn)&&board[pawnRow][pawnCol]->isWhite()!=color){
			return true;
		}
	}

	}

	//king
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			bool center=(i==0&&j==0);
			if(!center){
				int enemyKingRow=krow+i;
				int enemyKingCol=kcol+j;
				if(inBounds(enemyKingRow,enemyKingCol)&&board[enemyKingRow][enemyKingCol]!=NULL&&typeid(*board[enemyKingRow][enemyKingCol])==typeid(King))
					return true;
			}
		}
	}
	return false;


	 
}
void Piece::addMoveIfNotInCheck(int newRow,int newCol,std::vector<std::vector<Piece*> >& board,Piece& king,std::vector<std::tuple<int,int>>& moves){
	int oldRow=row;
	int oldCol=col;

	Piece* temp=board[newRow][newCol];


	board[newRow][newCol]=this;
	board[row][col]=NULL;
	row=newRow;
	col=newCol;
	
	if(!inCheck(board,king)){
		std::cout<<"Added Move Row: "<<row<<" Col: "<<col<<std::endl;
		moves.push_back(std::make_tuple(row,col));
	}

	row=oldRow;
	col=oldCol;
	board[row][col]=this;
	board[newRow][newCol]=temp;
}


bool Piece::inBounds(int row, int col){
	if(row<0||row>7||col<0||col>7)
		return false;
	return true;
}

Piece* Piece::move(int newRow,int newCol,std::vector<std::vector<Piece*> >& board){
	moved=true;
	Piece* temp=board[newRow][newCol];
		board[newRow][newCol]=board[row][col];
		board[row][col]=NULL;
		row=newRow;
		col=newCol;
		return temp;
}
