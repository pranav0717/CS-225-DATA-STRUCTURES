// /* Your code here! */

#include "maze.h"

#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
using namespace cs225;


SquareMaze::SquareMaze() {

    height_ = 0;
    width_ = 0;

}

void SquareMaze::makeMaze(int width, int height) {
    maze.clear(); 
    maze.resize(width, std::vector<std::pair<bool, bool>>(height, {true, true})); 

    elements.addelements(width * height); 


    int totalCells = width * height;
    int visitedCells = 0;
    int x = 0, y = 0, dir = 0;


    while (visitedCells < totalCells - 1) { 
        x = rand() % width;
        y = rand() % height;


        dir = rand() % 4;


        int dx = 0, dy = 0;
        if (dir == 0) dx = 1;
        if (dir == 1) dy = 1;
        if (dir == 2) dx = -1;
        if (dir == 3) dy = -1;

        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;


        int cell1 = y * width + x;
        int cell2 = ny * width + nx;


        if (elements.find(cell1) != elements.find(cell2)) {
      
            if (dir == 0) setWall(x, y, 0, false); 
            if (dir == 1) setWall(x, y, 1, false); 
            if (dir == 2) setWall(nx, ny, 0, false);
            if (dir == 3) setWall(nx, ny, 1, false); 

            elements.setunion(cell1, cell2);

            visitedCells++;
        }
    }
}


bool SquareMaze::canTravel(int x, int y, int dir) const {
    int width = static_cast<int>(maze.size());
    int height = static_cast<int>(maze[0].size());

    bool canMove = false;

    if (dir == 0) { //  right
        canMove = (x < width - 1 && !maze[x][y].first);
    }
    else if (dir == 1) { // down
        canMove = (y < height - 1 && !maze[x][y].second);
    }
    else if (dir == 2) { // left
        canMove = (x > 0 && !maze[x - 1][y].first);
    }
    else if (dir == 3) { //  up
        canMove = (y > 0 && !maze[x][y - 1].second);
    }

    return canMove;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    if (dir == 0) {
        if (exists) {
            maze.at(x).at(y).first = true;
        }
        else {
            maze.at(x).at(y).first = false;
        }
    }
    else {
        if (exists) {
            maze.at(x).at(y).second = true;
        }
        else {
            maze.at(x).at(y).second = false;
        }
    }
}



cs225::PNG* SquareMaze::drawMaze() const {
    unsigned width = maze.size() * 10 + 1; 
    unsigned height = maze.at(0).size() * 10 + 1; 
    cs225::PNG* png = new cs225::PNG(width, height);

    // Filling top ad left with black
    for (unsigned i = 0; i < width; i++) {
      if(i<1 || i>9){
        png->getPixel(i, 0).l = 0;
      }
    }
    for (unsigned j = 0; j < height; j++) {
        png->getPixel(0, j).l = 0;
    }

    // Drawing maze walls
    for (unsigned i = 0; i < maze.size(); i++) {
        for (unsigned j = 0; j < maze[i].size(); j++) {
            // Draw the right wall
            if (maze[i][j].first) {
                for (unsigned k = 0; k <= 10; k++) {
                    png->getPixel((i+1)*10, j*10+k).l = 0;
                }
            }
            // Drawing bottom wall
            if (maze[i][j].second) {
                for (unsigned k = 0; k <= 10; k++) {
                    png->getPixel(i*10+k, (j+1)*10).l = 0;
                }
            }
        }
    }

    return png;
}



vector<int> SquareMaze::solveMaze() {
    int width = (int) maze.size();
    int height = (int) (maze.at(0).size());
    vector<vector<int>> distance;
    distance.resize(width, vector<int>(height));

    queue<pair<int, int>> queue;
    queue.push(pair<int, int>(0, 0));
    int travx, travy;
    
        int ii = 0;
    while (ii < width) {
        int jj = 0;
        while (jj < height) {
            distance[ii][jj] = -1;
            jj++;
        }
        ii++;
}
    distance.at(0).at(0) = 0;

    while (!queue.empty()) {
        pair<int, int> temp;
        temp = queue.front();
        queue.pop();
        travx = temp.first;
        travy = temp.second;

        int direction;
        for (direction = 0; direction < 4; direction++) {
            bool canTravelDirection = canTravel(travx, travy, direction);
            int newX = travx, newY = travy;
            switch (direction) {
                case 0: // right x + 1
                    newX = travx + 1;
                    break;
                case 1: // down y + 1
                    newY = travy + 1;
                    break;
                case 2: // left x - 1
                    newX = travx - 1;
                    break;
                case 3: // up y - 1
                    newY = travy - 1;
                    break;
            }
            if (canTravelDirection && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[travx][travy] + 1;
                queue.push(make_pair(newX, newY));
            }
        }
    }

    int maxDist = 0, maxX = 0;

    int xx = 0;
while (xx < width) {
    if (maxDist < distance[xx][height - 1]) {
        maxDist = distance[xx][height - 1];
        maxX = xx;
    }
    xx++;
}
    int destX = maxX, destY = height - 1;

    vector<int> direction;
    direction.reserve(maxDist);

    int di = maxDist, x = destX, y = destY;

    while (di != 0) {
        for (int d = 0; d < 4; d++) {
            bool canTravelDirection = canTravel(x, y, d);
            int newX = x, newY = y;
            switch (d) {
                case 0: // right x + 1
                    newX = x + 1;
                    break;
                case 1: // down y + 1
                    newY = y + 1;
                    break;
                case 2: // left x - 1
                    newX = x - 1;
                    break;
                case 3: // up y - 1
                    newY = y - 1;
                    break;
            }
            if (canTravelDirection && distance[newX][newY] == di - 1) {
                int dir;
                if (d == 0) {
                    dir = 2;
                } else if (d == 1) {
                    dir = 3;
                } else if (d == 2) {
                    dir = 0;
                } else {
                    dir = 1;
                }
                direction.push_back(dir);
                x = newX;
                y = newY;
                di--;
                break;
            }
        }
    }
std::vector<int> ret = direction;
std::reverse(ret.begin(), ret.end());
return ret;

}



cs225::PNG* SquareMaze::drawMazeWithSolution() {
    cs225::PNG* maze = drawMaze();
    vector<int> solution = solveMaze();

    int posX = 5;
    int posY = 5;

    for (size_t i = 0; i < solution.size(); i++) {
        int dir = solution[i];
        int dx = 0;
        int dy = 0;

        switch (dir) {
            case 0: // move right, increase x
                dx = 10;
                break;
            case 1: // move down, increase y
                dy = 10;
                break;
            case 2: // move left, decrease x
                dx = -10;
                break;
            case 3: // move up, decrease y
                dy = -10;
                break;
        }

        for (int k = 0; k <= 10; k++) {
            int x = posX + dx * k / 10;
            int y = posY + dy * k / 10;
            cs225::HSLAPixel& pixel = maze->getPixel(x, y);
            pixel.h = 0;
            pixel.s = 1;
            pixel.l = 0.5;
            pixel.a = 1;
        }

        posX += dx;
        posY += dy;
    }

    posX -= 5;
    posY += 5;

        int kk = 1;
    while (kk <= 9) {
        int x = posX + kk;
        int y = posY;
        maze->getPixel(x, y).l = 1;
        kk++;
    }

    return maze;
}