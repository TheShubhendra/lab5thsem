#include<iostream>

using namespace std;

namespace Sec28{
    void ass1(){
        cout << "Assignment 1 of sec 28" << endl;
    }
    void ass2(){
        cout << "Assignment 2 of sec 28" << endl;
    }
}


namespace Sec29{
    void ass1(){
        cout << "Assignment 1 of sec 29" << endl;
    }
    void ass2(){
        cout << "Assignment 2 of sec 29" << endl;
    }
}



int main(){
    Sec28::ass1();
    Sec29::ass2();
    return 0;
}