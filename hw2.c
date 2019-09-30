#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
             FILE * fd;
	char str[] = {};
	char* token;
	char ch;
	int number = 0;
	int i = 0;

	if(argc < 2){
		fprintf(stderr, "사용법 : %s file\n", argv[0]);
		exit(1);
	}

	if((fd = fopen(argv[1], "rw")) == NULL){
		perror(argv[1]);
		exit(2);
	}

	while(1){
		ch = fgetc(fd);
		if(ch == ' ')number--;
		if(ch == EOF) {
			number--;
			break;
		}

		str[i] = ch;
		i++;
		number++;
	}

	printf("문자수 : %d\n", number);
	number = 0;

	i = 0;
	while(str[i] != '\0'){
		while(isspace(str[i]))
			i++;
		if(str[i] != '\0')number++;
		while(!isspace(str[i]) && str[i] != '\0')i++;
             }
	number--;
	printf("단어수 : %d\n", number);
	number = 0;

	i = 0;
	while(1){
		if(str[i] == '\n') number++;
		else if(str[i] == EOF){
		       	break;
		}
		i++;
	}

	printf("줄수 : %d\n", number);

	fclose(fd);

	exit(0);
}
