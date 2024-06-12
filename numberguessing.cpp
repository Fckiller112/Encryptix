#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main(){
    int n=100;
    srand(0);
    int ori=(rand() % n);
    int guess;
    cout<<"A random number is being generated from 1 to 100 enter your guess"<<endl;
    cin>>guess;
    int i=0;
    while(guess!=ori){
        if(i>=3){
            break;
        }
        if(guess<ori){
            cout<<"Your guessed number is less than the orignal number try again"<<endl;
            cin>>guess;
            i++;
        }
        else{
            cout<<"Your guessed number is greatter than the orignal number try again"<<endl;
            cin>>guess;
            i++;
        }
    }
    if(guess==ori){
        cout<<"You have guessed correctly you won"<<endl;
    }
    else{
        cout<<"Sorry you loose the original number was "<<ori<<endl;
    }
    return 0;
}