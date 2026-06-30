// ============================================================
// Topic:  Error Handling
// Summary: try/catch, throw, custom Exception, finally, wrap/rethrow.
// Run:     dotnet script csharp/18_error_handling.cs
//
// KEY DIFFERENCES:
//   C#:     try/catch/finally, throw, Exception hierarchy, when filter
//   Python: try/except/finally, raise, custom Exception subclass
//   TS/JS:  try/catch/finally, throw, Error subclass
//   Rust:   Result<T,E>, ? operator, panic! — no exceptions by default
//   Java:   try/catch/finally, throw, checked vs unchecked exceptions
// ============================================================

using System;

// ----- 1. Safe path — no exception -----
int SafeDivide(int a, int b) => a / b;
Console.WriteLine($"result: {SafeDivide(20, 2)}");     // result: 10 | normal return

// ----- 2. try/catch — handle DivideByZeroException -----
try
{
    SafeDivide(10, 0);                               // throws    | int division by zero
}
catch (DivideByZeroException)
{
    Console.WriteLine("caught: division by zero");   // caught    | specific handler
}

// ----- 3. Custom exception — throw and catch by type -----
class CustomBadException : Exception
{
    public CustomBadException(string message) : base(message) { }
}

try
{
    throw new CustomBadException("invalid");         // throw     | Python: raise CustomBad("invalid")
}
catch (CustomBadException ex)
{
    Console.WriteLine($"CustomBad: {ex.Message}");   // CustomBad: invalid
}

// ----- 4. finally — always runs (success or failure) -----
try
{
    int n = SafeDivide(30, 3);                       // succeeds  | finally still executes
    _ = n;
}
catch (DivideByZeroException)
{
    // not reached
}
finally
{
    Console.WriteLine("finally ran");                // finally ran | cleanup / guaranteed path
}

// ----- 5. Wrap and rethrow — inner fails, outer catches wrapped message -----
void RiskyWork()
{
    throw new InvalidOperationException("detail");   // inner     | original failure
}

try
{
    try
    {
        RiskyWork();
    }
    catch (Exception ex)
    {
        throw new ApplicationException("inner failed", ex);  // wrap | preserve InnerException
    }
}
catch (ApplicationException ex)
{
    Console.WriteLine($"outer: {ex.Message}");       // outer: inner failed | outer handler
}

// Cross-language note:
//   catch (Exception ex) catches all managed exceptions; order matters — most specific first.
//   `throw;` rethrows preserving stack trace; `throw ex;` resets it — prefer bare throw.
//   finally runs even with return/break in try; use using/IDisposable for resource cleanup too.
//   ApplicationException.InnerException holds the original — unwrap for full diagnostic chain.