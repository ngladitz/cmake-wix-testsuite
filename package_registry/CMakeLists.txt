project(FancyWiXLib)

add_library(fancy_wix fancy.cpp fancy.hpp)
install(TARGETS fancy_wix ARCHIVE DESTINATION lib)
install(FILES fancy.hpp DESTINATION include)
install(FILES FancyWiXLibConfig.cmake DESTINATION .)

set(CPACK_WIX_CMAKE_PACKAGE_REGISTRY "FancyWiXLib")

include(CPack)
