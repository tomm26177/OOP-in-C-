#include <iostream>

class Kolo {
public:
	int Kolo[16] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
	// -1 bankrut
    // 0 strata kolejki
public:
	int getKolo(int i) {
		return Kolo[i];
	}


};
