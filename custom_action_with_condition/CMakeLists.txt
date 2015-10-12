add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/patch.xml")

install(FILES hw.cpp DESTINATION src)

include(CPack)