
    #include <vector>
    #include <string>
    #include <map>
    #include <algorithm>
    #include <set>
    #include <cstdlib>
    #include <cctype>
    #include <cstring>
    #include <iomanip>
    #include <climits>
    #include <cfloat>
    #include <cstdio>
    #define MAX 100010
    #define MOD 1000000007
    
    int v[MAX];
    long long int tree[4*MAX], add[4*MAX], mul[4*MAX];
    
    class segment_tree{
    private:
        int n;
        public:
        segment_tree(const int root, const int left, const int right, int v[]){
            if(left == right){
                tree[root] = v[left];
                add[root] = 0, mul[root] = 1;
                return;
            }
            int mitad = (left+right)>>1;
            segment_tree((root<<1), left, mitad, v);
            segment_tree((root<<1)+1, mitad+1, right, v);
            tree[root] = (tree[root<<1]+tree[(root<<1)+1])%MOD;
            add[root] = 0, mul[root] = 1;
        }
        segment_tree(int n, int v[]){
            this->n = n;
            segment_tree(1, 1, n, v);
        }
    
        void inline update_child(const int root, const int left, const int right){
            tree[root] = ((tree[root]*mul[root])+(right-left+1)*add[root])%MOD;
            if(left != right){
                mul[root<<1] = (mul[root<<1]*mul[root])%MOD;
                add[root<<1] = ((add[root<<1]*mul[root])+add[root])%MOD;
                mul[(root<<1)+1] = (mul[(root<<1)+1]*mul[root])%MOD;
                add[(root<<1)+1] = ((add[(root<<1)+1]*mul[root])+add[root])%MOD;
            }
            mul[root] = 1, add[root] = 0;
            return;
        }
    
        void update(const int root, int left, int right,
          const int x, const int y, const long long int value, bool addok){
    //        printf("+ %d %d %d %d %d %lld\n", root, left, right, x, y, value);
            this->update_child(root, left, right);
            if(x <= left && right <= y){
                if(addok == true){
                    add[root] = value;
                    this->update_child(root, left, right);
                }
                else{
                    mul[root] = value;
                    this->update_child(root, left, right);
                }
                return;
            }
            int mitad = (left+right)>>1, a = tree[root<<1], b = tree[(root<<1)+1];
            if(left <= x && x <= mitad){
                update(root<<1, left, mitad, x, std::min(mitad, y), value, addok);
                tree[root] = (tree[root]-a+tree[root<<1]+MOD)%MOD;
            }
            if(mitad+1 <= y && y <= right){
                update((root<<1)+1, mitad+1, right, std::max(x, mitad+1), y, value, addok);
                tree[root] = (tree[root]-b+tree[(root<<1)+1]+MOD)%MOD;
            }
            return;
        }
    
        void update_mul(const int root, int left, int right,
          const int x, const int y, const long long int value){
            this->update_child(root, left, right);
    //        printf("mul %d %d %d %d %d %lld\n", root, left, right, x, y, value);
            if(x <= left && right <= y){
                tree[root] = (tree[root]*value)%MOD;
    //            printf("aca %d\n", tree[root]);
                return;
            }
            int mitad = (left+right)>>1, a = tree[root<<1], b = tree[(root<<1)+1];
            if(left <= x && x <= mitad){
                update_mul(root<<1, left, mitad, x, std::min(mitad, y), value);
                tree[root] = (tree[root]-a+tree[root<<1]+MOD)%MOD;
            }
            if(mitad+1 <= y && y <= right){
                update_mul((root<<1)+1, mitad+1, right, std::max(x, mitad+1), y, value);
                tree[root] = (tree[root]-b+tree[(root<<1)+1]+MOD)%MOD;
            }
    //        printf("aqui %d\n", tree[root]);
            return;
        }
    
    
        void update(const int option, const int x, const int y, const int val){
    //        printf("update\n");
            if(option==1){
                this->update(1, 1, this->n, x, y, val, true);
            }
            else if(option == 2){
                this->update(1, 1, this->n, x, y, val, false);
            }
            else{
                this->update(1, 1, this->n, x, y, 0, false);
                this->update(1, 1, this->n, x, y, val, true);
            }
            return;
        }
    
        int query(const int root, int left, int right,
            const int x, const int y){
            this->update_child(root, left, right);
            if(x <= left && right <= y){
                return tree[root];
            }
            int mitad = (left+right)>>1, a = 0, b = 0;
            if(left <= x && x <= mitad)
                a = query(root<<1, left, mitad, x, std::min(y, mitad));
            if(mitad+1 <= y && y <= right)
                b = query((root<<1)+1, mitad+1, right, std::max(x, mitad+1), y);
            return (a+b)%MOD;
        }
        int query(const int x, const int y){
    //        printf("query %d %d\n", x, y);
            return query(1, 1, this->n, x, y);
        }
    };
    
    int main(){
        int n, q, a, x, y, valor;
    /*    while(scanf("%d", &n)==1){
            printf("%d\n", Inverse(n, MOD));
        }*/
        scanf("%d%d", &n, &q);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        segment_tree T(n, v);
    //    printf("queries\n");
        for(int i = 0; i < q; i++){
            scanf("%d%d%d", &a, &x, &y);
            if(a != 4){
                scanf("%d", &valor);
                T.update(a, x, y, valor);
            }
            else{
                printf("%d\n", T.query(x, y));
            }
        }
    	return 0;
    }
    

