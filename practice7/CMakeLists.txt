project(Practice7 CXX)

add_executable(practice7 main.cpp)

target_sources("practice7"
  PRIVATE
    "main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
  "Counters.cppm")