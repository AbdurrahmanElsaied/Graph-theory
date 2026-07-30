struct dsu
       {
           int parent[N], sz[N];
           stack<array<int,4>> st;
           int comp ;
           dsu(int n)
           {    
                comp = n-1;
               for(int i = 0; i < n; i++)
               {
                   parent[i] = i;
                   sz[i] = 1;
               }
           }
       
           int find(int i)
           {
               return parent[i] == i ? i : find(parent[i]);
           }
       
           bool samegroup(int x, int y)
           {
               return find(x) == find(y);
           }
       
           void merge(int x, int y)
           {
               int root1 = find(x);
               int root2 = find(y);
       
               array<int,4> ins = {-1, -1, -1,-1};
               st.push(ins);
       
               if(root1 == root2) return;
       
               st.pop();
       
               if(sz[root1] > sz[root2])
                   swap(root1, root2);
       
               ins[0] = root1;
               ins[1] = root2;
               ins[2] = sz[root2];
               ins[3] = comp;
               st.push(ins);
               comp--;
               parent[root1] = root2;
               sz[root2] += sz[root1];
           }
       
           void rollback()
           {
               array<int,4> last = st.top();
               st.pop();
               if(last[0] == -1) return;

               parent[last[0]] = last[0];
               sz[last[1]] = last[2];
               comp = last[3];
           }
       
           int getsize(int x)
           {
               return sz[find(x)];
           }
       };
