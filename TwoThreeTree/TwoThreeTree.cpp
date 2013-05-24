#include <iostream>
#include <cstdio>
#include <ctime>
#include <set>
#include <vector>
#include <cstdlib>

using namespace std;


struct Node23Tree{
    Node23Tree *n[3];
    int k[3];
};

bool __T23_Insert__(Node23Tree*&, int&, Node23Tree*&);

Node23Tree* __CreateNode__(int k){
    Node23Tree *t = new Node23Tree;
    t->n[0] = t->n[1] = t->n[2] = NULL;
    t->k[0] = k;
    return t;
}

bool T23_Insert(Node23Tree* &root, int &k){
    if(!root){
        root = __CreateNode__(k);
        root->n[0] = __CreateNode__(k);
        return true;
    }
    if(root->n[1] == NULL){
        if(root->k[0] < k){
            root->n[1] = __CreateNode__(k);
            root->k[1] = k;
            return true;
        }else if(root->k[0] > k){
            root->n[1] = root->n[0];
            root->k[1] = root->k[0];
            root->n[0] = __CreateNode__(k);
            root->k[0] = k;
            return true;
        }else return false;
    }
    Node23Tree *tbk = NULL;
    bool f = __T23_Insert__(root, k, tbk);
    if(f && tbk){
        Node23Tree *rnew = __CreateNode__(root->k[0]);
        rnew->n[0] = root;
        rnew->n[1] = tbk;
        rnew->k[1] = tbk->k[0];
        root = rnew;
    }
    return f;
}

bool __T23_Insert__(Node23Tree* &t, int &k, Node23Tree* &tnew){
    tnew = NULL;
    if(t->n[0] == NULL){
        if(t->k[0] == k) return false;
        else{
            tnew = __CreateNode__(k);
            return true;
        }
    }
    Node23Tree *w = t->n[0], *tbk = NULL;
    if(k >= t->k[1]) w = t->n[1];
    if(t->n[2] && k >= t->k[2]) w = t->n[2];
    bool f = __T23_Insert__(w, k, tbk);
    if(f){
        t->k[0] = t->n[0]->k[0];
        t->k[1] = t->n[1]->k[0];
        if(t->n[2])
            t->k[2] = t->n[2]->k[0];
        if(tbk){
            if(t->n[2]){
                tnew = new Node23Tree;
                tnew->n[2] = NULL;
                tnew->n[1] = t->n[2];
                tnew->k[1] = t->k[2];
                tnew->n[0] = tbk;
                tnew->k[0] = tbk->k[0];
                t->n[2] = NULL;
                if(t->k[1] > tnew->k[0]){
                    swap(tnew->n[0], t->n[1]);
                    swap(tnew->k[0], t->k[1]);
                }
                if(t->k[0] > t->k[1]){
                    swap(t->n[0], t->n[1]);
                    swap(t->k[0], t->k[1]);
                }
                if(tnew->k[0] > tnew->k[1]){
                    swap(tnew->n[0], tnew->n[1]);
                    swap(tnew->k[0], tnew->k[1]);
                }
            }else{
                t->n[2] = tbk;
                t->k[2] = tbk->k[0];
                if(t->k[2] < t->k[1]){
                    swap(t->n[2], t->n[1]);
                    swap(t->k[2], t->k[1]);
                }
                if(t->k[0] > t->k[1]){
                    swap(t->n[0], t->n[1]);
                    swap(t->k[0], t->k[1]);
                }
            }
        }
    }
    return f;
}

bool __T23_Delete__(Node23Tree*&, int&, bool&);

bool T23_Delete(Node23Tree* &root, int &k){
    if(!root) return false;
    if(root->n[1] == NULL){
        if(root->k[0] == k){
            delete root->n[0];
            delete root;
            root = NULL;
            return true;
        }else return false;
    }
    bool one = false, f = __T23_Delete__(root, k, one);
    if(f){
        if(one){
            if(root->n[0]->n[1]){
                Node23Tree *tmp = root->n[0];
                delete root;
                root = tmp;
            }
        }else{
            root->k[0] = root->n[0]->k[0];
            root->k[1] = root->n[1]->k[0];
            if(root->n[2])
                root->k[2] = root->n[2]->k[0];
        }
    }
    return f;
}

bool __T23_Delete__(Node23Tree* &t, int &k, bool &one){
    one = false;
    bool f = false;
    if(t->n[0]->n[0] == NULL){
        for(int i=0;i<3;++i)
            if(t->k[i] == k){
                delete t->n[i];
                for(int j=i;j<2;++j){
                    t->k[j] = t->k[j+1];
                    t->n[j] = t->n[j+1];
                }
                f = true;
                t->n[2] = NULL;
                if(t->n[1] == NULL) one = true;
            }
        return f;
    }
    Node23Tree *w = t->n[0];
    if(k >= t->k[1]) w = t->n[1];
    if(t->n[2] && k >= t->k[2]) w = t->n[2];
    bool one_bk = false;
    f = __T23_Delete__(w, k, one_bk);
    if(f && one_bk){
        if(w == t->n[0]){
            w->n[1] = t->n[1]->n[0];
            w->k[1] = t->n[1]->k[0];
            if(t->n[1]->n[2]){
                t->n[1]->n[0] = t->n[1]->n[1];
                t->n[1]->n[1] = t->n[1]->n[2];
                t->n[1]->n[2] = NULL;
                t->n[1]->k[0] = t->n[1]->k[1];
                t->n[1]->k[1] = t->n[1]->k[2];
            }else{
                w->n[2] = t->n[1]->n[1];
                w->k[2] = t->n[1]->k[1];
                delete t->n[1];
                t->n[1] = t->n[2];
                t->n[2] = NULL;
                if(t->n[1] == NULL) one = true;
            }
        }else if(w == t->n[1]){
            if(t->n[0]->n[2]){
                w->n[1] = w->n[0];
                w->k[1] = w->k[0];
                w->n[0] = t->n[0]->n[2];
                w->k[0] = t->n[0]->k[2];
                t->n[0]->n[2] = NULL;
            }else if(t->n[2] && t->n[2]->n[2]){
                w->n[1] = t->n[2]->n[0];
                w->k[1] = t->n[2]->k[0];
                t->n[2]->n[0] = t->n[2]->n[1];
                t->n[2]->n[1] = t->n[2]->n[2];
                t->n[2]->n[2] = NULL;
                t->n[2]->k[0] = t->n[2]->k[1];
                t->n[2]->k[1] = t->n[2]->k[2];
            }else{
                t->n[0]->n[2] = w->n[0];
                t->n[0]->k[2] = w->k[0];
                delete w;
                t->n[1] = t->n[2];
                t->n[2] = NULL;
                if(t->n[1] == NULL) one = true;
            }
        }else{
            if(t->n[1]->n[2]){
                w->n[1] = w->n[0];
                w->k[1] = w->k[0];
                w->n[0] = t->n[1]->n[2];
                w->k[0] = t->n[1]->k[2];
                t->n[1]->n[2] = NULL;
            }else{
                t->n[1]->n[2] = w->n[0];
                t->n[1]->k[2] = w->k[0];
                delete w;
                t->n[2] = NULL;
            }
        }
        t->k[0] = t->n[0]->k[0];
        if(!one) t->k[1] = t->n[1]->k[0];
        if(t->n[2]) t->k[2] = t->n[2]->k[0];
    }
    return f;
}

bool T23_Find(Node23Tree *r, int &k){
    if(!r) return false;
    if(r->k[0] == k) return true;
    if(r->n[0]){
        if(r->k[1] > k) return T23_Find(r->n[0], k);
        else
            if(r->k[1] == k) return true;
            else
                if(r->n[2] && r->k[2] <= k) return T23_Find(r->n[2], k);
                else return T23_Find(r->n[1], k);
    }
    return false;
}

void T23_Print(Node23Tree *r, int t=0){
    if(!r){
        cout<<"Empty\n";
        return ;
    }
    for(int i=0;i<t;++i) cout<<'\t';
    cout<<r->k[0]<<" ";
    if(r->n[1]) cout<<r->k[1]<<" ";
    if(r->n[2]) cout<<r->k[2]<<" ";
    cout<<endl;
    if(r->n[0]) T23_Print(r->n[0], t+1);
    if(r->n[1]) T23_Print(r->n[1], t+1);
    if(r->n[2]) T23_Print(r->n[2], t+1);

}

int main(){
    int n = 1000000;
    Node23Tree *tree = NULL;
    /*cin>>n;*/
    /*for(int i=0;i<n;++i){*/
        /*int a;*/
        /*cin>>a;*/
        /*T23_Insert(tree, a);*/
        /*T23_Print(tree);*/
    /*}*/
    /*cin>>n;*/
    /*for(int i=0;i<n;++i){*/
        /*int a;*/
        /*cin>>a;*/
        /*T23_Delete(tree, a);*/
        /*T23_Print(tree);*/
    /*}*/

    srand(time(0));
    vector<int> v;
    for(int i=0;i<n;++i)
        v.push_back(rand());

    set<int> s;

    time_t t=clock();
    for(int i=0;i<(int)v.size();++i)
        s.insert(v[i]);
    printf("Set %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);

    t=clock();
    for(int i=0;i<(int)v.size();++i)
        T23_Insert(tree, v[i]);
    printf("T23 %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);

    int sum=0;
    t=clock();
    for(int i=0;i<10*n;++i)
        sum += (s.find(i)!=s.end());
    printf("Set %.6lf %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

    sum=0;
    t=clock();
    for(int i=0;i<10*n;++i)
        sum += T23_Find(tree, i);
    printf("T23 %.6lf %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

    t=clock();
    for(int i=0;i<(int)v.size();++i)
        s.erase(v[i]);
    printf("Set %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);

    t=clock();
    for(int i=0;i<(int)v.size();++i)
        T23_Delete(tree, v[i]);
    printf("T23 %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);

    T23_Print(tree);

    return 0;
}
