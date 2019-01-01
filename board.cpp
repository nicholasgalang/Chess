#include "board.hpp"
Board::Board(){
	//whitePieces.push_back(new Rook(7,0,true));
	whiteQueenRook=new Rook(7,0,true);
	whitePieces.push_back(whiteQueenRook);
	whitePieces.push_back(new Knight(7,1,true));
	whitePieces.push_back(new Bishop(7,2,true));
	whitePieces.push_back(new Queen(7,3,true));
	whiteKing=new King(7,4,true);
	whitePieces.push_back(whiteKing);

	whitePieces.push_back(new Bishop(7,5,true));
	whitePieces.push_back(new Knight(7,6,true));
	//whitePieces.push_back(new Rook(7,7,true));
	whiteKingRook=new Rook(7,7,true);
	whitePieces.push_back(whiteKingRook);

	for(int i=0;i<8;i++){
		whitePieces.push_back(new Pawn(6,i,true));
	}

	//blackPieces.push_back(new Rook(0,0,false));
	blackKingRook=new Rook(0,0,false);
	blackPieces.push_back(blackKingRook);
	blackPieces.push_back(new Knight(0,1,false));
	blackPieces.push_back(new Bishop(0,2,false));
	blackPieces.push_back(new Queen(0,3,false));
	
	blackKing= new King(0,4,false);
	blackPieces.push_back(blackKing);
	//blackPieces.push_back(new King(0,4,false));
	blackPieces.push_back(new Bishop(0,5,false));
	blackPieces.push_back(new Knight(0,6,false));
	//blackPieces.push_back(new Rook(0,7,false));
	blackQueenRook=new Rook(0,7,false);
	blackPieces.push_back(blackQueenRook);

	for(int i=0;i<8;i++){
		blackPieces.push_back(new Pawn(1,i,false));
	}
	for(int i=0;i<8;i++){
		vector<Piece*> row;// = new vector<Piece*>;
		for(int j=0;j<8;j++){
			if(i==0){
				row.push_back(blackPieces[j]);
			}
			else if(i==1){
				row.push_back(blackPieces[i*8+j]);
			}
			else if(i==6){
				row.push_back(whitePieces[(i-5)*8+j]);
			}
			else if(i==7){
				row.push_back(whitePieces[j]);
			}
			else{
				row.push_back(NULL);
			}
		}
		board.push_back(row);
	}
}

void Board::print(){
for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
			if(board[i][j]==NULL){
				std::cout<<". ";
			}
			else{
				board[i][j]->print();
				std::cout<<" ";
			}
	}
		std::cout<<8-i;
		std::cout<<std::endl;
		std::cout<<std::endl;
}
for(int i=0;i<8;i++){
	char file=(97+i);
	std::cout<<file<<" ";

}
		std::cout<<std::endl;
}

bool Board::inCheck(bool white){
	if(white&&whitePieces[0]->inCheck(board,*whiteKing))
		return true;
	if(!white&&blackPieces[0]->inCheck(board,*blackKing))
		return true;
	return false;
}

bool Board::noLegalMoves(std::vector<Piece*> pieces,Piece* king){
	for(Piece* piece:pieces){
			if(!piece->moves(board,*king).empty())
				return false;
	}
	return true;
}

bool Board::checkmate(bool white){
	if(inCheck(white)){
		if(white)
			return noLegalMoves(whitePieces,whiteKing);
		else
			return noLegalMoves(blackPieces,blackKing);

	}
	return false;
}
bool Board::stalemate(bool white){
	if(!inCheck(white)){
		if(white)
			return noLegalMoves(whitePieces,whiteKing);
		else
			return noLegalMoves(blackPieces,blackKing);
	}
	return false;
}
bool Board::validMove(Piece* piece,int row,int col){
	//std::cout<<"Got to valid move"<<std::endl;
	Piece* king;
	if(piece->isWhite())
		king=whiteKing;
	else
		king=blackKing;

	
	std::vector<std::tuple<int,int>> moves=piece->moves(board,*king);
	std::cout<<moves.size()<<std::endl;

	std::tuple<int,int> newMove=std::make_tuple(row,col);

	for(std::tuple<int,int> move:moves){
		if(move==newMove)
			return true;
	}
	return false;
}

void Board::kingSideCastle(int row){
	std::cout<<"canCastleKingSide"<<std::endl;
	board[row][6]=board[row][4];
	board[row][5]=board[row][7];
	//heres the prbolem same column
	board[row][6]->setCol(6);
	board[row][5]->setCol(5);
	board[row][5]->hasMoved();
	board[row][6]->hasMoved();
	board[row][4]=NULL;
	board[row][7]=NULL;

}
void Board::queenSideCastle(int row){
	std::cout<<"canCastleQueenSide"<<std::endl;
	board[row][2]=board[row][4];
	board[row][3]=board[row][0];
	//heres the prbolem same column
	board[row][2]->setCol(2);
	board[row][3]->setCol(3);
	board[row][2]->hasMoved();
	board[row][3]->hasMoved();
	board[row][4]=NULL;
	board[row][0]=NULL;

}
bool Board::removePiece(Piece* toRemove){
	if(toRemove!=NULL){
		if(toRemove->isWhite()){
			for(int i=0;i<whitePieces.size();i++){
				if(whitePieces[i]==toRemove){
					whitePieces.erase(whitePieces.begin()+i);
					return true;
				}
			}
		}
		else{
			for(int i=0;i<blackPieces.size();i++){
				if(blackPieces[i]==toRemove){
					blackPieces.erase(blackPieces.begin()+i);
					return true;
				}
			}

		}
	}
	return false;

}
Piece* Board::queenMe(int row,int col,bool isWhite){
	removePiece(board[row][col]);
	board[row][col]=NULL;
	while(true){
		char newPiece;
		cout << "What piece fo you want? (N, Q, B or R) ";
		cin >> newPiece;
		if(newPiece=='N'||newPiece=='n'){
			return new Knight(row,col,isWhite);
		}
		else if(newPiece=='Q'||newPiece=='q'){
			return new Queen(row,col,isWhite);
		}
		else if(newPiece=='B'||newPiece=='b'){
			return new Bishop(row,col,isWhite);
		}
		else if(newPiece=='R'||newPiece=='r'){
			return new Rook(row,col,isWhite);
		}
		else{
			cout << "Put in a valid piece";
		}
			
	}


}
bool Board::move(int oldRow,int oldCol,int newRow,int newCol,bool turn){

	if(oldRow<0||oldRow>7||newRow<0||newRow>7){
		std::cout<<"Out of bounds position"<<std::endl;
		return false;
	}
	if(oldCol<0||oldCol>7||newCol<0||newCol>7){
		std::cout<<"Out of bounds position"<<std::endl;
		return false;
	}

	if(board[oldRow][oldCol]==NULL){
		std::cout<<"No piece at origin"<<std::endl;
		return false;
	}
	if(board[oldRow][oldCol]->isWhite()!=turn){
		if(turn){
			std::cout<<"Not blacks turn"<<std::endl;
		}
		else{
			std::cout<<"Not whites turn"<<std::endl;
		}
		return false;
	}
	bool toPrint=dynamic_cast<King*>(whiteKing)->canCastleKingSide(board,*whiteKingRook);
	std::cout<<"White can castle king side: "<<toPrint<<std::endl;

	if(typeid(*board[oldRow][oldCol])==typeid(King)&&abs(newCol-oldCol)>1){
		bool rightRows=(oldRow==7&&newRow==7)||(oldRow==0&&newRow==0);
		if(rightRows&&oldCol==4&&newCol==6){
			//bool canCastleKingSide=false;
			if(oldRow==0&&dynamic_cast<King*>(board[oldRow][oldCol])->canCastleKingSide(board,*blackKingRook)){
				for(Piece* piece:whitePieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
		for(Piece* piece:blackPieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
				kingSideCastle(0);
				return true;
			}
			else if(oldRow==7&&dynamic_cast<King*>(board[oldRow][oldCol])->canCastleKingSide(board,*whiteKingRook)){
				for(Piece* piece:whitePieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
		for(Piece* piece:blackPieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
				kingSideCastle(7);
				return true;
			}
	
			// if(){
			// 	std::cout<<"canCastleKingSide"<<std::endl;
			// 		board[newRow][newCol]=board[oldRow][oldCol];
			// 		board[newRow][newCol-1]=board[7][7];
			// 		//heres the prbolem same column
			// 		board[newRow][newCol]->setCol(newCol);
			// 		board[newRow][newCol-1]->setCol(newCol-1);
			// 		board[newRow][newCol-1]->hasMoved();
			// 		board[newRow][newCol]->hasMoved();
			// 		board[oldRow][oldCol]=NULL;
			// 		board[oldRow][7]=NULL;



			// 		return true;

			//}
		}
		else if(rightRows&&oldCol==4&&newCol==2){
				if(oldRow==0&&dynamic_cast<King*>(board[oldRow][oldCol])->canCastleQueenSide(board,*blackQueenRook)){
					for(Piece* piece:whitePieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
		for(Piece* piece:blackPieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
				queenSideCastle(0);
				return true;
			}
			else if(oldRow==7&&dynamic_cast<King*>(board[oldRow][oldCol])->canCastleQueenSide(board,*whiteQueenRook)){
				for(Piece* piece:whitePieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
		for(Piece* piece:blackPieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
				queenSideCastle(7);
				return true;
			}

		}

	}


	if(validMove(board[oldRow][oldCol],newRow,newCol)){
		// if(typeid(*board[oldRow][oldCol])==typeid(Pawn)){
		// 	std::cout<<"Moved"<<std::endl;
		// 	dynamic_cast<Pawn*>(board[oldRow][oldCol])->setMoved();

		// }
		
		for(Piece* piece:whitePieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
		for(Piece* piece:blackPieces){
			if(typeid(*piece)==typeid(Pawn))
				dynamic_cast<Pawn*>(piece)->wasntEmPacanted();
		}
		
		

		//em pansatt move
		if(typeid(*board[oldRow][oldCol])==typeid(Pawn)&&newCol!=oldCol&&board[newRow][newCol]==NULL){
			board[oldRow][oldCol]->move(newRow,newCol,board);
			removePiece(board[oldRow][newCol]);
			board[oldRow][newCol]=NULL;
			return true;
		}

		Piece* toRemove=board[oldRow][oldCol]->move(newRow,newCol,board);

		//becomes empacantable
		if(typeid(*board[newRow][newCol])==typeid(Pawn)&&abs(newRow-oldRow)==2){
			dynamic_cast<Pawn*>(board[newRow][newCol])->movedFowardTwo();

		}
		// if(toRemove!=NULL){
		// 	if(toRemove->isWhite()){
		// 		for(int i=0;i<whitePieces.size();i++){
		// 			if(whitePieces[i]==toRemove){
		// 				whitePieces.erase(whitePieces.begin()+i);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 	else{
		// 		for(int i=0;i<blackPieces.size();i++){
		// 			if(blackPieces[i]==toRemove){
		// 				blackPieces.erase(blackPieces.begin()+i);
		// 				break;
		// 			}
		// 		}

		// 	}
		// }
		removePiece(toRemove);

		//queen me
		if(newRow==7&&typeid(*board[newRow][newCol])==typeid(Pawn)){
			Piece* newPiece=queenMe(newRow,newCol,board[newRow][newCol]->isWhite());
		
			blackPieces.push_back(newPiece);
			board[newRow][newCol]=newPiece;
			
		}
		else if(newRow==0&&typeid(*board[newRow][newCol])==typeid(Pawn)){
			Piece* newPiece=queenMe(newRow,newCol,board[newRow][newCol]->isWhite());
		
			whitePieces.push_back(newPiece);
			board[newRow][newCol]=newPiece;
		}


		return true;
	}

	return false;


	//return board[oldRow][oldCol]->move(newRow,newCol,board);
}