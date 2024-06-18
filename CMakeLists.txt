cmake_minimum_required(VERSION 3.24)
project(SDIcwk)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDIcwk
        src/main.cpp
        headers/LocationManager.h
        src/LocationManager.cpp
        headers/MainMenu.h
        src/MainMenu.cpp
        headers/WeatherForecast.h
        src/WeatherForecast.cpp
        headers/Setting.h
        src/Setting.cpp
        headers/HistoricalWeather.h
        src/HistoricalWeather.cpp
        headers/AirQuality.h
        src/AirQuality.cpp headers/VariableHandler.h src/VariableHandler.cpp)

find_package(CURL REQUIRED)
target_link_libraries(SDIcwk PRIVATE CURL::libcurl)

set(BOOST_ROOT /opt/homebrew/Cellar/boost/1.84.0_1)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(ErrorChecking
        headers/LocationManager.h
        src/LocationManager.cpp
        testing/ErrorChecking.cpp headers/VariableHandler.h src/VariableHandler.cpp)
target_link_libraries(ErrorChecking PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ErrorChecking PRIVATE CURL::libcurl)


