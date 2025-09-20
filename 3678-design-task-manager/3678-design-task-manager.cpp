class TaskManager {
public:
    unordered_map<int,int> task_user;
    unordered_map<int,int> task_priority;
    priority_queue<pair<int,int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task : tasks)
        {
            int user = task[0];
            int id = task[1];
            int priority = task[2];
            task_user[id]=user;
            task_priority[id]=priority;
            pq.push({priority,id});
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        task_user[taskId]=userId;
        task_priority[taskId]=priority;
        pq.push({priority,taskId});
        
    }
    
    void edit(int taskId, int newPriority) {
        task_priority[taskId]=newPriority;
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        int user = task_user[taskId]; //why did we save
        task_user.erase(taskId);
        task_priority.erase(taskId);    
    }
    
    int execTop() {
        while(!pq.empty())
        {
            auto [priority,task] = pq.top();
            if(task_priority.count(task) && task_priority[task]==priority)
            {
                int user = task_user[task];
                task_priority.erase(task);
                task_user.erase(task);
                return user;
            }
            pq.pop();
        }
        return -1;   
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */