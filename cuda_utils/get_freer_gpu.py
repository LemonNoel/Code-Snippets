import os
import numpy as np

def get_freer_gpu():
    os.system('nvidia-smi -q -d Memory|grep -A4 GPU|grep Free >tmp_gpu')
    memory_available = [int(x.split()[2]) for x in open('tmp_gpu', 'r').readlines()]
    return np.argmax(memory_available)