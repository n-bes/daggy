if(CONAN_BUILD)
    if(APPLE)
        set(CMAKE_INSTALL_RPATH "@executable_path/../${CMAKE_INSTALL_LIBDIR}/;@executable_path/../${CMAKE_INSTALL_LIBDIR}/daggy")
    elseif(UNIX)
        set(CMAKE_INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}/daggy;$ORIGIN/../${CMAKE_INSTALL_LIBDIR};")
    endif()
endif()
