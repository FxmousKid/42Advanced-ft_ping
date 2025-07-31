#!/usr/bin/env bash

txtgrn='\e[0;32m' # Green
txtylw='\e[0;33m' # Cyan
txtwht='\e[0;37m' # White

# To use when submitting to the official vogsphere repo

rm -rf ./.git ./en.subject.pdf ./ ./README.md ./.gitignore ./compile_commands.json ./build ./ft_ping
make --no-print-directory -s -C ./libft fclean
echo -e "${txtgrn}Successfully Cleaned the repo for submitting !${txtwht}"
echo -e "${txtylw}Now deleting the script...!${txtwht}"

rm "$(basename "$0")"
