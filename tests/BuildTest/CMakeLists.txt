add_executable( CPVector_BuildTest tester.cc ) 
target_link_libraries( CPVector_BuildTest PUBLIC CPVector PUBLIC GTest::gtest_main )