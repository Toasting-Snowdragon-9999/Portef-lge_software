
  cmake_minimum_required(VERSION 3.1...3.28)

  project(
    Game
    VERSION 1.0
    LANGUAGES CXX)

  add_executable(Game main.cpp)
  target_sources(Game PRIVATE hero.h enemy.h game.cpp GameControl.h area.h database_handler.h exit.h shop.h item.h)

  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED True)

  find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)
  target_include_directories(Game PRIVATE ${Qt5Sql_INCLUDE_DIRS})
  target_link_libraries(Game Qt5::Core Qt5::Quick Qt5::Sql)
