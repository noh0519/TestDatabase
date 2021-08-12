ADD_EXECUTABLE(mongodbcpp main.cpp)

ADD_COMPILE_OPTIONS(-g -Wall)

SET(MONGOC_PATH ../libs/mongo-c-driver/mongoc/)

TARGET_INCLUDE_DIRECTORIES(mongodbcpp
   PUBLIC
   ${MONGOC_PATH}src/libmongoc/src
   ${MONGOC_PATH}src/libbson/src
   ${MONGOC_PATH}cmake-build/src/libbson/src/bson
   ${MONGOC_PATH}cmake-build/src/libmongoc/src/mongoc
)

TARGET_LINK_DIRECTORIES(mongodbcpp
   PUBLIC
   ${MONGOC_PATH}cmake-build/src/libmongoc
   ${MONGOC_PATH}cmake-build/src/libbson
)

TARGET_LINK_LIBRARIES(mongodbcpp
   mongoc-1.0
   bson-1.0
)

# FIND_LIBRARY(
#    LIBMONGOC
#    NAME libmongoc-1.0.so
#    HINTS ${MONGOC_PATH}cmake-build/src/libmongoc
#    REQUIRED
# )
# TARGET_LINK_LIBRARIES(mongodbcpp ${LIBMONGOC})