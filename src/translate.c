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

#include "translate.h"
#include<string.h>

void translate(char* str ){
    //printf("%s\n",str);
    int len=strlen(str);
    char* vowels= "aeiouAEIOU";
    char* firstVowel = strpbrk(str,vowels);
    if (firstVowel==NULL){
        strcat(str,"ay");
        return;
    }
    int indexOfSplit=0;
    for (int i=0;i<len;i++){
        if (str[i]==*firstVowel){
            indexOfSplit=i;
            break;
        
        }
    }
    char result[255];
    strcpy(result,&str[indexOfSplit]);
    strncat(result,str,indexOfSplit);
    strcat(result,"ay");
    //printf("%s\n",result);
    strcpy(str, result);
    return;
}
