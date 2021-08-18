#include <iostream>
#include "mongoc/mongoc.h"

int main(int argc, char** argv) {
    const char *uri_string = "mongodb://127.0.0.1:27017";
    mongoc_uri_t *uri;
    mongoc_client_t *client;
    mongoc_database_t *database;
    mongoc_collection_t *collection;
    
    bson_t *command, *insert, reply;
    bson_error_t error;
    
    char *str;
    
    bool retval;

    // start
    mongoc_init();

    // get uri
    uri = mongoc_uri_new_with_error(uri_string, &error);
    printf("result : %s\n", error.message);
    if (!uri) {
        printf("uri new fail\n");
        return EXIT_FAILURE;
    }

    // get client
    client = mongoc_client_new_from_uri (uri);
    if (!client) {
        printf("client new fail\n");
        return EXIT_FAILURE;
    }

    //set appname
    // mongoc_client_set_appname(client, "nbhtestapp");

    // check ping
    command = BCON_NEW("ping", BCON_INT32 (1));
    retval = mongoc_client_command_simple(client, "admin", command, NULL, &reply, &error);
    if (!retval) {
        printf("ping command fail\n");
        return EXIT_FAILURE;
    }

    // end
    mongoc_cleanup();

    return 0;
}