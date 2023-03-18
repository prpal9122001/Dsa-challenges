//https://leetcode.com/problems/design-browser-history/description/


class BrowserHistory {
public:
    unordered_map<int,string>history;
    int mostforward=0,current=0;

    BrowserHistory(string homepage) {
        history[current]=homepage;
    }
    
    void visit(string url) {
        current++;
        history[current]=url;
        mostforward=current;
        return;
    }
    
    string back(int steps) {
        current=max(0,current-steps);
        return history[current];
    }
    
    string forward(int steps) {
        current=min(mostforward,current+steps);
        return history[current];
    }
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
