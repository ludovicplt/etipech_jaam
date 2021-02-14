#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)


# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(myproject)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "Forgotten")
add_executable(${EXECUTABLE_NAME}
        src/Main.cpp
        src/Display.cpp
        src/Application.cpp
        src/Animation.cpp
        src/Util/Random.cpp
        src/States/PlayingState.cpp
        src/States/StateBase.cpp
        src/States/PastTacosCity.cpp
        src/States/PastOffice.cpp
        src/States/SpawnState.cpp
        src/States/LabEntryState.cpp
        src/States/LabReceptionState.cpp
        src/States/LabEndingState.cpp
        src/ResourceManagers/FontManager.cpp
        src/ResourceManagers/ResourceManager.cpp
        src/ResourceManagers/SoundManager.cpp
        src/ResourceManagers/TextureManager.cpp
        src/Util/Scaling.cpp
        src/States/MenuState.cpp
        src/EntityParser.cpp
        src/States/MenuState.h
        src/PlayerController.cpp
        src/PlayerController.h
        src/ICollidable.h src/SFMLExtension.h
        src/WorldObject.cpp
        src/States/SplashScreen.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
#find_package(SFML 2 REQUIRED network audio graphics window system)
#if(SFML_FOUND)
    #include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} pthread sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
#endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)
