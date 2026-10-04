#include <glad/glad.h> // OpenGL loader
#include <GLFW/glfw3.h> // library with simple API for OpenGL
#include <iostream>

// Window resize callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Set new bottom left-corner + window size in pixels
    glViewport(0,0,width,height);
}

// Esc press callback
void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwWindowShouldClose(window);
    }
}

int main() {
    glfwInit();

    // Version of GLFW required
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // set up OpenGL's core-profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // MacOS-specific adjustment
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Gravity Sim", nullptr, nullptr);
    if (!window) {
        std::cout << "Window failed\n";
        glfwTerminate();
        return -1; }

    // Make the window context the main context on the current thread
    glfwMakeContextCurrent(window);

    // Initialize GLAD to find OpenGL's function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "glad failed\n";
        return -1;
    }

    // Register window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render loop (where each iteration = frame)
    while (!glfwWindowShouldClose(window)) {

        // Register esc press
        processInput(window);

        // Set RGB color + clear screen with it
        glClearColor(0.1f, 0.2f, 0.3f, 0.4f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Handle pending events
        glfwPollEvents();

        /* Swap between front and back buffer to ensure instant image visualization:
        rendering commands draw to the back buffer;
        when image is done, we swap back with front;
        front buffer shows the fully rendered image
        */
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}