#include "../include.h"

AST::AST(Lexer* lx) {
    this->lx = lx;
    this->tr = new Tree();
    pmTree.add(this->tr);
}
AST::~AST() {
    // nothing now
}

Tree* AST::addToNodeTree(Tree* tr, Tree* child) {
    #ifdef DEBUG
        if (tr->type != treeTypeNode) ASSERT("Not a Node Tree");
    #endif

    tr->children.push_back(child);

    return tr;
}

#ifdef DEBUG
void AST::display(Tree* tr, int indent) {
    tr->display(indent);
}
void AST::display() {
    this->display(this->tr);
}
#endif

Token noneTokenClass;