#include<iostream>
#include<algorithm>
using namespace std;
void board(char board1[3][3]){
    cout<<"-----------------"<<endl;
    for(int i=0; i<3; i++){
        cout<<" | ";
        for(int j=0; j<3; j++){
            cout<<board1[i][j]<<" | ";
        }
        cout<<endl<<"-----------------"<<endl;
    }
}
int winlosedraw(char board1[3][3]){
    for(int i=0; i<3; i++){
        if(board1[i][0]=='O' && board1[i][1]=='O' && board1[i][2]=='O' || 
        board1[0][i]=='O' && board1[1][i]=='O' && board1[2][i]=='O' || 
        board1[0][0]=='O' && board1[1][1]=='O' && board1[2][2]=='O' ||
        board1[2][0]=='O' && board1[1][1]=='O' && board1[0][2]=='O'){
            return 1;
        }
        else if(board1[i][0]=='X' && board1[i][1]=='X' && board1[i][2]=='X' || 
        board1[0][i]=='X' && board1[1][i]=='X' && board1[2][i]=='X' || 
        board1[0][0]=='X' && board1[1][1]=='X' && board1[2][2]=='X' ||
        board1[2][0]=='X' && board1[1][1]=='X' && board1[0][2]=='X'){
            return 2;
        }
    }
    int flag=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board1[i][j]==' '){
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag!=0){
        return 3;
    }
    return 0;
}
void playgame(char board1[3][3]){
    int i=0;
    char player1;
    char player2;
    cout<<"Player 1 enter your choice ( O or X ):"<<endl;
    cin>>player1;
    if(player1=='O'){
        player2='X';
        cout<<"Player 2 you are: "<<player2<<endl;
    }
    else{
        player2='O';
        cout<<"Player 2 you are: "<<player2<<endl; 
    }
    cout<<"Current state of the board "<<endl;
    board(board1);
    while(i<9){
        int j;
        int k;
        cout<<"Player 1 enter the row : ";
        cin>>j;
        cout<<"Player 1 enter the coloumn : ";
        cin>>k;
        board1[j][k]=player1;
        int decider=winlosedraw(board1);
        cout<<"Current state of the board "<<endl;
        board(board1);
        if(decider==1 && player1=='O'){
            cout<<"Player 1 (with O) won the game "<<endl;
            break;
        }
        else if(decider==1 && player2=='O'){
            cout<<"Player 2 (with O) won the game "<<endl;
            break;
        }
        else if(decider==2 && player1=='X'){
            cout<<"Player 1 (with X) won the game "<<endl;
            break;
        }
        else if(decider==2 && player2=='X'){
            cout<<"Player 2 (with X) won the game "<<endl;
            break;
        }
        else if(decider==0){
            cout<<"Game drawn"<<endl;
            break;
        }
        cout<<"Player 2 enter the row : ";
        cin>>j;
        cout<<"Player 2 enter the coloumn : ";
        cin>>k;
        board1[j][k]=player2;
        decider=winlosedraw(board1);
        cout<<"Current state of the board "<<endl;
        board(board1);
        if(decider==1 && player1=='O'){
            cout<<"Player 1 (with O) won the game "<<endl;
            break;
        }
        else if(decider==1 && player2=='O'){
            cout<<"Player 2 (with O) won the game "<<endl;
            break;
        }
        else if(decider==2 && player1=='X'){
            cout<<"Player 1 (with X) won the game "<<endl;
            break;
        }
        else if(decider==2 && player2=='X'){
            cout<<"Player 2 (with X) won the game "<<endl;
            break;
        }
        else if(decider==0){
            cout<<"Game drawn"<<endl;
            break;
        }
        i++;
    }
}
int main(){
    int opinion=1;
    do{
        char b[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
        playgame(b);
        cout<<"Do you want to play another game (yes - 1/no - 0)? "<<endl;
        cin>>opinion;
    }while(opinion!=0);
}
