#include <stdio.h>
#include "node.h"
#include "y.tab.h"
#include "hash.h"
#include "var.h"

int offset_local;

int exeNode(Node *p) 
{
    HashNode *node;

	if (!p) return 0;
	switch(p->type) {
    case TYPE_CONTENT: 
        printf("load %d\n", p->content);
        return 0;
    case TYPE_INDEX:   
        node = hash_lookup(var_local, HASHSIZE, p->index);
        if (node == NULL)
            printf("load(index) %d\n", p->index); /* var[p->index]; */
        else 
            printf("load(index) %d(esp)\n", node->data); /* var[p->index]; */
        return 0;
    case TYPE_OP:
		switch(p->op.name) {
        case VAR:
            offset_local -= VAR_LENGTH;
            node = hash_insert(var_local, HASHSIZE, p->op.node[1]->index, offset_local);
            printf("VAR(index) %d(esp)\n", node->data);
            return 0;
        case FUNC:
            offset_local = 0;
            if (p->op.num == 1) { /* compound */
                exeNode(p->op.node[0]);
            } else { /* declaration */
                printf("\nFUNC-D(index) %d\n", p->op.node[1]->index);
                exeNode(p->op.node[2]);
            }
            return 0;
        case PARAM:
            if (p->op.num == 2) { /* no [ ] */
                offset_local -= VAR_LENGTH;
                node = hash_insert(var_local, HASHSIZE, p->op.node[1]->index, offset_local);
                printf("PARAM(index) %d(esp)\n", node->data);
            } else { /* [ ] pointer */
                printf("PARAM(index) %d[]\n", p->op.node[1]->index);
            }
            return 0;
		case '=':	
            exeNode(p->op.node[1]);
            if (p->op.node[0]->type == TYPE_INDEX) {
                printf("Assign last result to VAR(index) %d\n", p->op.node[0]->index);
            } else { /* array */
                printf("Assign last result to VAR(index) %d[]\n", 
                    p->op.node[0]->op.node[0]->index);
            } 
            return 0;
        case '<':
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("< last two result\n");
            return 0;
        case '>':
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("> last two result\n");
            return 0;
        case LE_OP:
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("<= last two result\n");
            return 0;
        case GE_OP:
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf(">= last two result\n");
            return 0;
        case EQ_OP:
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("== last two result\n");
            return 0;
        case NE_OP:
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("!= last two result\n");
            return 0;
        case '+':
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("+ last two result\n");
            return 0;
        case '-':
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("- last two result\n");
            return 0;
        case '*':
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("* last two result\n");
            return 0;
        case '/':
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("/ last two result\n");
            return 0;
        case '[': /* array */
            exeNode(p->op.node[1]);
            printf("load(index) %d + last\n", p->op.node[0]->index);
            return 0;
        case CALL:
            printf("ready to call\n");
            exeNode(p->op.node[1]);
            printf("ready to fetch call name\n");
            exeNode(p->op.node[0]);
            printf("call last\n");
            return 0;
        case '{':
		case ';':    
        case ',':
            /*printf("exe {;,\n");*/
			exeNode(p->op.node[0]);
			return exeNode(p->op.node[1]);        
		case WHILE: 
            printf("start while\n");
            exeNode(p->op.node[0]);
            exeNode(p->op.node[1]);
            printf("end while\n");
			return 0;
		case IF:     
            printf("start if\n");
            exeNode(p->op.node[0]);
            printf("test last\n");
            exeNode(p->op.node[1]);
            printf("else\n");
            if (p->op.num > 2)
                exeNode(p->op.node[2]);
			return 0;   
        case RETURN:
            if (p->op.num > 0)
                exeNode(p->op.node[0]);
            printf("now return last value\n");
            return 0;
		}
    }
   
    return 0;
}
