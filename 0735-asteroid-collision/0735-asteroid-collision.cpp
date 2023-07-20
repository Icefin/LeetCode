class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        bool isBroken = false;
        for (int i = 0; i < asteroids.size(); i++){
            if (s.empty()){
                s.push(asteroids[i]);
                continue;
            }
            isBroken = false;
            if (s.top() * asteroids[i] > 0 || (s.top() < 0 && asteroids[i] > 0)){
                s.push(asteroids[i]);
            }
            else{
                while (!s.empty() && s.top() <= -asteroids[i] && !isBroken){
                    if (s.top() < 0){
                        s.push(asteroids[i]);
                        break;
                    }
                    else if (s.top() == -asteroids[i]){
                        s.pop();
                        isBroken = true;
                    }
                    else {
                        s.pop();
                    }
                }

                if (s.empty() && !isBroken){
                    s.push(asteroids[i]);
                }
            }
        }

        vector<int> ret(s.size());
        for (int i = ret.size() - 1; i >= 0; i--){
            ret[i] = s.top();
            s.pop();
        }
        return ret;
    }
};