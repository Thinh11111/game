
#include "Dependencies/glew/glew.h"
#include "Dependencies/freeglut/freeglut.h"


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <math.h>
#include <sys/timeb.h>
#include <sys/utime.h>
#define MAX_FRAME 20
#define  PI 3.141592655389
static int rotate = 1; // xoay
static GLfloat spin = 0.0;
static int der = 0;
static int d = 1;
static float earth = 360 / 365.2;
// Goc Quay
static float g_x = 0, g_y = 5, g_z = 20;
// Bien Khoi Tao Toc Do Quay
static int year = 0, day = 0, moon = 0,
mars = 0, jupiter = 0, mercury = 0, venus=0, saturn = 0, uranus = 0, neptune = 0;
int maxy = 1;
static float Tx, Ty, Tz, Tr;
float maxM = 1;
float m = 0;
//float randomMove = 1
float chieu = 1;

//float randomColorR = (rand() % 255 - 1);
//float randomColorG = (rand() % 255 - 1);
//float randomColorB = (rand() % 255 - 1);
//float randomColorR1 = (rand() % 255 - 1);
//float randomColorG1 = (rand() % 255 - 1);
//float randomColorB1 = (rand() % 255 - 1);
//float randomColorR2 = (rand() % 255 - 1);
//float randomColorG2 = (rand() % 255 - 1);
//float randomColorB2 = (rand() % 255 - 1);



int getMilliCount() {
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

void sleep(int sleeptime)
{
	int count = 0;
	int beginsleep = getMilliCount();
	while (getMilliCount() - beginsleep < sleeptime)
	{
		count++;
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}

void draw()
{
	// Truc X
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();
	// Truc Y
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, -10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();
	// Truc Z
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, -10.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// Goc Quay Camera
	gluLookAt(g_x, g_y, g_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
	// Mat Troi
	glColor3f(247.0f / 255.0f, 54.0f / 255.0f, 25.0f / 255.0f);
	glutSolidSphere(1.0, 100, 100);
	// Trai Dat Quay Xung Quanh mat Troi
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	//====================
	// Tinh Tien Ra 2.2
	glTranslatef(2.2, 0.0, 0.0);
	//===========
	// Sau Khi Tinh TieN 2.0 thì trai dat Tu Quay Quanh Truc
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	// Sau Do Ve Trai Dat
	//================

	//Trái Đất
	glColor3f(73.0f / 255.0f, 105.0f / 255.0f, 235.0f / 255.0f); // Màu
	glutSolidSphere(0.25, 50, 100); // Lưới
	// Vong Quay Xung QUanh Trai DAT (Qủy Đạo)
	/*glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {
		glVertex3f(cos(i) * 0.5, 0.0, sin(i) * 0.5);
	}
	glEnd();*/
	// Mat Trăng Quanh Quanh Trai Dat
	glRotatef((GLfloat)moon, 0.0, 12.0, 0.0);
	glTranslatef(0.4, 0.0, 0.0);
	// Tinh Tien Mat Trang Ra Xa Mat Troi 0.5
	// Sau Do Ve Mat Trang
	//Mặt Trăng
	glColor3f(219.0f / 255.0f, 211.0f / 255.0f, 206.0f / 255.0f);
	glutSolidSphere(0.08, 10, 100);
	glPopMatrix();



	glPushMatrix();
	//Sao Hỏa
	// Sao hỏa Quay QUanh mat Troi Nhờ PushMatrix() ;
	glRotatef((GLfloat)mars, 0.0, 1.0, 0.0);
	glTranslatef(3, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(242.0f / 255.0f, 134.0f / 255.0f, 80.0f / 255.0f);
	glutSolidSphere(0.23, 100, 100);
	glPopMatrix();
	glPushMatrix();

	glPushMatrix();
	// Sao Kim
	glRotatef((GLfloat)venus, 0.0, 1.0, 0.0);
	glTranslated(1.5, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(244.0f / 255.0f, 164.0f / 255.0f, 96.0f / 255.0f);
	glutSolidSphere(0.18, 50, 100);
	glPopMatrix();
	// Sao thuy
	glPushMatrix();
	glRotatef((GLfloat)mercury, 0.0, 1.0, 0.0);
	glTranslated(1.25, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(205.0f / 255.0f, 201.0f / 255.0f, 201.0f / 255.0f);
	glutSolidSphere(0.08, 50, 100);
	glPopMatrix();

	//Sao Mộc
	glRotatef((GLfloat)jupiter, 0.0, 1.0, 0.0);
	glTranslatef(4, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(227.0f / 255.0f, 97.0f / 255.0f, 16.0f / 255.0f);
	glutSolidSphere(0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
	//Sao Thổ
	glRotatef((GLfloat)saturn, 0.0, 1.0, 0.0);
	glTranslated(5.0, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	
	glColor3f(242.0f / 255.0f, 210.0f / 255.0f, 65.0f / 255.0f);
	glutSolidSphere(0.6, 50, 100);
	glColor3f(1.0, 1.0, 0.0);
	//tao vanh dai sao tho
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(0.0, cos(i) * 0.8, sin(i) * 0.5);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//Sao Thiên Vương
	glRotatef((GLfloat)uranus, 0.0, 1.0, 0.0);
	glTranslated(6.0, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(103.0f / 255.0f, 192.0f / 255.0f, 240.0f / 255.0f);
	glutSolidSphere(0.4, 50, 100);
	glColor3f(1.0, 1.0, 1.0);
	//ve vanh dai sao thiên vương
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(0.0, cos(i) * 0.6, sin(i) * 0.6);
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	//Sao Hải Vương
	glRotatef((GLfloat)neptune, 0.0, 1.0, 0.0);
	glTranslated(7.0, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(26.0f / 255.0f, 114.0f / 255.0f, 237.0f / 255.0f);
	glutSolidSphere(0.3, 50, 100);
	glPopMatrix();

	draw();
	//Sao Bang =================
	glPushMatrix();
	glTranslatef(Tx, Ty, Tz);
	glColor3f(1, 1, 1);
	glutSolidSphere(Tr, 20, 50);
	glPopMatrix();

	glutSwapBuffers();
}


// Quay Theo Truc Y len Xuong MAX 7
void calSC(double dec)
{
	g_x = 5 * sin(dec);
	g_z = 5 * cos(dec);
	g_y = g_y + 0.1 * maxy;
	if (g_y > 7 || g_y < -7)
	{
		maxy *= -1;
	}
}
// Ham QUay Quanh ===================================== Update

void spinDisplay(void)
{
	der += 10;
	calSC((double)der / 360);
	year = (year - rotate * d) % 360;

	day = (day - rotate * d) % 360;

	/*saturn = (saturn - rotate * 1) % 360;*/
	// Quay 12 Vòng Xung Quanh Trai Dat = 1 Lần Trái đất quay quanh mat troi
	moon = (moon - rotate * d * 12) % 360;
	mars = (mars - rotate * d * 4) % 360;
	venus = (venus - rotate * d *2) % 360;
	mercury= (mercury - rotate * d *4) % 360;
	jupiter = (jupiter - rotate * d * 12) % 360;
	saturn = (saturn - rotate * d * 6) % 360;
	uranus = (uranus - rotate * d * 10) % 360;
	neptune = (neptune - rotate * d * 3) % 360;

	int beginFrame = getMilliCount();

	glutPostRedisplay(); /* thông báo cho chương trình rằng: cần phải thực
						 hiện việc vẽ lại */
	int timeDiff = getMilliCount() - beginFrame;

	if (timeDiff < (1000 / MAX_FRAME)) // 25FPS
	{
		sleep((1000 / MAX_FRAME) - timeDiff);

	}
	if (MAX_FRAME * 10) {
		Tx = rand() % 21 - 10;
		Ty = rand() % 21 - 10;
		Tz = rand() % 21 - 10;
		Tr = 0.7 * rand() / RAND_MAX;
	}

	// Doi Chieu Sao Bang ====================
	m = m + 0.1 * maxM;
	if (m > 2)
	{
		chieu *= -1;
		maxM *= -1;
	}
	
}


void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		rotate = 1;
		spin = spin + 0.5;
		d = d + 0.2;

		glutIdleFunc(spinDisplay);
		break;
	case '2':
		rotate = -1;
		spin = spin + 0.5;
		d = d + 0.2;
		glutIdleFunc(spinDisplay);
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 600);

	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}