ADD_EXECUTABLE(mongodbcpp main.cpp)

SET(MONGOC_PATH ../libs/mongo-c-driver/mongoc/)

TARGET_INCLUDE_DIRECTORIES(mongodbcpp PUBLIC ${MONGOC_PATH}src/libmongoc/src/mongoc)
#src/libmongoc/src/mongoc/mongoc.h
TARGET_INCLUDE_DIRECTORIES(mongodbcpp PUBLIC ${MONGOC_PATH}src/libbson/src)
#src/libbson/src/bson/bson.h
TARGET_INCLUDE_DIRECTORIES(mongodbcpp PUBLIC ${MONGOC_PATH}cmake-build/src/libbson/src/bson)
#cmake-build/src/libbson/src/bson/bson-config.h
TARGET_INCLUDE_DIRECTORIES(mongodbcpp PUBLIC ${MONGOC_PATH}cmake-build/src/libmongoc/src/mongoc)
#cmake-build/src/libmongoc/src/mongoc/mongoc-config.h

#FIND_LIBRARY(
#    LIBMONGOC
#    NAME libmongoc-1.0.so
#    HINTS ${MONGOC_PATH}cmake-build/src/libmongoc
#    REQUIRED
#)
#TARGET_LINK_LIBRARIES(mongodbcpp ${LIBMONGOC})