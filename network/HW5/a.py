# -*- coding:utf-8 -*-
# -*- by prime -*-

import socket
import threading
import time
import struct
import queue

queue = queue.Queue()


def udp_sender(ip, port):
    try:
        ADDR = (ip, port)
        sock_udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock_udp.sendto("abcd...", ADDR)
        sock_udp.close()
    except:
        pass


def icmp_receiver(ip, port):
    icmp = socket.getprotobyname("icmp")
    sock_icmp = socket.socket(socket.AF_INET, socket.SOCK_RAW, icmp)
    sock_icmp.settimeout(3)
    try:
        recPacket, addr = sock_icmp.recvfrom(64)
    except:
        print('妈的')
        return
    icmpHeader = recPacket[20:28]
    icmpPort = int(recPacket.encode('hex')[100:104], 16)
    head_type, code, checksum, packetID, sequence = struct.unpack(
        "bbHHh", icmpHeader)
    print('ICMP报文类型:{},返回代码:{}'.format(head_type, code))
    sock_icmp.close()

    if code == 3 and icmpPort == port and addr[0] == ip:
        queue.put(False)
    return




def checker_udp(ip, port):
    thread_udp = threading.Thread(target=udp_sender, args=(ip, port))
    thread_icmp = threading.Thread(target=icmp_receiver, args=(ip, port))

    thread_udp.daemon = True
    thread_icmp.daemon = True

    thread_icmp.start()
    time.sleep(0.1)
    thread_udp.start()

    thread_icmp.join()
    thread_udp.join()
    return queue.get(False)


if __name__ == '__main__':
    import sys

    print(checker_udp('127.0.0.1', 53))