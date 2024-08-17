include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.11.0
)
fetchcontent_makeavailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)

target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(complex_datastuctures_test trie_tests.cpp)

target_link_libraries(complex_datastuctures_test
    PRIVATE
    GTest::GTest
    complex_datastructures
)

