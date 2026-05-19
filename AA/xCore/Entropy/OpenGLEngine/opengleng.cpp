#include "opengleng_private.hpp"
#include "e_Engine.hpp"
#include "x_threads.hpp"
#include "../Common/e_cdfs.hpp"

// Weird forward declaration stuff. Why weren't these put in a header? Who knows. Too lazy to extract from D3Dengine, sorry boss
void  draw_Init         ( void );
void  draw_Kill         ( void );

#define SCRATCH_MEM_SIZE (2*1024*1024)

struct opengleng_locals
{
    GLFWwindow* window;
    xbool       bActive;
    xbool       bReady;
    u32         Mode;
    s32         Width;
    s32         Height;
    xtick       FPSFrameTime[8];
    xtick       FPSLastTime;
};

static opengleng_locals s = { nullptr, FALSE, FALSE, ENG_ACT_DEFAULT, 800, 600 };

void opengleng_EntryPoint(s32& argc, char**& argv, void* reserved1, void* reserved2, void* reserved3, void* reserved4)
{
    (void)argc;
    (void)argv;
    (void)reserved1;
    (void)reserved2;
    (void)reserved3;
    (void)reserved4;

    if (!glfwInit())
    {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    s.window = glfwCreateWindow(s.Width, s.Height, "Tribes AA OpenGL", NULL, NULL);
    if (!s.window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(s.window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
    {
        glfwDestroyWindow(s.window);
        glfwTerminate();
        s.window = nullptr;
        return;
    }

    x_Init();

    s.Mode = ENG_ACT_DEFAULT;
    s.bActive = TRUE;
    s.bReady = FALSE;

    for (int i = 0; i < 8; ++i)
        s.FPSFrameTime[i] = 0;

    s.FPSLastTime = x_GetTime();

    vram_Init();
    draw_Init();
    smem_Init(SCRATCH_MEM_SIZE);
    opengleng_InitInput(s.window);

    s.bReady = TRUE;
}

s32 opengleng_ExitPoint(void)
{
    vram_Kill();
    draw_Kill();
    smem_Kill();

    if (s.window)
    {
        glfwDestroyWindow(s.window);
        s.window = nullptr;
    }

    glfwTerminate();
    s.bActive = FALSE;

    x_Kill();
    return 0;
}

void opengleng_SetPresets(u32 Mode)
{
    s.Mode = Mode;
}

RendererWindowHandle opengleng_GetWindowHandle(void)
{
    return static_cast<RendererWindowHandle>(s.window);
}

xbool opengleng_IsActive(void)
{
    return s.bActive;
}
