add_executable(
    bishop_main
    main.cc
    )

find_package (Eigen3 3.3 REQUIRED)

target_include_directories(
    bishop_main
    PUBLIC
        ${CMAKE_HOME_DIRECTORY}/include
    )

target_link_libraries(bishop_main my_friend_bishop)
