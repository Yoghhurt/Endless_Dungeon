#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define WIDTH 20
#define HEIGHT 20

enum Tile { Empty = '.', Wall = '#', Start = 'S', End = 'E' };

class Dungeon {
public:
    Dungeon() {
        // Random number generator
        std::srand(std::time(0));

        // Initialize the dungeon with walls
        dungeonGrid = std::vector<std::vector<Tile>>(HEIGHT, std::vector<Tile>(WIDTH, Wall));
    }

    void generate() {
        // Clear the grid and reset
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                dungeonGrid[i][j] = Wall;
            }
        }

        // Create random rooms
        createRandomRooms();

        // Create corridors connecting rooms
        createCorridors();

        // Place the start (S) and end (E) points
        placeStartAndEnd();
    }

    void printDungeon() {
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                std::cout << (char)dungeonGrid[i][j];
            }
            std::cout << std::endl;
        }
    }

    private:
    std::vector<std::vector<Tile>> dungeonGrid;

    void createRandomRooms() {
        // Randomly generate rooms
        for (int i = 0; i < 5; ++i) {
            int roomWidth = std::rand() % 4 + 4;   // Room width between 4 and 7
            int roomHeight = std::rand() % 4 + 4;  // Room height between 4 and 7
            int roomX = std::rand() % (WIDTH - roomWidth - 1);
            int roomY = std::rand() % (HEIGHT - roomHeight - 1);

            // Fill the room area with empty spaces
            for (int y = roomY; y < roomY + roomHeight; ++y) {
                for (int x = roomX; x < roomX + roomWidth; ++x) {
                    dungeonGrid[y][x] = Empty;
                }
            }
        }
    }

    void createCorridors() {
        for (int y = 1; y < HEIGHT; ++y) {
            for (int x = 1; x < WIDTH; ++x) {
                if (dungeonGrid[y][x] == Empty) {
                    if (y > 0 && dungeonGrid[y - 1][x] == Wall) {
                        dungeonGrid[y - 1][x] = Empty; // Vertical corridor
                    }
                    if (x > 0 && dungeonGrid[y][x - 1] == Wall) {
                        dungeonGrid[y][x - 1] = Empty; // Horizontal corridor
                    }
                }
            }
        }
    }

    void placeStartAndEnd() {
        int startX = std::rand() % WIDTH;
        int startY = std::rand() % HEIGHT;
        int endX = std::rand() % WIDTH;
        int endY = std::rand() % HEIGHT;

      
        while (dungeonGrid[startY][startX] != Empty) {
            startX = std::rand() % WIDTH;
            startY = std::rand() % HEIGHT;
        }

        while (dungeonGrid[endY][endX] != Empty || (startX == endX && startY == endY)) {
            endX = std::rand() % WIDTH;
            endY = std::rand() % HEIGHT;
        }

        // Place start and end
        dungeonGrid[startY][startX] = Start;
        dungeonGrid[endY][endX] = End;
    }
};