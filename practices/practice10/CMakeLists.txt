project("Practice10" LANGUAGES CXX)

find_package(SFML COMPONENTS Graphics CONFIG REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/main.cpp
    PRIVATE FILE_SET CXX_MODULES FILES
    lib/Renderer.cppm
    lib/LogicGame.cppm
    lib/Assets.cppm
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    SFML::Graphics
)

add_custom_target(${PROJECT_NAME}_pictures
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/pictures
    ${CMAKE_CURRENT_BINARY_DIR}/pictures
)

add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_pictures)