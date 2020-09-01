cmake_minimum_required(VERSION 3.15)
project(dataStructs)
set(CMAKE_CXX_STANDARD 14)
file(GLOB INCLUDES "include/*.h")


#-----------Individual Project Setup ---------
add_library(dataStructslib INTERFACE)
target_include_directories(dataStructslib
        INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# -------------- TESTING EXECUTABLES ---------------- #
#---------GOOGLE TESTING SETUP --------- (UNCOMMENT THIS BLOCK)
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()


# --------------- INDIVIDUAL TESTS -------------------
# Uncomment whichever test you want to run
add_executable(dataStructsTestStack test/stackTest.cpp)
target_link_libraries(dataStructsTestStack gtest_main)

add_executable(dataStructsTestQueue test/queueTest.cpp)
target_link_libraries(dataStructsTestQueue gtest_main)

add_executable(dataStructsTestLinkedList test/LinkedListTest.cpp)
target_link_libraries(dataStructsTestLinkedList gtest_main)

add_executable(dataStructsTestArrayList test/ArrayListTest.cpp)
target_link_libraries(dataStructsTestArrayList gtest_main)


