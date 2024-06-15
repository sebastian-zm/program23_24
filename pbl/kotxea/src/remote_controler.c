/*
 * remote_controller.c
 *
 *  Created on: 2023(e)ko mai. 11(a)
 *      Author: joseba
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include "remote_controller.h"

int init_ble(char *dev)
{
	int fd;
	struct termios serial;

	/*if (argc == 1) {
	   printf("Usage: %s [device]\n\n", argv[0]);
	   return -1;
	   } */

	printf("Opening %s\n", dev);

	fd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);

	if (fd == -1) {
		perror(dev);
		return -1;
	}

	if (tcgetattr(fd, &serial) < 0) {
		perror("Getting configuration");
		return -1;
	}
	// Set up Serial Configuration
	serial.c_iflag = 0;
	serial.c_oflag = 0;
	serial.c_lflag = 0;
	serial.c_cflag = 0;

	serial.c_cc[VMIN] = 0;
	serial.c_cc[VTIME] = 0;

	serial.c_cflag = B115200 | CS8 | CREAD;

	tcsetattr(fd, TCSANOW, &serial);	// Apply configuration
	return fd;
}
