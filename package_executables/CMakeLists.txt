add_executable(h-w hw.cpp)
install(TARGETS h-w DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_PACKAGE_EXECUTABLES h-w "Hello World")

include(CPack)
