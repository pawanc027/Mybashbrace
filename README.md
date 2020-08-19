Hello! Your task is to implement a similar behavior to bash’s brace expansion behavior as a runnable program.
Please use C++ as the language to implement this solution.
Your solution should contain build and run instructions and ideally be cross-platform.
Each test case will be a separate invocation of your program.
Input will be provided in single line read from stdin terminated by a LF. For a valid input, print the output to stdout followed by a LF.
For an invalid input, print nothing and exit.
For example, this is how your program should behave:
 $ echo "{A,B,C}" | your_program ABC
Examples of valid input and output:
{A,B,C} -> A B C {A,B}{C,D} -> AC AD BC BD {A,B{C,D}} -> A BC BD {ABC} -> ABC
        
   ABC -> ABC
Consider any input without properly matching braces to be invalid, and commas should only appear within braces.
Restrict the input character set to [a-zA-Z{},] , in other words only ASCII alpha characters, braces, and comma.
Braces should not be empty, and there should be no “empty” options within braces i.e. {A,}
Examples of invalid input:
}ABC {ABC
}{
{} A,B,C {A{B,C} {A,}
You may encounter additional edge cases, please ask if it is not clear what the behavior should be.
Implement tests that verify the implementation works according to the provided spec.
You may implement these however you see fit, but please write one for each of the provided cases, and ensure that they all pass.
       The code you write should be well structured and easy to read – your

solution should be one which would pass a code review.
