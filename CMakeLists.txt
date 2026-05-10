cmake_minimum_required(VERSION 4.2)
project(cpp_game)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Force static build of SFML" FORCE)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.0.2
)
FetchContent_MakeAvailable(SFML)

add_executable(cpp_game main.cpp
        include/Core/Game.h
        src/Core/Game.cpp
        src/Core/IScene.cpp
        include/Core/IScene.h
        include/Core/Constants.h
        include/ECS/Components.h
        src/ECS/Registry.cpp
        include/ECS/Registry.h
        src/ECS/systems/MovementSystem.cpp
        include/ECS/systems/MovementSystem.h
        include/ECS/Systems/ISystem.h
        src/ECS/Systems/RenderSystem.cpp
        include/ECS/Systems/RenderSystem.h)

target_link_libraries(cpp_game PRIVATE sfml-graphics sfml-window sfml-system)
