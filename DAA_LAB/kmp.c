#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void lpsArray(char pat[], int m , int *lps)
{
    int len=0;
     lps[0] = 0;
    
    for(int i=1;i<m; )
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
        {
            lps[i] = 0;
            i++;
        }
    }
}
}
void kmpsearch(char pat[], char text[])
{
  int m = strlen(pat);
  int n = strlen(text);
  
  int *lps = (int *)malloc(n*sizeof(int));
  if (lps == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
  
  lpsArray(pat,m,lps);
  
  int i =0;
  int j =0;
  
  while(i<n)
  {
      if(pat[j] == text[i])
      {
          i++;
          j++;
      }
      if(j==m)
      {
          printf("found at %d",i-j);
          j=lps[j-1];
      }
      else if(i<n && pat[j]!=text[i])
      {
          if(j!=0)
          {
              j=lps[j-1];
          }
          else
          {
              i++;
          }
      }
  }
}
int main()
{
     char *text = NULL;
    char *pat = NULL;

    printf("Enter the text: ");
    scanf("%ms", &text);

    printf("Enter the pattern: ");
    scanf("%ms", &pat);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pat);

    kmpsearch(pat,text);

    free(text);
    free(pat);

    return 0;
}
