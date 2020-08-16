#include <windows.h>
#include "Dependencies/glew/glew.h"
#include "Dependencies/freeglut/freeglut.h"
#include "game.h"
#include <iostream>
#include <string>
#define COLUMNS 40
#define ROWS 40

#define FPS 60
//tao bien di chuyen cua ran
extern  short sDirection;
//khai bao bien gameover
bool gameOver = false;
//khai bao diem
int score = 0;

void timer_callback(int);
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(int, int, int);

void init() {
    //khoi tao man hinh mau den
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //goi ham khoi tao o luoi
    initGrid(COLUMNS, ROWS);
}

int main(int argc, char* argv[])
{
    //khoi tao glut
    glutInit(&argc, argv);
    //khoi tao che do ve sigle buffer ca he mau RGB
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //khoi tao kich thuoc cua so
    glutInitWindowSize(500, 500);
    //title
    glutCreateWindow("Ran San Moi");
    //goi ham hien thi
    glutDisplayFunc(display_callback);
    //goi ham thay doi kich thuoc cua so
    glutReshapeFunc(reshape_callback);
    //goi ham thoi gian de tao frame
    glutTimerFunc(0, timer_callback, 0);
    //ham ban phim
    glutSpecialFunc(keyboard_callback);
    init();
    //lap lien tuc de ko bi thoat khi dang chay ctinh
    glutMainLoop();
    return 0;

}
//ham hien thi
void display_callback() {
    //xoa bo dem da dc tao truoc
    glClear(GL_COLOR_BUFFER_BIT);
    //goi ham ve luoi vien
    drawGrid();
    //goi ham ve ran
    drawSnake();
    //goi ham ve thuc an
    drawFood();
    //ham hien thi bo dem sau
    glutSwapBuffers();
    //kt neu gamover
    if (gameOver) {
        /*std::string std = std::to_string(score);
        std::string str = "Your Score: " + std;*/
        //khai bao chuoi "your score"
        std::string myString = "your score ";
        //covert bien score thanh chuoi va noi chuoi
        myString += std::to_string(score);
        //char text[100];
        //sprintf_s(text, "%s", myString.c_str());
        //xu li ki tu rac 
        LPWSTR text = new wchar_t[myString.size() + 1];
        copy(myString.begin(), myString.end(), text);
        text[myString.size()] = 0;
        //hien thi len messagebox
        MessageBox(NULL, text, L"GAME OVER", MB_OK);

        exit(0);
    }
}

//ham thay doi kich thuoc cua so
void reshape_callback(int w, int h) {
    //tinh toan chieu rong va cao cua cua so moi
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    //che do hien thi khop voi khung hinh
    glMatrixMode(GL_PROJECTION);//ma tran chieu
    glLoadIdentity();//dat lai ma tran chieu
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

}
//ham xua li khi bo hen het gio
void timer_callback(int) {
    //ve lai va hien thi len man hinh
    glutPostRedisplay();
    //hen thoi gian tiep theo
    glutTimerFunc(5000 / FPS, timer_callback, 0);
}
//ham xu li su kien ban phim 
void keyboard_callback(int key, int, int) {
    switch (key) {
        //xu li khi an nut len
    case GLUT_KEY_UP:
        //kt co dinh huong di chuyen cua ran khi di len, ko cho quay nguoc dau khi an xuong
        if (sDirection != DOWN)
            sDirection = UP;
        break;
        //xu li nut xuong
    case GLUT_KEY_DOWN:
        //kt co dinh huong di chuyen cua ran khi di xuog, ko cho quay nguoc dau khi an len
        if (sDirection != UP)
            sDirection = DOWN;
        break;
        //xu li nut phai
    case GLUT_KEY_RIGHT:
        //kt co dinh huong di chuyen cua ran khi di phai, ko cho quay nguoc dau khi an trai
        if (sDirection != LEFT)
            sDirection = RIGHT;
        break;
        //xu li nut trai
    case GLUT_KEY_LEFT:
        //kt co dinh huong di chuyen cua ran khi di trai, ko cho quay nguoc dau khi an phai
        if (sDirection != RIGHT)
            sDirection = LEFT;
        break;
    }
}