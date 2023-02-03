#include "1Appello_fun.h"
#include <string>
#include <vector>
#include <list>
using std::vector;
using std::list;


list<const D* const> fun(const vector<const B*>& v) {
    list<const D* const> aux;
    int counter = 0;
    for(auto cit = v.begin(); cit != v.end(); cit++) {
        if(*cit) {
            if(dynamic_cast<const C*>(*cit)) {
                const_cast<B*>(*cit);
                v.erase((cit));
                ++counter;
                if(counter > 2 ) {
                    throw C();
                }
            }
            A* ptr = (*cit)->f();
            if(!ptr)
                throw std::string("nullptr");
            else if(ptr && dynamic_cast<D*>(ptr) && !dynamic_cast<E*>(ptr))
                aux.push_back(dynamic_cast<const D*>(ptr));
        }
    }
    return aux;
}