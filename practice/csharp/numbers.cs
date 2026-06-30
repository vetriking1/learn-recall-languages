// ============================================================
// Practice: Numbers
// Summary: prime check, multiplication table, Euclidean GCD.
// Run:     dotnet script practice/csharp/numbers.cs
// ============================================================

using System;

// ----- 1. Is a number prime? -----
bool IsPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; (long)i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// ----- 2. Multiplication table for n, 1..limit -----
void PrintTable(int n, int limit)
{
    for (int i = 1; i <= limit; i++)
        Console.WriteLine($"{n} x {i} = {n * i}");
}

// ----- 3. GCD via the Euclidean algorithm -----
int Gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Console.WriteLine($"{IsPrime(7)} {IsPrime(10)}"); // Output: True False
PrintTable(7, 10);                                 // 7 x 1 = 7 ... 7 x 10 = 70
Console.WriteLine(Gcd(48, 18));                    // Output: 6
