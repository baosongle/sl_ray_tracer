cmake_minimum_required(VERSION 3.23)
project(sl_ray_tracer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(sl_ray_tracer main.cpp tuple.cpp tuple.h)

enable_testing()

add_executable(
        tuple_test
        tuple_test.cpp
        tuple.cpp
)
target_link_libraries(
        tuple_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tuple_test)