#include "TStack.h"
#include "Prot.h"
const int Max_Size_String = 100;


int Prioritet(char s) // приоритет операций
{
	if (s == '(')
		return 0;
	if (s == ')')
		return 1;
	if ((s == '+') || (s == '-'))
		return 2;
	if ((s == '*') || (s == '/'))
		return 3;
	else
	{
		return -1;
	}
}


bool Sravnenie(char str, TStack A) //если приоритет пришедшешого оператора больше приоритета, оператора на вершине стека
{
	char x;
	x = A.Peek();
	if (Prioritet(x) < Prioritet(str))
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Skobka(char * str)
{
	TStack s;
	int array[Max_Size_String][2];
	int n = 0;
	int j = 0;
	int m = 1;
	int errors = 0;
	int size = strlen(str);

	for (int i = 0; i < size; i++)
	{
		if (str[i] == '(')
		{
			s.Push(m++);
		}
		if (str[i] == ')')
			if (!s.IsEmpty())
			{
				n++;
				array[j][0] = s.Pop();
				array[j++][1] = m++;
			}
			else
			{
				n++;
				array[j][0] = 0;
				array[j++][1] = m++;
				++errors;
			}
	}
	while (!s.IsEmpty())
	{
		n++;
		array[j][0] = s.Pop();
		array[j++][1] = 0;
		errors++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i][0];
		cout << " " << array[i][1] << "\n";
	}

	return errors;
}


void Preobrazovanie(char str[])
{
	int err = 0;
	char y, x;
	TStack A; //стек 
	int i = 0;
	int z = 0; // индекс для res_str
	char res_str[Max_Size_String] = "";
	bool brackets = true;
	err = Skobka(str);
	cout << "OPZ:" << endl;
	while (str[i] != '\0')
	{
		if (isdigit(str[i])) {
			cout << str[i] << " ";
			x = str[i];
			res_str[z] = x;
			z++;

		}

		if ((str[i] == '*') || (str[i] == '/') || (str[i] == '-') || (str[i] == '+')) {
			if (Sravnenie(str[i], A))
				A.Push(str[i]);
			else {
				while (!Sravnenie(str[i], A)) {
					x = A.Pop();
					cout << x << " ";
					res_str[z] = x;
					z++;
				}
				A.Push(str[i]);
			}
		}

		if ((str[i] == '('))
			A.Push(str[i]);
		if ((str[i] == ')')) {
			x = A.Peek();
			while (x != '(') {
				y = A.Pop();
				cout << y << " ";
				res_str[z] = y;
				z++;
				x = A.Peek();
			}
			if (x != '(' || A.IsEmpty()) {
				cout << "Error! " << endl;
				brackets = false;
				//break;
			}
			else {
				A.Pop();
			}
		}
		i++;
	}
	while (!A.IsEmpty()) {
		x = A.Pop();
		cout << x << " ";
		res_str[z] = x;
		z++;
	}
	if (brackets)
		Calc(res_str);
	else cout << "Error! " << endl;
}


char Operation(char str, char Op1, char Op2)
{
	char result = 0;

	if (str == '*')
	{
		result = Op1*Op2;
	}
	if (str == '/')
	{
		result = Op1 / Op2;
	}
	if (str == '+')
	{
		result = Op1 + Op2;
	}
	if (str == '-')
	{
		result = Op1 - Op2;
	}
	return result;
}



void Calc(char str[])
{
	TStack A; //числа
	int Operand1 = 0;
	int Operand2 = 0;
	char VAlue = 0;
	char LastOperation = 0;
	int Result = 0;
	bool devine = false;
	bool stack_is_empty = false;
	int result = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]))
			A.Push(str[i]);
		else {
			VAlue = NULL;
			VAlue = A.Pop();
			if ((VAlue >= '0') && (VAlue <= '9'))
				Operand2 = (int)VAlue - 48;
			else
				Operand2 = VAlue;
			if (A.IsEmpty()) {
				stack_is_empty = true;//не достаточно операндов 
				break;
			}
			else {
				VAlue = NULL;
				VAlue = A.Pop();
				if ((VAlue >= '0') && (VAlue <= '9'))
					Operand1 = (int)VAlue - 48;
				else
					Operand1 = VAlue;
				LastOperation = str[i];
				if (LastOperation == '/'&& Operand2 == 0)
				{
					devine = true;
					break;
				}
				else {
					result = Operation(LastOperation, Operand1, Operand2);
					A.Push(result);
				}
			}
		}

	}
	if (devine)
		cout << "Error! " << endl;
	else {
		if (stack_is_empty) {
			cout << "Error! " << endl;
		}
		else { cout << endl << "Resultat= " << result << endl; }
	}
}