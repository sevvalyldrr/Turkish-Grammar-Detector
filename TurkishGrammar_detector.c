#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

/// necessary character definitions are made..

#define SIZE_TEXT 5000
#define SIZE_WORD 500
#define SIZE_LENGTH 2000
#define ALPHABET "abcž+defgžhžijklmnožprsžtužvyzABCžDEFGžHIžJKLMNOžPRSžTUžVYZ"
#define VOWEL "aežiožužAEIžOžUž"
#define CONSONENT "bcždfgžhjklmnprsžtvyzBCžDFGžHJKLMNPRSžTVYZ"
#define SOFT_CONSONENT "bcdgžjlmnrvyzBCDGžJLMNRVYZ"
#define STRONG_CONSONENT "žfhkpsžtžFHKPSžT"
#define BOLD_VOWEL "ažouAIOU"
#define NARROW_VOWEL "eižžEžžž"
#define UNROUNDED_VOWEL "aežiAEIž"
#define ROUNDED_VOWEL "ožužOžUž"
#define LABIAL_VOWEL "aeužAEUž"
#define UNLABIAL_VOWEL "ožžiOžIž"



///function prototype is defined...
int connexion(unsigned char word[][SIZE_WORD]);
int palatalharmony(unsigned char word[][SIZE_WORD]);
int labialharmony(unsigned char word[][SIZE_WORD]);
void tokwords(unsigned char text[],unsigned char word[][SIZE_WORD]);
int softConsonent(unsigned char text[]);
void tokwords2(unsigned char text[],unsigned char word2[][SIZE_WORD]);
int softConsonent(unsigned char text[]);
int numplural(unsigned char word[][SIZE_WORD]);
int numwords(unsigned char text[]);
int numsentences(unsigned char text[]);
int numletters(unsigned char text[]);
int menu(unsigned char text[],unsigned char word[][SIZE_WORD],unsigned char word2[][SIZE_WORD]);
int searchofwords(unsigned char text[]);


int main()
{
    setlocale(LC_ALL,"Turkish_turkish.1254");
    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);

    unsigned char text[SIZE_TEXT]={0};
    unsigned char word[SIZE_LENGTH][SIZE_WORD]={0};
    unsigned char word2[SIZE_LENGTH][SIZE_WORD]={0};
   
   
   
  printf("Please enter the text:\n");
  fgets(text,SIZE_TEXT,stdin);
  text[strlen(text)-1] = '\0';
  strlwr(text);
   
   tokwords(text,word);
  
   /// prints the functions that I will output
  printf("Number of connexions=%d\n\n",connexion(word));
  printf("Number of palatal harmonys=%d\n\n",palatalharmony(word));
  printf("Number of labial harmony=%d\n\n",labialharmony(word));
  printf("Number of strong consonent=%d\n",strongConsonent(text));
  printf("Number of soft consonent=%d\n",softConsonent(text));
  printf("Number of plural words=%d\n",numplural(word));
  printf("Number of words=%d\n",numwords(text));
  printf("Number of sentences=%d\n",numsentences(text));
  printf("Number of letters=%d\n",numletters(text));
  
 menu(text, word,word2);
 

   return 0;
}

int menu(unsigned char text[],unsigned char word[][SIZE_WORD],unsigned char word2[][SIZE_WORD])
{  
   char choice[SIZE_WORD]={0};
  
  int exit=1;

do{
  printf("\n\nulama\n");
  printf("buyuk unlu uyumu\n");
  printf("kucukk unlu uyumu\n");
  printf("sert unsuz sayisi\n");
  printf("yumusak unsuz sayisi\n");
  printf("cogul kelime sayisi\n");
  printf("kelime sayisi\n");
  printf("cumle sayisi\n");
  printf("harf sayisi\n");
  printf("arama\n");
  printf("exit\n\n");

  printf("PLEASE ENTER YOUR CHO?CE:\n\n");

  fgets(choice,SIZE_WORD,stdin);
  choice[strlen(choice)-1]='\0';


if(strcmp(choice,"ulama")==0)
{
    printf("Number of connexions=%d\n\n",connexion(word));

}

else if(strcmp(choice,"buyuk unlu uyumu")==0)
{
    printf("Number of palatal harmonys=%d\n\n",palatalharmony(word));
}

else if(strcmp(choice,"kucuk unlu uyumu")==0)
{
    printf("Number of labial harmony=%d\n\n",labialharmony(word));
}

else if(strcmp(choice,"sert unsuz sayisi")==0)
{
   printf("Number of strong consonent=%d\n",strongConsonent(text));
}

else if(strcmp(choice,"yumusak unsuz sayisi")==0)
{
   printf("Number of soft consonent=%d\n",softConsonent(text));
}

else if(strcmp(choice,"cogul kelime sayisi")==0)
{
    printf("Number of plural words=%d\n",numplural(word));
}

else if(strcmp(choice," kelime sayisi")==0)
{
   printf("Number of words=%d\n",numwords(text));

}

else if(strcmp(choice,"cumle sayisi")==0)
{
  printf("Number of sentences=%d\n",numsentences(text));

}

else if(strcmp(choice,"harf sayisi")==0)
{
  printf("Number of letters=%d\n",numletters(text));

}
else if(strcmp(choice,"arama")==0)
{
   searchofwords(text);
}
else if(strcmp(choice,"exit")==0)
{
  exit=0;
}

}while(exit);
return 0;

} 



///makes the connexions process step by step...
int connexion(unsigned char word[][SIZE_WORD])
{
  int count=0, i=0, j=0;
 
  for(i=0; word[i][0] != NULL;i++)
  {
        if ((strchr(CONSONENT, word[i][strlen(word[i])-1]) != NULL) && (strchr(VOWEL, word[i+1][0]) != NULL))
       {
             printf("%s %s, ", word[i], word[i+1]);
             count++;
       }
  }

  return count;
}

////finds words that match palatal harmony...
int palatalharmony(unsigned char word[][SIZE_WORD])
{
   int i,j,k,control1=0,control2=0,count=0;

   for(i=0; word[i][0] != NULL;i++)
   {
        control2 = 0;
        for(j=0;word[i][j] != NULL;j++)
        {
            if(strchr(BOLD_VOWEL,word[i][j]))
            {
               for(k=j+1; word[i][k]!=NULL; k++)
               {
                    if(strchr(BOLD_VOWEL,word[i][k]))
                    {
                      control1++;
                      break;
                    }
                    else if(strchr(NARROW_VOWEL,word[i][k]))
                    {
                      control2++;
                      
                      
                    }
               }
            }
            else if(strchr(NARROW_VOWEL,word[i][j]))
            {
                for(k=j+1; word[i][k]!=NULL; k++)
                {
                    if(strchr(NARROW_VOWEL,word[i][k]))
                    {
                         control1++;
                         break;
                    }
                    else if(strchr(BOLD_VOWEL,word[i][k]))
                    {
                        control2++;
                        
                        
                    }
                }
            }
        }

        if(control1>0 && control2==0)
        {
          printf("%s,",word[i]);
          ++count;
        }
    }
    return count;
}



////finds words that match labial harmony...
int labialharmony(unsigned char word[][SIZE_WORD])
{
   int i,j,k,control1=0,control2=0,count=0;

   for(i=0; word[i][0] != NULL;i++)
   {
        control2 = 0;
        for(j=0;word[i][j] != NULL;j++)
        {
            if(strchr(UNROUNDED_VOWEL,word[i][j]))
            {
               for(k=j+1; word[i][k]!=NULL; k++)
               {
                    if(strchr(UNROUNDED_VOWEL,word[i][k]))
                    {
                      control1++;
                      break;
                    }
                    else if(strchr(ROUNDED_VOWEL,word[i][k]))
                    {
                      control2++;
                      
                    }
               }
            }
            else if(strchr(ROUNDED_VOWEL,word[i][j]))
            {
                for(k=j+1; word[i][k]!=NULL; k++)
                {
                    if(strchr(LABIAL_VOWEL,word[i][k]))
                    {
                         control1++;
                         break;
                    }
                    else if(strchr(UNLABIAL_VOWEL,word[i][k]))
                    {
                        control2++;
                        
                    }
                }
            }
        }

        if(control1>0 && control2==0)
        {
          printf("%s,",word[i]);
          ++count;
        }
    }
    return count;
}

 ////finds strong consonants...
int strongConsonent(unsigned char text[])
{
  int i;
  int count=0;

   for(i=0; text[i] != '\0'; i++)
   {

     {
         if(strchr(STRONG_CONSONENT,text[i]))
         {
           count++;
         }
         
     }
   }

  return count;
}

////finds soft consonants...
int softConsonent(unsigned char text[])
{
  int i;
  int count=0;

   for(i=0; text[i] != '\0'; i++)
   {

     {
         if(strchr(SOFT_CONSONENT,text[i]))
         {
           count++;
         }
         
     }
   }

  return count;
}

////finds plural words...
int numplural(unsigned char word[][SIZE_WORD])
{
  int i,count=0,j;
  for(i=0; word[i][0] != NULL;i++)
  {
    for(j=0; word[i][j] != NULL;j++)
    {
    if((word[i][j]=='l' && word[i][j+1]=='e' && word[i][j+2]=='r')|| (word[i][j]=='l' && word[i][j+1]=='a' && word[i][j+2]=='r'))
    {
        printf("%s,",word[i]);
          ++count;
    }
  }
}
  return count;
}

////finds number of words...
int  numwords(unsigned char text[])
{
    int i;
   int count=1;
   char str[]=" ";

   for(i=0;i<strlen(text)-1;i++)
   {
     if(strchr(str, text[i]) != NULL)
     {
        count++;
     }
   }

 return count;
}

////finds number of sentences...
int numsentences(unsigned char text[])
{
   int i;
   int count=0;
   char str[]=".:?!";

   for(i=0;i<strlen(text);i++)
   {
     if(strchr(str, text[i]) != NULL)
     {
        while(text[i]=='.')
        {
          i++;
        }
        count++;
     }
   }


  return count;

}

////finds number of letters...
int numletters(unsigned char text[])
{
  int i;
  int count=0;

   for(i=0; text[i] != '\0'; i++)
   {

     {
         if(strchr(ALPHABET,text[i]))
         {
           count++;
         }


     }
   }

  return count;
}

/////searches for words entered on the keyboard and prints them when found...
int searchofwords(unsigned char text[])
{
    int count =0;
    unsigned char search[25 ]={};
    unsigned char punctuation[12]={' ','.',',',':',';',',','!','/','(',')','?'};
    char *ptr = strtok(text, punctuation);
    
    printf("enter the search word:\n");
    gets(search);
    strlwr(search);

    while( ptr != NULL ) 
    {
        if (strcmp(ptr, search)==0)
        {
            count++;
        }
        ptr = strtok('\0', punctuation);
    }

    printf("Number of searched word= %d ", count);

    return 0;
}

////splits text into words and assigns it to a new array...
void tokwords(unsigned char text[],unsigned char word[][SIZE_WORD])
{
 int i;
 unsigned char *ptr;
 unsigned char copy[SIZE_TEXT];

 strcpy(copy,text);
 
 ptr=strtok(copy," ");
 for(i=0; ptr!=NULL ;i++)
 {
  strncpy(word[i],ptr,SIZE_WORD);
  ptr=strtok(NULL," ");
  }

}

