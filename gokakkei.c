#include <GLUT/glut.h>

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	glFlush();
}

void init(void) {
	glClearColor(0.9, 0.9, 0.9, 0.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1.0, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void key(unsigned char key, int x, int y) {
	if (key == 'q') exit(0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Gokakkei Polygon");

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}

