#include <iostream>
#include "Node.h"
#include "DList_Iterator.h"
#include "DList_Reverse_Iterator.h"
#include "Doubly_Linked_List.h"

using namespace std;

int main()
{

    int n;
    cout << "Moi nhap so phan tu: ";
    cin >> n;

    Doubly_Linked_List<int> list;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Moi nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        list.push_back(x);
    }

    cout << "Danh sach vua nhap: ";
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Danh sach sau khi sap xep tang dan: ";
    list.sort([](int a, int b)
              { return a < b; });
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Danh sach sau khi sap xep giam dan: ";
    list.sort([](int a, int b)
              { return a > b; });
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}