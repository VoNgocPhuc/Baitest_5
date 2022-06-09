#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char light;
	char fan;
	char motor;
}smartHome_t;

char data[] = "HTTP1.1 200 OK\r\n{\r\n\t\"light\" : \"on\",\r\n\t\"fan\" : \"off\",\r\n\t\"motor\" : \"off\"\r\n}";

void light(smartHome_t* Home) {
	int x = 0;
	int i = 0;
	int location_on = 0;
	char* value = 0;
	char light1[3] = { 0 };
	value = strstr(data, "\"light\"");
	while (value[i] != 'o') {
		i++;
		location_on ++;
	}
		strncpy(light1, (value + location_on), 2);

	if (light1[1] == 'n') {
		Home->light = 1;
		printf("trang thai light: %d: \r\n", Home->light); 
	}
	else {
		Home->light = 0;
		printf("trang thai light: %d \r\n", Home->light);
	}

}

void fan(smartHome_t* Home) {
	int i = 0;
	int location_on = 0;
	char* value = 0;
	char fan1[3] = { 0 };
	value = strstr(data, "\"fan\"");
	while (value[i] != 'o') {
		i++;
		location_on++;
	}
	strncpy(fan1, (value + location_on), 2);

	
	if (fan1[1] == 'n') {
		Home->fan = 1;
		printf("trang thai fan: %d \r\n", Home->fan);  // trạng thái on thì bật thiết bị lên 1
	}
	else {
		Home->fan = 0;
		printf("trang thai fan: %d \r\n", Home->fan);	
	}
}

void motor(smartHome_t* Home) {
	int i = 0;
	int location_on = 0;
	char* value = 0;
	char motor1[3] = { 0 };
	value = strstr(data, "\"motor\"");
	while (value[i] != 'o') {
		i++;
		location_on++;
	}
	strncpy(motor1, (value + location_on), 2);
	
		

	if (motor1[1] == 'n') {
		Home->motor = 1;
		printf("trang thai motor: %d: \r\n", Home->motor); 
	}
	else {
		Home->motor = 0;
		printf("trang thai motor: %d \r\n", Home->motor);
	}

}


void main() {
	smartHome_t Home;
	light(&Home);
	fan(&Home);
	motor(&Home);
}
