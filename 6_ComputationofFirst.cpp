#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
void FIRST(char[], char); 
void addToResultSet(char[], char); 
int numOfProductions; 
char productionSet[10][10]; 
 
int main() { 
    int i; 
    char choice; 
    char ch; 
    char result[20]; 
 
    printf("How many number of productions?: "); 
    scanf("%d", &numOfProductions); 
 
    printf("Enter the Production in the form V=(VUT)*\n "); 
 
    for (i = 0; i < numOfProductions; i++) { 
        printf("Enter productions number %d: ", i + 1); 
        scanf("%s", productionSet[i]); 
    } 
 
    do { 
        printf("Find the First of: "); 
        scanf(" %c", &ch); 
        result[0] = '\0'; 
        FIRST(result, ch); 
        printf("\nFIRST(%c) = {", ch); 
        for (i = 0; result[i] != '\0'; i++) { 
            printf("%c", result[i]); 
            if (result[i + 1] != '\0') { 
                printf(", "); 
            } 
        } 
 
        printf("}\n"); 
        printf("Press 'y' to continue: "); 
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y'); 
     
     
    return 0; 
} 
 
void FIRST(char* Result, char ch) { 
    int i, j, k; 
    char subResult[20]; 
    int foundEpsilon; 
    subResult[0] = '\0'; 
 
    if (!isupper(ch)) { 
        addToResultSet(Result, ch); 
        return; 
    } 
 
    for (i = 0; i < numOfProductions; i++) { 
        if (productionSet[i][0] == ch) { 
            if (productionSet[i][2] == '$') { 
                addToResultSet(Result, '$'); 
            } else { 
                j = 2; 
                while (productionSet[i][j] != '\0') { 
                    foundEpsilon = 0; 
                    FIRST(subResult, productionSet[i][j]); 
                    for (k = 0; subResult[k] != '\0'; k++) { 
                        addToResultSet(Result, subResult[k]); 
                    } 
                    for (k = 0; subResult[k] != '\0'; k++) { 
                        if (subResult[k] == '$') { 
                            foundEpsilon = 1; 
                            break; 
                        } 
                    } 
                    if (!foundEpsilon) { 
                        break; 
                    } 
                    j++; 
                } 
 
            } 
        } 
    } 
} 
 
void addToResultSet(char Result[], char val) { 
    int k; 
    for (k = 0; Result[k] != '\0'; k++) { 
        if (Result[k] == val) { 
            return; 
        } 
    } 
    Result[k] = val; 
    Result[k + 1] = '\0'; 
}  

  
  
 
 
 
 
 
 
 
 
 
 