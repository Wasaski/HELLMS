cmake_minimum_required(VERSION 3.18)
project(HELLMS VERSION 0.1 LANGUAGES CXX)

# C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL (always available)
find_package(OpenGL REQUIRED)

# SDL2 - check if available
find_package(SDL2)
if(SDL2_FOUND)
    message("SDL2 found - enabling input/window system")
else()
    message("WARNING: SDL2 not found - building without SDL2 subsystem")
endif()

# Source files - all modules
set(SOURCES
    src/main.cpp
    
    # Core
    src/core/Time.cpp
    src/core/Application.cpp
    src/core/Application.hpp
    src/core/Time.hpp
    src/core/Game.cpp
    src/core/Game.hpp
    
    # Graphics
    src/graphics/Camera.cpp
    src/graphics/Camera.hpp
    src/graphics/Shader.cpp
    src/graphics/Shader.hpp
    src/graphics/Mesh.cpp
    src/graphics/Mesh.hpp
    
    # World
    src/world/World.cpp
    src/world/World.hpp
    src/world/House.cpp
    src/world/House.hpp
    src/world/Forest.cpp
    src/world/Forest.hpp
    src/world/Tree.cpp
    src/world/Tree.hpp
    
    # Player
    src/player/Player.cpp
    src/player/Player.hpp
    src/player/Controller.cpp
    src/player/Controller.hpp
    
    # UI
    src/ui/Menu.cpp
    src/ui/Menu.hpp
    src/ui/HUD.cpp
    src/ui/HUD.hpp
    src/ui/PauseMenu.cpp
    src/ui/PauseMenu.hpp
    
    # Audio
    src/audio/AudioManager.cpp
    src/audio/AudioManager.hpp
)

# Add executable
add_executable(hellms ${SOURCES})

target_link_libraries(hellms
    OpenGL::GL
)

if(SDL2_FOUND)
    target_link_libraries(hellms SDL2::SDL2)
endif()

# Install target
install(TARGETS hellms DESTINATION bin)