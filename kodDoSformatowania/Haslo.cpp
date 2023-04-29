class Haslo {
	public
	string Haslo;
	

public:
	string getHaslo() {
		return Haslo;
	}

	void setHaslo(String s) {
		Haslo = s;
	}


	int jestSamogloska(int i)
	{
		char c = Haslo[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
			return 1;
		else
			return 0;

	}
	int jestSamogloska()
	{
		char c = Haslo[0];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
			return 1;
		else
			return 0;

	}

	int nieJestSamogloska(int i)
	{
		char c = Haslo[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
			return 0;
		else
			return 1;

	}

	int nieJestSamogloska()
	{
		char c = Haslo[0];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
			return 0;
		else
			return 1;

	}

	char getChar(int i) {

		return Haslo[i];
	}

	int size() {
		int i = 0;
		 char c = Haslo[0];
		 while (c != 0) {
			 c = Haslo[i++];
			 
		}
		 return i;
	}
	bool equals(string s) {
		return Haslo == s;
	   }


};