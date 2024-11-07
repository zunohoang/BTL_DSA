#include <iostream>
#include "Node.h"
#include "DList_Iterator.h"
#include "DList_Reverse_Iterator.h"
#include "Doubly_Linked_List.h"

using namespace std;

struct Person
{
    string parent;
    string name;
    int age;
    int parent_age_when_born;
};

class ProgramService
{
private:
    Doubly_Linked_List<Person> people;

public:
    void input()
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            Person person;
            cin >> person.parent;
            cin >> person.name;
            cin >> person.parent_age_when_born;
            person.age = -1;

            // moi nguoi chua biet tuoi nen dat la -1
            people.push_back(person);
        }

        // cho tuoi cu Ted la 100 tuoi va khong co cha...
        people.push_back({"", "Ted", 100, 0});
    }
    void run(int q)
    {

        bool allAgesCalculated = false;
        while (!allAgesCalculated)
        {
            allAgesCalculated = true;

            for (auto &person : people) // duyet qua tat ca nguoi
            {
                if (person.age == -1) // neu = -1 tuc la chua tinh tuoi
                {
                    bool foundParentWithAge = false; // kiem tra xem co cha me nao co tuoi chua

                    for (const auto &parent : people) // duyet qua tat ca cha me co the cua nguoi do
                    {
                        if (person.parent == parent.name && parent.age != -1) // neu la cha me va tuoi khac -1 thi tinh tuoi
                        {
                            person.age = parent.age - person.parent_age_when_born;
                            foundParentWithAge = true;
                            break;
                        }
                    }

                    if (!foundParentWithAge)
                    {
                        allAgesCalculated = false; // neu khong tim thay cha me thi chua tinh xong
                    }
                }
            }
        }

        // sap xep theo tuoi giam dan, neu cung tuoi thi sap xep theo ten
        people.sort(cmp);
        cout << "DATASET " << q << endl;
        for (const auto &person : people)
        {
            if (person.name != "Ted")
                cout << person.name << " " << person.age << endl;
        }
    }

    static bool cmp(Person a, Person b)
    {
        if (a.age == b.age)
        {
            return a.name < b.name;
        }
        return a.age < b.age;
    }
};

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        ProgramService programService;
        programService.input();
        programService.run(q);
    }
    return 0;
}