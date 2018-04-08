#include "SudokuGen.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

SudokuGen::SudokuGen() // 建構子(Constructor)
{
    srand(time(NULL)); //以物件初始化時間設定為亂數種子
    //generator(); //以亂數方法產生數獨棋盤
}

void SudokuGen::generator() //亂數法產生新棋盤
{
    int tmp; //置換用暫存變數
    int numtmp[4] = {1,2,3,4}; //4宮格內的數字
    vector <int> board(16); //棋盤
    bool check = false; //表示棋盤是否成功產生

    for (i=0;i<16;i++){board[i] = 0;} //初始化棋盤(填入0)

    for (i=0;i<4;i++) //先填入左上角4宮格
//    1 2 
//    3 4 
    {
        board[i/2*4+i%2] = numtmp[i];
    }
    while(!check) //不斷嘗試直到符合規則的棋盤產生
    {
//        填入數字函式，嘗試失敗超過1000次會回傳false值
        check = board_put(board);
    }
    for (i=0;i<4;i++) //將1-4的數字順序打亂
    {
        j = rand() % 4;
        tmp = numtmp[i];
        numtmp[i] = numtmp[j];
        numtmp[j] = tmp;
    }

    for(i=0;i<16;i++) //將棋盤的數字序置換為新產生的數字序
    {
        board[i] = numtmp[board[i]-1];
    }
    /*
    for (i=0;i<SIZE;i++) //將結果寫入new_board變數
        for (j=0;j<SIZE;j++)
        {
            new_board[i][j] = board[i*SIZE+j];
        }
    */
    All_board_ANS.push_back( board ) ; 
    board_dig(board, 8) ; // 挖8個洞 
}

vector <int > SudokuGen::get_board() //輸出棋盤至vector變數
{
    vector < int > out_board (SIZE*SIZE);
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            out_board[i*SIZE+j] = dig_board[i][j];
        }
    All_board.push_back( out_board ) ;     
    return out_board;
}

bool SudokuGen::check_rep(vector<int> board,int pos,int n)
{
    int i;
    for (i=0;i<4;i++)
    {
        if(board[pos/4*4+i]==n) //check橫排上數字是否有重複
        {
            return true; //有重複，回傳true
        }
        if(board[i*4+pos%4]==n) //check直排上數字是否有重複
        {
            return true; //有重複，回傳true
        }
    }
    return false;  //無重複，回傳false
}

bool SudokuGen::board_put(vector<int > &board) //填入數字函式
{
    int pos;
    int count1,count2; //計數器
    bool check = true; //check數字是否重複

    for (j=0;j<4;j++) //填入的數字1-4 (j+1的結果)
    {
        count2 = 0; //計算單一數字填入總共嘗試錯誤次數
        for (i=1;i<4;i++) //依序將數字填入其餘3個小四宮格(左上角已經產生)
        {
            pos = i/2*8+i%2*2; //每個小四宮格的起始index
            count1 = 0; //計算單一數字填入嘗試錯誤次數
            while (check==true)
            {
                k = rand() % 4;
                check = check_rep(board,pos+k/2*4+k%2,j+1);
                ++count1;
                ++count2;
                if (board[pos+k/2*4+k%2]==0 && check==false) //數字沒有重複，成功填入結束while loop
                {
                    board[pos+k/2*4+k%2] = j+1;
                    check = true;
                    break;
                }
                else
                {
                    check = true;
                }
                if (count1 > 100) // 錯誤超過100次，數字重填
                {
                    for (l=0;l<16;l++)
                    {
                        if (board[l]==j+1)
                        {
                            board[l]=0;
                        }
                    }
                    board[j/2*4+j%2]=j+1;
                    i = 0;
                    break;
                }
                if (count2 > 1000) // 錯誤超過1000次，回傳false並結束函式
                {
                    return false;
                }
            }
        }
    }
    return true; //成功填滿棋盤，回傳true
}

void SudokuGen::board_dig(vector < int > board, int n_hole)
{   
    for (a=0;a<SIZE*SIZE;a++) //建立0到15的數字序列
    {
        number_seres[a] = a;
    }
    for (a=0;a<SIZE;a++)//將輸入的數獨題目寫入至in_board變數
        for (s=0;s<SIZE;s++)
        {
            in_board[a][s] = board[a*SIZE+s];

        }
	 
    int temp; //置換用暫存變數
    copy_board(); //呼叫複製函數
    for (a=0;a<16;a++) //將數字序列打亂
    {
        s = rand()%16;
        temp = number_seres[a];
        number_seres[a] = number_seres[s];
        number_seres[s] = temp;
    }
    for (a=0;a<n_hole;a++)
    {
        dig_board[number_seres[a]/SIZE][number_seres[a]%SIZE] = 0;
    }
}

void SudokuGen::copy_board()
/*
複製棋盤函式
copy in_board into dig_board
*/
{
    for (a=0;a<SIZE;a++)
        for (s=0;s<SIZE;s++)
        {
            dig_board[a][s] = in_board[a][s];
        }
}
