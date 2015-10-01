/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 30 Сентябрь 2015 г., 21:06
 */

#include <iostream>
#include <fstream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
using namespace std;

int main(int argc, char *argv[]) {
	ifstream stream(argv[1]);
	int n, sum, t;
	
	list<int> myList;
B:
	while (stream >> n) {
		
		while (n != 1) {
			myList.push_back(n);
			sum = 0;
			
			while (n) {
				t = n%10;
				sum += t*t;
				n /= 10;
			}
			for (list<int>::iterator it=myList.begin(); it != myList.end(); ++it) {
				if (*it == sum) {
					myList.clear();
					cout << 0 << endl;
					goto B;
				}
			}
			
			myList.push_back(sum);
			// cout << ' ' << *it;
			// сравнить с прошлыми sum и добавить новый
			
			n = sum;
		}
		
		myList.clear();
		cout << n << endl;
	}
	
//	list<int> myList; // объявляем пустой список
//	for(int i = 0; i < 11; i++) {
//		myList.push_back(i); // добавляем в список новые элементы
//	}
//
//	cout << "Список: ";
//	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," ")); // вывод на экран элементов списка
//	cout << "\nПервый элемент списка: " << myList.front();
//	cout << "\nПоследний элемент списка: " << myList.back();
	
	return 0;
}