project(FancyWiXUser)

find_package(FancyWiXLib)

include(CPack)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/FancyWiXLib.txt
    "FancyWiXLib_DIR [${FancyWiXLib_DIR}]\n"
    "FancyWiXLib_FOUND [${FancyWiXLib_FOUND}]"
)
