class Solution {
public:
    double gain(int pass, int total)
    {
        return (double)(pass+1)/(total+1) - (double)(pass)/(total);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        vector<int> pass(n),total(n);
        for(int i=0;i<n;i++)
        {
            pass[i]=classes[i][0];
            total[i]=classes[i][1];
        }
        for(int i=0;i<n;i++)
        {
            pq.push({gain(pass[i],total[i]),i});
        }
        while(extraStudents--)
        {
            auto [g,i] =pq.top();
            pq.pop();
            ++pass[i];
            ++total[i];
            pq.push({gain(pass[i],total[i]),i});
        }
        double sum = 0.0;
        for(int i=0;i<n;i++)
        {
            sum+=(double)pass[i]/total[i];
        }
        return sum/n;

    }
};