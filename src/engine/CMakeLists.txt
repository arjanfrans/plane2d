# add_subdirectory(utils/json)
add_subdirectory(utils/tmxparser)

add_subdirectory(states)
add_subdirectory(ecs)
add_subdirectory(input)
add_subdirectory(ui)

set(ENGINE_SOURCES
    # ${ENGINE_UTILS_JSON_SOURCES}
    ${ENGINE_UTILS_TMXPARSER_SOURCES}
    engine/config.cpp 
    engine/resource_manager.cpp
    engine/tile_map.cpp
    ${ENGINE_INPUT_SOURCES}
    ${ENGINE_STATES_SOURCES}
    ${ENGINE_ECS_SOURCES}
    ${ENGINE_UI_SOURCES}
    engine/engine.cpp
    engine/game.cpp
    PARENT_SCOPE
)
