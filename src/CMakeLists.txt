
# find_package(OpenGL REQUIRED)
find_package(Boost 1.54.0 REQUIRED COMPONENTS filesystem regex)
find_package(SFML 2 REQUIRED network graphics window audio system)
find_package(YamlCpp REQUIRED)

# directories for header inclusion
include_directories(
    ${OPENGL_INCLUDE_DIR}
	${SFML_INCLUDE_DIR}
    ${YAMLCPP_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    )

# add_executable(${PROJECT_NAME} ${project_SRC})
add_executable(${PROJECT_NAME} 
    engine/config.cpp
    engine/resource_manager.cpp
    engine/engine.cpp
    engine/ecs/components/input_component.cpp
    engine/ecs/components/view_component.cpp
    engine/ecs/components/input/player_input.cpp
    engine/ecs/components/view/player_view.cpp
    engine/ecs/controllable.cpp
    engine/ecs/drawable.cpp
    engine/ecs/entity.cpp
    engine/ecs/movable_entity.cpp
    # engine/ecs/player.cpp
    engine/states/view.cpp
    engine/input/input.cpp
    engine/input/global_input.cpp
    engine/states/state.cpp
    engine/states/world/world_state.cpp
    engine/states/world/world_input.cpp
    engine/states/world/world_view.cpp
    engine/states/menu/menu_state.cpp
    engine/states/menu/menu_input.cpp
    engine/states/menu/menu_view.cpp
    engine/ui/mouse_listener.cpp
    engine/ui/button.cpp
    engine/states/state_builder.cpp
    engine/game.cpp
    plane.cpp
    main.cpp
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARY}
    ${SFML_LIBRARIES}
    ${YAMLCPP_LIBRARY}
    ${Boost_LIBRARIES}
)
