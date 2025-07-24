# ft_ping

## Description

The goal of this project is to replicate _ping(8)_ ([inetutils-2.0](https://layers.openembedded.org/layerindex/recipe/169108/)), with the following constraints :
- implementing the <b>-v</b> and <b>-?</b> options
- managing simple IPv4 (address/hostname) as parameters
- managing FQDN without DNS resolution in packet return