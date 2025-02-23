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

private:
    int width, height;
    vector<vector<string>> grid;
    vector<tuple<int, int, int, int>> rooms;  // (x, y, width, height)
    pair<int, int> start, end;

    int randInt(int min, int max) {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    bool checkCollision(int x, int y, int width, int height) {
        for (int i = x; i < x + width; i++) {
            for (int j = y; j < y + height; j++) {
                if (grid[j][i] != "wall") {
                    return true;
                }
            }
        }
        return false;
    }

    void placeRoom(int x, int y, int width, int height) {
        for (int i = x; i < x + width; i++) {
            for (int j = y; j < y + height; j++) {
                grid[j][i] = "room";
            }
        }
    }
