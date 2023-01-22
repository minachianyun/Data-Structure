#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct {
    // coefficient
    int coef;
    // exponent
    int expon;
}polynomial;

typedef struct Node{
    polynomial poly;
    struct Node *next;
}LNode,*LinkList;

void CreateLinkList(LinkList L){
    int num;
    LNode *r,*s;
    polynomial pp;
    cin >> num;
    r = L;
    for(int i = 0; i < num; i++){
        cin >> pp.coef >> pp.expon;
        s = (LinkList)malloc(sizeof(LNode));
        s->poly = pp;
        if(r->poly.expon == pp.expon){
            r->poly.coef = pp.coef + r->poly.coef;
        }
        else{
            r->next = s;
            r = s;
        }
    }
    r->next = NULL;
}
void OutLinkList(LinkList L){
    LNode *p;
    p = L->next;
    while(p){
        if(p->poly.coef != 0){
            if(p->next == NULL){
            cout << p->poly.coef << " " << p->poly.expon;
            }
            else{
                cout << p->poly.coef << " " << p->poly.expon << " ";
            }
            p = p->next;
        }
        else{
            p = p->next;
        }
    }
}

LinkList Add_L(LinkList P,LinkList Q){
    LNode *p,*q;
    LNode *r,*s;
    int sum;
    p = P->next;
    q = Q->next;
    r = P;
    while(p&&q){
        if((p->poly).expon > (q->poly).expon){
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else if((p->poly).expon < (q->poly).expon){
            r->next = q;
            r = r->next;
            q = q->next;
        }
        else{
            sum = (p->poly).coef + (q->poly).coef;
            if(sum != 0){
                p->poly.coef = sum;
                r->next = p;
                r = r->next;
                p = p->next;
                s = q;
                q = q->next;
                free(s);
            }
            else{
                s = p;
                p = p->next;
                free(s);
                s = q;
                q = q->next;
                free(s);
            }
        }
    }
    if(p){
        r->next = p;
    }
    else{
        r->next = q;
    }
    free(Q);
    return P;
}
int main(){
    // A(x)+B(x)=C(x)
    LinkList A, B, C;
    A = (LinkList)malloc(sizeof(LNode));
    B = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;
    B->next = NULL;
    CreateLinkList(A);
    CreateLinkList(B);
    C = Add_L(A,B);
    OutLinkList(C);
    return 0;
}
