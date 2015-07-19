set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMake")


find_package(OpenGL REQUIRED)
find_package(SFML REQUIRED system window graphics network audio)

# add_executable(${PROJECT_NAME} ${project_SRC})
add_executable(${PROJECT_NAME} 
    game.cpp
	game_state_menu.cpp
    main.cpp
)

# directories for header inclusion
include_directories(
    ${OPENGL_INCLUDE_DIR}
	${SFML_INCLUDE_DIR}
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    m
    ${OPENGL_LIBRARY}
	${SFML_LIBRARIES}
)

