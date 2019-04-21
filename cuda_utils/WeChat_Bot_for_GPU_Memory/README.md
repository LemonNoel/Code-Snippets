# WeChat Bot for GPU Memory

A Single WeChat Bot to Watch GPU Memory Periodically.

## Requirements

* python 3.x
* wxpy
* paramiko

## Quick Start

* Write the information of servers into a file FILE with format

```
(hostname/ip)\t(port)\t(username)\t(password)\t(servername)\t\n
```

* Arguments:
  * **server_list**:   Name of FILE made in last step
  * **receiver_name**: Remark name of your receiver in WeChat. Your own name and u'文件传输助手' is not a good choice
  * **lifecycle**:     Lifecycle of process in seconds. As QR-code is always required to scan in the beginning, it is not feasible to restart the program periodically. Thus set up this argument to keep process alive as long as you need
  * **timestep**:      Seconds between every two messages.
  
* Run core.py
