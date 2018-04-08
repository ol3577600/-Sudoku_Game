#include "SudokuGen.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
// 10227150 �յq�� 10227135 ���@�� 
using namespace std;

SudokuGen::SudokuGen() // �غc�l(Constructor)
{
    srand(time(NULL)); //�H�����l�Ʈɶ��]�w���üƺؤl
    //generator(); //�H�üƤ�k���ͼƿW�ѽL
}

void SudokuGen::generator() //�üƪk���ͷs�ѽL
{
    int tmp; //�m���μȦs�ܼ�
    int numtmp[4] = {1,2,3,4}; //4�c�椺���Ʀr
    vector <int> board(16); //�ѽL
    bool check = false; //��ܴѽL�O�_���\����

    for (i=0;i<16;i++){board[i] = 0;} //��l�ƴѽL(��J0)

    for (i=0;i<4;i++) //����J���W��4�c��
//    1 2 
//    3 4 
    {
        board[i/2*4+i%2] = numtmp[i];
    }
    while(!check) //���_���ժ���ŦX�W�h���ѽL����
    {
//        ��J�Ʀr�禡�A���ե��ѶW�L1000���|�^��false��
        check = board_put(board);
    }
    for (i=0;i<4;i++) //�N1-4���Ʀr���ǥ���
    {
        j = rand() % 4;
        tmp = numtmp[i];
        numtmp[i] = numtmp[j];
        numtmp[j] = tmp;
    }

    for(i=0;i<16;i++) //�N�ѽL���Ʀr�Ǹm�����s���ͪ��Ʀr��
    {
        board[i] = numtmp[board[i]-1];
    }
    /*
    for (i=0;i<SIZE;i++) //�N���G�g�Jnew_board�ܼ�
        for (j=0;j<SIZE;j++)
        {
            new_board[i][j] = board[i*SIZE+j];
        }
    */
    All_board_ANS.push_back( board ) ; 
    board_dig(board, 8) ; // ��8�Ӭ} 
}

vector <int > SudokuGen::get_board() //��X�ѽL��vector�ܼ�
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
        if(board[pos/4*4+i]==n) //check��ƤW�Ʀr�O�_������
        {
            return true; //�����ơA�^��true
        }
        if(board[i*4+pos%4]==n) //check���ƤW�Ʀr�O�_������
        {
            return true; //�����ơA�^��true
        }
    }
    return false;  //�L���ơA�^��false
}

bool SudokuGen::board_put(vector<int > &board) //��J�Ʀr�禡
{
    int pos;
    int count1,count2; //�p�ƾ�
    bool check = true; //check�Ʀr�O�_����

    for (j=0;j<4;j++) //��J���Ʀr1-4 (j+1�����G)
    {
        count2 = 0; //�p���@�Ʀr��J�`�@���տ��~����
        for (i=1;i<4;i++) //�̧ǱN�Ʀr��J��l3�Ӥp�|�c��(���W���w�g����)
        {
            pos = i/2*8+i%2*2; //�C�Ӥp�|�c�檺�_�lindex
            count1 = 0; //�p���@�Ʀr��J���տ��~����
            while (check==true)
            {
                k = rand() % 4;
                check = check_rep(board,pos+k/2*4+k%2,j+1);
                ++count1;
                ++count2;
                if (board[pos+k/2*4+k%2]==0 && check==false) //�Ʀr�S�����ơA���\��J����while loop
                {
                    board[pos+k/2*4+k%2] = j+1;
                    check = true;
                    break;
                }
                else
                {
                    check = true;
                }
                if (count1 > 100) // ���~�W�L100���A�Ʀr����
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
                if (count2 > 1000) // ���~�W�L1000���A�^��false�õ����禡
                {
                    return false;
                }
            }
        }
    }
    return true; //���\�񺡴ѽL�A�^��true
}

void SudokuGen::board_dig(vector < int > board, int n_hole)
{   
    for (a=0;a<SIZE*SIZE;a++) //�إ�0��15���Ʀr�ǦC
    {
        number_seres[a] = a;
    }
    for (a=0;a<SIZE;a++)//�N��J���ƿW�D�ؼg�J��in_board�ܼ�
        for (s=0;s<SIZE;s++)
        {
            in_board[a][s] = board[a*SIZE+s];

        }
	 
    int temp; //�m���μȦs�ܼ�
    copy_board(); //�I�s�ƻs���
    for (a=0;a<16;a++) //�N�Ʀr�ǦC����
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
�ƻs�ѽL�禡
copy in_board into dig_board
*/
{
    for (a=0;a<SIZE;a++)
        for (s=0;s<SIZE;s++)
        {
            dig_board[a][s] = in_board[a][s];
        }
}
