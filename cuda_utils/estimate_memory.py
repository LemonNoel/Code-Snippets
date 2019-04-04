import torch
import torch.nn as nn
import numpy as np

def estimate_memory(model, input, type_size=4, backward=1, momentum=1, square=1):
    model_size = sum([np.prod(list(p.size())) for p in model.parameters()])
    print('Model {} : params {:4f}M'
        .format(model._get_name(), (model_size * type_size / 1000 / 1000)))

    input_ = input.clone().detach()
    model_ = list(model.modules())

    input_size = np.prod(list(input_.size()))
    print('Model {} : inputs {:4f}M'
        .format(model._get_name(), (input_size * type_size / 1000 / 1000)))

    param_set = []

    for index in range(1, len(model_)):
        layer = model_[index]
        if isinstance(layer, nn.ReLU):
            if layer.inplace:
                continue
        input_ = layer(input_)
        param_set.append(np.array(input_.size()))

    param_size = sum([np.prod(x) for x in param_set])
    param_size = param_size * type_size * (1. + backward + momentum + square)

    print('Model {} : intermediate {:4f}M  backward-{:d}, momentum-{:d}, square-{:d}'
        .format(model._get_name(), param_size / 1000 / 1000, backward, momentum, square))

    print('Model {} : total_memory {:4f}M'
        .format(model._get_name(), ((model_size + input_size) * type_size + param_size) / 1000 / 1000))


