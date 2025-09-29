#include <cstdlib>
#include <vector> 
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    srand(time(0));

    int r, c;
    cout << "enter number of rows" << endl;
    cin >> r;
    cout << "enter number of columns" << endl;
    cin >> c;

    vector<vector<int>> mazeMap;
    for (int i = 0; i < r; i++) {
        vector<int> tmp(c, 1);
        mazeMap.push_back(tmp);
    }


    pair<int, int> path{ 1, 1 };
    mazeMap[1][0] = 0;
    mazeMap[1][1] = 0;
    queue<pair<int, int>> soll;

    for (int i = 0; i < r * c; i++) {
        if (path.first == r - 1 || path.second == c - 1) {
            mazeMap[path.first][path.second] = 0;
            break;
        }
        int randomNumber = rand();
        if (randomNumber % 2 == 0) {
            path.second += 1;
            mazeMap[path.first][path.second] = 0;
            soll.push({ path.first, path.second });
        }
        else {
            path.first += 1;
            mazeMap[path.first][path.second] = 0;
            soll.push({ path.first, path.second });
        }
    }


    path = { 1, 1 };
    stack<pair<int, int>> walls;


    if (1 + 1 < r && mazeMap[1 + 1][1] == 1) walls.push({ 1 + 1, 1 });
    if (1 + 1 < c && mazeMap[1][1 + 1] == 1) walls.push({ 1, 1 + 1 });
    if (1 - 1 >= 0 && mazeMap[1][1 - 1] == 1) walls.push({ 1, 1 - 1 });
    if (1 - 1 >= 0 && mazeMap[1 - 1][1] == 1) walls.push({ 1 - 1, 1 });


    while (!walls.empty() && !soll.empty()) {
        pair<int, int> current = walls.top();
        walls.pop();

        int x = current.first;
        int y = current.second;


        if (mazeMap[x][y] == 1) {

            int wallCount = 0;

            if (x + 1 < r && mazeMap[x + 1][y] == 1) wallCount++;
            if (y + 1 < c && mazeMap[x][y + 1] == 1) wallCount++;
            if (y - 1 >= 0 && mazeMap[x][y - 1] == 1) wallCount++;
            if (x - 1 >= 0 && mazeMap[x - 1][y] == 1) wallCount++;



            if (wallCount >= 3) {
                mazeMap[x][y] = 0;

                int number = rand();

                if (x + 1 < r && mazeMap[x + 1][y] == 1) walls.push({ x + 1, y });
                if (y + 1 < c && mazeMap[x][y + 1] == 1) walls.push({ x, y + 1 });
                if (y - 1 >= 0 && mazeMap[x][y - 1] == 1) walls.push({ x, y - 1 });
                if (x - 1 >= 0 && mazeMap[x - 1][y] == 1) walls.push({ x - 1, y });

            }
        }


        if (walls.size() <= 1 && !soll.empty()) {
            pair<int, int> pathPoint = soll.front();
            soll.pop();

            int px = pathPoint.first;
            int py = pathPoint.second;


            if (px + 1 < r && mazeMap[px + 1][py] == 1) walls.push({ px + 1, py });
            if (px - 1 >= 0 && mazeMap[px - 1][py] == 1) walls.push({ px - 1, py });
            if (py - 1 >= 0 && mazeMap[px][py - 1] == 1) walls.push({ px, py - 1 });
            if (py + 1 < c && mazeMap[px][py + 1] == 1) walls.push({ px, py + 1 });

        }
    }

    cout << "Here your maze:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << (mazeMap[i][j] == 0 ? "  " : "[]");
        }
        cout << endl;
    }

    return 0;
}