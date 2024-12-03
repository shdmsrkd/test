cmake_minimum_required(VERSION 3.8)
project(qt_udp_sender_ros2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Qt5 COMPONENTS Core Network REQUIRED)

add_executable(qt_udp_node
  src/main.cpp
  src/myudp.cpp
  src/myudp.hpp
)

ament_target_dependencies(qt_udp_node
  rclcpp
)

target_link_libraries(qt_udp_node
  Qt5::Core
  Qt5::Network
)

install(TARGETS
  qt_udp_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
