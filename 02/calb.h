#include <iostream> 
#include <string> 
#include <cstddef>
using namespace std;

using OnLet = void (*)(const string& token);  
using OnEdge = void (*)();
using OnNum = void (*)(int token);

void regnum(OnNum callback);
void reglet(OnLet callback);
void regbeg(OnEdge callback);
void regend(OnEdge callback);
void parse (const string& str);