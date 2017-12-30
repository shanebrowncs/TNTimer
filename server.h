//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// File: server.h
// Author: Shane Brown
// Description: Creates web server and arduino serial connection
// Date: 30/12/17
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <json-c/json.h>

#include <onion/onion.h>
#include <onion/dict.h>
#include <onion/block.h>
#include <onion/request.h>
#include <onion/response.h>
#include <onion/url.h>
#include <onion/low.h>


#include "arduino-serial/arduino-serial-lib.h"

void start_server();

int fd;

#endif
