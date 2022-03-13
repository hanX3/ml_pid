#!/usr/bin/env python3

import struct

header_size = 56
event_length = 20000
run = 50
data_in_path = '/mnt/hgfs/vm_hanX/'
data_out_path = '../../data/'

def divide_data(number):
  path_in = ("%srun_R%04d.bin") % (data_in_path, run)
  path_out = ("%sR%04d_%d.bin") % (data_out_path, run, number)
  print(path_in)
  print(path_out)
  fo = open(path_out, 'wb')
  with open(path_in, 'rb') as fi:
    fi.seek(56, 0)
    for _ in range(number):
      #print(_)
      for __ in range(event_length):
        #print(__)
        temp = fi.read(2)
        fo.write(temp)
        #y, = struct.unpack('h', temp)
        #print(y)
    fi.close()
  fo.close()
  
divide_data(100000)
