
find_package(OpenGL REQUIRED)
find_package(SFML 2 REQUIRED network graphics window audio system)

# add_executable(${PROJECT_NAME} ${project_SRC})
add_executable(${PROJECT_NAME} 
	game_state_menu.cpp
    game.cpp
	input/menu_input.cpp
    game_manager.cpp
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
    ${OPENGL_LIBRARY}
	${SFML_LIBRARIES}
)
