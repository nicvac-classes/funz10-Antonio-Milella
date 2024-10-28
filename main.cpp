#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int entraPersone(int sel, int persone);
int esciPersone(int sel, int persone);
string leggiOperazione();
int pulisciPalestra();
int resetPalestra(int capMax, int pulizia);
int usaAttrezzi();

int entraPersone(int sel, int persone) {
    int resto;
    
    resto = sel + persone;
    
    return resto;
}

int esciPersone(int sel, int persone) {
    int resto;
    
    resto = persone - sel;
    
    return resto;
}

string leggiOperazione() {
    string comando;
    bool controllo;
    
    cout << "Inserire un operazione tra i seguenti valori: P E U A R X" << endl;
    do {
        cin >> comando;
        controllo = comando != "P" && comando != "E" && comando != "U" && comando != "A" && comando != "R" && comando != "X";
        if (controllo) {
            cout << "Devi inserire un operazione tra i seguenti valori: P E U A R X" << endl;
        }
    } while (controllo);
    
    return comando;
}

int pulisciPalestra() {
    int pulito;
    
    pulito = 10;
    
    return pulito;
}

int resetPalestra(int capMax, int pulizia) {
    int persone;
    
    persone = 0;
    
    return persone;
}

int usaAttrezzi() {
    int sporco;
    
    sporco = rand() % 101;
    
    return sporco;
}

int main() {
    int capMax, pulizia, persone, sel;
    string comando;
    
    cout << "Benvenuto nel pannello di controllo della Palestra." << endl;
    cout << "Inserisci la capienza massima di persone che possono entrare nella palestra: " << endl;
    cin >> capMax;
    cout << "Inserisci il livello di pulizia dalla quale iniziare: " << endl;
    cin >> pulizia;
    persone = resetPalestra(capMax, pulizia);
    comando = leggiOperazione();
    while (comando != "X") {
        if (comando == "E") {
            cout << "Inserisci il numero di persone che vuoi far entrare: " << endl;
            cin >> sel;
            persone = entraPersone(sel, persone);
            if (persone > capMax) {
                cout << "Il numero di persone che hai scelto di far entrare vanno oltre la capienza massima. In palestra ci sono " << persone - capMax << " persone." << endl;
                persone = capMax;
            }
            cout << "Persone: " << persone << "/" << capMax << ". Lv Pulizia: " << pulizia << "%" << endl;
        } else {
            if (comando == "U") {
                cout << "Inserisci il numero di persone che vuoi far uscire: " << endl;
                cin >> sel;
                persone = esciPersone(sel, persone);
                if (persone < 0) {
                    cout << "Il numero di persone che hai scelto di far uscire vanno oltre la quantità di persone che erano già presenti." << endl;
                    persone = 0;
                }
                cout << "Persone: " << persone << "/" << capMax << ". Lv Pulizia: " << pulizia << "%" << endl;
            } else {
                if (comando == "P") {
                    pulizia = pulizia + pulisciPalestra();
                    cout << "Palestra pulita con successo. Livello pulizia: " << pulizia << "%" << endl;
                } else {
                    if (comando == "A") {
                        pulizia = (int) (pulizia * ((double) usaAttrezzi() / 100));
                        cout << "Hanno usato molti attrezzi. [" << usaAttrezzi() << "%] Livello pulizia: " << pulizia << endl;
                    } else {
                        if (comando == "R") {
                            cout << "Hai deciso di resettare la palestra, inserisci la capienza massima di persone ospitabili in palestra: " << endl;
                            cin >> capMax;
                            cout << "Inserisci il livello di pulizia dalla quale iniziare: " << endl;
                            cin >> pulizia;
                            persone = resetPalestra(capMax, pulizia);
                        }
                    }
                }
            }
        }
        comando = leggiOperazione();
    }
    cout << "Sei uscito dal programma con successo" << endl;
    return 0;
}

