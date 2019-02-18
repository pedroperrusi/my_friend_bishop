add_executable(
    bishop_tests
    test_Bishop.cc
  )

target_link_libraries(
    bishop_tests
    my_friend_bishop
    gtest_main
  )

target_include_directories(
    bishop_tests
    PUBLIC
    ${CMAKE_HOME_DIRECTORY}/include
  )

add_test(
    NAME
      unit
    COMMAND
      ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
