#ifndef NODE_H
#define NODE_H

/* 定义树结点的权举类型 */ 
typedef enum { TYPE_CONTENT, TYPE_INDEX, TYPE_OP } NodeEnum;

/* 操作符 */ 
    typedef struct {
	int name;		/* 操作符名称 */
	int num;		/* 操作元个数 */
	struct NodeTag *node[1];	/* 操作元地址 可扩展 */
} OpNode;
typedef struct NodeTag {
	NodeEnum type;		/* 树结点类型 */
	
	    /* Union 必须是最后一个成员 */ 
	    union {
		int content;	/* 内容 */
		int index;	/* 索引 */
		OpNode op;	/* 操作符对象 */
	};
} Node;

#endif	/*  */
