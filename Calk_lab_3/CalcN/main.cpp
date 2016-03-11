#include "TStack.h" 
#include "Prot.h"

const int Max_Size_String = 100;
int main()
{

		char str[Max_Size_String] = "";
		cout << "Vvedite virazhenie: ";
		cin >> str;
		Preobrazovanie(str);
		cout << endl;
	return 0;
}
