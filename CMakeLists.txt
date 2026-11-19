cmake_minimum_required(VERSION 3.18)
project(HELLMS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Portable game sources (no platform-specific APIs)
set(HELLMS_SOURCES
    src/core/Time.cpp
    src/core/Application.cpp
    src/core/Game.cpp

    src/graphics/Camera.cpp
    src/graphics/Shader.cpp
    src/graphics/Mesh.cpp

    src/world/World.cpp
    src/world/House.cpp
    src/world/Forest.cpp
    src/world/Tree.cpp

    src/player/Player.cpp
    src/player/Controller.cpp

    src/ui/Menu.cpp
    src/ui/HUD.cpp
    src/ui/PauseMenu.cpp

    src/audio/AudioManager.cpp
)

if(ANDROID)
    # Android: build a JNI shared library (libhellms.so) packaged in the APK
    message("Building HELLMS for Android (NDK ${CMAKE_ANDROID_NDK_VERSION}, ABI ${ANDROID_ABI})")

    add_library(hellms SHARED
        ${HELLMS_SOURCES}
        src/platform/android_jni.cpp
    )

    target_include_directories(hellms PRIVATE src)

    target_link_libraries(hellms
        android
        log
        EGL
        GLESv2
    )

    target_compile_options(hellms PRIVATE -Wall -Wextra)
else()
    # Desktop: console executable (OpenGL available on the host)
    find_package(OpenGL REQUIRED)

    find_package(SDL2)
    if(SDL2_FOUND)
        message("SDL2 found - enabling input/window system")
    else()
        message("WARNING: SDL2 not found - building without SDL2 subsystem")
    endif()

    add_executable(hellms src/main.cpp ${HELLMS_SOURCES})
    target_include_directories(hellms PRIVATE src)

    target_link_libraries(hellms OpenGL::GL)
    if(SDL2_FOUND)
        target_link_libraries(hellms SDL2::SDL2)
    endif()

    install(TARGETS hellms DESTINATION bin)
endif()
