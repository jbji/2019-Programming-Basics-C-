cmake_minimum_required(VERSION 3.15)

project(googletest-download NONE)

include(ExternalProject)

ExternalProject_Add(
        googletest
        SOURCE_DIR "C:/Users/jbji/CLionProjects/Test C course/test-framework/googletest-src"
        BINARY_DIR "C:/Users/jbji/CLionProjects/Test C course/test-framework/googletest-build"
        GIT_REPOSITORY
            https://github.com/google/googletest.git
        GIT_TAG
            release-1.8.1
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
)
