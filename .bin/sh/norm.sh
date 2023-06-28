#!/bin/bash

#color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD='\033[1m'
UNSET='\033[0m'

# execute norminette on all .c and .h files in the current project folder
# instead of printing "OK!" messages, print "Norminette OK!" if there are no errors
# if there are any errors, print "Norminette KO!" and the errors
if [[ -z $(find . '(' -type f -name "*.c" -o -name "*.h" ')' -exec norminette {} \; | grep -v "OK!") ]]; then
	echo -e "${GREEN}${BOLD}Norminette OK!${NC}${UNSET}"
else
	echo -e "${RED}${BOLD}Norminette KO!${UNSET}"
	echo -e "${RED}$(find . '(' -type f -name "*.c" -o -name "*.h" ')' -exec norminette {} \; | grep -v "OK!")${UNSET}"
fi
