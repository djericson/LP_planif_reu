#include <iostream>
#include <fstream>
using namespace std;


struct Horario
{
    char dur[10];
    char file[5];

    char dia[5];
    char f_int_ini[25];
    char f_int_fin[25];

    Horario(char* _dur, char* file)
    {
        dur[0] = _dur[0];
        f = file;
    }

    void leer()
    {
        ifstream f1(file);
        while(!f1.eof()){
            f1.getline(dia, 5, ' ');
            f1.getline(f_int_ini, 25, ' ');
            f1.getline(f_int_fin, 25, '\n');

            cout<<dia<<"-"<<f_int_ini<<"-"<<f_int_fin<<"\n";
        }
    }
};

int main()
{
    char duracion[10]; // = {"00:45 a e"};
    char a1[5];
    char a2[5];

    cin>>duracion;
    cin>>a1;
    cin>>a2;

    cout<<duracion;
    cout<<a1;
    cout<<a2;

    Horario h1(duracion, a1);
    h1.leer();
    Horario h2(duracion, a2);
    h2.leer();


    /*
    h1.f =
    ifstream f1(a1);
    char dia[5];
    char h_ini[25];
    char h_fin[25];

    while(!f1.eof()){
        f1.getline(dia,5, ' ');
        f1.getline(h_ini,25, ' ');
        f1.getline(h_fin,25, '\n');

    }
    */

    cout << "Hello world!" << endl;
    return 0;
}
