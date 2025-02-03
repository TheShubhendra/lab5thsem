#include<iostream>

using namespace std;

class Shallow{
    public:
        int *ptr;
        Shallow(int val){
            ptr = new int;
            *ptr = val;
        }

        ~Shallow(){
            delete ptr;
            cout << "Shallow Destructor called" << endl;
        }
};


int main(){
    Shallow s1(10);
    Shallow s2 = s1;

}