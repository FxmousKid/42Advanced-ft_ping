# ft_ping

## Description

The goal of this project is to replicate _ping(8)_ ([inetutils-2.0](https://layers.openembedded.org/layerindex/recipe/169108/)),
with the following minimum constraints :
- implementing the <b>-v</b> and <b>-?</b> options
- managing simple IPv4 (address/hostname) as parameters
- managing FQDN without DNS resolution in packet return

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
