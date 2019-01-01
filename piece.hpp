#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <tuple>
#include <typeinfo>
#include <tuple>
//#include "board.hpp"


using namespace std;
class Board;
class Piece {
protected:
	int row,col;
  bool color,moved;
  bool inBounds(int row, int col);

  void addMoveIfNotInCheck(int newRow,int newCol,std::vector<std::vector<Piece*> >& board,Piece& king,std::vector<std::tuple<int,int>>& moves);
  



public:
    //virtual bool move(int row,int col,std::vector<std::vector<Piece*> >& board)=0;
    virtual std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king)=0;
    virtual void print()=0;
    bool isWhite(){return color;}
    bool isSameColor(bool other){return other==color;}
    bool inCheck(std::vector<std::vector<Piece*> >& board,Piece &king);
    Piece* move(int row,int col,std::vector<std::vector<Piece*> >& board);
    int getRow(){return row;}
    int getCol(){return col;}
    bool hasMoved(){return moved;}
    void setRow(int newRow){row=newRow;}
    void setCol(int newCol){col=newCol;}


 

  
    
    
    
    
    
};

class Queen: public Piece
{ 
  
public: 
    Queen(int row1,int col1,bool color);
    std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king);
    void print();
//private:
 //   void swap(int row,int col,std::vector<std::vector<Piece*> >& board);
}; 

class Rook: public Piece
{
public: 
    Rook(int row1,int col1,bool color);
    std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king);
    void print();
//private:
 //   void swap(int row,int col,std::vector<std::vector<Piece*> >& board);

};
class Bishop: public Piece
{
public: 
    Bishop(int row1,int col1,bool color);
    std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king);
    void print();
//private:
//    void swap(int row,int col,std::vector<std::vector<Piece*> >& board);

};
class Knight: public Piece
{
public: 
    Knight(int row1,int col1,bool color);
    std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king);
    void print();
//private:
 //   void swap(int row,int col,std::vector<std::vector<Piece*> >& board);

};
class King: public Piece
{
public: 
    King(int row1,int col1,bool color);
  std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king);
    void print();
    bool canCastleKingSide(std::vector<std::vector<Piece*> >& board,Piece& rook);
    bool canCastleQueenSide(std::vector<std::vector<Piece*> >& board,Piece& rook);
//private:
 //   void swap(int row,int col,std::vector<std::vector<Piece*> >& board);

};
class Pawn: public Piece
{
public: 
    Pawn(int row1,int col1,bool color);
   std::vector<std::tuple<int,int>> moves(std::vector<std::vector<Piece*> >& board,Piece& king);
    void print();
    void movedFowardTwo();
    void wasntEmPacanted();
    bool isEmPacntalbe(){return emPacantable;}
    //void setMoved();
private:
  bool emPacantable;
    //bool moved;
    //void addMoveIfNotInCheck(int newRow,int newCol,std::vector<std::vector<Piece*> >& board,Piece& king,std::vector<std::tuple<int,int>>& moves);

};


