project(Lab5 CXX)

add_executable(lab5)

target_sources("lab5"
  PRIVATE
    "main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
    "counting_unique_words.cppm"
    "download_text.cppm"
    "frequent_repetition.cppm"
    "normalize.cppm")