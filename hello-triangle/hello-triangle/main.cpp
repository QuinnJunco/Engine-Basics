#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertex_shader_source = "#version 420 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragment_shader_source = "#version 420 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
" FragColor = vec4(.8f, .9f, .1f, 1.0f);\n"
"}\0";

/**
* Called when the window is resized
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


/**
* Handles input events to the window
*/
void process_input(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //checks for escape to close the window
		glfwSetWindowShouldClose(window, true);

}

int main(){

	glfwInit(); // initializes GLFW library

	// tells glfw which opengl version to use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int status { 0 };

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World!", nullptr, nullptr); // creates a new window
	if (window == nullptr) {
		std::cout << "Failed to initialize window." << std::endl;
		status = { 1 };
	}

	if (!status)
		glfwMakeContextCurrent(window); // sets the opengl context
	

	if (!status && !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { // initializes glad
		std::cout << "Failed to initialize GLAD. Status: " << std::dec << status << std::endl;
		status = { 2 };
	}

	if (!status) {
		float vertices[] = { // triangle vertices
			-0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f
		};

		unsigned int shader_program; // initializes shader program

		unsigned int VBO; // Vertext Buffer Object

		glGenBuffers(1, &VBO); // generates the buffer with id=1
		glBindBuffer(GL_ARRAY_BUFFER, VBO); // binds the buffer to the GPU
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // sets the vertices once to be used many times

		unsigned int VAO; // Vertex Array Object
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO); // binds VAO

		glViewport(0, 0, 640, 480); // sets the viewport dimensions

		/* VERTEX SHADER */
		unsigned int vertext_shader;
		vertext_shader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertext_shader, 1, &vertex_shader_source, nullptr);
		glCompileShader(vertext_shader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertext_shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(vertext_shader, 512, nullptr, infoLog);
			std::cout << "Failed to compile vertex shader: \n" << infoLog << std::endl;
			status = 3;
		}
		else {
			
			/* FRAGMENT SHADER */
			unsigned int fragment_shader;
			fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

			glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
			glCompileShader(fragment_shader);

			glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(fragment_shader, 512, nullptr, infoLog);
				std::cout << "Failed to compile fragment shader: \n" << infoLog << std::endl;
				status = 4;
			}
			else {
				// creates a shader program
				shader_program = glCreateProgram();
				glAttachShader(shader_program, vertext_shader);
				glAttachShader(shader_program, fragment_shader);
				glLinkProgram(shader_program);

				glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
				if (!success) {
					glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
					std::cout << "Failed to link shader program: \n" << infoLog << std::endl;
					status = 5;
				}
				else {
					glUseProgram(shader_program); // sets the program to be used by the opengl context

					// deletes leftover shader objects
					glDeleteShader(vertext_shader);
					glDeleteShader(fragment_shader);
				}
			}

		}

		if (!status) {

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);


			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
			// main loop
			while (!glfwWindowShouldClose(window)) {

				process_input(window); // process input

				/* RENDERING */
				glClearColor(.2f, .4f, .8f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				glUseProgram(shader_program);
				glBindVertexArray(VAO);
				glDrawArrays(GL_TRIANGLES, 0, 3);

				glfwSwapBuffers(window); // swaps opengl buffers
				glfwPollEvents();
			}
		}
	}
	

	glfwTerminate(); // terminates opengl

	std::cout << status << std::endl;
	return status;
}