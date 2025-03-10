#include <iostream>
#include <unordered_map>
using namespace std;

class Car{
private:
    string plate;
    string brand;
    string type;
    unsigned short year;
public:
    Car():plate(""),brand(""),type(""),year(0){}
    Car(string pl,string br,string tp,int yr)
        :plate(pl),brand(br),type(tp),year(yr){}
    void details(){
        cout<<"Rendszam: "<<plate<<"\nMarka: "<<brand<<"\nTipus: "<<type<<"\nEvjarat: "<<to_string(year)<<endl;
    }
};

class CarDatabase{
private:
    unordered_map<string,Car> database;
public:
    CarDatabase(){
        database={
            {"ABC-123",Car("ABC-123","Suzuki","Swift",1997)},
            {"BCD-234",Car("BCD-234","BMW","M4",2021)},
            {"CDE-345",Car("CDE-345","Mercedes-Benz","G63",2024)},
            {"DEF-456",Car("DEF-456","Toyota","Supra",1994)},
            {"EFG-567",Car("EFG-567","Aston Martin","DB7",2001)},
            {"FGH-678",Car("FGH-678","Fiat","Stillo",2004)},
            {"GHI-789",Car("GHI-789","Ferrari","F430",2006)},
            {"HIJ-890",Car("HIJ-890","McLaren","720S",2017)},
            {"IJK-901",Car("IJK-901","Ford","Fiesta",2007)},
            {"JKL-012",Car("JKL-012","Mazda","MX5",2003)}
        };
    }
    bool findCar(string& pl){
        auto p=database.find(pl);
        if(p!=database.end()){
            p->second.details();
            return true;
        }
        return false;
    }
};

int main()
{
    CarDatabase db;
    string input_plate;
    cout<<"Kerem adja meg a rendszamot: ",cin>>input_plate;
    if(!db.findCar(input_plate))
        cout<<"Ilyen rendszam nem talalhato az adatbazisban"<<endl;
    return 0;
}
