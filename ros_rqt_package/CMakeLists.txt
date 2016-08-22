cmake_minimum_required(VERSION 2.8.3)

project(ros_rqt_package)

# enable c++11 support
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++11 -O3")
endif(CMAKE_COMPILER_IS_GNUCXX)

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS roscpp rqt_gui rqt_gui_cpp)

# find Qt. ROS Kinetic needs Qt5
if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  find_package(Qt5Widgets REQUIRED)
else()
  find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
  include(${QT_USE_FILE})
endif()


set(ros_rqt_plugin_SRC
    src/ros_rqt_plugin/ros_rqt_plugin.cpp
)

# list only QT-Object headers
set(ros_rqt_plugin_HDRS
    include/ros_rqt_plugin/ros_rqt_plugin.h
)

set(ros_rqt_plugin_UIS
    src/ros_rqt_plugin/ros_rqt_plugin.ui
)

set(ros_rqt_plugin_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

catkin_package(
  INCLUDE_DIRS ${ros_rqt_plugin_INCLUDE_DIRECTORIES}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rqt_gui rqt_gui_cpp
)
catkin_python_setup()

if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  qt5_wrap_cpp(ros_rqt_plugin_MOCS ${ros_rqt_plugin_HDRS})
  qt5_wrap_ui(ros_rqt_plugin_UIS_H ${ros_rqt_plugin_UIS})
else()
  qt4_wrap_cpp(ros_rqt_plugin_MOCS ${ros_rqt_plugin_HDRS})
  qt4_wrap_ui(ros_rqt_plugin_UIS_H ${ros_rqt_plugin_UIS})
endif()

include_directories(${ros_rqt_plugin_INCLUDE_DIRECTORIES} ${catkin_INCLUDE_DIRS})
add_library(${PROJECT_NAME} ${ros_rqt_plugin_SRC} ${ros_rqt_plugin_MOCS} ${ros_rqt_plugin_UIS_H})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
else()
  target_link_libraries(${PROJECT_NAME} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
endif()


# Install
find_package(class_loader)
class_loader_hide_library_symbols(${PROJECT_NAME})

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(PROGRAMS scripts/ros_rqt_package
    DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES plugin.xml
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
