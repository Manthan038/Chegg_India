#include <stdio.h>
int main() {
    char s1[100], s2[100],s3[100],s4[100];  // suppose one line take max 100 character
    char Ms[400]; // All string will be concatenating into it.
    int i, j;
    printf("Enter First line :\n ");
    scanf("%s",s1);
    printf("Enter Second Line :\n");
    scanf("%s",s2);
    printf("Enter Thrird Line :\n");
    scanf("%s",s3);
    printf("Enter Fourth Line :\n");
    scanf("%s",s4);

    // length of Ms is stored in i
    for (i = 0; s1[i] != '\0'; ++i) {
        Ms[i]=s1[i];
    }

    // concatenating each character of s2 to Ms
    for (j = 0; s2[j] != '\0'; ++j, ++i) {
        Ms[i] = s2[j];
    }
    // concatenating each character of s3 to Ms
    for (j = 0; s3[j] != '\0'; ++j, ++i) {
        Ms[i] = s3[j];
    }
    // concatenating each character of s4 to Ms
    for (j = 0; s4[j] != '\0'; ++j, ++i) {
        Ms[i] = s4[j];
    }

    // terminating s1 string
    s1[i] = '\0';
    
    int countA=0,countE=0,countI=0,countO=0,countU=0;
    
    for (j = 0; Ms[j] != '\0'; ++j) 
    {
      if(Ms[j]=='A' || Ms[j]=='a')
      countA++;
      else if(Ms[j]=='E' || Ms[j]=='e')
      countE++;
      else if(Ms[j]=='I' || Ms[j]=='i')
      countI++;
      else if(Ms[j]=='O' || Ms[j]=='o')
      countO++;
      else if(Ms[j]=='U' || Ms[j]=='u')
      countU++;
    }
    printf("Vowel character\t\tOccurences ");
    printf("\na\t\t\t%d",countA);
    printf("\ne\t\t\t%d",countE);
    printf("\ni\t\t\t%d",countI);
    printf("\no\t\t\t%d",countO);
    printf("\nu\t\t\t%d",countU);
    return 0;
}
