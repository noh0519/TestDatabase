ADD_EXECUTABLE(datagenerator main.cpp)

SET(JSON_PATH ../libs/json/json/)

TARGET_INCLUDE_DIRECTORIES(
    datagenerator
    PUBLIC
    ${JSON_PATH}include
)