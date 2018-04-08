#include "Game_nine.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

void Game_nine::test( vector < int > board, vector < int > board_ans ) 
{   int get = -1 ;
    ansboard.resize(81) ;
    input.open("test.txt",ios::out);
    for (int i=0;i<board.size();i++) {
       input << board[i] << ' ';
       if ((i+1) % 9 == 0) input << "\n";
    }
    input << "\n", input.close();
	cout <<endl << "[題目以輸出至test.txt" << endl << "請將0更改為答案後儲存" << endl << "儲存完後按兩次enter鍵]"<<endl<<endl;               	  	
    system("pause"), system("pause");
    input.open("test.txt",ios::in);
	for(int i=0;i<81;i++) 
        input >> get, ansboard[i] = get ; 
    input.close();
	cout << "[這是你的答案~]" << endl ;
	print_board(ansboard) ; 
	
	if ( Check_equal(ansboard, board_ans) ) cout << "[答案正確!!]" << endl ;
	else cout << "[答案錯誤!!]" << endl ;
}

bool Game_nine::Check_equal(vector <int > one, vector <int > two) {
	for (int i=0;i<81;i++) {
	  if ( one[i] != two[i] ) return false ;	
	}
	return true ;
}

void Game_nine::print_board(vector <int > board) //將棋盤印出
{
    for (int i=0;i<board.size();i++)
    {
        cout << board[i] << ' ';
        if ((i+1) % 9 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
