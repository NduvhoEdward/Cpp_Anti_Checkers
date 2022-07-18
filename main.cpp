// 23/04/2020  19:39
// win status function working, 
// 24/04/2020  20:45
// final arrays-vectors replacement
// 25/04/2020  02:45
// vectors fully working
// 26/04/2020  18:45 
// algs base working
// 26/04/2020  22:45 
// algss successfully making the first move
// 27/04/2020  13:15
// algss successfully making moves
// 27/04/2020  16:15
// functions are all working
// 27/04/2020  19:45/20:15
// working //cout, f_out still having some noise/ list_0 and list_1 working
// 28/04/2020  02:05
// all working but the list_1 implimentation
// 28/04/2020  03:45
// player one's moves done


#include "checkers.h"
#include <fstream>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[])
{
    //open the files
    ifstream f_in("input.txt");
    ofstream f_out("results.txt");

    checkers check_me;

    check_me.PLAY(f_in,f_out);

    //close them files
    f_in.close();
    f_out.close();

    return 0;
}



