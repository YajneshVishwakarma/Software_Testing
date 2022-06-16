
#include<iostream>
#include<dirent.h>

struct FolderFile
{
    char* name[100];
};

using namespace std;

FolderFile fileName[1000];
int numberFile = 0;

void listFile()
{
    
    DIR *pDIR;
    struct dirent *entry;


    char  directoryName[261];
    strcpy_s(directoryName,"ImageLibrary/");
    
    if( pDIR=opendir(directoryName) )
    {
        while(entry = readdir(pDIR))
        {
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
            {
                if (strcmp(entry->d_name,"Thumbs.db")!=0)
                {
                
                    char tempFile[260];
                    strcpy_s(tempFile,"ImageLibrary/");
                    strcat_s(tempFile,entry->d_name);

                     strcpy(fileName[numberFile].name,tempFile);
                    
                     //This will print the output to test the result.
                     //Until now, it works well and prints out the right result    
                    cout<< fileName[numberFile].name << "\n";
                    
                    numberFile= numberFile + 1;        
                }
            
            }
            

        }

                closedir(pDIR);
    }
}
