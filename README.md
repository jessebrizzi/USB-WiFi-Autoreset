# USB-WiFi-Autoreset
Monitors my Internet connection and resets my USB wifi adapter in linux if it goes down.

Currently set up for Kubuntu (KDE) notifications, modify for your specific window manager. (Internet_check.sh line 7)

autostart scripts require absolute path to the programs that it calls, modify for your specific case. (internet_check.sh line 8)

The Internet reset program needs sudo privileges to run, provide this by adding the program to your sudo visudo config to run without the password prompt.

Build with 

$ cc internet_fix.c -o internet_fix
