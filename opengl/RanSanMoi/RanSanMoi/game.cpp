#include <windows.h>
#include"Dependencies/glew/glew.h"
#include "Dependencies/freeglut/freeglut.h"
#include "game.h"
#include <ctime>

//khai bao diem 
extern int score;
//khai bao toa do luoi
int gridX, gridY;
//chieu dai an ban dau
int snake_length = 3;
//khai bao food 
bool food = true;
//khai bao toa do food
int foodX, foodY;
//huong di cua ran ban dau 
short sDirection = RIGHT;
//khai bao bien khi game over
extern bool gameOver;
//tao mang vi tri X,Y
int posX[60] = { 20,20,20,20,20 }, posY[60] = { 20,19,18,17,16 };
// khoi tao luoi
void initGrid(int x, int y) {
    //vi tri luoi
    gridX = x;
    gridY = y;
}

void unit(int, int);
//ham ve luoi
void drawGrid() {
    //chay lap de ve luoi theo truc X, Y
    for (int x = 0; x < gridX; x++) {
        for (int y = 0; y < gridY; y++) {
            unit(x, y);
        }
    }
    unit(20, 20);
}
void unit(int x, int y) {
    //ve vien cho box
    if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
        //do day cua vien'mau vang'
        glLineWidth(2.0);
        //mau vien
        glColor3f(1.0, 0.0, 1.0);
    }
    else {
        //do day vien trong
        glLineWidth(1.0);
        //mau vien trong'mau hong'
        glColor3f(0.0, 0.0, 0.0);
    }
    //ve vien va luoi
    glBegin(GL_LINE_LOOP);
    //ve cac diem x y
    glVertex2f(x, y);
    // ve cac diem khi tang x y, tao vien cheo
    glVertex2f(x + 1, y + 1);
    glEnd();

}
//ham ve thuc an
void drawFood() {
    //kt thuc an
    if (food)
        //tao ngau nhien vi tri thuc an
        random(foodX, foodY);
    //flase de co dinh vi tri, ko cho random khi ran chua an
    food = false;
    //mau thuc an
    glColor3f(0.0, 1.0, 0.0);
    //ve khoi' thuc an co toa do 4 dinh
    glRectf(foodX, foodY, foodX + 1, foodY + 1);

}
//ham ve ran
void drawSnake() {
    //kt lap de tao vi tri chieu dai ran
    for (int i = snake_length - 1; i > 0; i--) {
        //cac dien phia sau se -1 don vi de tao chieu dai ran
        posX[i] = posX[i - 1];
        posY[i] = posY[i - 1];
    }
    if (sDirection == UP) posY[0]++;//di chuyen len thi toa do Y tang
    else if (sDirection == DOWN) posY[0]--; //di chuyen xuong thi toa do Y giam
    else if (sDirection == RIGHT) posX[0]++;//di chuyen qua phai thi toa do X tang
    else if (sDirection == LEFT) posX[0]--;//di chuyen qua trai thi toa do X giam
    //loop de xac dinh mau ran
    for (int i = 0; i < snake_length; i++) {
        //xau dinh mau vi tri ban dau"dau` ran"
        if (i == 0)
            //mau dau` ran
            glColor3f(1.0, 0.0, 0.0);
        else
            //mau cac phan con lai cua ran
            glColor3f(1.0, 1.0, 1.0);
        //ve tung khoi cua ran toa do 4 dinh
        glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
    }

    //kt nau vi tri dau tien 'dau ran' ma cham vien thi dung game
    if (posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1) {
        gameOver = true;
    }
    //neu dau ran == vi tri thuc an thi tang chieu dai ran
    if (posX[0] == foodX && posY[0] == foodY) {
        //tang diem khi an dc thuc an
        score++;
        //tang chieu dai ran khi an dc thuc an
        snake_length++;
        //kt ko cho chieu dai ran vuot qua MAX=60
        if (snake_length > MAX)
            snake_length = MAX;
        // ran van an dc food
        food = true;
    }


}
//tao ham random de random food
void random(int& x, int& y) {
    int _maxX = gridX - 2;
    int _maxY = gridX - 2;
    int _min = 1;
    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() % (_maxY - _min);

}