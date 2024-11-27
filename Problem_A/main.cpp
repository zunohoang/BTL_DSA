#include <bits/stdc++.h>
#include "./lib/RoomType.h"
#include "./lib/Room.h"
#include "./lib/RoomService.h"

using namespace std;

int main()
{
    RoomService roomService("./data/phong.txt");
    roomService.run();
    return 0;
}