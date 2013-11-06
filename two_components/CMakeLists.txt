cmake_minimum_required(VERSION 2.8)

add_executable(myapp myapp.cpp)

install(TARGETS myapp RUNTIME DESTINATION bin COMPONENT foo)
install(FILES myapp.cpp DESTINATION src COMPONENT bar)

include(CPackComponent)

cpack_add_component(foo DISPLAY_NAME "My Foo Display Name"
    DESCRIPTION "My Foo Description")

cpack_add_component(bar DISPLAY_NAME "My Bar Display Name"
    DESCRIPTION "My Bar Description")

include(CPack)
