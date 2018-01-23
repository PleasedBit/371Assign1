//dictobject implementation

//struct entry

struct entry {
    char *filename;
    int   filetype;
    char *filehash;
}
//struvt table
struct dict {
    int size;
    struct entry **entryList;
}

//create dict

dict create_dict(int size) {
    //create a dict object and return it
    //????
}


//create new entry
void add_entry(struct dict *dictionary, char *filename, int filetype) {
    //create new entry object
    //this fuction does not read and needs to be passed pointers
    //calls hash itself????
    //add it to the passed dict
}


//get entry by filename
entry get_entry(struct dict *dictionary, char *key) {
    //search the dict for the key
    //returnt he entry coresponding

}

//???
//win


//need a compaire enrty function
int cmp_entry(struct entry *e1, struct entry *e2) {

}