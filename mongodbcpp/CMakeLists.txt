add_compile_options(-g -Wall)

set(MONGOC_PATH ../libs/mongo-c-driver/mongoc/)

add_executable(mongodbcpp main.cpp)

target_include_directories(mongodbcpp
   PUBLIC
   ${MONGOC_PATH}src/libmongoc/src
   ${MONGOC_PATH}src/libbson/src
   ${MONGOC_PATH}cmake-build/src/libbson/src/bson
   ${MONGOC_PATH}cmake-build/src/libmongoc/src/mongoc
)

target_link_directories(mongodbcpp
   PUBLIC
   ${MONGOC_PATH}cmake-build/src/libmongoc
   ${MONGOC_PATH}cmake-build/src/libbson
)

target_link_libraries(mongodbcpp
   mongoc-1.0
   bson-1.0
)

# find_library(
#    LIBMONGOC
#    NAME libmongoc-1.0.so
#    HINTS ${MONGOC_PATH}cmake-build/src/libmongoc
#    REQUIRED
# )
# target_link_libraries(mongodbcpp ${LIBMONGOC})