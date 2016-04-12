/* usbreset -- send a USB port reset to a USB device */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>


int main(int argc, char **argv)
{
    // const char *filename;
    int fd;
    int rc;
    FILE *fp;
    char path[1035];
    char filename[21];
    char buff[3];

    /* Open the command for reading. */
    fp = popen("lsusb | grep \"WLAN\"", "r");
    if (fp == NULL) {
      printf("Failed to run command\n" );
      exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
      printf("%s", path);
    }

    /* close */
    pclose(fp);

    strcpy(filename, "/dev/bus/usb/");
    strncpy(buff, path + 4, 3);
    strcat(filename, buff);
    strcat(filename, "/");
    strncpy(buff, path + 15, 3);
    strcat(filename, buff);

    filename[21] = '\0';

    fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("Error opening output file");
        return 1;
    }

    printf("Resetting USB device %s\n", filename);
    rc = ioctl(fd, USBDEVFS_RESET, 0);
    if (rc < 0) {
        perror("Error in ioctl");
        return 1;
    }
    printf("Reset successful\n");

    close(fd);
    return 0;
}
