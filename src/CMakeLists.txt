add_library(my_friend_bishop "")

target_sources(
    my_friend_bishop
    PRIVATE
        Bishop.cc
    PUBLIC
        ${CMAKE_HOME_DIRECTORY}/include/${PROJECT_NAME}/Bishop.h
    )

target_include_directories(
    my_friend_bishop
    PUBLIC
        ${CMAKE_HOME_DIRECTORY}/include
    )

target_link_libraries(my_friend_bishop)
