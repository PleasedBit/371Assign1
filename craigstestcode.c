#include <dirent.h>
#include <stdlib.h>

struct FileIn {
    char* filename;
    int   filetype;
	//8: file
	//4: directory
    char hash[50];
};

int readFolderContents( struct FileIn *dirCont ) {
    DIR *dir;
    struct dirent *dp;
    dir = opendir("/home/user/Documents");
    int i = 0;
    while((dp = readdir(dir)) != NULL && i < 10) {
	dirCont[i].filename = dp->d_name;
	dirCont[i].filetype = dp->d_type;
	i++;
    }
    return i;
}

void printFileStruct(struct FileIn *dirCont, int length) {
    
    for(int i=0;i<length;i++) {
        printf("%s  %i\n", dirCont[i].filename, DTTOIF(dirCont[i].filetype));
    }
}

int main(void) {
    struct FileIn dirContents[10];
    int fileCount = readFolderContents(dirContents);
    printFileStruct(dirContents, fileCount);

}