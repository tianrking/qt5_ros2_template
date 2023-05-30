cmake_minimum_required(VERSION 3.5)
project(my_project)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(
  ${rclcpp_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
)

add_executable(my_executable src/main.cpp)

target_link_libraries(my_executable 
  ${rclcpp_LIBRARIES} 
  Qt5::Widgets
)

ament_target_dependencies(my_executable rclcpp)

ament_package()
