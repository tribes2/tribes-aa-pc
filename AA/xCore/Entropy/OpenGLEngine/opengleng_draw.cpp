#include "opengleng_private.hpp"

// Stub implementations for OpenGL draw functions

void draw_Init(void) {
    // Set up OpenGL state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    // ... other initializations
}

void draw_Kill(void) {
    // Cleanup OpenGL state
}

void draw_Begin(void) {
    // Begin frame
}

void draw_End(void) {
    // End frame, swap buffers
    // glfwSwapBuffers(window);
}

void draw_Vertex(f32 x, f32 y, f32 z) {
    // Add vertex to buffer
}

void draw_Color(xcolor Color) {
    // Set color
}

void draw_UV(f32 u, f32 v) {
    // Set UV coordinates
}