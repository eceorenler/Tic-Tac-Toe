#include <iostream>
using namespace std;

void printBoard(char board[3][3]){
    cout<<"---------------"<<endl;
    
    for(int i=0; i<3; i++){
        cout<<" "<<"|";
        for (int j=0; j<3; j++){
            cout<<" "<< board[i][j]<<" |";
        }
    cout<<"\n---------------"<<endl;
    }
}

void initializeBoard(char board[3][3]){
    char value= '1';
    
    for (int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=value++;
        }
    }
}

bool placeMarker (char board [3][3], int position, char marker){
    int row = (position -1)/3;
    int col = (position-1) %3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = marker;
        
        return true;
    } else {
        cout<< "position is already taken. try again."<<endl;
        
        return false;
    }
}

bool check(char board[3][3]){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
            return true;
        }
    }
    
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]){
            return true;
        }
    }
        
  if(board[0][0]==board[1][1]&&board[1][1]==board[1][2]){
    return true;
    }
  if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
    return true;
    }
    
    
    return false;
}
void playGame(){
    char board[3][3];
    initializeBoard(board);
    
    char currentMarker='X';
    int currentPlayer=1;
    int position;
    
    for(int i=0;i<9;i++){
        printBoard(board);
        cout<<"player "<<currentPlayer<<"'s turn (enter a position 1-9) :  ";
        cin>>position;
    
        while(position<1 || position>9|| !placeMarker(board, position,currentMarker)){
        cout<<"invalid move. try again: ";
        cin>> position;
        }
        
        if(check(board)){
        printBoard(board);
        cout<<"player"<<currentPlayer<<" wins!"<<endl;
            
        return;
        }
    
        if (currentMarker=='X'){
            currentMarker= 'O';
            currentPlayer=2;
        }else if (currentMarker=='O'){
            currentMarker='X';
            currentPlayer=1;
    }
        
        
}
    
    printBoard(board);
    cout<<"it's a draw!"<<endl;
    
}

bool replay(){
    char choice;
    cout<<"do you want to play again? (y/n):  ";
    cin>>choice;
    
    return(choice=='y'|| choice =='Y');
}

int main(){
  do { playGame();
} while (replay());

cout<< "thanks for playing"<<endl;
   return 0;
}