cmake_minimum_required (VERSION 3.8)

project(awesomeProject)

include_directories(include)
#aux_source_directory (src SRC_LIST)

set (SRC_LIST
    src/main.cpp
)

set (LIB_SRC
    src/memu.cpp
    src/sadc.cpp
)

add_library(lib SHARED ${LIB_SRC})

add_executable(main ${SRC_LIST})
add_dependencies(main lib)
target_link_libraries(main lib)

add_executable(main1 test/main1.cpp)
add_dependencies(main1 lib)
target_link_libraries(main1 lib)

add_executable(main2 test/main2.cpp)
add_dependencies(main2 lib)
target_link_libraries(main2 lib)

#set (SRC_LIST ./test/testSkiplish.cc)
#set (SRC_LIST ./test/testReadFile.cc)
#set (SRC_LIST ./test/testStudent.cc)

add_compile_options(-std=c++17 -Wall -g)

#add_executable (main ${SRC_LIST})
#add_executable (testSkiplish ${SRC_LIST})
#add_executable (testReadFile ${SRC_LIST})
#add_executable (testStudent ${SRC_LIST})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)