#ifndef THMANAGER_H
#define THMANAGER_H

#include <thread>
#include <queue>
#include <mutex>


template<class Func_Param>
class threadManager{
    std::vector<std::thread*> _th;
    std::vector< std::pair<std::mutex*, std::queue<Func_Param*>* > > _muq;
    bool _joinOnDelete;
    bool _finish;

    enum queue_action{
        PUSH,
        POP,
        READ,
        SIZE
    };

    static void* accessQueue(std::mutex* m, std::queue<Func_Param*>* q, queue_action action, Func_Param* param=nullptr){
        std::lock_guard<std::mutex> lock(*m);
        switch(action){
        case PUSH:
            q->push(param);
            return nullptr;
        case POP:
            q->pop();
            return nullptr;
        case READ:
            {
                Func_Param* pr = q->front();
                return pr;
            }
        case SIZE:
            {
                size_t t= q->size();
                return (void*)t;
            }
        default:
            break;
        }
        return nullptr;
    }

    static void threadManager_Main(bool& finish, void (*func)(Func_Param), std::mutex* m, std::queue<Func_Param*>* q){
        Func_Param* t=nullptr;
        while(!finish || (size_t)accessQueue(m,q,SIZE)>0){
            while(q->size()>0){
                t = (Func_Param*)accessQueue(m,q,READ);
                (*func)(*t);
                accessQueue(m,q,POP);
                delete t;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    void deleteAll(){
        _finish=true;
        if(_joinOnDelete)
            for(auto it:_th)
                if(it->joinable()){
                    it->join();
                }
        for(int i=0; i<_th.size() && i<_muq.size(); i++){
            delete _th[i];
            delete _muq[i].first;
            delete _muq[i].second;
        }
    }

public:
    threadManager()=delete;
    threadManager(const threadManager&)=delete;

    threadManager(void (*func)(Func_Param), size_t nThreads, bool joinOnDelete = true):_joinOnDelete(joinOnDelete),_finish(false){
        if(nThreads==0 || func==nullptr) return;
        for(int i=0; i<nThreads; i++){
            std::mutex* m = new std::mutex();
            std::queue<Func_Param*>* q = new std::queue<Func_Param*>();
            _muq.push_back(std::pair<std::mutex*, std::queue<Func_Param*>* >(m, q));
            std::thread* th = new std::thread(&threadManager_Main, std::ref(_finish), func, m, q);
            if(!joinOnDelete)
                th->detach();
            _th.push_back(th);
        }
    }
    ~threadManager(){
        deleteAll();
    }

    void add(Func_Param var){
        if(_th.size()==0) return;
        size_t min_index = 0;
        size_t min=_muq[0].second->size();
        for(size_t i=0; i<_muq.size(); i++){
            size_t temp = _muq[i].second->size();
            if(temp < min){
                min_index = i;
                min = temp;
            }
            if(min==0)
                break;
        }
        accessQueue(_muq[min_index].first,_muq[min_index].second, PUSH, new Func_Param(var));
    }

    size_t remaining(){
        size_t t = 0;
        for(auto it:_muq)
            t+=it.second->size();
        return t;
    }
};

#endif // THMANAGER_H
