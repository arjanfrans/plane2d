
find_package(OpenGL REQUIRED)
find_package(SFML 2 REQUIRED network graphics window audio system)

# add_executable(${PROJECT_NAME} ${project_SRC})
add_executable(${PROJECT_NAME} 
	texture_manager.cpp
	tile.cpp
	map.cpp
	animation.cpp
	animation_handler.cpp
	game_state_world.cpp
	game_state_menu.cpp
    game.cpp
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
