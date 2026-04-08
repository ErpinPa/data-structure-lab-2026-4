#include "ImageMax.h"
#include <cstdio>

// 최대값 찾기 함수
int findMaxPixel(int image[][WIDTH], int h, int w) {
    if (h <= 0 || w <= 0) return -1;

    int maxVal = image[0][0];  // 핵심 수정

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (image[i][j] > maxVal) {
                maxVal = image[i][j];
            }
        }
    }
    return maxVal;
}

int main() {

    //  문제에서 주어진 예제 이미지 배열
    int image[HEIGHT][WIDTH] = {
        { 10, 30, 55, 80, 120, 160, 200, 230 },
        { 20, 45, 70, 100, 140, 180, 220, 210 },
        { 35, 60, 90, 130, 170, 210, 240, 190 },
        { 50, 80, 115, 150, 190, 230, 255, 170 },
        { 40, 65, 100, 140, 175, 215, 235, 150 },
        { 25, 50, 80, 115, 155, 195, 210, 130 },
        { 15, 35, 60, 90, 130, 165, 185, 110 },
        {  5, 20, 40, 70, 105, 140, 160,  90 }
    };

    printf("예제 이미지:\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    printf("\n결과 -> 최대 화소 밝기: %d\n",
        findMaxPixel(image, HEIGHT, WIDTH));

    return 0;
}