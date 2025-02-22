#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
class Dungeon {
public:
Dungeon(int width, int height) : width(width), height(height) {
    grid.resize(height, vector<string>(width, "wall"));
}

void generateRooms(int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        int roomWidth = randInt(5, 10);
        int roomHeight = randInt(5, 10);
        int roomX = randInt(1, width - roomWidth - 1);
        int roomY = randInt(1, height - roomHeight - 1);

        if (checkCollision(roomX, roomY, roomWidth, roomHeight)) {
            continue;
        }

        placeRoom(roomX, roomY, roomWidth, roomHeight);
        rooms.push_back({roomX, roomY, roomWidth, roomHeight});
    }
}
