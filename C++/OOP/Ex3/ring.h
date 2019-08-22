#pragma once
#include <iostream>
#include <string>

template<typename T>

class ring{

    private:
        unsigned m_capacity{};
        unsigned m_pos{};
        T *m_buf{};

    public:
        ring(unsigned capacity): 
            m_capacity{capacity}{
                m_buf = new T[capacity]{};
            }

        ring(const ring &o) :
            ring{o.m_capacity}
            {
                for(unsigned i = 0u; i < m_capacity; i++)
                    add(o.m_buf[i]);
                m_pos = o.m_pos;
            }

        ring &operator=(const ring &o){
            m_capacity = o.m_capacity;
            m_pos = 0u;
            delete[] m_buf;
            m_buf = new T[o.m_capacity]{};
            for(auto i = 0u; i < m_capacity; i++)
                add(o.m_buf[i]);
            
            m_pos = o.m_pos;
            return *this;
        }
        
        ~ring(){
            if(m_buf != nullptr) //redundant
                delete[] m_buf;
        }

        T at(unsigned index) const{
            if(index > m_capacity)
                throw std::string{"ring::get: index out of range"};
            return m_buf[index];
        }

        ring &add(T obj){
            if(m_capacity == 0u) return *this;
            m_buf[m_pos++] = obj;
            m_pos = m_pos % m_capacity;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &out, const ring &r){
            out << "Capacity: " << r.m_capacity << ", Pos: " << r.m_pos;
            out << std::endl;

            for(unsigned i = 0u; i < r.m_capacity; i++)
                out << r.m_buf[i] << " ";
            
            return out;

        }

        class iterator;

        iterator begin() { return iterator{0, *this}; }
        iterator end() { return iterator{m_capacity, *this}; }



};

template<typename T>
class ring<T>::iterator
{
    public:
        iterator(unsigned pos, ring &r) : 
            m_pos{pos},
            m_ring{r}
            {}
        ~iterator(){}

        T operator*() {return m_ring.at(m_pos);}
        bool operator == (const iterator &o) { return m_pos == o.m_pos; }
        bool operator != (const iterator &o) { return m_pos != o.m_pos; }
        iterator &operator++(int) { m_pos++; return *this; }
        iterator &operator++() { 
            iterator it = *this; 
            m_pos++; 
            return it; 
        }

    private:
        unsigned m_pos{};
        ring &m_ring;
};