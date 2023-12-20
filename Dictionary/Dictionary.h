#pragma once
//@author Maltseva K.V.

#include "AVLTree.h"

//Пара ключ-значение
template<class K, class T>
class KeyValue {
protected:
    //ключ
	 K key;
public:
    //значение
	T value;
    //Конструктор по умолчанию 
    KeyValue() : key(), value() {} 
    //Конструктор с параметрами
    KeyValue(const K& key, const T& value) : key(key), value(value) {}
   
    //Перегрузка оператора присваивания
    KeyValue<K, T>& operator=(const KeyValue<K, T>& other) {
        //проверка на самоприсваивание
        if (this != &other) {
            // Присваивание значения ключа и значения из другого объекта
            key = other.key;
            value = other.value;
        }
        // Возвращаем текущий объект
        return *this;
    }
    //Перегрузка оператора сравнения
    bool operator==(const KeyValue<K, T>& other) const {
        //сравниваем ключ текущего объекта с ключом другого объекта 
        // true, если ключи равны
        return key == other.key ;
    }

    //Перегрузка оператора меньше
    bool operator<(const KeyValue<K, T>& other) const {
        //сравниваем ключ текущего объекта с ключом другого объекта 
       // true, если ключ текущего меньше
        return key < other.key;
    }
   
    //Перегрузка оператора больше
    bool operator>(const KeyValue<K, T>& other) const {
        //сравниваем ключ текущего объекта с ключом другого объекта 
       // true, если ключ текущего больше
        return key > other.key;
    }


    //Получить ключ
	K getkey() const
    {
        return key;
    };
    // Перегрузка оператора вывода << для вывода обектов словаря через cout
    friend ostream& operator<<(ostream& os, const KeyValue<K, T>& keyValue) {
        os << "Ключ: ";
        if (keyValue.key < 10) {
            os << "\t";
        }
        os << keyValue.key << "\tЗначение: " << keyValue.value;
        return os;
    }
};
//Словарь, построенный по принципу AVL дерева
template<class K, class T>
class Dictionary :public AVLTree<KeyValue<K, T>> {

public:
   //вставка новой пары в дерево
    void Insert(const K& key, const T& value) {
        //создается объект KeyValue<K, T> с переданными ключом и значением
        KeyValue<K, T> keyValue(key, value);
        //вызывается вставкаа из базового класса
        AVLTree<KeyValue<K, T>>::Insert(keyValue);
    }

  
    //удаление ключа из дерева
    void Remove(const K& key) {
        //Создается объект KeyValue<K, T> с переданным ключом и пустым значением
        KeyValue<K, T> keyValue(key, T());
        //вызывается удаление из базового класса
        AVLTree<KeyValue<K, T>>::Remove(keyValue);
    }
    //получение значения по ключу
    T Get(const K& key) {
        //вызываем метод базового класса для поиска
        AVLTreeNode<KeyValue<K, T>>* node = AVLTree<KeyValue<K, T>>::Find(KeyValue<K, T>(key, T()));
        //узел найден, его значение возвращается
        if (node != nullptr) {
            return node->data.value;
        }
        //узел не найден, выбрасывается исключение
        throw  invalid_argument("Ключ не найден");
        return T(); 
    }
    //поиск элемента по ключу
    bool Search(const K& key) {
        //Создается объект KeyValue<K, T> с переданным ключом и пустым значением
        KeyValue<K, T> keyValue(key, T());
        //вызываем метод базового класса для поиска
        return AVLTree<KeyValue<K, T>>::Find(keyValue) != nullptr;
    }
    //печать 
    void PrintTreeAVL() {
        //вызываем метод базового класса для печати 
        PrintTree(AVLTree<KeyValue<K, T>>::GetRoot(), 0);
    }

    //подсчет узлов дерева
    int CountNode() {
        //вызываем метод базового класса для печати
       return CountNodes(AVLTree<KeyValue<K, T>>::GetRoot());
    }



    //template<class K, class T>
  //void Update(const K& key, const T& value) {
  //    KeyValue<K, T> keyValue(key, value);
  //    AVLTreeNode < KeyValue < K, T>>* node = AVLTree < KeyValue < K, T>>::Find(keyValue);
  //    if (node != nullptr) {
  //        node->data.value = value; // Заменяем значение существующего элемента
  //       
  //    }
  //   
  //}

};