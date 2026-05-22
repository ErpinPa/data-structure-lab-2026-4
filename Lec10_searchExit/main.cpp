#include <iostream>
#include <stack>
#include <deque>

using namespace std;

//2차원 행렬 만들기
struct Location2D {     
    int row;
    int col;

    Location2D(int r = 0, int c = 0) {
        row = r;
        col = c;
    }
};

//nxm 행렬
const int MAZE_SIZE_x = 6;
const int MAZE_SIZE_y = 7;

// 미로 설정
char originalMap[MAZE_SIZE_x][MAZE_SIZE_y] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', '1'},
    {'1', '1', '1', '1', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

char map[MAZE_SIZE_x][MAZE_SIZE_y];

//초기 설정
void resetMap() {
    for (int i = 0; i < MAZE_SIZ_x; i++) {
        for (int j = 0; j < MAZE_SIZE_y; j++) {
            map[i][j] = originalMap[i][j];
        }
    }
}

bool isValidLoc(int r, int c) {
    if (r < 0 || c < 0 || r >= MAZE_SIZE_x || c >= MAZE_SIZE_y)
        return false;

    return map[r][c] == '0' || map[r][c] == 'x';
}

//Case Deque
void solveWithDeque() {
    deque<Location2D> locDeque;

    locDeque.push_back(Location2D(1, 0));

    while (!locDeque.empty()) {

        Location2D here = locDeque.front();
        locDeque.pop_front();

        int r = here.row;
        int c = here.col;

        cout << "(" << r << "," << c << ") ";

        if (map[r][c] == 'x') {
            cout << "\n미로 탐색 성공! (Deque BFS)\n";
            return;
        }

        map[r][c] = '.';

        if (isValidLoc(r - 1, c))
            locDeque.push_back(Location2D(r - 1, c));

        if (isValidLoc(r + 1, c))
            locDeque.push_back(Location2D(r + 1, c));

        if (isValidLoc(r, c - 1))
            locDeque.push_back(Location2D(r, c - 1));

        if (isValidLoc(r, c + 1))
            locDeque.push_back(Location2D(r, c + 1));
    }

    printf("\n미로 탐색 실패!\n");
}


//Case Stack
void solveWithStack() {
    stack<Location2D> locStack;

    locStack.push(Location2D(1, 0));

    while (!locStack.empty()) {

        Location2D here = locStack.top();
        locStack.pop();

        int r = here.row;
        int c = here.col;

        cout << "(" << r << "," << c << ") ";

        if (map[r][c] == 'x') {
            cout << "\n미로 탐색 성공! (Stack DFS)\n";
            return;
        }

        map[r][c] = '.';

        if (isValidLoc(r - 1, c))
            locStack.push(Location2D(r - 1, c));

        if (isValidLoc(r + 1, c))
            locStack.push(Location2D(r + 1, c));

        if (isValidLoc(r, c - 1))
            locStack.push(Location2D(r, c - 1));

        if (isValidLoc(r, c + 1))
            locStack.push(Location2D(r, c + 1));
    }

   printf("\n미로 탐색 실패!\n");
}

int main() {

    string choice;
    printf("Deque 또는 Stack 입력: "\n);
    resetMap();

    if (choice == "Deque") {
        solveWithDeque();
    }
    else if (choice == "Stack") {
        solveWithStack();
    }
    else {
        printf("잘못된 입력입니다.\n");
    }

    return 0;
}