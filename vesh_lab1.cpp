#include <iostream>
#include <fstream>
using namespace std;


struct Pipe {
    string name;
    float length;
    int diametr;
    bool repair;
};

struct CS {
    string name;
    int work_p; // станции 
    int work_p_on; // работающие станции
    string class_cs;
};

void Menu(Pipe& t, CS& cs){
    while (1){
        cout << "Viberite option:\n1 Add pipe\n2 Add CS\n3 Show all\n4 Edit pipe\n5 Edit cs\n6 Save\n7 Download \n0 Exit\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Ukazhite pipe name: ";
            cin >> t.name;
            cout << "Ukazhite length: ";
            cin >> t.length;
            cout << "Ukazhite diametr: ";
            cin >> t.diametr;
            t.repair = false;
            break;

        case 2:
            cout << "Ukazhite cs name: ";
            cin >> cs.name;
            cout << "Ukazhite vsego stations: ";
            cin >> cs.work_p;
            cout << "Ukazhite rabotayushchie stations: ";
            cin >> cs.work_p_on;
            cout << "Ukazhite class: ";
            cin >> cs.class_cs;
            break;

        case 3:
            if (!t.name.empty()) {
                cout << "\nTRUBA:\n";
                cout << "Name: " << t.name << endl;
                cout << "Length: " << t.length << " km" << endl;
                cout << "Diametr: " << t.diametr << " mm" << endl;
                cout << "V remonte: " << (t.repair ? "Da" : "Net") << endl;
            } else {
                cout << "Truba ne sozdana" << endl;
            }
            
            if (!cs.name.empty()) {
                cout << "\nKS:\n";
                cout << "Name: " << cs.name << endl;
                cout << "Vsego stantsiy: " << cs.work_p << endl;
                cout << "Rabotayushchikh: " << cs.work_p_on << endl;
                cout << "Class: " << cs.class_cs << endl;
            } else {
                cout << "KS ne sozdana" << endl;
            }
            break;


        case 4:
            if (!t.name.empty()) {
                cout << "Tekushchiy status remonta: " << (t.repair ? "Da" : "Net") << endl;
                cout << "Izmenit status? (1 - Da, 0 - Net): ";

                int choice;
                cin >> choice;

                if (choice == 1) {
                    t.repair = !t.repair;
                    cout << "Noviy status: " << (t.repair ? "Da" : "Net") << endl;
                }
            } else {
                cout << "Truba ne sozdana" << endl;
            }
            break;

            case 5:
            if (!cs.name.empty()) {
                cout << "Tekushchee kolichestvo rabotayushchikh stantsiy: " << cs.work_p_on << " iz " << cs.work_p << endl;
                cout << "1 - Zapustit stantsiyu\n2 - Ostanovit stantsiyu\nViberite: ";

                int choice;
                cin >> choice;

                if (choice == 1 && cs.work_p_on < cs.work_p) {
                    cs.work_p_on++;
                    cout << "Zapushchena odna stantsiya. Teper rabotayet: " << cs.work_p_on << endl;
                } else if (choice == 2 && cs.work_p_on > 0) {
                    cs.work_p_on--;
                    cout << "Ostanovlena odna stantsiya. Teper rabotayet: " << cs.work_p_on << endl;
                } else {
                    cout << "Nevozmozhno deystvie" << endl;
                }
            } else {
                cout << "KS ne sozdana" << endl;
            }
            break;
            
        case 6:
            {
                ofstream file("data.txt");

                file << t.name << endl;
                file << t.length << endl;
                file << t.diametr << endl;
                file << t.repair << endl;

                file << cs.name << endl;
                file << cs.work_p << endl;
                file << cs.work_p_on << endl;
                file << cs.class_cs << endl;
                file.close();
                cout << "Dannie sohraneni v fail data.txt" << endl;
            }
            break;

        case 7:
            {
                ifstream file("data.txt");
                if (file) {
                    file >> t.name;
                    file >> t.length;
                    file >> t.diametr;
                     
                    file >> t.repair;
                    file >> cs.name;
                    file >> cs.work_p;
                    file >> cs.work_p_on;
                    file >> cs.class_cs;
                    file.close();
                    
                } else {
                    cout << "Oshibka" << endl;
                }
            }
            break;
            
        case 0:
            cout << "Exit" << endl;
            return;
        
        default:
            cout << "Nepravilniy vibor!" << endl;
        
        
        };
    };

};
 
int main(){
    Pipe truba;
    CS station;
    
    Menu(truba, station);
    
    

}
