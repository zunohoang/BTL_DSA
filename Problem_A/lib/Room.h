#ifndef ROOM_H
#define ROOM_H
#include <bits/stdc++.h>

class Room
{
private:
    int id;
    string name;
    int floor;
    RoomType type;
    int size;

public:
    Room() {}
    Room(int id, std::string name, int floor, RoomType type, int size)
        : id(id), name(name), floor(floor), type(type), size(size) {}

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
            return "Hoi thao";
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
        }
        room.type = type[option - 1];

        cout << "Moi nhap suc chua phong: ";
        in >> room.size;

        return in;
    }

    friend ostream &operator<<(ostream &os, const Room &room)
    {
        os << left << setw(6) << room.id << setw(12) << room.name << setw(10) << room.floor << setw(15) << room.roomTypeToString() << setw(10) << room.size;
        return os;
    }
};

#endif // ROOM_H