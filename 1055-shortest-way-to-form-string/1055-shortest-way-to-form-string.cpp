class Solution {
public:
    int shortestWay(string source, string target) {
        int i=0,j=0;
        int res = 0;
        bool flag = false;
        while(i<target.size()){
            if(source[j] == target[i]){
                i++;
                flag = true;
            }
            j++;
            if(j == source.size()){
                if(flag == false)
                    return -1;
                res++;
                j = 0;
                flag = false;
            }
        }
        if(i == target.size() && j!=0)
            res++;
        return res;
    }
};