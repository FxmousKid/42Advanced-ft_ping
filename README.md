# ft_ping

## Description

The goal of this project is to replicate _ping(8)_ ([inetutils-2.0](https://layers.openembedded.org/layerindex/recipe/169108/)),
with the following minimum constraints :
- implementing the <b>-v</b> and <b>-?</b> options
- managing simple IPv4 (address/hostname) as parameters
- managing FQDN without DNS resolution in packet return

## Installation

> [!WARNING]
> ft_ping uses SOCK_RAW (raw sockets), and therefore needs super user permission
> A - run with sudo (please don't)
> B - run sudo ```setcap cap_net_raw+ep [full/ft_ping/executable/path]```

> [!NOTE]
> to run with valgrind, DON'T run cap_net_raw on the executable (or rebuild it)
> and run valgrind on ft_ping with sudo ```sudo valgrind [path/ft_ping/] ...```

## Usage

```bash 
./ft_ping [OPTION] [HOST(S)]
```


## Documentation

> [!NOTE]
> Doxygen doc for this project is inpsired by https://github.com/glfw/glfw/

This Projects uses doxygen for documentation, by having comment blocks with annotations
inside of them, and a template Doxyfile.in which gets built using ```make docs```

this command will then open your default browser and greet you with extensive documentation,
the ability to view sources, navigate along the file tree, etc...

> [!WARNING]
> 1] ```doxygen``` needs to be installed on your machine first.\n
> 2] if ```make docs``` doesn't open the browser, try it again
