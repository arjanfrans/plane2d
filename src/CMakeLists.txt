set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/buildsystem")

Set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB project_SRC
    "*.h"
    "*.cpp"
)

# add_executable(${PROJECT_NAME} ${project_SRC})
add_executable(${PROJECT_NAME} 
    main.cpp
    game.cpp
    engine/engine.cpp
    engine/renderer.cpp
)

# directories for header inclusion
include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    m
    ${OPENGL_LIBRARY}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
)

