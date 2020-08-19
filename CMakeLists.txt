cmake_minimum_required(VERSION 3.10)

# set the project name
project(Mybashbrace)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify Flags
set(CMAKE_CXX_FLAGS "-Wall")

# Add the executable
add_executable(Mybashbrace main.cpp)

set_target_properties( Mybashbrace
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

enable_testing()

# Define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# Tests with Valid Input
do_test(Mybashbrace "{A,B,C}" "A B C")
do_test(Mybashbrace "{A,B}{C,D}" "AC AD BC BD")
do_test(Mybashbrace "{A,B{C,D}}" "A BC BD")
do_test(Mybashbrace "{ABC}" "ABC")
do_test(Mybashbrace "ABC" "ABC")

# Tests with Invalid Input
do_test(Mybashbrace "}ABC" "^$")
do_test(Mybashbrace "{ABC" "^$")
do_test(Mybashbrace "}{" "^$")
do_test(Mybashbrace "{}" "^$")
do_test(Mybashbrace "A,B,C" "^$")
do_test(Mybashbrace "{A{B,C}" "^$")
do_test(Mybashbrace "{A,}" "^$")
