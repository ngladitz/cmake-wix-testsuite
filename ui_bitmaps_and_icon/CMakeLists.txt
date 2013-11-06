add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_WIX_PRODUCT_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
set(CPACK_WIX_UI_BANNER "${CMAKE_CURRENT_SOURCE_DIR}/banner.bmp")
set(CPACK_WIX_UI_DIALOG "${CMAKE_CURRENT_SOURCE_DIR}/dialog.bmp")

include(CPack)
