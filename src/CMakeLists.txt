
find_package(OpenGL REQUIRED)
find_package(SFML 2 REQUIRED network graphics window audio system)


# directories for header inclusion
include_directories(
    ${OPENGL_INCLUDE_DIR}
	${SFML_INCLUDE_DIR}
)

# add_executable(${PROJECT_NAME} ${project_SRC})
add_executable(${PROJECT_NAME} 
    engine/input/input.cpp
    engine/states/state_manager.cpp
    engine/states/menu/menu_input.cpp
    engine/states/menu/menu_state.cpp
    engine/states/menu/menu_view.cpp
    engine/ui/mouse_listener.cpp
    engine/ui/button.cpp
    engine/game.cpp
    plane.cpp
    main.cpp
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARY}
	${SFML_LIBRARIES}
)
