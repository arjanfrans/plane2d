# find_package(OpenGL REQUIRED)
find_package(Boost 1.54.0 REQUIRED COMPONENTS filesystem regex)
find_package(SFML 2 REQUIRED network graphics window audio system)
find_package(TmxParser REQUIRED)
find_package(YamlCpp REQUIRED)

# directories for header inclusion
include_directories(
    ${TMXPARSER_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
	${SFML_INCLUDE_DIR}
    ${YAMLCPP_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
)

add_subdirectory(engine)
add_subdirectory(platformer)

set(SOURCES 
    ${ENGINE_SOURCES}
    ${PLATFORMER_SOURCES}
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    ${TMXPARSER_LIBRARY}
    ${OPENGL_LIBRARY}
    ${SFML_LIBRARIES}
    ${YAMLCPP_LIBRARY}
    ${Boost_LIBRARIES}
)
