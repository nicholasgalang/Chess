#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <tuple>
#include "piece.hpp"

using namespace std;

class Board {
private:
	std::vector<Piece*> whitePieces,blackPieces;
  std::vector<std::vector<Piece*> > board;
  Piece *whiteKing;
  Piece* blackKing;
  Piece* whiteKingRook;
  Piece* whiteQueenRook;
  Piece* blackKingRook;
  Piece* blackQueenRook;

  void kingSideCastle(int row);
  void queenSideCastle(int row);
  bool removePiece(Piece* toRemove);
  Piece* queenMe(int row,int col,bool isWhite);


public:
   Board();
   void print();
   bool move(int oldRow,int oldCol,int newRow,int newCol,bool turn);

   bool validMove(Piece* piece,int newRow,int newCol);
   bool inCheck(bool white);
   bool noLegalMoves(std::vector<Piece*> pieces,Piece* king);
   bool checkmate(bool white);
   bool stalemate(bool white);

  
    
};