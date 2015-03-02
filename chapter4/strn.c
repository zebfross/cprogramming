void pstrncpy(char *s, char *t, int n) {
	char *pt = t;
	while(*pt && pt - t < n)
		*s++ = *pt++;
}

int pstrncmp(char *s, char *t, int n) {
	char *pt;
	for(pt = t; *pt && pt - t < n; ++pt, ++s) {
		if(*s < *pt)
			return -1;
		if(*s > *pt)
			return 1;
	}
	return 0;
}

void pstrncat(char *s, char *t, int n) {
	while(*s)
		s++;
	char *pt = t;
	while(*pt && pt - t < n)
		*s++ = *pt++;
}
