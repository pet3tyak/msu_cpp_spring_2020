#include "calb.h"

OnNum numer=nullptr;
OnLet letr=nullptr;
OnEdge tend=nullptr;
OnEdge tbegin=nullptr;

void regnum(OnNum callback)
{
    numer=callback;
}

void reglet(OnLet callback)
{
    letr=callback;
}

void regbeg(OnEdge callback)
{
    tbegin=callback;
}

void regend(OnEdge callback)
{
    tend=callback;
}

void parse(const string& str)
{
    if (tbegin!=nullptr)
        tbegin();
    size_t a = 0;
    size_t b;
    string token;

    while((b = str.find_first_of(" \n\t", a))!=string::npos){
        token = str.substr(a, b-a);
        if ((isdigit(token[0]))&&(numer!= nullptr))
        {
            int number = atoi(token.c_str());
            numer(number);
        }
        else if (letr!=nullptr)
            letr(token);
        a = str.find_first_not_of(" \n\t", b);
    }
    if (tend!=nullptr)
        tend();
}