cmake_minimum_required(VERSION 3.15)

project(global-lesson1-task1)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC
        src/task.cpp)

# Files from `./test` directory
set(TEST
        test/test.cpp)


# Running learner side code
add_executable(global-lesson1-task1-run
        ${SRC})

# Running tests
configure_test_target(global-lesson1-task1-test
        ${SRC}
        ${TEST})