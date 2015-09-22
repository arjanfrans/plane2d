find_package(Boost 1.54.0 REQUIRED COMPONENTS filesystem regex)
find_package(SFML 2 REQUIRED network graphics window audio system)
find_package(YamlCpp REQUIRED)
find_package(TinyXML2 REQUIRED)
find_package(ZLIB REQUIRED)


# directories for header inclusion
include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${TINYXML2_INCLUDE_DIR}
    ${ZLIB_INCLUDE_DIRS}
	${SFML_INCLUDE_DIR}
    ${YAMLCPP_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
)

add_subdirectory(engine)
add_subdirectory(platformer)

# Source files (.cpp files)
set(SOURCES 
    ${ENGINE_SOURCES}
    ${PLATFORMER_SOURCES}
)

# Add source files as executables
add_executable(${PROJECT_NAME}
    ${SOURCES}
)

# link the executable to those libraries
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARY}
    ${SFML_LIBRARIES}
    ${ZLIB_LIBRARIES}
    ${TINYXML2_LIBRARIES}
    ${YAMLCPP_LIBRARY}
    ${Boost_LIBRARIES}
)
