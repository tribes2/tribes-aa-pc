# Default renderer backend (D3D or OPENGL)
RENDERER_BACKEND ?= OPENGL

# Base compiler flags
CXX = g++
CXXFLAGS = -I../xCore -I../Support -I../Support/BotEditor -I.. \
           -I../xCore/x_files -I../xCore/Entropy -I../xCore/Auxiliary/bitmap \
           -I../xCore/Entropy/Common -DTARGET_PC -DX_DEBUG -std=c++11 \
           -Wall -Wno-unused-variable -Wno-unused-function

# Conditional backend setup
ifeq ($(RENDERER_BACKEND), OPENGL)
  CXXFLAGS += -DRENDERER_BACKEND_OPENGL -I../xCore/Entropy/OpenGLEngine
  LDFLAGS = -lm -lpthread -ldl -lGL -lGLEW -lglfw
  BACKEND_SOURCES = \
    ../xCore/Entropy/OpenGLEngine/opengleng.cpp \
    ../xCore/Entropy/OpenGLEngine/opengleng_draw.cpp \
    ../xCore/Entropy/OpenGLEngine/opengleng_input.cpp \
    ../xCore/Entropy/OpenGLEngine/opengleng_vram.cpp
else
  CXXFLAGS += -DRENDERER_BACKEND_D3D -I../xCore/Entropy/D3DEngine
  LDFLAGS = -lm -lpthread -ldl
  # Note: On Linux, DirectX libs may not be available; adjust as needed
  BACKEND_SOURCES = \
    ../xCore/Entropy/D3DEngine/d3deng.cpp \
    ../xCore/Entropy/D3DEngine/d3deng_draw.cpp \
    ../xCore/Entropy/D3DEngine/d3deng_input.cpp \
    ../xCore/Entropy/D3DEngine/d3deng_vram.cpp
endif

# Common source files
SOURCES = \
    ../Support/Damage/Damage.cpp \
    ../Support/Fog/Fog.cpp \
    ../Support/PointLight/PointLight.cpp \
    event_Input.cpp \
    event_Render.cpp \
    event_Time.cpp \
    fe_Globals.cpp \
    FrontEnd.cpp \
    Globals.cpp \
    Main.cpp \
    MissionIO.cpp \
    titles.cpp \
    $(BACKEND_SOURCES)

OBJS = $(SOURCES:.cpp=.o)

TribesAADemo1: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) TribesAADemo1

.PHONY: clean
