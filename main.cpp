#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <map>
using namespace std;

class Intervalo
{
public:
    int* time_ini; //12:45 ->time_ini[0]=12 y time_ini[1]=45
    int* time_fin;
    Intervalo(int* t_ini, int* t_fin)
    {
        time_ini = new int[2];
        time_fin = new int[2];

        time_ini[0] = t_ini[0];
        time_ini[1] = t_ini[1];
        time_fin[0] = t_fin[0];
        time_fin[1] = t_fin[1];

        cout<<"constr time_ini: "<<time_ini[0]<<":"<<time_ini[1]<<endl;
        cout<<"constr time_fin: "<<time_fin[0]<<":"<<time_fin[1]<<endl;
    }

};

class Horario
{
public:
    char dur[10];
    char file[7];

    char dia[5]; //mon, tue..
    list<Intervalo> h_ini; //lista de intervalos ejm: {(11:30-13_20)->(14:00-14:50)->null)}
    list<Intervalo> h_fin;

    char f_int_line[150]; //el buffer que captura en una linea los intervalos, del archivo
    list<char*> f_interv; //la lista que guardara los intervalos por separado de f_int_ini
    list<char*> interv;

    Horario(char* _dur, char* file)
    {
        strcpy(dur, _dur);
        strcpy(this->file, file);
    }

    void leer()
    {
        strcat(file, ".txt");
        cout<<"file: "<<file<<endl;
		char c; //para iterar el buffer
		char str_interval[20]; //contendra un intervalo
        ifstream f1(file);
		
        while(!f1.eof() ){
            f1.getline(dia, 5, ' ');
			f1.getline(f_int_line, 150, '\n');
			for(int i = 0, j= 0; f_int_line[i] != '\0' ; i++, j++){
				if(f_int_line[i] != ' ' && f_int_line[i+1] != '\0')
					str_interval[j] = f_int_line[i];
				else{
					if(f_int_line[i+1] == '\0'){
						str_interval[j] = f_int_line[i];
						str_interval[j+1] = '\0';
					}
					else
						str_interval[j] = '\0';
					j = -1;
					interv.push_back(str_interval);
					str_interval[0] = '\0';
				}
			}

			list<char*>::iterator it;
			for (it = interv.begin(); it != interv.end(); ++it){
			    cout << "; " << (*it) <<endl;
			}
            //cout<<dia<<", "<<f_int_line<<"\n";
        }

        //list<char*>::iterator it;
        //for (it = interv.begin(); it != interv.end(); ++it){
        //    cout << '; ' << (*it) <<endl;
        //}

    }
};

struct Datos_prueba{
    char dia[4];
    char f_int_ini[25];
    char f_int_fin[25];

    Datos_prueba(){

        //dia = "mon";
        //f_int_ini = "08:30-10:30";
        //f_int_fin = "14:03-16:00";
    }

    void func(char* dia, Horario h1, Horario h2)
    {
        //comprar los dias (mon, tue)
        cout<<"h1.dia: "<<h1.dia<<endl;
        cout<<"h2.dia: "<<h2.dia<<endl;
        if(strcmp(h1.dia, h2.dia) == 0){
        //tomar la hora de inicio del intervalo del 1er archivo con el inter. del 2do archivo(el ke sea mas tarde)
            //h1.h_ini.
            cout<<"\nentro\n";
            list<Intervalo>::iterator it;
            for (it = h1.h_ini.begin(); it != h1.h_ini.end(); ++it){
                cout << ' ' << ((*it).time_ini)[0] <<":"<<((*it).time_ini)[1]<<endl;

            }

        //hacer lo mismo, la hora que sea mas temprano a evaluar(el ke sea mas temprano)
        //con el intervalo armado, comprobar que la hora de inicio sea menor a la hora de fin
        //se restan estas horas, si sale menor, desech el rengo armado y verifica con ottro, caso contrario, continua con dicho inter. armado
        //
        }

    }

};

int* ToHour(char* h){
    int* hour = new int[2];
    int h1, h2, m1, m2, ht, mt;
    h1 = int(h[0]) - 48;  //extrae el numero del char
    h2 = int(h[1]) - 48;  //extrae el numero del char
    m1 = int(h[3]) - 48;  //extrae el numero del char
    m2 = int(h[4]) - 48;  //extrae el numero del char
    ht = h1 * 10 + h2;    //obtencion del formato horas
    mt = m1 * 10 + m2;    //obtencion del formato minutos
    hour[0] = ht;         //posicion de horas
    hour[1] = mt;         //posicion de minutos

    return hour;
}

int main()
{
    char duracion[10]; // = {"00:45 a e"};
    char a1[7];
    char a2[7];

    cin>>duracion;
    cin>>a1;
    cin>>a2;

    cout<<duracion<<"-";
    cout<<a1<<"-";
    cout<<a2<<endl;

    int* res = ToHour("11:46");
	cout<<res[0]<<":"<<res[1]<<endl;

    Horario h1(duracion, a1);
    //strcpy_s(h1.dia, "mon");

    //cout<<"h1.dia: "<<h1.dia<<endl;
    list<Intervalo> e1;
    e1.push_back(Intervalo(ToHour("11:35"), ToHour("11:47")) );
    e1.push_back(Intervalo(ToHour("12:15"), ToHour("14:23")) );
    list<Intervalo> e2;

    h1.h_ini = e1;

    //list<Intervalo> e2;
    //e2.push_back(new Intervalo(ToHour("11:35"), ToHour("11:47")) );
    //e2.push_back(new Intervalo(ToHour("12:15"), ToHour("14:23")) );

    Datos_prueba d;
    d.func("mon", h1, h1);

    h1.leer();

    //Horario h2(duracion, a2);
    //h2.leer();

    cout << "Hello world!" << endl;
    return 0;
}
