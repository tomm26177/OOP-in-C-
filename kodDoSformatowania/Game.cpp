class Game {
public:
    int n;
    string haslo;
    int maska[100];
    int kolejka;
    int suma;
    int sa_spolgloski;
    int kwota;
    vector<string> hasla;
    char wybor;
    char literka;
    string proba;
    int zgadl;
    ifstream strum;
    string rezultat;
    Player gracze[3];
    static const int Kolo[15];
    void WczytajHasla() {
        strum.open("dane.txt");
        setlocale(LC_CTYPE, "Polish");
        while (!strum.eof()) {
            string s;
            getline(strum, s);
            hasla.push_back(s);
        }
        strum.close();
        assert(hasla.size() > 0);
    }
    void Inicjuj() {
        srand(time(NULL));
        WczytajHasla();
        int j = rand() % hasla.size();
        haslo = hasla[j];
        n = haslo.size();
        for (int i = 0; i < n; i++) {
            if (haslo[i] == ' ')
                maska[i] = 0;
            else
                maska[i] = 1;
        }
        gracze[0].imie = "Bryanusz";
        gracze[1].imie = "Jessica";
        gracze[2].imie = "Nepomucen";
    }
    void textPlayers() {
        cout << "Gracze i stan kont:" << endl;
        for (int i = 0; i < 3; i++)
            cout << gracze[i].imie << " " << gracze[i].portfel << endl;
    }
    void Play() {
        Inicjuj();
        kolejka = 0;
        suma = 0;
        while (1) {
            cout << "\033[2J";
            cout << "\033[47m" << "\033[31m";
            for (int i = 0; i < n; i++) {
                if (maska[i] == 1)
                    cout << ".";
                else
                    cout << haslo[i];
            }
            cout << "\033[0m";
            cout << endl;
            sa_spolgloski = 0;
            kwota = 0;
            for (int i = 0; i < n; i++)
                if ((!jestSamogloska(haslo[i])) && (maska[i])) {
                    sa_spolgloski = 1;
                    break;
                }
            if (sa_spolgloski)
                cout << " -- Spolgloski sa --" << endl;
            textPlayers();
            cout << "1. zgaduj haslo" << endl;
            cout << "2. krecenie kolem" << endl;
            wybor = WczytajWybor();
            if (wybor == '1') {
                cout << "Podaj haslo" << endl;
                getline(cin >> ws, proba);
                for (auto& c : proba)
                    c = toupper(c);
                if (haslo == proba) {
                    cout <<

                        "Wygrales! Haslo to: " << haslo << endl;
                    gracze[kolejka].portfel += suma;
                    textPlayers();
                    break;
                }
                else {
                    cout << "Nieprawidlowe haslo" << endl;
                    gracze[kolejka].portfel -= 500;
                    textPlayers();
                }
            }
            else {
                cout << "Kręcę kołem" << endl;
                int los = rand() % 15;
                cout << "Wylosowana wartość: " << Kolo[los] << endl;
                if (Kolo[los] == 0) {
                    cout << "Bankrut! Tracisz swoją sumę" << endl;
                    gracze[kolejka].portfel = 0;
                    suma = 0;
                    kolejka = (kolejka + 1) % 3;
                }
                else if (Kolo[los] == -1) {
                    cout << "Porażka! Kolejka przepada." << endl;
                    kolejka = (kolejka + 1) % 3;
                }
                else {
                    cout << "Wybierz literę" << endl;
                    literka = WczytajLiterke();
                    int ile = 0;
                    for (int i = 0; i < n; i++) {
                        if (haslo[i] == literka) {
                            maska[i] = 0;
                            ile++;
                        }
                    }
                    if (ile == 0) {
                        cout << "Nie ma takiej litery" << endl;
                        kolejka = (kolejka + 1) % 3;
                    }
                    else {
                        kwota = Kolo[los] * ile;
                        suma += kwota;
                        cout << "Wygrałeś: " << kwota << endl;
                        cout << "Suma: " << suma << endl;
                        zgadl = 0;
                        for (int i = 0; i < n; i++)
                            if (maska[i] == 1) {
                                zgadl = 1;
                                break;
                            }
                        if (zgadl == 0) {
                            cout << "Wygrał " << gracze[kolejka].imie << endl;
                            gracze[kolejka].portfel += suma;
                            textPlayers();
                            break;
                        }
                        else {
                            kolejka = (kolejka + 1) % 3;
                        }
                    }
                }
            }
        }
    }
    char WczytajWybor() {
        char wybor;
        cout << "Twój wybór: ";
        while (1) {
            cin >> wybor;
            if ((wybor == '1') || (wybor == '2'))
                return wybor;
            cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    }
    char WczytajLiterke() {
        char literka;
        cout << "Podaj literę: ";
        while (1) {
            cin >> literka;
            if (isalpha(literka))
                return toupper(literka);
            cout << "Nieprawidłowa litera. Spróbuj ponownie." << endl;
        }
    }
};
