#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class hashTable{
    vector<int> vec;
    int size;

    public:
        hashTable(int size){
            vec = vector<int>(size, 0);
            this->size = size;
        }

        int h1(string s){
            unsigned long long int  i = 0;
            for (auto c : s){
                i += fmod(int(c),size);
            }
            return (i%size);
        }

        int h2 (string s){
            unsigned long long int i = 1;
            for (int j =0; j<s.size(); j++){
                i+= fmod((s[j]*pow(19,j-1)), size);
            }
            return (i%size);
        }
    
        int h3 (string s){
            unsigned long long int i = 7;
            for (int j = 0; j<s.size(); j++){
                i += fmod((s[j]*pow(30,j-1)), size);
            }
            return (i%size);
        }
    
        int h4(string s){
            unsigned long long  int i = 3;
            for (int j = 0; j<s.size(); j++){
                i += fmod((s[j]*pow(3,j-1)*pow(7,j-1)), size);
            }
            return (i%size);
        }


        void insert (string s) {
            int j1 = h1(s);
            int j2 = h2(s);
            int j3 = h3(s);
            int j4 = h4(s);

            vec[j1] = 1;
            vec[j2] = 1;
            vec[j3] = 1;
            vec[j4] = 1;
            return;
        }   

        string  search (string s){
            int j1 = h1(s);
            int j2 = h2(s);
            int j3 = h3(s);
            int j4 = h4(s);

            if (vec[j1] == 0 ){
                return("Element nije u tablici.");
            }
            if (vec[j2] == 0 ){
                return("Element nije u tablici.");
            }
            if (vec[j3] == 0 ){
                return("Element nije u tablici.");
            }
            if (vec[j4] == 0 ){
                return("Element nije u tablici.");
            }
            return("Element je vjerojatno u tablici.");
        }
};

int main(){
    hashTable h(100);

    vector<string> str = {
        "jopis107", "hstranput", "Matej293", "MateaCucman", "JosipCestar", 
        "lanamak", "DanijelaValjak", "filipuranjek", "domagojziros", "lsanic",
        "TomislavVinkovic", "IvoSusac", "matej2810", "KresimirSecan", 
        "inespejic", "InesSimunovic", "IvanFrantal", "Frle001", "inesstrapac", 
        "mkolak", "Dpritisa", "istvavk", "mtoldi", "lbrodar5", "mkristic", 
        "andreamatasovic", "balentovicanja", "IvanaVinkovic", "prakidzija", 
        "DMV1204", "JMesaric", "KarloKampic", "jurick1910", "LarisaDarojkovic"
    };

    for(auto i : str){
        h.insert(i);
    }

    cout << h.search("InesSimunovic") << endl;
    cout << h.search("lsanic") << endl;
    cout<< h.search("nijeutablici")<<endl;
    cout << h.search("12345") << endl; 

    return 0;
}