project(Lab4 CXX)

add_executable(lab4)

target_sources("lab4"
  PRIVATE
    "main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
  "squares.cppm"
  "sequence.cppm"
  "factorial.cppm"
  "delete_error.cppm"
  "helping_for_reading.cppm"
  "min_sequence.cppm")