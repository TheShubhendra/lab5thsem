#include<iostream>

using namespace std;

class Box{
    private:
        double length, breath, height;

    public:
        Box(double length, double breath, double height){
            this->length = length;
            this->breath = breath;
            this->height = height;
        }

        double getVolume();
};

double Box::getVolume(){
    return length * breath * height;
}



int main(){
    Box box1 = Box(2, 3,3);

    cout << box1.getVolume() << endl;
}

