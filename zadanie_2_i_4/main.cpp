// Kolory.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <locale.h>
#include <Gracz.cpp>
#include <Kolo.cpp>
#include <Haslo.cpp>
#include <WczytywanieZnaku.cpp>
#include <TextPlayers.cpp>
#include <Kolejka.cpp>
#include <WczytywanieWyboru.cpp>




using namespace std;



 Gracz gracze[3];


 Kolejka kolejka;

 
 
 





int main()
{
    int i;
    kolejka.setKolejka(0);
    Haslo haslo; // = "wielka antarktyda";
    string proba;
    char literka;
    int n;
    int maska[100];
    int suma = 0;
    int zgadl = 0;
    int sa_spolgloski = 0;
    int kwota = 0;
    char wybor;
    srand(time(NULL));
    string rezultat;
    vector<Haslo> hasla;
    int j;

    ifstream strum;
    strum.open("dane.txt");

    setlocale(LC_CTYPE, "Polish");

    while (!strum.eof())
    {
        Haslo s;
        //strum >> s;
        getline(strum, s.getHaslo());
        //cout << s << endl;
        hasla.push_back(s);

    }

    strum.close();




    // for (i = 0; i < hasla.size(); i++)
     //    cout << hasla[i] << endl;



    for (Haslo item : hasla)
        cout << item.getHaslo() << endl;



    cout << endl << endl;

    assert(hasla.size() > 0);
    j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1
    //cout << hasla[j];

   Haslo haslo = hasla[j];
    n = haslo.size();

    gracze[0].imie = "Bryanusz";
    gracze[1].imie = "Jessica ";
    gracze[2].imie = "Nepomucen";

    for (i = 0; i < n; i++)
    {
        if (haslo.getChar(i) == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }




    do
    {
        // cout << "\033[2J";

        cout << "\033[47m" << "\033[31m";
        for (i = 0; i < n; i++)
        {

            if (maska[i] == 1)
                cout << ".";
            else
                cout << haslo.getChar(i);
        }

        cout << "\033[0m";
        cout << endl;


        sa_spolgloski = 0;
        kwota = 0;

        for (i = 0; i < n; i++)
            if (haslo.nieJestSamogloska(i) && (maska[i]))
            {
                sa_spolgloski = 1;
                break;
            }

        if (sa_spolgloski)
            cout << " -- Spolgloski sa --" << endl;


        cout << gracze[kolejka.getKolejka()].imie << " " << endl;

        TextPlayers textPlayers(gracze, kolejka);

        cout << "1. zgaduj haslo" << endl;
        cout << "2. krecenie kolem" << endl;

        // TODO tylko 1 i 2, nie mozna wprowadzac liter

        WczytywanieWyboru wczystywanieWyboru;
        wybor = wczystywanieWyboru.WczytajWybor();

        if (wybor == '1')
        {
            cout << "Podaj haslo" << endl;
            getline(cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
            for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
                c = toupper(c);
            if (haslo.equals( proba)) {
                cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
                gracze[kolejka.getKolejka()].portfel += gracze[kolejka.getKolejka()].kasa;
                break;
            }
            else
            {
                kolejka.setKolejka( (kolejka.getKolejka() + 1) % 3);
                suma = 1;
                cout << endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << endl;
                cout << endl << "=================================================" << endl;
                continue;


            }



        }
        
        Kolo Kolo;
        
        rezultat = "";
        i = rand() % 15;
        if (Kolo.getKolo(0) == 0)
            rezultat = "Strata kolejki";
        if (Kolo.getKolo(i) == -1)
            rezultat = "Bankrut";
        if (rezultat != "")
            cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
        else
        {
            cout << "\033[1;34m" << Kolo.getKolo(i) << "\033[0m" << endl;
            kwota = Kolo.getKolo(i);
        }

        // Strata kolejki i bankrut
        if ((Kolo.getKolo(i) == 0) || (Kolo.getKolo(i) == -1))
        {
            if (Kolo.getKolo(i) == -1) // bankrut
                gracze[kolejka.getKolejka()].kasa = 0;

            kolejka.setKolejka((kolejka.getKolejka() + 1) % 3);
            suma = 1;
            cout << endl << "=================================================" << endl;

            // TODO
            // sleep for
            // kupowanie samoglosek

            continue;

        }





        cout << gracze[kolejka.getKolejka()].imie << ": Podaj litere" << endl;


        WczytywanieZnaku wczytywanieznaku;
        char Literka = wczytywanieznaku.WczytajZnak();
        


        zgadl = 0;
        Haslo literka;
        literka.setHaslo(Literka);
        bool b = literka.jestSamogloska();//domyœlnie sprawdzam pierwsz¹ literkê 

        //podmieniam "Literkê" na obiekt Has³o ¿eby mieæ dostêp do metody "jest samogloska"
        if (b)
            cout << "samogloska";
        else
            cout << "spolgloska";
        cout << endl;

        for (i = 0; i < n; i++)
        {
            if ((haslo.getChar(i) == literka.getChar(0)) && (maska[i] == 1)) {
                maska[i] = 0;
                zgadl++;
            }
        }

        if (zgadl)
        {
            cout << "OK";
            gracze[kolejka.getKolejka()].kasa += kwota * zgadl;

            cout << endl << gracze[kolejka.getKolejka()].imie <<
                "\033[1;32m " << gracze[kolejka.getKolejka()].kasa << "\033[0m";


        }
        else {
            cout << "Zle!";
            // strata kolejki
            kolejka.setKolejka((kolejka.getKolejka() + 1) % 3);
            cout << endl << "=================================================" << endl;
            suma = 1;
            continue;
        }




        cout << endl;



        suma = 0;

        for (i = 0; i < n; i++)
        {
            suma += maska[i];
        }



    } while (suma);
    cout << "BRAWO!";
    exit(0);

    TextPlayers(gracze, kolejka);
    Beep(523, 500);
}