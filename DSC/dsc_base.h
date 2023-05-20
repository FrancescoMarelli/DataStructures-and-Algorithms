#ifndef _DSC_BASE_H_
#define _DSC_BASE_H_

#include <iostream>

template <class T>
class dsc_base{
    public:
    virtual bool empty() const = 0;
    virtual void insert(const &T) = 0;
    virtual T retrieve() const = 0;
    virtual std::ostream& write(std::ostream& os) const = 0;

    template <class U>
    friend std::ostream& operator<<(std::ostream&, dsc_base<U>& const);
};


     template <class T>
    std::ostream& operator<<(std::ostream& os, dsc_base<T>& const dsc){
        return dsc.write(os);
    }

#endif // _DSC_BASE_H_