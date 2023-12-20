#pragma once
//@author Maltseva K.V.

#include "AVLTree.h"

//���� ����-��������
template<class K, class T>
class KeyValue {
protected:
    //����
	 K key;
public:
    //��������
	T value;
    //����������� �� ��������� 
    KeyValue() : key(), value() {} 
    //����������� � �����������
    KeyValue(const K& key, const T& value) : key(key), value(value) {}
   
    //���������� ��������� ������������
    KeyValue<K, T>& operator=(const KeyValue<K, T>& other) {
        //�������� �� ����������������
        if (this != &other) {
            // ������������ �������� ����� � �������� �� ������� �������
            key = other.key;
            value = other.value;
        }
        // ���������� ������� ������
        return *this;
    }
    //���������� ��������� ���������
    bool operator==(const KeyValue<K, T>& other) const {
        //���������� ���� �������� ������� � ������ ������� ������� 
        // true, ���� ����� �����
        return key == other.key ;
    }

    //���������� ��������� ������
    bool operator<(const KeyValue<K, T>& other) const {
        //���������� ���� �������� ������� � ������ ������� ������� 
       // true, ���� ���� �������� ������
        return key < other.key;
    }
   
    //���������� ��������� ������
    bool operator>(const KeyValue<K, T>& other) const {
        //���������� ���� �������� ������� � ������ ������� ������� 
       // true, ���� ���� �������� ������
        return key > other.key;
    }


    //�������� ����
	K getkey() const
    {
        return key;
    };
    // ���������� ��������� ������ << ��� ������ ������� ������� ����� cout
    friend ostream& operator<<(ostream& os, const KeyValue<K, T>& keyValue) {
        os << "����: ";
        if (keyValue.key < 10) {
            os << "\t";
        }
        os << keyValue.key << "\t��������: " << keyValue.value;
        return os;
    }
};
//�������, ����������� �� �������� AVL ������
template<class K, class T>
class Dictionary :public AVLTree<KeyValue<K, T>> {

public:
   //������� ����� ���� � ������
    void Insert(const K& key, const T& value) {
        //��������� ������ KeyValue<K, T> � ����������� ������ � ���������
        KeyValue<K, T> keyValue(key, value);
        //���������� �������� �� �������� ������
        AVLTree<KeyValue<K, T>>::Insert(keyValue);
    }

  
    //�������� ����� �� ������
    void Remove(const K& key) {
        //��������� ������ KeyValue<K, T> � ���������� ������ � ������ ���������
        KeyValue<K, T> keyValue(key, T());
        //���������� �������� �� �������� ������
        AVLTree<KeyValue<K, T>>::Remove(keyValue);
    }
    //��������� �������� �� �����
    T Get(const K& key) {
        //�������� ����� �������� ������ ��� ������
        AVLTreeNode<KeyValue<K, T>>* node = AVLTree<KeyValue<K, T>>::Find(KeyValue<K, T>(key, T()));
        //���� ������, ��� �������� ������������
        if (node != nullptr) {
            return node->data.value;
        }
        //���� �� ������, ������������� ����������
        throw  invalid_argument("���� �� ������");
        return T(); 
    }
    //����� �������� �� �����
    bool Search(const K& key) {
        //��������� ������ KeyValue<K, T> � ���������� ������ � ������ ���������
        KeyValue<K, T> keyValue(key, T());
        //�������� ����� �������� ������ ��� ������
        return AVLTree<KeyValue<K, T>>::Find(keyValue) != nullptr;
    }
    //������ 
    void PrintTreeAVL() {
        //�������� ����� �������� ������ ��� ������ 
        PrintTree(AVLTree<KeyValue<K, T>>::GetRoot(), 0);
    }

    //������� ����� ������
    int CountNode() {
        //�������� ����� �������� ������ ��� ������
       return CountNodes(AVLTree<KeyValue<K, T>>::GetRoot());
    }



    //template<class K, class T>
  //void Update(const K& key, const T& value) {
  //    KeyValue<K, T> keyValue(key, value);
  //    AVLTreeNode < KeyValue < K, T>>* node = AVLTree < KeyValue < K, T>>::Find(keyValue);
  //    if (node != nullptr) {
  //        node->data.value = value; // �������� �������� ������������� ��������
  //       
  //    }
  //   
  //}

};