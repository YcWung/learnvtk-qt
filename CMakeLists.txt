cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(PointCloudViewer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE DEBUG)

find_package(VTK
  COMPONENTS
  CommonCore
  GUISupportQt
  InfovisCore
  RenderingFreeType
  FiltersExtraction
  ViewsQt)
if (NOT VTK_FOUND)
  message("Skipping example: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif ()

find_package(Qt5 COMPONENTS Widgets Gui)
if (NOT TARGET Qt5::Widgets OR NOT TARGET Qt5::Gui)
  message("Skipping example: ${Qt5_NOT_FOUND_MESSAGE}")
  return ()
endif ()

# Set your files and resources here
set(Srcs
  ViewerWin.cpp
  main.cpp)

set(Hdrs
  ViewerWin.hpp)

set(UIs
  ViewerWin.ui)

set(QRCs
  resources.qrc)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

source_group("Resources" FILES
  ${UIs}
  ${QRCs})

add_executable(PointCloudViewer
  ${Srcs} ${Hdrs} ${UIs} ${QRCs})
target_link_libraries(PointCloudViewer
  PRIVATE
  ${VTK_LIBRARIES}
  Qt5::Gui
  Qt5::Widgets)
