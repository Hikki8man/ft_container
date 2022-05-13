#!/bin/bash

red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
cyan=`tput setaf 6`
reset=`tput sgr0`

echo "${cyan}Compiling test...${reset}"
make -s re
make -s clean
#testing stack
./ft_stack && ./std_stack
./checker Stack ./testOutput/ft_stack_out.txt ./testOutput/std_stack_out.txt
echo "${cyan}Testing leaks: ${reset}"
leaks -q -atExit -- ./ft_stack > /dev/null 2> /dev/null
if [ $? -eq 0 ]; then
	echo "${green}No leaks detected :)${reset}"
else
	echo "${red}Leaks detected !!${reset}"
fi
#testing vector
./ft_vector && ./std_vector
./checker Vector ./testOutput/ft_vector_out.txt ./testOutput/std_vector_out.txt
echo "${cyan}Testing leaks: ${reset}"
leaks -q -atExit -- ./ft_vector > /dev/null 2> /dev/null
if [ $? -eq 0 ]; then
	echo "${green}No leaks detected :)${reset}"
else
	echo "${red}Leaks detected /!\\${reset}"
fi