//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// File: main.c
// Author: Shane Brown
// Description: Main entry point
// Date: 30/12/17
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int main(int argc, char* argv[]){
	#undef ONION_DEBUG
	#undef ONION_INFO
	#define ONION_DEBUG(...)
	#define ONION_INFO(...)

	// Disable onion debug
	setenv("ONION_LOG", "nodebug", 1);

	if(argc < 2){
		printf("usage: port\n");
		return 0;
	}

	port = argv[1];

	// Start HTTP server
	start_server();
	return 0;
}
