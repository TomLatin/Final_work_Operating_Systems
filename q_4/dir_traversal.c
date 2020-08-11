#define _XOPEN_SOURCE 500 //it tells your compiler to include definitions for some extra functions that are defined in the X/Open and POSIX standards.he numbers refer to different versions of the standard.
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// max num of sub dirs
#define MAXLEVEL  2

static int display_info(const char *fpath, const struct stat *sb,
                        int tflag, struct FTW *ftwbuf)
{

    // if the depth is above the max sub dirs, continue to next file
    if (ftwbuf->level > MAXLEVEL) {
        return 0;//To tell nftw() to continue
    }
    //This is how soft link is ignored
    if(tflag==FTW_SL)
    {
        return 0; //To tell nftw() to continue
    }

    //print:type,inode,name of the file
    printf("%-3s\t%ld\t%s\n",
           (tflag == FTW_D) ?   "D"   : (tflag == FTW_DNR) ? "DNR" :
                                        (tflag == FTW_DP) ?  "DP"  : (tflag == FTW_F) ?   "F" :
                                                                     (tflag == FTW_NS) ?  "NS"  : "???",
           sb->st_ino,fpath + ftwbuf->base);
    return 0; //To tell nftw() to continue
}

int main(int argc, char *argv[])
{

    //nftw arg:(directory,display function, maximum number of directories that nftw() will hold open simultaneously, flag)
    if (nftw((argc < 2) ? "." : argv[1], display_info, 20, FTW_PHYS) == -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}