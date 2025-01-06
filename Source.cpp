#include "GAI.h"

int main()
{
	setlocale(LC_ALL, "rus");
	GAI base;
	string offence;
	int number, choise, end, begin;
	enum MENU {
		EXIT = 0,
		ADD,
		PRINT,
		SEARCH,
		PRINT_RANGE
	};

	cout << "1 - ��������\n2 - ����� ��� ���� ���\n3 - ����� �� ����\n4 - ����� � ���������\n";

	do
	{
		try
		{
			cin >> choise;
			switch (choise)
			{
			case ADD:
				cout << "������� ����� ����: ";
				cin >> number;
				cout << "������� ��������������: ";
				cin >> offence;
				base.Add(number, offence);
				break;
			case PRINT:
				cout << "\n���� ������ ���\n\n";
				base.print(base.getRoot());
				cout << "---------------\n";
				break;
			case SEARCH:
				cout << "������� ����� ��� ������: ";
				cin >> number;
				cout << *base.Search(base.getRoot(), number);
				break;
			case PRINT_RANGE:
				cout << "������� ������ ��� �������: ";
				cin >> begin;
				cout << "������� ����� ��� �������: ";
				cin >> end;
				base.print_range(base.getRoot(), begin, end);
				break;
			}
		}
		catch (const underflow_error& exc)
		{
			cout << exc.what();
		}
	} while (choise != 0);

	return 0;
}