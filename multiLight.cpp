//#include<iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<stb/stb_image.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//
//#include"Texture.h"
//#include"shaderClass.h"
//#include"VAO.h"
//#include"VBO.h"
//#include"EBO.h"
//#include"Camera.h"
//
//
//
//const unsigned int width = 800;
//const unsigned int height = 800;
//
//
//
//// Vertices coordinates
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side
//
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
//
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side
//
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2, // Bottom side
//	0, 2, 3, // Bottom side
//	4, 6, 5, // Left side
//	7, 9, 8, // Non-facing side
//	10, 12, 11, // Right side
//	13, 15, 14 // Facing side
//};
//
//GLfloat lightVertices[] =
//{ //     COORDINATES     //
//	-0.1f, -0.1f,  0.1f,
//	-0.1f, -0.1f, -0.1f,
//	 0.1f, -0.1f, -0.1f,
//	 0.1f, -0.1f,  0.1f,
//	-0.1f,  0.1f,  0.1f,
//	-0.1f,  0.1f, -0.1f,
//	 0.1f,  0.1f, -0.1f,
//	 0.1f,  0.1f,  0.1f
//};
//
//GLuint lightIndices[] =
//{
//	0, 1, 2,
//	0, 2, 3,
//	0, 4, 7,
//	0, 7, 3,
//	3, 7, 6,
//	3, 6, 2,
//	2, 6, 5,
//	2, 5, 1,
//	1, 5, 4,
//	1, 4, 0,
//	4, 5, 6,
//	4, 6, 7
//};
//
//
//void multi_light()
//{
//	// Initialize GLFW
//	glfwInit();
//
//	// Tell GLFW what version of OpenGL we are using 
//	// In this case we are using OpenGL 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	// Tell GLFW we are using the CORE profile
//	// So that means we only have the modern functions
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
//	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
//	// Error check if the window fails to create
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return;
//	}
//	// Introduce the window into the current context
//	glfwMakeContextCurrent(window);
//
//	//Load GLAD so it configures OpenGL
//	gladLoadGL();
//	// Specify the viewport of OpenGL in the Window
//	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
//	glViewport(0, 0, width, height);
//
//
//
//	// Generates Shader object using shaders default.vert and default.frag
//	Shader shaderProgram("multiLight.vert", "multiLight.frag");
//	// Generates Vertex Array Object and binds it
//	VAO VAO1;
//	VAO1.Bind();
//	// Generates Vertex Buffer Object and links it to vertices
//	VBO VBO1(vertices, sizeof(vertices));
//	// Generates Element Buffer Object and links it to indices
//	EBO EBO1(indices, sizeof(indices));
//	// Links VBO attributes such as coordinates and colors to VAO
//	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//	// Unbind all to prevent accidentally modifying them
//	VAO1.Unbind();
//	VBO1.Unbind();
//	EBO1.Unbind();
//
//
//	// Shader for light cube
//	Shader lightShader("light.vert", "light.frag");
//	// Generates Vertex Array Object and binds it
//	VAO lightVAO;
//	lightVAO.Bind();
//	// Generates Vertex Buffer Object and links it to vertices
//	VBO lightVBO(lightVertices, sizeof(lightVertices));
//	// Generates Element Buffer Object and links it to indices
//	EBO lightEBO(lightIndices, sizeof(lightIndices));
//	// Links VBO attributes such as coordinates and colors to VAO
//	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
//	// Unbind all to prevent accidentally modifying them
//	lightVAO.Unbind();
//	lightVBO.Unbind();
//	lightEBO.Unbind();
//
//
//
//
//
//	// Texture
//	Texture brickTex(("brick.png"), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
//	brickTex.texUnit(shaderProgram, "tex0", 0);
//
//
//
//	// Enables the Depth Buffer
//	glEnable(GL_DEPTH_TEST);
//
//	// Creates camera object
//	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 3.0f));
//
//	glm::vec3 lightPos2 = glm::vec3(0.5f, -0.5f, 0.5f);
//	glm::vec4 lightColor1 = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f); // red light
//	glm::vec4 lightColor2 = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f); // green light
//
//	// Main while loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Specify the color of the background
//		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//		// Clean the back buffer and depth buffer
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// Handles camera inputs
//		camera.Inputs(window);
//		// Updates and exports the camera matrix to the Vertex Shader
//		camera.updateMatrix(45.0f, 0.1f, 100.0f);
//
//		float time = glfwGetTime();
//		float x = cos(time) * 2.0f;
//		float z = sin(time) * 2.0f;
//		glm::vec3 lightPos1 = glm::vec3(x, 0.5f, z);
//		glm::vec3 lightPos2 = glm::vec3(0.5f, sin(2*time+1), sin(2 * time + 1));
//		glm::mat4 lightModel1 = glm::translate(glm::mat4(1.0f), lightPos1);
//		glm::mat4 lightModel2 = glm::translate(glm::mat4(1.0f), lightPos2);
//
//		// Light cube MOVING
//		lightShader.Activate();
//		camera.Matrix(lightShader, "camMatrix");
//		glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel1));
//		glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor1.r, lightColor1.g, lightColor1.b, lightColor1.a);
//		lightVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
//
//		// Light cube 2 (also moving)
//		glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel2));
//		glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor2.r, lightColor2.g, lightColor2.b, lightColor2.a);
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
//
//
//		// Pyramid
//		shaderProgram.Activate();
//		camera.Matrix(shaderProgram, "camMatrix");
//		glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos[0]"), lightPos1.x, lightPos1.y, lightPos1.z);
//		glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos[1]"), lightPos2.x, lightPos2.y, lightPos2.z);
//		glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor[0]"), lightColor1.r, lightColor1.g, lightColor1.b, lightColor1.a);
//		glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor[1]"), lightColor2.r, lightColor2.g, lightColor2.b, lightColor2.a); // green second light
//		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//
//		glm::mat4 pyramidModel = glm::mat4(1.0f);
//		glm::vec3 pyramidPos = glm::vec3(0.0f,cos(time), 0.0f);
//		pyramidModel = glm::translate(pyramidModel, pyramidPos);
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
//
//		brickTex.Bind(GL_TEXTURE0);
//		VAO1.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
//		// Swap the back buffer with the front buffer
//		glfwSwapBuffers(window);
//		// Take care of all GLFW events
//		glfwPollEvents();
//	}
//
//
//
//	// Delete all the objects we've created
//	VAO1.Delete();
//	VBO1.Delete();
//	EBO1.Delete();
//	brickTex.Delete();
//	shaderProgram.Delete();
//	lightVAO.Delete();
//	lightVBO.Delete();
//	lightEBO.Delete();
//	lightShader.Delete();
//	// Delete window before ending the program
//	glfwDestroyWindow(window);
//	// Terminate GLFW before ending the program
//	glfwTerminate();
//	return;
//	//check check
//}