#define SIZE 4 
#include <vector>
#include <fstream>

using namespace std;

class Game
{
    public:	
      void test( vector <int>, vector <int>) ;
      bool Check_equal(vector <int >, vector <int > ) ;
      void print_board(vector <int >);
      vector <double> score ;
    private:
      fstream input ;
      vector <int > ansboard ;
};
