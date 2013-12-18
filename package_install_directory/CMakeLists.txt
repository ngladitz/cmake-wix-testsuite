add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_PACKAGE_INSTALL_DIRECTORY "CMakeWiXTestsuite/${CMAKE_PROJECT_NAME}")

include(CPack)
