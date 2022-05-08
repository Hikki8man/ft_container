#!/bin/bash

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

if test -f "stack" && test -f "vector"; then
	echo "${green}Executing...${reset}"
	./stack && ./vector
else
	echo "${red}You need to compile the files first ! ${reset}"
fi