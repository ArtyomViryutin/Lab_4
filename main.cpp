#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Stack<int, 5> s;
	cin >> s;
	Iterator<int, 5, Stack<int, 5>> it = s.CreateIterator();
	Sep();
	for (it.begin(); !it.isDone(); it--)
	{
		cout << *it << endl;
	}
	Sep();
	it.reset();
	cout << "Проверка работы инкремента и декремента: " << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "it++:\t" << (it++).current() << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "++it:\t" << (++it).current() << endl;
	Sep();
	cout << "it:\t" << it.current() << endl;
	cout << "it--:\t" << (it--).current() << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "--it:\t" << (--it).current() << endl;
	cout << "it.begin():" << it.begin() << endl;
	cout << "it.end():" << it.end() << endl;
	Iterator<int, 5, Stack<int, 5>> it1 = s.CreateIterator();
	Sep();
	if (it == it1)
		cout << "Итераторы равны!" << endl;
	else
		cout << "Итераторы не равны!" << endl;
	it--; 
	if (it == it1)
		cout << "Итераторы равно!" << endl;
	else
		cout << "Итераторы не равны!" << endl;


	system("pause");
	return 0;
}
