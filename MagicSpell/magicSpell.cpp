#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
  /* Enter your code here */
    if(Fireball *fireball= dynamic_cast<Fireball*>(spell))
    {
        fireball->revealFirepower();
        return;
    }
    else if(Frostbite *frostbite= dynamic_cast<Frostbite*>(spell))
    {
        frostbite->revealFrostpower();
        return;
    }
    else if(Thunderstorm *thunderstorm= dynamic_cast<Thunderstorm*>(spell))
    {
        thunderstorm->revealThunderpower();
        return;
    }
    else if(Waterbolt *waterbolt= dynamic_cast<Waterbolt*>(spell))
    {
        waterbolt->revealWaterpower();
        return;
    }
    string first= SpellJournal::journal;
    string second= spell->revealScrollName();
    int len_f= first.length();
    int len_s= second.length();

    int **mat= new int*[len_f+1];
    for(int i=0; i<len_f+1; i++)
    {
        mat[i]= new int[len_s+1];
        for(int j=0; j<len_s+1; j++)
            mat[i][j]= 0;
    }        
    
    for(int i=1; i<len_f+1; i++)
    {
        for(int j=1; j<len_s+1; j++)
        {
            if(first[i-1]==second[j-1])
            {
                mat[i][j]= 1+mat[i-1][j-1];
            }
            else
            {
                mat[i][j]= mat[i-1][j]>mat[i][j-1]?mat[i-1][j]:mat[i][j-1];
            }
        }
    }
    cout<<mat[len_f][len_s]<<endl;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
