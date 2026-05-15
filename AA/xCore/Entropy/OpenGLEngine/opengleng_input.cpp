#include "opengleng_private.hpp"

// Stub implementations for OpenGL input functions

xbool opengleng_InitInput(GLFWwindow* window) {
    // Set up GLFW callbacks
    return TRUE;
}

void opengleng_SetMouseMode(mouse_mode Mode) {
    // Set mouse mode
}

f32 opengleng_GetMouseX(void) {
    return 0.0f;
}

f32 opengleng_GetMouseY(void) {
    return 0.0f;
}

f32 opengleng_GetMouseWheel(void) {
    return 0.0f;
}

xbool opengleng_MouseGetLButton(void) {
    return FALSE;
}

xbool opengleng_MouseGetRButton(void) {
    return FALSE;
}