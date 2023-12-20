#pragma once
#include <iostream>
# include<cassert>
#include "Dictionary.h"


using namespace std;
//Создаем словари для тестирования
Dictionary<int, double> FillDictionary() {
    Dictionary<int, double> dict;

    dict.Insert(1, 20);
    dict.Insert(2, 40);
    dict.Insert(3, 10.5);
    dict.Insert(4, 20);
    dict.Insert(5, 8.7);
    dict.Insert(6, 10);
    return dict;
}
Dictionary<int,string> FillStrDictionary() {
    Dictionary<int, string> dict;

    dict.Insert(1, "Аня");
    dict.Insert(2, "Ваня");
    dict.Insert(3,"Толя");
    dict.Insert(4, "Коля");
    dict.Insert(5, "Антонина");
    dict.Insert(6, "Настя");
    return dict;
}


// Тестирование вставки в словарь
void TestInsert() {
    //Создаем словарь
    Dictionary<int, double> dict;
    //Вставляем пару ключ-значение
    dict.Insert(1, 23.6);
    //Проверяем что по ключу находится ожиддаемое значение
    assert(dict.Get(1) == 23.6);
  //Вставляем по существующему ключу новое значение
  // Ожидаем , что значение не поменяется на ноое
    dict.Insert(1, 100);
    assert(dict.Get(1) == 23.6);
    //Добавляем другие пары ключ-значение
    dict.Insert(7, 30.9);
    dict.Insert(11, 15);
    dict.Insert(18, 2);
    dict.Insert(3, 30.9);
   
    //Проверяем ожидаемый результат
    //По разным ключам может находится одинаковое значение
    assert(dict.Get(7) == 30.9);
    assert(dict.Get(11) == 15);

    assert(dict.Get(18) == 2);
    assert(dict.Get(3) == 30.9);

    cout << "Тест вставки пройден " << endl;
}
// Тестирование удаления в словарь
void TestRemove() {
    //Создаем словарь
    Dictionary<int, double> dict = FillDictionary();
    //Проверяем наличие ключей
    assert(dict.Search(6) == true);
    assert(dict.Search(3) == true);
    //Считаем количество пар ключ-значение
    assert(dict.CountNode() == 6);
    //Удаляем ключи
    dict.Remove(6);
    dict.Remove(3);
    //Проверяем , что ключи удалились
    assert(dict.Search(6) == false);
    assert(dict.Search(3) == false);
    //Проверяем, что количество пар уменьшилось
    assert(dict.CountNode() == 4);



    //Создаем словарь
    Dictionary<int, string> dict1 = FillStrDictionary();
    //Проверяем наличие ключей
    assert(dict1.Search(2) == true);
    assert(dict1.Search(1) == true);
    //Считаем количество пар ключ-значение
    assert(dict1.CountNode() == 6);
    //Удаляем ключи
    dict1.Remove(1);
    dict1.Remove(2);
    //Проверяем , что ключи удалились
    assert(dict1.Search(1) == false);
    assert(dict1.Search(2) == false);
    //Проверяем, что количество пар уменьшилось
    assert(dict1.CountNode() == 4);
    cout << "Тест удаления пройден " << endl;
}
// Тестирование получения значения по ключу
void TestGet() {
    //Создаем словарь
    Dictionary<int, double> dict = FillDictionary();
    try {
    //Проверяем ожидаемые значения по существующим ключам
    assert(dict.Get(1) == 20);
    assert(dict.Get(2) == 40);
    assert(dict.Get(3) == 10.5);
    assert(dict.Get(4) == 20);
    assert(dict.Get(5) == 8.7);
    assert(dict.Get(6) == 10);

    //Проверяем значения по несуществующим ключам, ловим исключения
    assert(dict.Get(9) == 10);
    assert(dict.Get(23) == 67);
    assert(dict.Get(99) == 10);
    assert(dict.Get(70) == 8);


    //Создаем словарь
    Dictionary<int, string> dict1 = FillStrDictionary();
    //Проверяем ожидаемые значения по существующим ключам
    assert(dict1.Get(1) == "Аня");
    assert(dict1.Get(2) == "Ваня");
    assert(dict1.Get(3) == "Толя");
    assert(dict1.Get(4) == "Коля");
    assert(dict1.Get(5) == "Антонина");
    assert(dict1.Get(6) == "Настя");

    //Проверяем значения по несуществующим ключам, ловим исключения
    assert(dict1.Get(9) == "Оля");
    assert(dict1.Get(23) == "Вася");
  
    }
    catch (const invalid_argument& e) {
      //  cout << e.what() << endl;
    }
    cout << "Тест получения значения по ключу пройден " << endl;
}
// Тестирование поиска 
void TestContains() {
    //Создаем словарь
    Dictionary<int, double> dict = FillDictionary();
    //Проверяем наличие существующих ключей
    assert(dict.Search(1) == true);
    assert(dict.Search(2) == true);
    assert(dict.Search(3) == true);
    assert(dict.Search(4) == true);
    assert(dict.Search(5) == true);
    assert(dict.Search(6) == true);

    //Проверяем , что ключей нет
    assert(dict.Search(7) == false);
    assert(dict.Search(8) == false);
    assert(dict.Search(9) == false);


    //Создаем словарь
    Dictionary<int, string> dict1 = FillStrDictionary();
    //Проверяем наличие существующих ключей
    assert(dict.Search(1) == true);
    assert(dict.Search(2) == true);
    assert(dict.Search(3) == true);
    assert(dict.Search(4) == true);
    assert(dict.Search(5) == true);
    assert(dict.Search(6) == true);

    //Проверяем , что ключей нет
    assert(dict.Search(17) == false);
    assert(dict.Search(18) == false);
    assert(dict.Search(19) == false);

    cout << "Тест проверки наличия ключей пройден " << endl;
}
