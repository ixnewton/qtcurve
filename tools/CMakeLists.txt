if(ENABLE_QT4 OR ENABLE_QT5 OR ENABLE_QT6)
  set(qt_dump_png_SRCS
    qt_dump_png.cpp)
  add_executable(qt-dump-png ${qt_dump_png_SRCS})
endif()

# QtCurve Widget Test Application (Qt6)
if(ENABLE_QT6)
  find_package(Qt6 COMPONENTS Core Gui Widgets QUIET)
  if(Qt6_FOUND)
    set(qtcurve_widget_test_SRCS
      qtcurve-widget-test.cpp)
    add_executable(qtcurve-widget-test ${qtcurve_widget_test_SRCS})
    target_link_libraries(qtcurve-widget-test
      Qt6::Core
      Qt6::Gui
      Qt6::Widgets)
    set_target_properties(qtcurve-widget-test PROPERTIES
      AUTOMOC ON)
    message(STATUS "QtCurve widget test application will be built")
  endif()
endif()
