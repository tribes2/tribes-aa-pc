#ifndef OPENGLENG_PRIVATE_HPP
#define OPENGLENG_PRIVATE_HPP

#include "../e_RendererTypes.hpp"

// OpenGL-specific includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// OpenGL-specific structures (if any needed)
struct opengl_context {
    GLFWwindow* window;
    GLuint vertexArrayObject;
    GLuint shaderProgram;
    // ... other OpenGL state ...
};

// OpenGL shader handle (maps to s32 ID like D3D)
struct opengl_vertex_shader {
    char name[32];
    GLuint handle;
    // ... other shader data ...
};

// Function declarations (same signatures as D3D backend)
void        opengleng_EntryPoint      ( s32& argc, char**& argv, void* reserved1, void* reserved2, void* reserved3, void* reserved4 );
s32         opengleng_ExitPoint       ( void );
void        opengleng_SetPresets      ( u32 Mode );
RendererWindowHandle opengleng_GetWindowHandle( void );
xbool       opengleng_IsActive        ( void );
xbool       opengleng_InitInput       ( GLFWwindow* window );

void        opengleng_SetMouseMode    ( mouse_mode Mode );
f32         opengleng_GetMouseX       ( void );
f32         opengleng_GetMouseY       ( void );
f32         opengleng_GetMouseWheel   ( void );
xbool       opengleng_MouseGetLButton ( void );
xbool       opengleng_MouseGetRButton ( void );

#endif // OPENGLENG_PRIVATE_HPP