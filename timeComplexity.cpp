#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

class Complexity{
	vector<double> results;  /// [-1,1]
	
public:

	string name;

	template<class F,class T>
	Complexity(F generator, unsigned int times, T start, T step, string _name = ""):name(_name){
		results.resize(times, 0.0);
		double max = 0;
		for(int i=0; i<times; i++, start+=step){
			results[i] = generator(start);
			if(abs(results[i])>max)
				max = abs(results[i]);
		}
		if(max>0){
			for(int i=0; i<results.size(); i++)
				results[i] /= max;
		}
	}
	
	Complexity(vector<double> r){
		results = r;
		double max = 0;
		for(int i=0; i<results.size(); i++)
			if(abs(results[i])>max)
				max = abs(results[i]);
		if(max>0){
			for(int i=0; i<results.size(); i++)
				results[i] /= max;
		}
	}
	
	const vector<double>& getResults() const {
		return results;
	}
	
	double compareTo(const Complexity& c) const {
		const vector<double>& r = c.getResults();
		double fitness = 0;
		for(int i=0; i<results.size() && i<r.size(); i++){
			fitness += abs(results[i]-r[i]);
		}
		return fitness;
	}
	
	double compareTo(map<int,int>& tests) const {
		double fitness = 0;
		int maxIndex = 0;
		double max = 0;
		for(auto it : tests){
		    if(it.first>maxIndex)
		        maxIndex = it.first;
		    if(it.second>max)
		        max = it.second;
		}
		if(max<=0)
		    max = 1.0;
		if(maxIndex<=0)
		    maxIndex = 1;
		for(auto it : tests){
			fitness += abs(results[(it.first*(results.size()-1))/maxIndex]-it.second/max);
		}
		return fitness;
	}
	
};

double bubbleSort(int n){
	if(n<1)
		return 0;
	vector<int> v(n, 0);
	for(int i=0; i<n; i++)
		v[i] = rand();
	
	clock_t cl = clock();
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(v[i]>v[j]){
				int t = v[i];
				v[i] = v[j];
				v[j] = v[i];
			}
	
	return clock()-cl;
}

vector<Complexity> complexities;

string test(Complexity comp){
	int cIndex = -1,
		minFitness = 0;
	for(int i=0; i<complexities.size(); i++){
		double t = comp.compareTo(complexities[i]);
		if(cIndex<0 || t<minFitness){
			cIndex = i;
			minFitness = t;
		}
	}
	if(cIndex<0)
		return "";
	return complexities[cIndex].name;
}

string test(map<int,int>& tests){ // tests : {{input,time},...}
	int cIndex = -1,
		minFitness = 0;
	for(int i=0; i<complexities.size(); i++){
		double t = complexities[i].compareTo(tests);
		if(cIndex<0 || t<minFitness){
			cIndex = i;
			minFitness = t;
		}
	}
	if(cIndex<0)
		return "";
	return complexities[cIndex].name;
}

void printFitnesses(Complexity c){
	for(const Complexity& comp : complexities){
		cout << comp.name << ": " << comp.compareTo(c) << endl;
	}
}

int main(){
	srand(time(0));
	int times = 50;
	complexities.push_back(Complexity([](int n)->double{ return 1; },            times,1,2, "O(1)"));
	complexities.push_back(Complexity([](int n)->double{ return log(n); },       times,1,2, "O(log n)"));
	complexities.push_back(Complexity([](int n)->double{ return n; },            times,1,2, "O(n)"));
	complexities.push_back(Complexity([](int n)->double{ return n*log(n); },     times,1,2, "O(n log n)"));
	complexities.push_back(Complexity([](int n)->double{ return n*n; },          times,1,2, "O(n^2)"));
	complexities.push_back(Complexity([](int n)->double{ return n*n * log(n); }, times,1,2, "O(n^2 log n)"));
	complexities.push_back(Complexity([](int n)->double{ return n*n*n; },        times,1,2, "O(n^3)"));
	complexities.push_back(Complexity([](int n)->double{ return pow(2, n); },    times,1,2, "O(2^n)"));
    
	Complexity bubbleComplexity(&bubbleSort, times,0,5000);
	Complexity c([](int n)->double{ return 2*log(n); }, times,1,1);
	printFitnesses(c);
	cout << "Winner: " << test(bubbleComplexity);
}
