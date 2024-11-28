#ifndef ROOMSERVICE_H
#define ROOMSERVICE_H
#include <bits/stdc++.h>

using namespace std;

class RoomService
{
private:
    vector<Room> rooms;
    string fileName;

public:
    RoomService(string fileName);
    void showHeader();
    void display();
    void add();
    void remove();
    void update();
    void sortByName();
    void sortBySize();
    void showByType();
    Room *searchById(int id);
    Room *searchByName(string name);
    void searchBySize();
    void removeAll();
    void readFromFile();
    void writeToFile();
    void menu();
    void run();
};

void RoomService::menu()
{
    cout << "========================PHONG_HOC_CRUD============================" << endl;
    cout << "==                                                              ==" << endl;
    cout << "==     1. Them phong.                                           ==" << endl;
    cout << "==     2. Xoa phong                                             ==" << endl;
    cout << "==     3. Cap nhat phong                                        ==" << endl;
    cout << "==     4. Hien danh sach phong                                  ==" << endl;
    cout << "==     5. Hien thi phong sap xep theo (Ten, Suc chua)           ==" << endl;
    cout << "==     6. Hien thi theo loai phong (Hoc, Thuc Hanh, Hoi Truong) ==" << endl;
    cout << "==     7. Tim kiem theo (ID, Ten)                               ==" << endl;
    cout << "==     8. Tim phong theo suc chua                               ==" << endl;
    cout << "==     9. Xoa tat ca cac phong                                  ==" << endl;
    cout << "==     10. Lay du lieu tu file                                  ==" << endl;
    cout << "==     11. Luu du lieu vao file                                 ==" << endl;
    cout << "==     12. Hien thi MENU                                        ==" << endl;
    cout << "==     0. Thoat                                                 ==" << endl;
    cout << "==                                                              ==" << endl;
    cout << "===========================END_CRUD===============================" << endl;
}

void RoomService::run()
{
    menu();
    int option;
    do
    {
        cout << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            add();
            break;
        case 2:
            remove();
            break;
        case 3:
            update();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "1. Sap xep theo ten" << endl;
            cout << "2. Sap xep theo suc chua" << endl;
            int sortOption;
            cout << "Nhap lua chon cua ban(1,2): ";
            cin >> sortOption;
            if (sortOption == 1)
            {
                sortByName();
            }
            else if (sortOption == 2)
            {
                sortBySize();
            }
            break;
        case 6:
            showByType();
            break;
        case 7:
            cout << "1. Tim theo ID" << endl;
            cout << "2. Tim theo ten" << endl;
            int searchOption;
            cout << "Nhap lua chon cua ban(1,2): ";
            cin >> searchOption;
            if (searchOption == 1)
            {
                int id;
                cout << "Nhap ID can tim: ";
                cin >> id;
                Room *room = searchById(id);
                if (room != NULL)
                {
                    showHeader();
                    cout << *room << endl;
                    cout << "=========================================================" << endl;
                }
                else
                {
                    cout << "Khong tim thay phong co ID = " << id << endl;
                }
            }
            else if (searchOption == 2)
            {
                string name;
                cout << "Nhap ten can tim: ";
                cin.ignore();
                getline(cin, name);
                Room *room = searchByName(name);
                if (room != NULL)
                {
                    showHeader();
                    cout << *room << endl;
                    cout << "=========================================================" << endl;
                }
                else
                {
                    cout << "Khong tim thay phong co ten = " << name << endl;
                }
            }
            break;
        case 8:
            searchBySize();
            break;
        case 9:
            removeAll();
            break;
        case 10:
            readFromFile();
            break;
        case 11:
            writeToFile();
            break;
        case 12:
            menu();
            break;
        case 0:
            cout << "Cam on ban da su dung dich vu cua chung toi!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
        cout << endl;
    } while (option != 0);
}

RoomService::RoomService(string fileName)
{
    this->fileName = fileName;
    ifstream file(fileName);
    if (file.is_open())
    {
        int n;
        file >> n;
        for (int i = 0; i < n; i++)
        {
            int id;
            string name;
            int floor;
            RoomType type;
            int size;
            file >> id;
            file.ignore();
            getline(file, name);
            file >> floor;
            int option;
            RoomType types[3] = {RoomType::CLASSROOM, RoomType::LAB, RoomType::AUDITORIUM};
            file >> option;
            type = types[option];
            file >> size;
            Room room(id, name, floor, type, size);
            rooms.push_back(room);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << fileName << endl;
        exit(1);
    }
}

void RoomService::showHeader()
{
    cout << endl;
    cout << "====================DANH_SACH_PHONG======================" << endl;
    cout << left << setw(6) << "ID" << setw(12) << "Ten" << setw(10) << "Tang" << setw(15) << "Loai phong" << setw(10) << "Suc chua" << endl;
    cout << "=========================================================" << endl;
}

void RoomService::display()
{
    showHeader();
    for (const auto &room : rooms)
    {
        cout << room << endl;
    }
    cout << "=========================================================" << endl;
}

void RoomService::add()
{
    Room newRoom;
    cin >> newRoom;
    for (const auto &room : rooms)
    {
        if (room.getId() == newRoom.getId())
        {
            cout << "Phong da ton tai!" << endl;
            return;
        }
    }
    rooms.push_back(newRoom);
    cout << "Them phong thanh cong!" << endl;
}

void RoomService::remove()
{
    int id;
    cout << "Nhap ID cua phong can xoa: ";
    cin >> id;

    for (auto it = rooms.begin(); it != rooms.end(); it++)
    {
        if (it->getId() == id)
        {
            rooms.erase(it);
            cout << "Xoa phong thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay phong co ID = " << id << endl;
}

void RoomService::update()
{
    int id;
    cout << "Nhap ID cua phong can cap nhat: ";
    cin >> id;
    cin.ignore();
    for (auto &room : rooms)
    {
        if (room.getId() == id)
        {
            cout << "Nhap thong tin moi cho phong: " << endl;
            cin >> room;
            cout << "Cap nhat phong thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay phong co ID = " << id << endl;
}

void RoomService::sortByName()
{
    sort(rooms.begin(), rooms.end(), [](const Room &a, const Room &b)
         { return a.getName() < b.getName(); });
    display();
}

void RoomService::sortBySize()
{
    sort(rooms.begin(), rooms.end(), [](const Room &a, const Room &b)
         { return a.getSize() < b.getSize(); });
    display();
}

void RoomService::showByType()
{
    cout << "Chon loai phong can hien thi: " << endl;
    cout << "0. Phong hoc" << endl;
    cout << "1. Phong lab" << endl;
    cout << "2. Hoi truong" << endl;
    cout << "Nhap lua chon cua ban(0,1,2): ";
    int option;
    cin >> option;
    RoomType types[3] = {RoomType::CLASSROOM, RoomType::LAB, RoomType::AUDITORIUM};
    while (option < 0 || option > 2)
    {
        cout << "Nhap lai: ";
        cin >> option;
    }
    RoomType type = types[option];
    showHeader();
    for (const auto &room : rooms)
    {
        if (room.getType() == type)
        {
            cout << room << endl;
        }
    }
    cout << "=========================================================" << endl;
}

Room *RoomService::searchById(int id)
{
    for (auto &room : rooms)
    {
        if (room.getId() == id)
        {
            return &room;
        }
    }
    return NULL;
}

Room *RoomService::searchByName(string name)
{
    for (auto &room : rooms)
    {
        if (room.getName() == name)
        {
            return &room;
        }
    }
    return NULL;
}

void RoomService::searchBySize()
{
    int size;
    cout << "Tim kiem phong co suc chua lon hon hoac bang: ";
    cin >> size;
    showHeader();
    for (const auto &room : rooms)
    {
        if (room.getSize() >= size)
        {
            cout << room << endl;
        }
    }
    cout << "=========================================================" << endl;
}

void RoomService::removeAll()
{
    cout << "Ban co chac muon xoa " << rooms.size() << " phong?" << endl;
    cout << "1. Xoa" << endl;
    cout << "2. Huy" << endl;
    cout << "Nhap lua chon cua ban(1,2): ";
    int option;
    cin >> option;
    if (option == 2)
        return;
    rooms.clear();
    cout << "Xoa tat ca cac phong thanh cong!" << endl;
}

void RoomService::readFromFile()
{
    ifstream file(fileName);
    if (file.is_open())
    {
        int n;
        file >> n;
        rooms.clear();
        for (int i = 0; i < n; i++)
        {
            int id;
            string name;
            int floor;
            RoomType type;
            int size;
            file >> id;
            file.ignore();
            getline(file, name);
            file >> floor;
            int option;
            RoomType types[3] = {RoomType::CLASSROOM, RoomType::LAB, RoomType::AUDITORIUM};
            file >> option;
            type = types[option];
            file >> size;
            Room room(id, name, floor, type, size);
            rooms.push_back(room);
        }
        file.close();
        cout << "Doc du lieu tu file thanh cong!" << endl;
    }
    else
    {
        cout << "Khong the mo file: " << fileName << endl;
    }
}

void RoomService::writeToFile()
{
    ofstream file(fileName);
    if (file.is_open())
    {
        file << rooms.size() << endl;
        for (const auto &room : rooms)
        {
            file << room.getId() << endl;
            file << room.getName() << endl;
            file << room.getFloor() << endl;
            file << static_cast<int>(room.getType()) << endl;
            file << room.getSize() << endl;
        }
        file.close();
        cout << "Ghi du lieu vao file thanh cong!" << endl;
    }
    else
    {
        cout << "Khong the mo file: " << fileName << endl;
    }
}

#endif // ROOMSERVICE_H