#include <iostream>
using namespace std;


struct Pipe {
    string name;
    float length;
    int diametr;
    bool repair;
};

struct CS {
    string name;
    int work_p;
    int work_p_on;
    string class_cs;
};

int main(){
    cout <<"Hello !" << endl;
    Pipe truba;
    truba.name = "Zona 1";
    cout << truba.name;
    

}
