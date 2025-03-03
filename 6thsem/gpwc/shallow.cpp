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
class Deep{
    public:
        int *ptr;
        Deep(int val){
            // ptr = new int;
            *ptr = val;
        }

        Deep(const Deep &obj){
            ptr = new int;
            *ptr = *obj.ptr;
        }

        ~Deep(){
            delete ptr;
            cout << "Shallow Destructor called" << endl;
        }
};

// 9337609501
int main(){
    Deep s1(10);
    Deep s2 = s1;

}