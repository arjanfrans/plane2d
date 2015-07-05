find_package(OpenGL REQUIRED)

file(GLOB project_SRC
    "*.h"
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${project_SRC})

# directories for header inclusion
include_directories(
    ${OPENGL_INCLUDE_DIR}
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARY}
)

