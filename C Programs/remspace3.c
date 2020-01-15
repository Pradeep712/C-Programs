remove_spaces(char *str) {
	char *temp;
	char *cur;



cur = str;


while (*cur != '\0' && *cur != ' ' ) {
cur++;
}


temp = cur;


while (temp != '\0') {
if (temp != ' ')
*cur = *temp;
cur++;
}
temp++;
}
*cur = '\0';
}

