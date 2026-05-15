#ifndef E_RENDERER_TYPES_HPP
#define E_RENDERER_TYPES_HPP

// Abstract handles for backend-specific types
typedef void* RendererTextureHandle;      // D3D: IDirect3DTexture8*, OpenGL: GLuint
typedef void* RendererWindowHandle;       // D3D: HWND, OpenGL: GLFWwindow*

// Shared enums (move from d3deng_private.hpp)
enum d3deng_mode {
    ENG_ACT_DEFAULT             = (0),
    ENG_ACT_FULLSCREEN          = (1<<0),
    ENG_ACT_SOFTWARE            = (1<<1),
    ENG_ACT_BACKBUFFER_LOCK     = (1<<2),
    ENG_ACT_STENCILOFF          = (1<<3),
    ENG_ACT_16_BPP              = (1<<4),
    ENG_ACT_SHADERS_IN_SOFTWARE = (1<<5),
    ENG_ACT_LOCK_WINDOW_SIZE    = (1<<6)
};

enum mouse_mode {
    MOUSE_MODE_BUTTONS,
    MOUSE_MODE_NEVER,
    MOUSE_MODE_ALWAYS,
    MOUSE_MODE_ABSOLUTE
};

#endif // E_RENDERER_TYPES_HPP