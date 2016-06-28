#include<iostream>
#include<stdexcept>
#include<vector>

using namespace std;

template<class T>
class myVec
{
public:
	myVec(size_t cap = 10)
    {
        capacity = cap;
        ptr = new T [capacity];
        size = 0;
    }
	~myVec(){ delete [] ptr; }

	void resize(std::size_t newSize)
    {
        size = newSize;
    }
    
	void push_back(const T &obj)
    {
        ptr[size++] = obj;
    }
    
	void pop_back()
    {
        size--;
    }

	void insert(std::size_t idx,const T &obj)
    {
        T *temp = new T [size+1];
        for(size_t i =0;i<idx;i++)
            temp[i]=ptr[i];
        temp[idx] = obj;
        for(size_t i = idx;i<size;i++)
            temp[i+1]=ptr[i];
        delete [] ptr;
        size++;
        ptr = new T [size];
        for(size_t i = 0; i <size ; i++)
        {
            ptr[i]=temp[i];
        }
    }

	void erase(std::size_t idx)
    {
        T *temp = new T [capacity];
        size_t j=0;
        for(size_t i = 0; i <= size ; i++)
        {
            if(i == idx)
                continue;
            else
            {
                temp[j] = ptr[i];
                j++;
            }
        }
        delete [] ptr;
        ptr = new T [capacity];
        for(size_t i = 0; i < size ; i++)
        {
            ptr[i]=temp[i];
        }
        size--;
        delete [] temp;
    }

	size_t getSize()
    {
        return size;
    }

	void clear()
    {
        size = 0;
        capacity = 10;
        delete [] ptr;
        ptr = new T [capacity];
    }

	T& operator[](std::size_t idx)
    {
        if(idx <= capacity)
            return ptr[idx];
        else
        {
            out_of_range oor("incorrect index in operator[]!");
            throw oor;
        }
    }

	const T& operator[](std::size_t idx) const
    {
        if(idx <= capacity)
            return ptr[idx];
        else
        {
            out_of_range oor("incorrect index in operator[]!");
            throw oor;
        }

    }
	
protected:
    size_t capacity;
    size_t size;
    T *ptr;
};

class myStr : public myVec<char>
{
public:
	myStr()
    {
        capacity = 10;
        size = 0;
        ptr = new char[capacity];
    }
    
	myStr(char* inStr)
    {
        capacity = strlen(inStr)+1;
        size=strlen(inStr);
        for(size_t i = 0;i < size; i++)
        {
            ptr[i] = inStr[i];
        }
    }

    friend ostream& operator<<(ostream& os, const myStr& str)
    {
        for(size_t i = 0;i < str.size; i++)
        {
            os << str.ptr[i];
        }
        return os;
    }
    
    myStr &append(const myStr &str)
    {
        char *temp = new char[size+str.size];
        for(size_t i = 0; i < size; i++)
            temp[i] = ptr[i];
        for(size_t i = 0; i < str.size; i++)
            temp[i+size] = str.ptr[i];
        delete ptr;
        size = size+str.size;
        ptr = new char[size];
        for(size_t i = 0; i< size ; i++)
            ptr[i] = temp [i];
        return *this;
    }
};