project(Practice9 LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

target_sources(${PROJECT_NAME}
    PRIVATE
    src/main.cpp
    PRIVATE FILE_SET CXX_MODULES FILES
    src/lib/LogicGame.cppm
)