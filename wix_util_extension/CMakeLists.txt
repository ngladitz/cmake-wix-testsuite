set(CPACK_WIX_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/mywix.template.in")

add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_WIX_EXTENSIONS WixUtilExtension)

include(CPack)
