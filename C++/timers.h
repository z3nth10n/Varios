#ifndef TIMERS_H
#define TIMERS_H

#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

class chronometer{
    clock_t _ini, _fin, _temp;
    std::vector<uint32_t> _laps;
public:
    chronometer():_ini(0), _fin(0){}
    void start(){_ini = _temp = clock();}
    void stop(){_fin = clock();}
    void nextLap(){
        if(_fin!=0) return;
        _laps.push_back(clock()-_temp);
        _temp = clock();
    }
    uint32_t getLapCount(){return _laps.size();}
    uint32_t getLap(uint32_t n){return (_laps.size()>n && n>=0)?_laps[n]*1000/CLOCKS_PER_SEC:0;}
    uint32_t getTotal(){return ((_fin==0)?clock()-_ini:_fin-_ini)*1000/CLOCKS_PER_SEC;}
};

inline void thSleep(uint32_t ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

template<class T>std::thread* callbackAfter(uint32_t ms, void (*f)(T), T param){
    return new std::thread([](uint32_t time, void (*func)(T), T p){thSleep(time);(*func)(p);},ms,f,param);
}

#endif // TIMERS_H
