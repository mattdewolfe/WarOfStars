#include <cstdlib>
#include <cmath>
#include <iostream>

#include "GameLogic.h"
#include "openGL/glut.h"

#define PI 3.14159265
							 
// global variables
static int animationPeriod = 33; // Time between draw calls
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection
static int width, height; // Size of the OpenGL window

static GameManager gameManager;

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
}

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{  
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
} 

// Initialization routine
void setup(void) 
{
   glEnable(GL_DEPTH_TEST);
   glClearColor (0.0, 0.0, 0.0, 0.0);
}
/*
// Function to check if two spheres centered at (x1,y1,z1) and (x2,y2,z2) with
// radius r1 and r2 intersect.
int checkSpheresIntersection(float x1, float y1, float z1, float r1, 
						     float x2, float y2, float z2, float r2)
{
   return ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) <= (r1+r2)*(r1+r2) );
}

// Function to check if the spacecraft collides with an asteroid when the center of the base
// of the craft is at (x, 0, z) and it is aligned at an angle a to to the -z direction.
// Collision detection is approximate as instead of the spacecraft we use a bounding sphere.
int asteroidCraftCollision(float x, float z, float a)
{
   int i,j;

   // Check for collision with each asteroid.
   for (j=0; j<COLUMNS; j++)
      for (i=0; i<ROWS; i++)
		 if (arrayAsteroids[i][j].getRadius() > 0 ) // If asteroid exists.
            if ( checkSpheresIntersection( x - 5 * sin( (PI/180.0) * a), 0.0, 
		         z - 5 * cos( (PI/180.0) * a), 7.072, 
		         arrayAsteroids[i][j].getCenterX(), arrayAsteroids[i][j].getCenterY(), 
		         arrayAsteroids[i][j].getCenterZ(), arrayAsteroids[i][j].getRadius() ) )
		       return 1;
   return 0;
}*/

// Drawing routine
void drawScene(void)
{  
	int i, j;
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gameManager.DrawVisuals();
/*	glRasterPos3f(3.0, 98.0f, zTime - 1.0f);
	writeBitmapString((void*)font, "Star Wars");
	
	// Write text in isolated (i.e., before gluLookAt) translate block.
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.0f, 0.0f, 0);
		glVertex3f(0.0f, 40.0f, 0);
	glEnd();

	glPopMatrix();*/
//	gluLookAt(width/2, height/2, -0.1, width/2, height/2, zTime, 0.0, 1.0, 0.0);
	glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(0.0, 50.0, 0.0, 50.0, 1.0, 200.0);
   glMatrixMode(GL_MODELVIEW);
   // Pass the size of the OpenGL window
   width = w;
   height = h;
}

// Keyboard input processing routine
void keyInput(unsigned char key, int x, int y)
{
   switch (key) 
   {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

// Callback routine for non-ASCII key entry
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT) 
	{ 
		if (gameManager.moveLeft == false)
			gameManager.moveLeft = true;
	}
	if (key == GLUT_KEY_RIGHT) 
	{ 
		if (gameManager.moveRight == false)
			gameManager.moveRight = true;
	}
		if (key == GLUT_KEY_DOWN) 
	{ 
		if (gameManager.moveDown == false)
			gameManager.moveDown = true;
	}
	if (key == GLUT_KEY_UP) 
	{ 
		if (gameManager.moveUp == false)
			gameManager.moveUp = true;
	}
}

// Callback routine for non-ASCII key release
void specialKeyUp(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT) 
	{ 
		if (gameManager.moveLeft == true)
			gameManager.moveLeft = false;
	}
	if (key == GLUT_KEY_RIGHT) 
	{ 
		if (gameManager.moveRight == true)
			gameManager.moveRight = false;
	}
		if (key == GLUT_KEY_DOWN) 
	{ 
		if (gameManager.moveDown == true)
			gameManager.moveDown = false;
	}
	if (key == GLUT_KEY_UP) 
	{ 
		if (gameManager.moveUp == true)
			gameManager.moveUp = false;
	}
}

// animation timer
void animate(int value)
{
 	glutPostRedisplay();
	glutTimerFunc(animationPeriod, animate, 1);
}

// Main routine
int main(int argc, char **argv) 
{
	printInteraction();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(250, 150); 
	glutCreateWindow("War of Stars");
	setup(); 
	glutDisplayFunc(drawScene); 
	glutReshapeFunc(resize);  
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	glutSpecialUpFunc(specialKeyUp);
	glutTimerFunc(animationPeriod, animate, 1);
	glutMainLoop(); 
	return 0;  
}

