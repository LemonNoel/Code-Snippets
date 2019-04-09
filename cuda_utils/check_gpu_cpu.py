import torch


# python -m torch.utils.bottleneck /path/to/resource/script.py


# Select GPU
# - CUDA_VISIBLE_DEVICES=x python /path/to/resource/script.py [RECOMMEMDED]
# - import os
#   os.environ["CUDA_VISIBLE_DEVICES"] = "x"
# - import torch
#   torch.cuda.set_device(x)


def check_gpu_cpu_time(model, input, use_cuda):
    with torch.autograd.profiler.profile(use_cuda=use_cuda) as prof:
        output = model(input)
        output.backward(torch.ones_like(output))
    print(prof)
