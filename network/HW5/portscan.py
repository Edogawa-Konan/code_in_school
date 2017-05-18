#!/usr/bin/env python
###########################################################################
#
# PROGRAMMER:   Drew Stefanik and Greg Gorajski - Group 2
# PROGRAM:      Assignment 4 - Port Scan and RC4 Decryption Program
# DATE DUE:     7/27/2016
# PURPOSE:      Scans a server for an open UDP port, and receives a secret
#					key from the open port.  Then scans the server for an
#					open TCP port and receives an encrypted message from
#					from the open port.  The encrypted message is
#					decrypted using RC4 with the secret key obtained from
#					UDP.  Prints out the message, which ports where open,
#					and the time of each connection.
#
###########################################################################
 
import socket, sys, datetime
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes


print("Starting UDP Port Scan: ")

#create UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#for each port in the given range
for port in range(9000,9100):
	#attempt to connect to the port
	#if the port is open, create a timestamp, receive the secret key,
	#save the number of the open port, and break the loop
	try:
		sock.settimeout(0.05)
		sock.sendto(b"group 2", (("10.158.56.43", port)))
		time_UDP = datetime.datetime.now()
		key, addr = sock.recvfrom(1024)
		print("Port %s Open" % port)
		port_UDP = port
		break
	#if the port is closed, print message and continue the loop
	except socket.error:
		print ("Port %s Closed" % port)

sock.close()

print("Starting TCP Port Scan: ")

#create TCP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#for each port in the given range
for port in range(9000,9100):
	#attempt to connect to the port
	#if the port is open, create a timestamp, receive the encrypted message,
	#save the number of the open port, and break the loop
	try:
		sock.connect(("10.158.56.43", port))
		time_TCP = datetime.datetime.now()
		sock.send("group 2", )
		ciphertext = sock.recv(1024)
		print("Port %s Open" % port)
		port_TCP = port
		break
	#if the port is closed, print message and continue the loop
	except socket.error:
		print ("Port %s Closed" % port)

sock.close()

#prepare the RC4 cipher with the UDP secret key, and derypt the TCP message



#print the ports, timestamps, and plaintext message
print ("Open UDP Port: %s" % port_UDP)
print ("Open UDP Timestamp: %s" % time_UDP)
print ("Open TCP Port: %s" % port_TCP)
print ("Open TCP Timestamp: %s" % time_TCP)
print ("Message:")

print("***Program Execution Complete***")
