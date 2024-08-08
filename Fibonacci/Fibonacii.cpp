#include <iostream>
#include <unordered_map>
int iterFibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n <= 2)
    {
        return 1;
    }
    int res = 0;
    int first = 1;
    int second = 1;
    for (size_t i = 2; i < n; i++)
    {
        res = first + second;
        first = second;
        second = res;
    }
    return res;
}
int recFibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n <= 2)
    {
        return 1;
    }
    return recFibonacci(n-1) + recFibonacci(n-2);
}
int recFibonacciCashable(int n) 
{
    static std::unordered_map<int, int> cache;

    if (n == 0) 
    {
        return 0;
    }
    if (n <= 2) 
    {
        return 1;
    }

    if (cache.find(n) != cache.end()) 
    {
        return cache[n];
    }
    int result = recFibonacciCashable(n - 1) + recFibonacciCashable(n - 2);
    cache[n] = result;

    return result;
}


int main()
{
    // std::cout<<recFibonacci(6);
    std::cout<<recFibonacciCashable(6);
    // std::cout<<iterFibonacci(6);
}