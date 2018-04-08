#include <iostream>
#include <vector>
#include "SudokuGen.h"
#include "SudokuGen_nine.h"
#include "Game.h"
#include "Game_nine.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ctime>
// 10227150 �յq�� 10227135 ���@�� 
using namespace std;

void print_board(vector <int >);

int main()
{
   int command = -1, num = -1, index = -1, get = -1, q = -1;
   Game start ;
   Game_nine start_two ;
   SudokuGen NewBoard; // ���ʹѽL����
   SudokuGen_nine NewBoard_two;
   vector <int > board;
   vector <int > boardtwo;
   bool out = true ;
   clock_t start1, stop;
   do { 
   cout << endl << "***** ���O���� ********************";
   cout << endl << "* 0. QUIT ����                    *";
   cout << endl << "* 1. Manage. �޲z                 *";
   cout << endl << "* 2. Play. �C��                   *";
   cout << endl << "* 3. �S��     9�c��C��           *";
   cout << endl << "***********************************";
   cout << endl << "Input a command(0, 1, 2, 3): ";
   cin >> command; //����Ū���ާ@���O
   switch (command)
   { case 0: return 0 ;
     case 1: //
	         do {
               cout << "(�޲z)" << endl << "0. �s�W�D��" << endl << "1. ����D��" << endl << "2. �R���D��" << endl << "3. �����޲z" << endl ;
               cin >> command;
               switch (command) {
               	  case 0:
               	  	          NewBoard.generator();
                              board = NewBoard.get_board(); //���o�ѽL
                              print_board(board); // �N�ѽL�L�X
                              cout << "[�s�W�D������!!]" << endl ;
               	  	break;
               	  case 1:
               	  	          for ( int q = 0 ; q < NewBoard.All_board.size(); q++ ) 
								cout << "[ " << q << " ]" <<endl ,print_board(NewBoard.All_board[q]),
								print_board(NewBoard.All_board_ANS[q]) ;
							  cout << "[����D������!!]" << endl ;	
               	  	break;
				  case 2:     cout << "�п�J�n�R���D�������X: " , cin >> num ;
				  	          if ( num < NewBoard.All_board.size() ) 
								NewBoard.All_board_ANS.erase( NewBoard.All_board_ANS.begin() + num ),  
								NewBoard.All_board.erase( NewBoard.All_board.begin() + num ), cout << "[�R���D������!!]" << endl ;
							  else  cout << "Number does not exist!" << endl ;
							    	   
				  	break;
				  case 3:
				             out = false ; 
				    break;	
				  default: cout << endl << "Command does not exist!" << endl;	 	
			   }
			   
			 } while (out);
			 out = true ; 
             break;
     case 2: // 
	         do {
               cout << "(�޲z)" << endl << "0. �m��" << endl << "1. �}�l����" << endl << "2. �[�ݱo��" << endl << "3. �����C��" << endl ;
               cin >> command;
               switch (command) {
               	  case 0:
               	  	          index =  rand() % (NewBoard.All_board.size()-1) ;
							  start.test( NewBoard.All_board[index], NewBoard.All_board_ANS[index] ) ; 
               	  	break;
               	  case 1:     start1 = clock(); //�}�l�ɶ� 
                              for ( int j = 0; j < 3; j++ ) {
				           	    index =  rand() % (NewBoard.All_board.size()-1) ;
							    start.test( NewBoard.All_board[index], NewBoard.All_board_ANS[index] ) ;
							    if ( j == 2 ) cout << "����" << endl,stop = clock(),cout << double(stop - start1) / CLOCKS_PER_SEC<< "��" <<endl,
								              system("pause"), q = double(stop - start1) / CLOCKS_PER_SEC, start.score.push_back( q ) ; 
								else cout << "�}�l�U�@�D" << endl, system("pause");
						      } 
               	  	break;
				  case 2:     
				              for ( int j = 0; j < start.score.size() ; j++ )
				              	cout << "[" << j << "] " << start.score[j] << "��" << endl ; 	   
				  	break;
				  case 3:
				             out = false ; 
				    break;	
				  default: cout << endl << "Command does not exist!" << endl;	 	
			   }
			   
			 } while (out);
			 out = true ;
             break;
     case 3: 
	        NewBoard_two.generator();
	        boardtwo = NewBoard_two.get_board(); //���o�ѽL
	        start_two.test( NewBoard_two.All_board[NewBoard_two.All_board.size()-1], NewBoard_two.All_board_ANS[NewBoard_two.All_board_ANS.size()-1] ) ;
	        break ;
     default: cout << endl << "Command does not exist!" << endl;
   } // end switch
 } while (true); //���O'0': �����D�{��
	

    system("pause");
    return 0;
}

void print_board(vector <int > board) //�N�ѽL�L�X
{
    for (int i=0;i<board.size();i++)
    {
        cout << board[i] << ' ';
        if ((i+1) % 4 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
