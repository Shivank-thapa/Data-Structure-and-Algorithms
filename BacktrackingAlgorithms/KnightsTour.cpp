//Knight's tour problem using backtracking

#include <iostream>
using namespace std;

#define N 8

void displaySolution(int board[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << board[i][j] << "  ";
		}
       cout << '\n';
	}
}

bool isSafeMove(int x, int y, int board[N][N]) {
    if(x >=0 && x < N && y >=0 && y < N && board[x][y] == -1)
        return true;
    return false;
}

bool knightTourUtil(int x, int y, int moveIndex, int board[N][N], int xMove[N], int yMove[N]) {
    if(moveIndex == N*N)
        return true;
    
    for(int k=0; k<8; k++) {
        int nextX = x+xMove[k];
        int nextY = y+yMove[k];
        
        if(isSafeMove(nextX, nextY, board)) {
            board[nextX][nextY] = moveIndex;
            if(knightTourUtil(nextX, nextY, moveIndex+1, board, xMove, yMove))
                return true;
            else
                board[nextX][nextY] = -1;
        }
    }
    return false;
}

bool solution() {
    int board[N][N];
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            board[i][j] = -1;
            
    int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int yMove[8] = {1, 2,  2,  1, -1, -2, -2, -1};
    
    board[0][0] = 0;
    
    if(!knightTourUtil(0, 0, 1, board, xMove, yMove)) {
        cout << "Solution does not exist\n";
        return false;
    }
    else {
        displaySolution(board);
    }
    return true;
}

int main() {
	solution();
	return 0;
}
