/*
 * Authorization API module to communicate with IoT Cloud via REST APIs
 * Copyright (c) 2014, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 */

/**
 * @file authorization.c
 * @brief Implementation of Authorization API
 *
 * Provides features for communication with IoT Cloud server
 */


#include "iotkit.h"


char *getNewAuthorizationToken(char *username, char *password) {
    struct curl_slist *headers = NULL;
    char *url;
    char body[BODY_SIZE_MIN];
    char *response;

    if(!username) {
        fprintf(stderr, "Username cannot be NULL");
        return NULL;
    }

    if(!password) {
        fprintf(stderr, "Password cannot be NULL");
        return NULL;
    }


    prepareUrl(&url, configurations.base_url, configurations.new_auth_token);


    sprintf(body, "{\"username\":\"%s\",\"password\":\"%s\"}", username, password);

    appendHttpHeader(&headers, HEADER_CONTENT_TYPE_NAME, HEADER_CONTENT_TYPE_JSON);

    doHttpPost(url, headers, body);


    // TODO: store the authorization token in the config.json file


    return response;
}


char *validateAuthorizationToken() {
    struct curl_slist *headers = NULL;
    char *url;
    char *response;

    appendHttpHeader(&headers, HEADER_CONTENT_TYPE_NAME, HEADER_CONTENT_TYPE_JSON);
    appendHttpHeader(&headers, HEADER_AUTHORIZATION, getConfigAuthorizationToken());

    prepareUrl(&url, configurations.base_url, configurations.auth_token_info);

    doHttpGet(url, headers, &response);

    // TODO: store the account id in the config.json file

    return response;
}



char *getAuthorizationTokenMeInfo() {
    struct curl_slist *headers = NULL;
    char *url;
    char *response;

    appendHttpHeader(&headers, HEADER_CONTENT_TYPE_NAME, HEADER_CONTENT_TYPE_JSON);
    appendHttpHeader(&headers, HEADER_AUTHORIZATION, getConfigAuthorizationToken());

    prepareUrl(&url, configurations.base_url, configurations.me_info);

    doHttpGet(url, headers, &response);

    // TODO: store the account name etc in config.json file

    return response;
}