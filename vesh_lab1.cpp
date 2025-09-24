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
        cin.ignore(10000, '\n');
        cout << "Ukazhite pipe name: ";
        cin.ignore();
        getline(cin, t.name);
    
        cout << "Ukazhite length: ";
        while (!(cin >> t.length) || t.length <= 0) {
            cout << "Oshibka! Vvedite chislo: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    
        cout << "Ukazhite diametr: ";
        while (!(cin >> t.diametr) || t.diametr <= 0) {
            cout << "Oshibka! Vvedite chislo: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    
        t.repair = false;
        break;

        case 2:
        cout << "Ukazhite cs name: ";
        cin.ignore();
        getline(cin, cs.name);
        
        cout << "Ukazhite vsego stations: ";
        while (!(cin >> cs.work_p) || cs.work_p <= 0) {
            cout << "Oshibka! Vvedite chislo: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        cout << "Ukazhite rabotayushchie stations: ";
        while (!(cin >> cs.work_p_on) || cs.work_p_on < 0 || cs.work_p_on > cs.work_p) {
            cout << "Oshibka! Vvedite chislo ot 0 do " << cs.work_p << ": ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        cout << "Ukazhite class: ";
        cin.ignore();
        getline(cin, cs.class_cs);
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
                while (!(cin >> choice) || (choice != 0 && choice != 1)) {
                    cout << "Oshibka! Vvedite 1 or 0: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                
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
                while (!(cin >> choice) || (choice != 1 && choice != 2)) {
                    cout << "Oshibka! Vvedite 1 or 2: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                
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
            //
        case 6:
            {
                ofstream file("data.txt");
                
               
                file << "PIPE" << endl;
                file << t.name << endl;
                file << t.length << endl;
                file << t.diametr << endl;
                file << t.repair << endl;
                
                
                file << "CS" << endl;
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
                    string marker;
                    
                    
                    file >> marker;
                    if (marker == "PIPE") {
                        file.ignore(); // пропускаем перевод строки
                        getline(file, t.name);
                        file >> t.length >> t.diametr >> t.repair;
                    }
                    
                    
                    file >> marker;
                    if (marker == "CS") {
                        file.ignore(); 
                        getline(file, cs.name);
                        file >> cs.work_p >> cs.work_p_on;
                        file.ignore(); 
                        getline(file, cs.class_cs);
                    }
                    
                    file.close();
                    cout << "Dannie zagruzheni" << endl;
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
