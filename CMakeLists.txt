cmake_minimum_required(VERSION 3.5)

project(
  constraints
  VERSION 1.0
  LANGUAGES CXX)

add_compile_options("-g3" "-Wall")
add_library(libscrabble Word.cxx)
target_compile_features(
  libscrabble PUBLIC
  cxx_generalized_initializers)

add_executable(show-board show-board.cxx)
target_link_libraries(show-board libscrabble)

add_executable(test-word test-word.cxx)
target_link_libraries(test-word libscrabble)

add_executable(scrabble scrabble.cxx)
target_link_libraries(scrabble libscrabble)
