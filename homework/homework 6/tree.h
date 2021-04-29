#define MAX 80
typedef struct treenode {
  char* user; //usuario 
  char* password; //contraseña 

  struct treenode* leftChild;
  struct treenode* rightChild;
  unsigned int depth;
} node;

char linea[MAX], password[MAX], user[MAX];
int saca();
void get (char l[MAX],char p[MAX],char u[MAX]); 
node* insert(char* u, char* p, node* pos, int d); 
void alpha(node* position);
void delete(node* position, char* u, char* p, int* n); 