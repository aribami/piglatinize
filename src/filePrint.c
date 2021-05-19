/*
Copyright (C) 2021 by Abhirami Kirthivasan
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "filePrint.h"

int filePrint(int argc,char * argv[]){
    int index=0;
    for (int i=0;i<argc;i++){
        if (strcmp(argv[i],"-o")==0){
            index=i;
            break;
        }     
    }
    if ((index+1)<argc){
    FILE* source=fopen(argv[1],"r");
    FILE* dest=fopen(argv[index+1],"w");
    char word[50];
    char ending;
    while (fscanf(source,"%s%c",word,&ending)!=EOF){
        fprintf(dest,"%s ",word);
        if (ending=='\n')
            fprintf(dest,"\n");
    }
    fclose(dest);
    fclose(source);
    return 0;
    }
    else {
        return -1;
    }
}