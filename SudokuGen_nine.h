#define SIZE1 9 
#include <vector>
// 10227150 白皓元 10227135 邱世鑫 
using namespace std;

class SudokuGen_nine
{
    public:
        SudokuGen_nine();
        void generator(); //亂數法產生新棋盤 (初始化時建構子就會呼叫一次)
        vector<int > get_board(); //輸出棋盤至vector變數
        bool check_rep(vector<int>,int,int); //偵測填入數字是否重複、符合規則，不符合會回傳false值
        bool board_put(vector<int>&); //填入數字函式，嘗試失敗超過1000次會回傳false值
        void board_dig(vector<int>,int); //挖洞函式
        void copy_board(); //複製棋盤函式
        vector < vector <int> > All_board ; // 所有棋盤
		vector < vector <int> > All_board_ANS ; 
    private:
        int new_board[SIZE1][SIZE1]; //棋盤
        int i,j,k,l,a,s; //迴圈用變數
        int in_board[SIZE1][SIZE1]; //輸入棋盤
        int dig_board[SIZE1][SIZE1]; //輸出棋盤(挖完洞)
        int number_seres[SIZE1*SIZE1]; //數字序列
};
