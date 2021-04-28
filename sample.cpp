#include <iostream>
#include "timercpp.h"

using namespace std;

void function()
{
    Timer  t([&]() {
        cout << "Hey.. I will go out of scope soon..." << endl;
    }, 1s, Mode::ONESHOT); 

    for(auto i = 0; i < 100; ++i)
    {
	    cout << ".";
    }
}

int main() {
    function();
    Timer  t([&]() {
        cout << "\nHey.. waiting.." << endl;
    }, 10s, Mode::PERIODIC); 


    cout << "I am Timer" <<endl;


    while(true); // Keep mail thread active
}
