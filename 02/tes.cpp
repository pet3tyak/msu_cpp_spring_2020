#include "calb.h"


void Begin(){
    cout << "begin parsing -> ";
}

void End(){
    cout << "end parsing\n";
}

void onNumberFound(int n){
    cout << n << " - number -> ";
}

void onLetterFound(const string& n){
    cout << n << " - string -> ";
}

int main()
{
    regnum(onNumberFound);
    reglet(onLetterFound);
    regend(End);

    parse("123 abc\n4567\tdefg 891");

    regbeg(Begin);
    parse("123 abc\n4567\tdefg 891");
    return 0;
}