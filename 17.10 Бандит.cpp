#include <iostream>
#include<time.h>

using namespace std;

class bandito {
    char drum1,drum2,drum3;
    int count = 0;
public:
    bandito() :drum1{' '}, drum2{' '}, drum3{' '} {
        cout << "Hello friend!\t";
        show_comb();
    };
    void show_comb() {
        cout << "Price of one spin - 50\nAny combination with 3 different symbols - 0\n"\
            "@@ - 25\t\t@@@ - 50\n## - 50\t\t### - 100\n$$ - 100\t$$$ - 300";
    }
    void how_spins() {
        cout << "Do your bet: ";
        cin >> count;
        cout<<"You have "<< count / 50<<" spin(s)\n";
        cout << "Your change " << count%50;
        count /= 50;
    }
    void spin() {
        for (int i = 0; i < count; i++) {
            srand(time(NULL));
            short temp;
            temp = rand() % 3 + 1;
            check_sym(drum1, temp);
            temp = rand() % 3 + 1;
            check_sym(drum2, temp);
            temp = rand() % 3 + 1;
            check_sym(drum3, temp);
            string go;
            cout << "\n\nPut \"go\" to spin... ";
            cin >> go;
            if (go == "go") {
                cout << "\nLet's spin....\n----------" << drum1 << "-" << drum2 << "-" << drum3 << "----------";
                check_cash();
            }
            else {
                cout << "\nWeak....";
            }
        }
    }
    void check_cash() {
        cout << "\n\nYour cash is ";
        if (drum1!=drum2&& drum2 != drum3&& drum1 != drum3) {
            cout << "0";
        }
        if ((drum1 == drum2 && drum2 != drum3 && drum1 != drum3)||(drum1 != drum2 && drum2 != drum3 && drum1 == drum3)){
            if (drum1 == '@') { cout << "25"; }
            if (drum1 == '#') { cout << "50"; }
            if (drum1 == '$') { cout << "100"; }
        }
        if (drum1 != drum2 && drum2 == drum3 && drum1 != drum3) {
            if (drum2 == '@') { cout << "25"; }
            if (drum2 == '#') { cout << "50"; }
            if (drum2 == '$') { cout << "100"; }
        }
        if (drum1 == drum2 && drum2 == drum3 && drum1 == drum3) {
            if (drum2 == '@') { cout << "50"; }
            if (drum2 == '#') { cout << "100"; }
            if (drum2 == '$') { cout << "300"; }
        }

    }
    void check_sym(char &sym, short num) {
        if (num == 1) {sym = '@';}
        if (num == 2) {sym = '#';}
        if (num == 3) {sym = '$';}
    }
    int get_count() {
        return count;
    }
};

int main()
{
    bandito Game;
    while (1) {
        cout << "\n\nChoose an action:\n1) Spin the drum!\n2) Watch combinations\n";
        short choose;
        cin >> choose;
        cout << endl;
        switch (choose) {
        case 1:
            Game.how_spins();
            if (Game.get_count() < 1) {
                cout << "\n\nToo small bet...";
            }
            else {
                Game.spin();
            }
            break;
        case 2:
            Game.show_comb();
            break;
        default:
            cout << "Wrong choice...";
            break;
        }
    }
}

