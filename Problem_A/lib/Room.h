#ifndef ROOM_H
#define ROOM_H
#include <bits/stdc++.h>
#include "RoomType.h"

using namespace std;

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
        in.ignore();
        getline(in, room.name);

        cout << "Moi nhap tang: ";
        in >> room.floor;

        cout << "Chon loai phong: " << endl;
        cout << "   0. Phong hoc" << endl;
        cout << "   1. Phong thuc hanh" << endl;
        cout << "   2. Phong hoi truong" << endl;
        int option = 0;
        RoomType type[3] = {RoomType::CLASSROOM, RoomType::LAB, RoomType::AUDITORIUM};
        do
        {
            cout << "Nhap (0/1/2): " << endl;
            in >> option;
        } while (option > 2 || option < 0);

        room.type = type[option];

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