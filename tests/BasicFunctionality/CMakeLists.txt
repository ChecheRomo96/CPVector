add_executable( CPVector_BasicFunctionality BasicFunctionalityTesting.cc ) 
target_link_libraries( CPVector_BasicFunctionality PUBLIC CPVector PUBLIC GTest::gtest_main )
gtest_discover_tests(CPVector_BasicFunctionality)

add_executable( CPVector_Constructors ConstructorTesting.cc ) 
target_link_libraries( CPVector_Constructor PUBLIC CPVector PUBLIC GTest::gtest_main )
gtest_discover_tests(CPVector_Constructor)

add_executable( CPVector_DynamicAllocation DynamicAllocationTesting.cc ) 
target_link_libraries( CPVector_DynamicAllocation PUBLIC CPVector PUBLIC GTest::gtest_main )
gtest_discover_tests(CPVector_DynamicAllocation)

add_executable( CPVector_Operators OperatorTesting.cc ) 
target_link_libraries( CPVector_Operator PUBLIC CPVector PUBLIC GTest::gtest_main )
gtest_discover_tests(CPVector_Operator)