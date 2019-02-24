#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create node structure
typedef struct huffman_node{
  struct huffman_node *left;
  struct huffman_node *right;
  char letter;
  int depth;
} node;


//create insert node function
void insert(node *tree,int length, char ltr,char *msg){
    int num,count;
    for (count = 1; count < length-1; count++){
        num = *(msg+count);
        //printf("%d,%c\n",count,num);
        if (count < length-2){

            if(num == '0'){
            
                if(tree->left == NULL){
                    tree->left = (node*)malloc(sizeof(node));
                    tree = tree->left;
                    //printf("node\n");
                }
                
                else{
                    tree = tree->left;
                }
            
                //insert(tree->left,num,count+1,length,ltr);
            }
        
            if(num == '1'){
                if(tree->right == NULL){
                    tree->right = (node*)malloc(sizeof(node));
                    tree = tree->right;
                    //printf("node\n");
                }
                
                else{
                    tree = tree->right;
                }
                //insert(tree->right,num,count+1,length,ltr);
            }
        }
        
        if(count == length-2){
            
            if(num == '0'){
                
                if(tree->left == NULL){
                    tree->left = (node*)malloc(sizeof(node));
                    tree = tree->left;
                    tree->letter = ltr;
                    //printf("node,%c\n" ,tree->letter);
                }
                
                else{
                    tree = tree->left;
                }
                
                //insert(tree->left,num,count+1,length,ltr);
            }
            
            if(num == '1'){
                if(tree->right == NULL){
                    tree->right = (node*)malloc(sizeof(node));
                    tree = tree->right;
                    tree->letter = ltr;
                    //printf("node,%c\n" ,tree->letter);
                }
                
                else{
                    tree = tree->right;
                }

            }
        }
    }
    
}

//read brinary tree to decode
int read(node *tree,char *msg, int count){
    char decoded;

    if (*(msg+count) == '0'){
        if (tree->left != NULL){
            //printf("not null");
            return read(tree->left, msg, count+1);
            
        }
        
        if (tree->left == NULL){
            decoded = tree->letter;
            printf("%c",decoded);
            //printf("null");
        }
    }
    
    else if (*(msg+count) == '1'){
        if (tree->right != NULL){
            //printf("not null");
            return read(tree->right, msg, count+1);
        }
        
        if (tree->right == NULL){
            decoded = tree->letter;
            printf("%c",decoded);
            //printf("null");
        }
            
    }
    else{
        decoded = tree->letter;
        printf("%c",decoded);
    }
    
    
    return count;

}

//free allocated memory
void freetree(node *tree){
    if(tree != NULL){
        freetree(tree->left);
        freetree(tree->right);
        free(tree);
    }
}

//main program
int main(){
    
    int N;
    
    //printf("Enter the integer N");
    scanf("%d",&N);
    
    node *root = NULL;
    root = (node*)malloc(sizeof(node));
    
    int i,j;
    int count=0;
    
    for (i = 0; i < N+1; i++){
        
        char code[100000];
        //printf("Enter the character and code");
        fgets(code,100000,stdin);
        //printf("%lu",strlen(code));
        insert(root,(int)strlen(code),code[0],code);
    }
    
    char message[100000];
    char readout[100000];
    //printf("Enter the encoded message.");
    fgets(message,100000,stdin);
    //printf("%s", message);
    
    while (count < (int)strlen(message)-1){
        count = read(root,message,count);
        
        //k = k+count;
        //printf("%d\n",count);
    }
    
    freetree(root);
    //free(root);
    //printf("/n");
             
    return 0;
}

