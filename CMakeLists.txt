cmake_minimum_required(VERSION 3.16)

project(LiveQML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Network HttpServer Positioning Location)
find_package(OpenSSL)

qt_standard_project_setup()

qt_add_executable(appLiveQML
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/resources.qrc
)

qt_add_qml_module(appLiveQML
    URI LiveQML
    VERSION 1.0
)

set_target_properties(appLiveQML PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

add_subdirectory( QLIVE )
include_directories( appLiveQML QLive/src )

set( PROJECT_NAME appLiveQML )
add_subdirectory( android_openssl )

#if (ANDROID)
#    list(APPEND ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/arm64-v8a/libcrypto_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/arm64-v8a/libssl_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/armeabi-v7a/libcrypto_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/armeabi-v7a/libssl_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/x86/libcrypto_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/x86/libssl_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/x86_64/libcrypto_3.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/android/ssl_3/x86_64/libssl_3.so
#    )
#endif()

target_link_libraries(appLiveQML
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Network
    PRIVATE Qt6::HttpServer
    PRIVATE Qt6::Positioning
    PRIVATE Qt6::Location
    QLive
)


install(TARGETS appLiveQML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(CPACK_GENERATOR "DragNDrop")
include(CPack)
