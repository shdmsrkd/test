cmake_minimum_required(VERSION 3.16)

project(QUdpSocket LANGUAGES CXX)

# C++17 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 라이브러리 찾기 (Qt6 사용 예시, Qt5를 사용할 경우 Qt5 대신 Qt6 사용)
find_package(Qt5 REQUIRED COMPONENTS Core Network)  # Add Network here

set(CMAKE_AUTOMOC ON)

# 실행 파일 생성
add_executable(QUdpSocket main.cpp myudp.h myudp.cpp)


# Qt Core 및 Network 라이브러리 링크
target_link_libraries(QUdpSocket Qt5::Core Qt5::Network)  # Add Qt5::Network here

# 설치 설정
include(GNUInstallDirs)
install(TARGETS QUdpSocket
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
