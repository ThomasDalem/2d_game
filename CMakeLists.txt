cmake_minimum_required(VERSION 3.7)

project(2d_game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SRCS
    src/main.cpp
    src/MainLoop.cpp
    src/utils/TexturesLoader.cpp
    src/utils/Timer.cpp
    src/SDL/App.cpp
    src/SDL/Surface.cpp
    src/SDL/Texture.cpp
    src/SDL/Renderer.cpp
    src/systems/RenderSystem.cpp
    src/systems/PlayerMovement.cpp
    src/systems/AnimationSystem.cpp
    src/systems/MovementSystem.cpp
    src/entities/playerEntity.cpp
)
    
set(HEADERS
    src/MainLoop.hpp
    src/utils/Vec.hpp
    src/utils/Rect.hpp
    src/utils/TexturesLoader.hpp
    src/utils/Timer.hpp
    src/SDL/App.hpp
    src/SDL/Surface.hpp
    src/SDL/Texture.hpp
    src/SDL/Renderer.hpp
    src/components/Position.hpp
    src/components/Sprite.hpp
    src/components/Player.hpp
    src/components/Animation.hpp
    src/components/Movement.hpp
    src/components/Relationship.hpp
    src/systems/RenderSystem.hpp
    src/systems/PlayerMovement.hpp
    src/systems/AnimationSystem.hpp
    src/systems/MovementSystem.hpp
    src/entities/playerEntity.hpp
)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -g)
endif()


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(2d_game ${SRCS} ${HEADERS})
target_include_directories(2d_game PRIVATE "src/" "include/")
target_link_libraries(2d_game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})