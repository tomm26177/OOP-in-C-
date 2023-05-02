#include <iostream>
#include <string>


class WczytywanieZnaku {


public:

    char WczytajZnak()
    {
        string letter;
        cin >> letter;

        while (letter.length() != 1)
        {
            cout << endl << "Type a single letter and press <enter>: ";
            cin >> letter;
        }

        for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
            c = toupper(c);

        return letter[0];

    }
};
