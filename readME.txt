TODO:
//Fix knight moves 
(probably more debugging todo in other places) 
//fix castling add column back if in check
//Add empassant 
//Add checkemate and stalemate
(other draws)
//Turns
(clean up moves now that turns is added or keep it for debugging)
//UI
 (Graphics stretch goal)
Engine
GitHub

How it Works:
Row numbers and ranks are flipped as rank 8 corresponds to row 0 in the board and rank 1 is row 7 in the board. UI is fine just the internal representation is flipped.

Git:
git init
git add .
git commit -m "First commit"
git remote add origin https://github.com/nicholasgalang/WordBrainSolver.git
git remote -v
git push -u origin master
git add .
git commit -m "Second commit"
git push -u origin master