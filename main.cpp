#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Stack<int, 5> s;
	cin >> s;
	Iterator<int, 5, Stack<int, 5>> it = s.CreateIterator();
	cout << "Вывод с помощью оператора вывода:" << endl;
	cout << s;
	Sep();
	//s.Pop();
	//it.reset();
	cout << "Вывод с помощью итератора:" << endl;
	for (it.end(); !it.isDone(); it--)
	{
		cout << *it << endl;
	}
	Sep();
	it.reset();
	cout << "Проверка работы декремента: " << endl;
	cout << "it.end():" << it.end() << endl;
	cout << "\tАдрес" << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "it--:\t" << (it--).current() << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "--it:\t" << (--it).current() << endl;
	Sep();
	cout << "Проверка работы инкремента: " << endl;
	cout << "\tАдрес" << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "it++:\t" << (it++).current() << endl;
	cout << "it:\t" << it.current() << endl;
	cout << "++it:\t" << (++it).current() << endl;
	Sep();
	Iterator<int, 5, Stack<int, 5>> it1 = s.CreateIterator();
	cout << "Первый итератор: " << it.current() << endl;
	cout << "Второй итератор: " << it1.current() << endl;
	if (it == it1)
		cout << "Итераторы равны!" << endl;
	else
		cout << "Итераторы не равны!" << endl;
	cout << "Первый итератор: " << it.current() << endl;
	cout << "Второй итератор: " << it1.current() << endl;
	cout << "*Операция декремента*" << endl;
	it--; 
	cout << "Первый итератор: " << it.current() << endl;
	cout << "Второй итератор: " << it1.current() << endl;
	if (it != it1)
		cout << "Итераторы не равны!" << endl;
	else
		cout << "Итераторы равны!" << endl;


	system("pause");
	return 0;
}
