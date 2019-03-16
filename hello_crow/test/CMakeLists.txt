include_directories(
        googletest-1.8.1/googletest/include googletest-1.8.1/googletest
        googletest-1.8.1/googlemock/include googletest-1.8.1/googlemock
)

add_subdirectory(googletest-1.8.1)

add_executable(runHelloCrowTests
        main.cpp test_main.cpp)

target_link_libraries(runHelloCrowTests gtest gtest_main gmock gmock_main)