#include "all_h3lp.h"
#define TOTAL 7

// file list
char *allh3lpFiles[TOTAL]={
	"00_dummy",
	"development/Gedit",
	"gaming/CS2",
	"multimedia/Ardour",
	"multimedia/GIMP",
	"multimedia/Kdenlive",
	"programming/Bash",
};

// initialize submenu
struct subMenu allh3lpMenu={
	.title="ALL H3LP",
	.list=NULL,
	.size=TOTAL
};

// allocate lists
void initAllh3lp(){
	allh3lpMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(allh3lpMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		allh3lpMenu.list[i]=strdup(allh3lpFiles[i]);
		if(allh3lpMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanAllh3lp(){
	for(int i = 0; i < TOTAL; i++){
		free(allh3lpMenu.list[i]);}
	free(allh3lpMenu.list);
	allh3lpMenu.list=NULL;
};
