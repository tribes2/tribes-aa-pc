# Default renderer backend (D3D or OPENGL)
RENDERER_BACKEND ?= OPENGL

# Base compiler flags
CXX = g++
CXXFLAGS = -I../xCore -I../Support -I../Support/BotEditor -I.. \
           -I../xCore/x_files -I../xCore/Entropy -I../xCore/Auxiliary/bitmap \
           -I../xCore/Entropy/Common -I../../osdialog -DTARGET_PC -DX_DEBUG -std=c++11 \
           -Wall -Wno-unused-variable -Wno-unused-function -fPIC

# Conditional backend setup
ifeq ($(RENDERER_BACKEND), OPENGL)
  CXXFLAGS += -DRENDERER_BACKEND_OPENGL -I../xCore/Entropy/OpenGLEngine
  LDFLAGS = -lm -lpthread -ldl -lGL -lGLEW -lglfw $(shell pkg-config --libs gtk+-3.0)
  BACKEND_SOURCES = \
    ../xCore/Entropy/OpenGLEngine/opengleng.cpp \
    ../xCore/Entropy/OpenGLEngine/opengleng_draw.cpp \
    ../xCore/Entropy/OpenGLEngine/opengleng_input.cpp \
    ../xCore/Entropy/OpenGLEngine/opengleng_vram.cpp
else
  CXXFLAGS += -DRENDERER_BACKEND_D3D -I../xCore/Entropy/D3DEngine
  LDFLAGS = -lm -lpthread -ldl $(shell pkg-config --libs gtk+-3.0)
  # Note: On Linux, DirectX libs may not be available; adjust as needed
  BACKEND_SOURCES = \
    ../xCore/Entropy/D3DEngine/d3deng.cpp \
    ../xCore/Entropy/D3DEngine/d3deng_draw.cpp \
    ../xCore/Entropy/D3DEngine/d3deng_input.cpp \
    ../xCore/Entropy/D3DEngine/d3deng_vram.cpp
endif

# Core Demo1 files
DEMO_SOURCES = \
    event_Input.cpp \
    event_Render.cpp \
    event_Time.cpp \
    fe_Globals.cpp \
    FrontEnd.cpp \
    Globals.cpp \
    Main.cpp \
    MissionIO.cpp \
    titles.cpp

# Support library sources - compile most support modules
SUPPORT_SOURCES = \
    $(wildcard ../Support/Damage/*.cpp) \
    $(wildcard ../Support/Fog/*.cpp) \
    $(wildcard ../Support/PointLight/*.cpp) \
    $(filter-out ../Support/Building/PS2BldRender.cpp,$(wildcard ../Support/Building/*.cpp)) \
    $(wildcard ../Support/Poly/*.cpp) \
    $(wildcard ../Support/Sky/*.cpp) \
    $(wildcard ../Support/Shield/*.cpp) \
    $(wildcard ../Support/GameMgr/*.cpp) \
    $(wildcard ../Support/NetworkMgr/*.cpp) \
    $(wildcard ../Support/Objects/*.cpp) \
    $(wildcard ../Support/Objects/Terrain/*.cpp) \
    $(filter-out ../Support/Objects/Bot/FibTest.cpp,$(wildcard ../Support/Objects/Bot/*.cpp)) \
    $(wildcard ../Support/Objects/Projectiles/*.cpp) \
    $(wildcard ../Support/EventMgr/*.cpp) \
    $(wildcard ../Support/ObjectMgr/*.cpp) \
    $(wildcard ../Support/LabelSets/*.cpp) \
    $(wildcard ../Support/CardMgr/*.cpp) \
    $(wildcard ../Support/Tokenizer/*.cpp) \
    $(wildcard ../Support/StringMgr/*.cpp) \
    $(wildcard ../Support/UI/*.cpp) \
    $(wildcard ../Support/Hud/*.cpp) \
    $(wildcard ../Support/AudioMgr/*.cpp) \
    $(wildcard ../Support/NetLib/*.cpp)

# xCore library sources
XCORE_SOURCES = \
    $(wildcard ../xCore/x_files/*.cpp) \
    $(wildcard ../xCore/Auxiliary/*.cpp) \
    $(wildcard ../xCore/Auxiliary/bitmap/*.cpp) \
    $(wildcard ../xCore/Entropy/Common/*.cpp) \
    ../../osdialog/osdialog.c \
    ../../osdialog/osdialog_gtk.c

# Combine all sources
SOURCES = $(DEMO_SOURCES) $(SUPPORT_SOURCES) $(XCORE_SOURCES) $(BACKEND_SOURCES)

# Generate object file list (preserve directory structure via sed)
OBJS = $(addprefix obj/,$(SOURCES:.cpp=.o))
OBJS := $(OBJS:.c=.o)

# Main target
TribesAADemo1: obj $(OBJS)
	@echo "Linking $@..."
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)
	@echo "Build complete: $@"

# Create object directories
obj:
	mkdir -p obj

# Compile rule with automatic directory creation
obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $(notdir $<)..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $(notdir $<)..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf obj TribesAADemo1

# Show all sources to be compiled
show-sources:
	@echo "Demo files:"
	@echo "$(DEMO_SOURCES)"
	@echo ""
	@echo "Support files (count: $(words $(SUPPORT_SOURCES))):"
	@echo "$(SUPPORT_SOURCES)"
	@echo ""
	@echo "xCore files (count: $(words $(XCORE_SOURCES))):"
	@echo "$(XCORE_SOURCES)"

.PHONY: clean show-sources
