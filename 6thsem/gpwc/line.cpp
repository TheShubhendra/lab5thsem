#include<iostream>

using namespace std;

class Line{
    public:
        int getLength();

        Line(int len);
        Line(const Line& obj);
        ~Line();

    private:
        int *ptr;
};

Line::Line(int len){
    cout << "Normal cnostruvtor " << endl;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj){
    cout << "Copy constructor " << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line(){
    cout << "Destructor " << endl;
    delete ptr;
}

int Line::getLength(){
    return *ptr;
}

void display(Line line){
    cout << "Length of line is " << line.getLength() << endl;
}

int main(){
    Line l1(10);
    cout << l1.getLength() << endl;
    display(l1);
}