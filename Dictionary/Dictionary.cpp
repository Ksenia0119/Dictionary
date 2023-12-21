//@author Maltseva K.V.


#include<string>
#include <iostream>
#include"Dictionary.h"
#include"TestDictionary.h"

using namespace std;
int main() {

   setlocale(LC_ALL, "ru");

   try {
       Dictionary<int, int> dict;
       dict.Insert(42, 6);
       dict.Insert(55, 12);
       dict.Insert(17, 3);
       dict.Insert(2, 3);
       dict.Insert(1, 3);
       dict.Insert(2, 4);
       dict.Remove(1);
       dict.Update(2, 5);
       dict.Update(120, 5);
       cout << "Поиск по ключу " << dict.Get(42) << endl;


       bool result = dict.Search(55);
       if (result) {
           cout << "Элемент с ключом 55 найден." << endl;
       }
       else {
           cout << "Элемент с ключом 55 не найден." << endl;
       }
       dict.PrintTreeAVL();
       cout<<"Количество пар ключ-значение = " << dict.CountNode()<<endl;

   } catch (const invalid_argument& e) {
           cout << e.what() << endl;
          }
   
   cout << "Тестирование" << endl;
   TestInsert();
   TestRemove();
   TestGet();
   TestContains();
   TestUpdate();
    return 0;
}