#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int mapsize = 1000;

void draw(const int n, char map[][mapsize], const int r, const int c){
    int size = (1 << (n + 2));
    map[r][c] = map[r + size - 1][c + size - 1] = map[r][c + size - 1] = map[r + size - 1][c] = '+';
    for (int i = 1; i < size - 1; i++) {
        map[r][c + i] = map[r + size - 1][c + i] = '-';
        map[r + i][c] = map[r + i][c + size - 1] = '|';
    }
    if (n == 0) return;
    for (int i = 2; i < size / 2 - 1; i++) {
        map[r + i][c + size / 2 - i] = '/';
        map[r + i][c + size / 2 + i - 1] = '\\';
    }

    draw(n - 1, map, r + size / 2, c + size / 4);  //递归下一层
}

int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        static char map[mapsize][mapsize];
        cin >> n;
        memset(map, ' ', sizeof(map)); //因大面积区域无字符，所以初始化为空格
        draw(n, map, 0, 0);
        int size = (1 << (n + 2));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) putchar(map[i][j]);
            putchar(10); //换行键
        }
    }
    return 0;
}