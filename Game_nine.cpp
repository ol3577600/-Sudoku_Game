#include "Game_nine.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
// 10227150 �յq�� 10227135 ���@�� 
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
	cout <<endl << "[�D�إH��X��test.txt" << endl << "�бN0��אּ���׫��x�s" << endl << "�x�s������⦸enter��]"<<endl<<endl;               	  	
    system("pause"), system("pause");
    input.open("test.txt",ios::in);
	for(int i=0;i<81;i++) 
        input >> get, ansboard[i] = get ; 
    input.close();
	cout << "[�o�O�A������~]" << endl ;
	print_board(ansboard) ; 
	
	if ( Check_equal(ansboard, board_ans) ) cout << "[���ץ��T!!]" << endl ;
	else cout << "[���׿��~!!]" << endl ;
}

bool Game_nine::Check_equal(vector <int > one, vector <int > two) {
	for (int i=0;i<81;i++) {
	  if ( one[i] != two[i] ) return false ;	
	}
	return true ;
}

void Game_nine::print_board(vector <int > board) //�N�ѽL�L�X
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
