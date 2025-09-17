#include <iostream>
using namespace std;


struct Pipe {
    string name;
    float length;
    int diametr;
    bool repair;
};

void bebra(){
    cout << "!1";
}
int main(){
    cout <<"Hello !" << endl;
    Pipe truba;
    truba.name = "Zona 1";
    cin >> truba.name;
    bebra();

}
