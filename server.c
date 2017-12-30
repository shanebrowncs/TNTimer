//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// File: server.c
// Author: Shane Brown
// Description: Creates web server and arduino serial connection
// Date: 30/12/17
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include "server.h"


static onion_connection_status strip_rpc(void *_, onion_request *req, onion_response *res){
	const onion_block *dreq=onion_request_get_data(req);
	if (dreq){
		const char* jsonData = onion_block_data(dreq);
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n%s\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n", jsonData);
		json_object* jobj = json_tokener_parse(jsonData);

		json_object* roundObj;
		json_object_object_get_ex(jobj, "round", &roundObj);
		if(roundObj != NULL){
			json_object* bombObj;
			json_object_object_get_ex(roundObj, "bomb", &bombObj);
			if(strcmp(json_object_to_json_string(bombObj), "\"planted\"") == 0){
				printf("//////BOMB PLANTED - START COUNTDOWN//////\n");
				serialport_writebyte(fd, 1);
			}
		}else{
			printf("'round' json object is null\n");
		}
	}else{
		printf("Invalid json request\n");
	}

	return OCS_PROCESSED;
}

void start_server(void){
	fd = serialport_init("/dev/ttyUSB1", 9600);
	serialport_flush(fd);

	if(fd == -1){
		printf("Could not open ttyUSB0\n");
		return;
	}

	printf("Started serial connection\n");

	onion *o=onion_new(0);
	
	onion_url *url=onion_root_url(o);
	onion_set_port(o, "3000");
	onion_url_add(url, "", strip_rpc);
	
	onion_listen(o);
}
