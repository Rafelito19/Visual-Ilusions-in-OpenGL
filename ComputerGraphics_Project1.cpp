


#include "stdafx.h"
#include <string>
#include  <gl\freeglut.h>
#include <iostream>
#include <cmath>
void draw2(){
	int sqSize = 86;
	int x1 = 0;
	int y1 = 0;

	int x2 = sqSize;
	int y2 = 0;


	int x3 = sqSize;
	int y3 = sqSize;


	int x4 = 0;
	int y4 = sqSize;
	glClear(GL_COLOR_BUFFER_BIT);

	

	glColor3f(0.0, 0.0, 0.0);

	for (int i = 0; (i + y4) <= 600; i = i + 102) {
	for 	(int j = 0; (j + x3) <= 800; j = j + 102) {

		
		glBegin(GL_POLYGON);

		glVertex2i(x1+j, y1+i);
		glVertex2i(x2+j, y2+i);
		glVertex2i(x3+j, y3+i);
		glVertex2i(x4+j, y4+i);
		glEnd();
	}
	}
	glFlush();

}


void draw3(){          //fig 3.39
	int sqSize = 40;
	int sqx = 36;
	int x1 = 0;
	int y1 = 0;

	int x2 = sqx;
	int y2 = 0;


	int x3 = sqx;
	int y3 = sqSize;


	int x4 = 0;
	int y4 = sqSize;
	glClear(GL_COLOR_BUFFER_BIT);
	int dt = 0; // tells wheather to go foward of backwards

	int ofset = 20;  // point from which to begin drawing
	for (int i = 0; (i + y4) <= 650; i = i + 40) {
		glLineWidth(2.5);
		glColor3f(0.6, 0.66, 0.65);
		glBegin(GL_LINES);

		glVertex2i(0 , y1 + i);
	
		glVertex2i(800 , y1+i);
		glEnd();

		


		
		
	

		for (int j =ofset; (j + x3) <= 800; j = j + 80) {



			if (j % 3 == 0) { //we cchage the parrent every 3 blcoks
				ofset = 20;

				if (dt == 0) //we are going foward time to go backwars
					dt = 1;
				if (dt == 1)
				dt = 0;
				

			}

			if (dt == 0) //move left
				ofset = ofset - 5;
			if (dt == 1) // move right
				ofset = ofset + 5;

			glColor3f(0.0, 0.0, 0.0);
			
			glBegin(GL_POLYGON);

			glVertex2i(x1 + j, y1 + i);
			glVertex2i(x2 + j, y2 + i);
			glVertex2i(x3 + j, y3 + i);
			glVertex2i(x4 + j, y4 + i);
			glEnd();

		}
	}
	glFlush();


}
void draw1() {


	glClear(GL_COLOR_BUFFER_BIT);
	int x1 = 0;
	int x2 = 0;
	int y1 = 800;
	int y2 = -800;
	int ofset = 50;
	for (int i = 0; i < 500; i = i +ofset) {
		x1 = x1 + i;
		//y1 = y1 + i;
		x2 = x2 - i;
		//y2 = y2 - i;
		ofset= ofset-1;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);

	glVertex2i(x1,y1);
	glVertex2f(x2,y2 );

	glEnd();
}
	glFlush();
	



}

void drawtest(){
	glClear(GL_COLOR_BUFFER_BIT);
	int x1 = 0;
	int x2 = 0;
	int y1 = 800;
	int y2 = -800;
	int ofset = 10;
	for (int i = 0; i < 20000; i = i + ofset) {
		x1 = x1 + i;
		y1 = y1 + i;
		x2 = x2 - i;
		y2 = y2 - i;
		ofset = ofset - 1;
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex2i(x1, y1);
		glVertex2f(x2, y2);

		glEnd();
	}
	glFlush();
}
void draw4(){

	
	// seting up initial variables 

	int sqSize = 600;
	int sqx = 600;
	int x1 = 0;
	int y1 = 0;

	int x2 = sqx;
	int y2 = 0;


	int x3 = sqx;
	int y3 = sqSize;


	int x4 = 0;
	int y4 = sqSize;
	
	
	glClear(GL_COLOR_BUFFER_BIT);


	float current_color=0.0;
	float colorD = 0.01; //color delta controls the color change between each square
	for (int i = 0; i <= 600; i = i + 10) { //10 controls the number of squueres

		glColor3f(current_color, current_color , current_color); //
		current_color = current_color +colorD; //make the color brighter
		
		
		int sizeSf = i/2;
		
		glBegin(GL_POLYGON);

			glVertex2i(x1+sizeSf, y1+sizeSf );     //v1
			glVertex2i(x2-sizeSf, y2+sizeSf);    //v2
			glVertex2i(x3-sizeSf , y3-sizeSf );  //v3

			glVertex2i(x4+sizeSf , y4-sizeSf);  //v4
			glEnd();
		

	}

		glFlush();


	


}

void drawPoints();




using namespace std;

int main(int argc, char **argv)
{
	int control;


		cout << "1) to draw figure 1  " << "  2) to draw figure 2  " << "  3) to draw figure 3  " << "  4) to draw figure 4  " << endl;
		cout << "Please enter a your choice:  ";
		cin >> control;

		//Initialize GLUT
		glutInit(&argc, argv);
		//double buffering used to avoid flickering problem in animation
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		// window size
		glutInitWindowSize(800, 600);
		// create the window 
		glutCreateWindow("Computer Graphics project 1 ");


		if (control == 3) {


			gluOrtho2D(0.0, 800.0, 0.0, 600.00);

			glClearColor(1.0, 1.0, 1.0, 0.0);
			glutDisplayFunc(draw3);

		}
		if (control == 4) {


			gluOrtho2D(0.0, 600.0, 0.0, 600.00);

		
			glClearColor(0.0, 0.0, 0.0, 0.0);
			glutDisplayFunc(draw4);

		}

		if (control == 2) {

			gluOrtho2D(0.0, 800.0, 0.0, 600.00);

			glClearColor(1.0, 1.0, 1.0, 0.0);
			glutDisplayFunc(draw2);

		}
		if (control == 1) {

			gluOrtho2D(-800.0, 800.0, -600.0, 600.0);

			glClearColor(1.0, 1.0, 1.0, 0.0);
			glutDisplayFunc(draw1);

		}


		glutMainLoop();
	
	return 0;
}



