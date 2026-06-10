project(Lab3 CXX)

add_executable(lab3)

target_sources("lab3"
  PRIVATE
    "main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
  "ssmodule.cppm"
   "delete_error.cppm")