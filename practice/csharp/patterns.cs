// ============================================================
// Practice: Patterns
// Summary: right-angled triangle, centered pyramid.
// Run:     dotnet script practice/csharp/patterns.cs
// ============================================================

using System;

// ----- 1. Right-angled triangle of stars -----
void RightTriangle(int n)
{
    for (int i = 1; i <= n; i++)
        Console.WriteLine(new string('*', i));
}

// ----- 2. Centered pyramid of stars (height h) -----
void Pyramid(int h)
{
    for (int i = 1; i <= h; i++)
    {
        string spaces = new string(' ', h - i);
        string stars = new string('*', 2 * i - 1);
        Console.WriteLine(spaces + stars);
    }
}

Console.WriteLine("Right triangle (N=5):");
RightTriangle(5);
// *
// **
// ***
// ****
// *****

Console.WriteLine("Pyramid (height=5):");
Pyramid(5);
//     *
//    ***
//   *****
//  *******
// *********
