/*
 * Data API module to communicate with IoT Cloud via REST APIs
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
 * @file data_api.h
 * @brief Implementation of Data Submit & Retrieval API
 *
 * Provides features for communication with IoT Cloud server
 */

#ifndef __DATA_H
#define __DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "iotkit.h"
#include <sys/time.h>

typedef struct _RetrieveData {
    long fromMillis;
    long toMillis;
    StringList *deviceList;
    StringList *componentId;
} RetrieveData;

#ifdef __cplusplus
}
#endif

#endif
