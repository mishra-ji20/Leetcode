class Solution {
public:
    int un(vector<int>&parent, int a)
    {
        if(parent[a]!=a)
            return un(parent,parent[a]);
        return parent[a];
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++)
        {
            char a=equations[i][0],b=equations[i][1],c=equations[i][2],d=equations[i][3];
            if(b=='=')
            {
                parent[un(parent,d-'a')]=un(parent,a-'a');
            }
        }
        // for(int i=0;i<parent.size();i++)
        //     cout<<i<<" "<<parent[i]<<" ";
        for(int i=0;i<equations.size();i++)
        { char a=equations[i][0],b=equations[i][1],c=equations[i][2],d=equations[i][3];
            if(b=='!')
            {
                if(un(parent,a-'a')==un(parent,d-'a'))
                    return false;
            }
        }
        return true;
        
    }
};