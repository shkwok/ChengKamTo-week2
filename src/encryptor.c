#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char key[26], map[26][26];
    char c;
    int i =0, j =0;
    for(i = 0;i < 26;i++)
        for(j = 0;j < 26;j++){
            map[i][j]= 'A'+i+j > 'Z' ? 64+('A'+i+j-'Z'):'A'+i+j;
        }


    printf("Please enter a key within 26 letters:");
    scanf("%s",key);
    getchar();
    for(i = 0; i < 26 ;i++)
        key[i] = toupper(key[i]);

    do {
        do {
            printf("\nEnter 1 to encrypt or 2 to decrypt: ");
            scanf("%c", &c);

        } while (c != '1' && c != '2');
        getchar();

        if (c == '1') {
            int currPos = 0;
            printf("Enter the string: ");
            do {
                int row = 0;
                int col = 0;
                // Read a character from stdin
                c = fgetc(stdin);
                if (('A' <= c && c <= 'Z') || ('a' <= c && c<= 'z')) {
                    c = toupper(c);
                    row = key[currPos] - 65;
                    if(currPos + 1 >= strlen(key))
                        currPos = 0;
                    else
                        currPos += 1;
                    col = c - 65;
                    printf("%c", map[row][col]);
                }
                else
                    printf("%c", c);

            } while (c != '\n');
        }
        else if( c == '2'){
            int currPos = 0;
            printf("Enter the string: ");
            do {
                int row = 0;
                int col = 0;
                // Read a character from stdin
                c = fgetc(stdin);
                if (('A' <= c && c <= 'Z') || ('a' <= c && c<= 'z')) {
                    c = toupper(c);
                    row = key[currPos] - 65;
                    if(currPos + 1 >= strlen(key))
                        currPos = 0;
                    else
                        currPos += 1;
                    for(col = 0;col < 26;col++){
                        if(map[row][col] == c)
                            break;
                    }
                    printf("%c", col + 65);
                }
                else
                    printf("%c", c);

            } while (c != '\n');


        }
    }while(1);
    return 0;
}
