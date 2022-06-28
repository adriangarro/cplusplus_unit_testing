project(Example)

set(HEADER_FILES
        Gregorian.h
        Julian.h
        Authorization.h
        AuthorizationManager.h
        )

set(SOURCE_FILES
        Gregorian.cpp
        Julian.cpp
        Authorization.cpp
        AuthorizationManager.cpp
        )

add_library(Example_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
