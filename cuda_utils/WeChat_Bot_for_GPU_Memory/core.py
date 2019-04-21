#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : LemonNoel

import os, time
import argparse
import paramiko
from wxpy import *

def parse_arg():
    parser = argparse.ArgumentParser()
    parser.add_argument('-server_list', type=str, default=None, 
                        help="Filename of server list. ('hostname\tport\tusername\tpassword\thost\t\n'")
    parser.add_argument('-receiver_name', type=str, default=None, 
                        help="User to receive messages. Don't use your own name")
    parser.add_argument('-time_step', type=float, default=3600, 
                        help='The frequency of sending messages (second)')
    parser.add_argument('-lifecycle', type=float, default=None, 
                        help='Lifecycle of GPU Bot, infinite for None (second)')
    args = parser.parse_args()
    return args

def output_format(server_name, stdout):
    message = '#%s#:\n' % server_name
    gpu_mem = [int(x.split()[2]) for x in stdout.readlines()]
    for gpu_id, unoccupied_mem in enumerate(gpu_mem):
        message += 'GPU %2d: %5dM\n' % (gpu_id, unoccupied_mem)
    return message

def get_gpu_info(server):
    assert ('hostname' in server.keys() and 'port' in server.keys() and 
            'username' in server.keys() and 'password' in server.keys())
    server_name =  '%s:%d' % (server['hostname'], server['port']) if 'host' not in server.keys() \
                else server['host']
    try:
        command = 'nvidia-smi -q -d Memory|grep -A4 GPU|grep Free'
        client = paramiko.SSHClient()
        client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        client.connect(server['hostname'], server['port'], server['username'], server['password'])
        stdin, stdout, stderr = client.exec_command(command, get_pty=True)
        message = output_format(server_name, stdout)        
        client.close()
    except:
        message = "Can't connect server %s\n" % server_name
    return message

def build_wechat_bot(receiver):
    gpu_bot = Bot(console_qr=True)
    try:
        my_friend = gpu_bot.friends().search(receiver)[0]
    except:
        raise Exception("Your WeChat has no friend named '%s' 0-0" % receiver)
    return my_friend

if __name__ == '__main__':
    args = parse_arg()
    my_friend = build_wechat_bot(args.receiver_name)
    start_time = time.time()
    start_flag = True
    condition = lambda x: (True if args.lifecycle is None 
                           else ((x - start_time) < args.lifecycle))
    while condition(time.time()):
        try:
            if start_flag:
                my_friend.send("Hi~ ^-^")
                start_flag = False
            elif (args.lifecycle is None) or (time.time() - start_time + args.time_step < args.lifecycle):
                time.sleep(args.time_step)
            else:
                break
            messages = ''
            try:
                stdout = os.popen('nvidia-smi -q -d Memory|grep -A4 GPU|grep Free')
                message = output_format('SELF', stdout)
                messages += (message + '\n')
            except:
                pass
            if args.server_list is not None:
                with open(args.server_list, 'r') as fp:
                    dict_maker = lambda x: {'hostname':x[0],'port':x[1],'username':x[2],\
                                            'password':x[3],'host':x[4] if len(x)>4 else None}
                    server_info = [dict_maker(x.strip().split('\t')) for x in fp.readlines()]
                        
                    print(server_info)
                    print(type(server_info))
                    for server in server_info:
                        message = get_gpu_info(server)
                        messages += (message + '\n')
            if len(messages):
                my_friend.send(messages)
            else:
                my_friend.send("No GPU found 0-0")
                break
        except:
            break
    try:
        my_friend.send("I'm off work. Byebye~")
    except:
        raise Exception('Error!')
