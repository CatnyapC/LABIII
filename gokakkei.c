
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>

int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(500, 500, "Gokakkei Polygon", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
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

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
