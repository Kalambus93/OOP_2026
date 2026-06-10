project(Practice8 CXX)

add_executable(practice8 src/main.cpp)

target_sources("practice8" 
PRIVATE 
"src/main.cpp"
PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
"src/interface/IEnumerator.cppm"
"src/interface/IEnumerable.cppm"
"src/interface/ICollection.cppm"
"src/containers/List.cppm"
"src/containers/HashSet.cppm"
"src/containers/Dictionary.cppm"
"src/containers/Stack.cppm"
"src/containers/Queue.cppm"
)