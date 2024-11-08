#include <bits/stdc++.h>

using namespace std;

enum class RoomType
{
    CLASSROOM,
    LAB,
    AUDITORIUM
};

class Room
{
private:
    int id;
    string name;
    int floor;
    RoomType type;
    int size;

public:
    // Constructor
    Room() {}
    Room(int id, std::string name, int floor, RoomType type, int size)
        : id(id), name(name), floor(floor), type(type), size(size) {}

    // Getters
    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    int getFloor() const
    {
        return floor;
    }

    RoomType getType() const
    {
        return type;
    }

    int getSize() const
    {
        return size;
    }

    // Setters
    void setId(int id)
    {
        this->id = id;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setFloor(int floor)
    {
        this->floor = floor;
    }

    void setType(RoomType type)
    {
        this->type = type;
    }

    void setSize(int size)
    {
        this->size = size;
    }

    string roomTypeToString() const
    {
        switch (type)
        {
        case RoomType::CLASSROOM:
            return "Phong hoc";
        case RoomType::LAB:
            return "Phong lab";
        case RoomType::AUDITORIUM:
            return "Hoi truong";
        default:
            return "Khong xac dinh";
        }
    }

    friend istream &operator>>(istream &in, Room &room)
    {
        cout << "Moi nhap ID: ";
        in >> room.id;

        cout << "Moi nhap ten: ";
        in >> room.name;

        cout << "Moi nhap tang: ";
        in >> room.floor;

        cout << "Chon loai phong: " << endl;
        cout << "   1. Phong hoc" << endl;
        cout << "   2. Phong thi nghiem" << endl;
        cout << "   3. Phong hoi thao" << endl;
        int option = 0;
        RoomType type[3] = {RoomType::CLASSROOM, RoomType::LAB, RoomType::AUDITORIUM};
        while (option > 3 || option < 1)
        {
            cout << "Nhap (1/2/3): " << endl;
            in >> option;
            option += 1;
        }
        room.type = type[option];

        cout << "Moi nhap suc chua phong: ";
        in >> room.size;

        return in;
    }

    friend ostream &operator<<(ostream &os, const Room &room)
    {
        os << "   + Ma phong: " << room.id << endl;
        os << "   + Ten phong: " << room.name << endl;
        os << "   + Tang: " << room.floor << endl;
        os << "   + Loai: " << room.roomTypeToString() << endl;
        os << "   + Suc chua: " << room.size << endl;
        return os;
    }
};

class RoomService
{
private:
    vector<Room> rooms;

public:
    RoomService() = default;

    void add(const Room &room)
    {
        this->rooms.push_back(room);
    }

    void remove(const int &id)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].getId() == id)
            {
                rooms.erase(rooms.begin() + i);
                cout << "Xoa phong thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay phong co ma " << id << "!" << endl;
    }

    void showAll()
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            cout << rooms[i] << endl;
        }
    }

    void showSortBySize()
    {
        vector<Room> temp = rooms;
        sort(temp.begin(), temp.end(), [](const Room &a, const Room &b)
             { return a.getSize() < b.getSize(); });
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << endl;
        }
    }

    void showSortByName()
    {
        vector<Room> temp = rooms;
        sort(temp.begin(), temp.end(), [](const Room &a, const Room &b)
             { return a.getName() < b.getName(); });
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << endl;
        }
    }

    void showSortByFloor()
    {
        vector<Room> temp = rooms;
        sort(temp.begin(), temp.end(), [](const Room &a, const Room &b)
             { return a.getFloor() < b.getFloor(); });
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << endl;
        }
    }

    void showByFloor(const int &floor)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].getFloor() == floor)
            {
                cout << rooms[i] << endl;
            }
        }
    }

    void showById(const int &id)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].getId() == id)
            {
                cout << rooms[i] << endl;
            }
        }
    }

    void update(const int &id, const Room &room)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].getId() == id)
            {
                rooms[i] = room;
                cout << "Cap nhat phong thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay phong co ma " << id << "!" << endl;
    }

    void removeAll()
    {
        rooms.clear();
        cout << "Xoa tat ca cac phong thanh cong!" << endl;
    }

    void showBySize(const int &size)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].getSize() >= size)
            {
                cout << rooms[i] << endl;
            }
        }
    }

    void showByType(const RoomType &type)
    {
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].getType() == type)
            {
                cout << rooms[i] << endl;
            }
        }
    }

    void showMenu()
    {
        cout << "============================MENU_CRUD=============================" << endl;
        cout << "==                                                              ==" << endl;
        cout << "==     1. Them phong.                                           ==" << endl;
        cout << "==     2. Xoa phong                                             ==" << endl;
        cout << "==     3. Hien danh sach phong                                  ==" << endl;
        cout << "==     4. In danh sach phong sap xep theo kich co               ==" << endl;
        cout << "==     5. In danh sach phong sap xep theo ten                   ==" << endl;
        cout << "==     6. In danh sach phong sap xep theo tang                  ==" << endl;
        cout << "==     7. In danh sach theo tang                                ==" << endl;
        cout << "==     8. Tim phong co theo ma phong                            ==" << endl;
        cout << "==     9. Cap nhat thong tin phong                              ==" << endl;
        cout << "==     10. Xoa tat ca cac phong                                 ==" << endl;
        cout << "==     11. Tim phong co kich co lon hon hoac bang               ==" << endl;
        cout << "==     12. Tim va in danh sach theo loai phong                  ==" << endl;
        cout << "==     13. Hien thi lai MENU                                    ==" << endl;
        cout << "==     0. Thoat                                                 ==" << endl;
        cout << "==                                                              ==" << endl;
        cout << "===========================END_CRUD===============================" << endl;
    }

    void program(const int &option)
    {
        switch (option)
        {
        case 0:
            cout << "Chuong trinh da thoat!";
            return;
        case 1:
        {
            cout << "--THEM PHONG--" << endl;
            cout << "Moi nhap thong tin phong" << endl;
            Room room;
            cin >> room;
            this->add(room);
            cout << "Them phong thanh cong!" << endl;
            break;
        }
        case 2:
        {
            cout << "--XOA PHONG--" << endl;
            cout << "Nhap ma phong can xoa: ";
            int id;
            cin >> id;
            for (int i = 0; i < rooms.size(); i++)
            {
                if (rooms[i].getId() == id)
                {
                    rooms.erase(rooms.begin() + i);
                    cout << "Xoa phong thanh cong!" << endl;
                    return;
                }
            }
            cout << "Khong tim thay phong co ma " << id << "!" << endl;
            break;
        }
        case 3:
        {
            cout << "--HIEN DANH SACH PHONG--";
            this->showAll();
            break;
        }
        case 4:
        {
            cout << "--HIEN DANH SACH PHONG SAP XEP THEO KICH CO--";
            this->showSortBySize();
            break;
        }
        case 5:
        {
            cout << "--HIEN DANH SACH PHONG SAP XEP THEO TEN--" << endl;
            this->showSortByName();
            break;
        }
        case 6:
        {
            cout << "--HIEN DANH SACH PHONG SAP XEP THEO TANG--" << endl;
            this->showSortByFloor();
            break;
        }
        case 7:
        {
            cout << "--HIEN DANH SACH THEO TANG--" << endl;
            cout << "Nhap tang: ";
            int floor;
            cin >> floor;
            this->showByFloor(floor);
            break;
        }
        case 8:
        {
            cout << "--TIM PHONG CO THEO MA PHONG--" << endl;
            cout << "Nhap ma phong: ";
            int id;
            cin >> id;
            this->showById(id);
            break;
        }
        case 9:
        {
            cout << "--CAP NHAT THONG TIN PHONG--" << endl;
            cout << "Nhap ma phong can cap nhat: ";
            int id;
            cin >> id;
            Room room;
            cin >> room;
            this->update(id, room);
            break;
        }
        case 10:
        {
            cout << "--XOA TAT CA CAC PHONG--" << endl;
            this->removeAll();
            break;
        }
        case 11:
        {
            cout << "--TIM PHONG CO KICH CO LON HON HOAC BANG--" << endl;
            cout << "Nhap kich co: ";
            int size;
            cin >> size;
            this->showBySize(size);
            break;
        }
        case 12:
        {
            cout << "--TIM VA IN DANH SACH THEO LOAI PHONG--" << endl;
            cout << "Chon loai phong: " << endl;
            cout << "   1. Phong hoc" << endl;
            cout << "   2. Phong thi nghiem" << endl;
            cout << "   3. Phong hoi thao" << endl;
            int option = 0;
            RoomType type[3] = {RoomType::CLASSROOM, RoomType::LAB, RoomType::AUDITORIUM};
            while (option > 3 || option < 1)
            {
                cout << "Nhap (1/2/3): " << endl;
                cin >> option;
            }
            this->showByType(type[option - 1]);
            break;
        }
        case 13:
        {
            showMenu();
            break;
        }
        }
    }

    void run()
    {
        cout << "+----CHAO MUNG BAN DEN VOI QUAN LY PHONG HOC----+" << endl;
        cout << "De tiep tuc an phim Enter";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        this->program(13);

        while (true)
        {
            int option;
            cout << "Vui long nhap [0-13]: ";
            cin >> option;
            if (option < 0 || option > 13)
            {
                cout << "Moi nhap trong khoang [0-13]: ";
                cin >> option;
            }
            if (option == 0)
            {
                cout << "Thoat chuong trinh!" << endl;
                return;
            }
            this->program(option);
            cout << endl;
            cout << endl;
            cout << "Thuc hien chuc nang khac vui long chon [0-13] hoac chọn 13 de hien MENU" << endl;
        }
    }
};

int main()
{
    RoomService roomService;
    roomService.run();
    return 0;
}