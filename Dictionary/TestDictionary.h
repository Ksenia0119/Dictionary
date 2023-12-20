#pragma once
#include <iostream>
# include<cassert>
#include "Dictionary.h"


using namespace std;
//������� ������� ��� ������������
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

    dict.Insert(1, "���");
    dict.Insert(2, "����");
    dict.Insert(3,"����");
    dict.Insert(4, "����");
    dict.Insert(5, "��������");
    dict.Insert(6, "�����");
    return dict;
}


// ������������ ������� � �������
void TestInsert() {
    //������� �������
    Dictionary<int, double> dict;
    //��������� ���� ����-��������
    dict.Insert(1, 23.6);
    //��������� ��� �� ����� ��������� ���������� ��������
    assert(dict.Get(1) == 23.6);
  //��������� �� ������������� ����� ����� ��������
  // ������� , ��� �������� �� ���������� �� ����
    dict.Insert(1, 100);
    assert(dict.Get(1) == 23.6);
    //��������� ������ ���� ����-��������
    dict.Insert(7, 30.9);
    dict.Insert(11, 15);
    dict.Insert(18, 2);
    dict.Insert(3, 30.9);
   
    //��������� ��������� ���������
    //�� ������ ������ ����� ��������� ���������� ��������
    assert(dict.Get(7) == 30.9);
    assert(dict.Get(11) == 15);

    assert(dict.Get(18) == 2);
    assert(dict.Get(3) == 30.9);

    cout << "���� ������� ������� " << endl;
}
// ������������ �������� � �������
void TestRemove() {
    //������� �������
    Dictionary<int, double> dict = FillDictionary();
    //��������� ������� ������
    assert(dict.Search(6) == true);
    assert(dict.Search(3) == true);
    //������� ���������� ��� ����-��������
    assert(dict.CountNode() == 6);
    //������� �����
    dict.Remove(6);
    dict.Remove(3);
    //��������� , ��� ����� ���������
    assert(dict.Search(6) == false);
    assert(dict.Search(3) == false);
    //���������, ��� ���������� ��� �����������
    assert(dict.CountNode() == 4);



    //������� �������
    Dictionary<int, string> dict1 = FillStrDictionary();
    //��������� ������� ������
    assert(dict1.Search(2) == true);
    assert(dict1.Search(1) == true);
    //������� ���������� ��� ����-��������
    assert(dict1.CountNode() == 6);
    //������� �����
    dict1.Remove(1);
    dict1.Remove(2);
    //��������� , ��� ����� ���������
    assert(dict1.Search(1) == false);
    assert(dict1.Search(2) == false);
    //���������, ��� ���������� ��� �����������
    assert(dict1.CountNode() == 4);
    cout << "���� �������� ������� " << endl;
}
// ������������ ��������� �������� �� �����
void TestGet() {
    //������� �������
    Dictionary<int, double> dict = FillDictionary();
    try {
    //��������� ��������� �������� �� ������������ ������
    assert(dict.Get(1) == 20);
    assert(dict.Get(2) == 40);
    assert(dict.Get(3) == 10.5);
    assert(dict.Get(4) == 20);
    assert(dict.Get(5) == 8.7);
    assert(dict.Get(6) == 10);

    //��������� �������� �� �������������� ������, ����� ����������
    assert(dict.Get(9) == 10);
    assert(dict.Get(23) == 67);
    assert(dict.Get(99) == 10);
    assert(dict.Get(70) == 8);


    //������� �������
    Dictionary<int, string> dict1 = FillStrDictionary();
    //��������� ��������� �������� �� ������������ ������
    assert(dict1.Get(1) == "���");
    assert(dict1.Get(2) == "����");
    assert(dict1.Get(3) == "����");
    assert(dict1.Get(4) == "����");
    assert(dict1.Get(5) == "��������");
    assert(dict1.Get(6) == "�����");

    //��������� �������� �� �������������� ������, ����� ����������
    assert(dict1.Get(9) == "���");
    assert(dict1.Get(23) == "����");
  
    }
    catch (const invalid_argument& e) {
      //  cout << e.what() << endl;
    }
    cout << "���� ��������� �������� �� ����� ������� " << endl;
}
// ������������ ������ 
void TestContains() {
    //������� �������
    Dictionary<int, double> dict = FillDictionary();
    //��������� ������� ������������ ������
    assert(dict.Search(1) == true);
    assert(dict.Search(2) == true);
    assert(dict.Search(3) == true);
    assert(dict.Search(4) == true);
    assert(dict.Search(5) == true);
    assert(dict.Search(6) == true);

    //��������� , ��� ������ ���
    assert(dict.Search(7) == false);
    assert(dict.Search(8) == false);
    assert(dict.Search(9) == false);


    //������� �������
    Dictionary<int, string> dict1 = FillStrDictionary();
    //��������� ������� ������������ ������
    assert(dict.Search(1) == true);
    assert(dict.Search(2) == true);
    assert(dict.Search(3) == true);
    assert(dict.Search(4) == true);
    assert(dict.Search(5) == true);
    assert(dict.Search(6) == true);

    //��������� , ��� ������ ���
    assert(dict.Search(17) == false);
    assert(dict.Search(18) == false);
    assert(dict.Search(19) == false);

    cout << "���� �������� ������� ������ ������� " << endl;
}
