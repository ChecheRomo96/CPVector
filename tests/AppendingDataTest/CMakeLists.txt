add_executable( CPVector_AppendingData tester.cc ) 
target_link_libraries( CPVector_AppendingData PUBLIC CPVector PUBLIC GTest::gtest_main )
gtest_discover_tests(CPVector_AppendingData)