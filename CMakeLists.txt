
cmake_minimum_required(VERSION 3.1...3.28)

project(
  Game
  VERSION 1.0
  LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)


add_executable(Game main.cpp hero.h enemy.h GameControl.h setup.h area.h)

target_link_libraries(Game Qt5::Core Qt5::Quick Qt5::Sql)
