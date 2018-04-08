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
// 10227150 白皓元 10227135 邱世鑫 
using namespace std;

void print_board(vector <int >);

int main()
{
   int command = -1, num = -1, index = -1, get = -1, q = -1;
   Game start ;
   Game_nine start_two ;
   SudokuGen NewBoard; // 產生棋盤物件
   SudokuGen_nine NewBoard_two;
   vector <int > board;
   vector <int > boardtwo;
   bool out = true ;
   clock_t start1, stop;
   do { 
   cout << endl << "***** 指令介面 ********************";
   cout << endl << "* 0. QUIT 結束                    *";
   cout << endl << "* 1. Manage. 管理                 *";
   cout << endl << "* 2. Play. 遊戲                   *";
   cout << endl << "* 3. 特殊     9宮格遊戲           *";
   cout << endl << "***********************************";
   cout << endl << "Input a command(0, 1, 2, 3): ";
   cin >> command; //嘗試讀取操作指令
   switch (command)
   { case 0: return 0 ;
     case 1: //
	         do {
               cout << "(管理)" << endl << "0. 新增題型" << endl << "1. 顯示題型" << endl << "2. 刪除題型" << endl << "3. 結束管理" << endl ;
               cin >> command;
               switch (command) {
               	  case 0:
               	  	          NewBoard.generator();
                              board = NewBoard.get_board(); //取得棋盤
                              print_board(board); // 將棋盤印出
                              cout << "[新增題型完成!!]" << endl ;
               	  	break;
               	  case 1:
               	  	          for ( int q = 0 ; q < NewBoard.All_board.size(); q++ ) 
								cout << "[ " << q << " ]" <<endl ,print_board(NewBoard.All_board[q]),
								print_board(NewBoard.All_board_ANS[q]) ;
							  cout << "[顯示題型完成!!]" << endl ;	
               	  	break;
				  case 2:     cout << "請輸入要刪除題型的號碼: " , cin >> num ;
				  	          if ( num < NewBoard.All_board.size() ) 
								NewBoard.All_board_ANS.erase( NewBoard.All_board_ANS.begin() + num ),  
								NewBoard.All_board.erase( NewBoard.All_board.begin() + num ), cout << "[刪除題型完成!!]" << endl ;
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
               cout << "(管理)" << endl << "0. 練習" << endl << "1. 開始闖關" << endl << "2. 觀看得分" << endl << "3. 結束遊戲" << endl ;
               cin >> command;
               switch (command) {
               	  case 0:
               	  	          index =  rand() % (NewBoard.All_board.size()-1) ;
							  start.test( NewBoard.All_board[index], NewBoard.All_board_ANS[index] ) ; 
               	  	break;
               	  case 1:     start1 = clock(); //開始時間 
                              for ( int j = 0; j < 3; j++ ) {
				           	    index =  rand() % (NewBoard.All_board.size()-1) ;
							    start.test( NewBoard.All_board[index], NewBoard.All_board_ANS[index] ) ;
							    if ( j == 2 ) cout << "結束" << endl,stop = clock(),cout << double(stop - start1) / CLOCKS_PER_SEC<< "秒" <<endl,
								              system("pause"), q = double(stop - start1) / CLOCKS_PER_SEC, start.score.push_back( q ) ; 
								else cout << "開始下一題" << endl, system("pause");
						      } 
               	  	break;
				  case 2:     
				              for ( int j = 0; j < start.score.size() ; j++ )
				              	cout << "[" << j << "] " << start.score[j] << "秒" << endl ; 	   
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
	        boardtwo = NewBoard_two.get_board(); //取得棋盤
	        start_two.test( NewBoard_two.All_board[NewBoard_two.All_board.size()-1], NewBoard_two.All_board_ANS[NewBoard_two.All_board_ANS.size()-1] ) ;
	        break ;
     default: cout << endl << "Command does not exist!" << endl;
   } // end switch
 } while (true); //指令'0': 結束主程式
	

    system("pause");
    return 0;
}

void print_board(vector <int > board) //將棋盤印出
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
