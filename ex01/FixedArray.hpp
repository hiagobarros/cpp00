#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP

template<typename T, int N> class FixedArray
{
    private:
        T _arr[N];
    public:
        T& operator[](int index)
        {
            return _arr[index];
        }
        const T& operator[](int index) const 
        {
            return _arr[index];
        }
        int size() const 
        {
            return N;
        }
        T* begin()
        {
            return _arr;
        }
        T* end()
        {
            return _arr + N;
        }
        const T* begin() const
        {
            return _arr;
        }
        const T* end() const
        {
            return _arr + N;
        }
};

#endif

