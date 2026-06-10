project(Lab2 CXX)

add_executable(lab2)

target_sources("lab2"
  PRIVATE
    "main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
    "vec.cppm"
)