It becomes harder to efficiently look through code when everybody is using their own variations of C style/syntax. It is suggested that everyone follow the style rules below.

+ Curly braces (i.e. "{") must be on the same line as the function definition, seperated by a space
  ```c
	void myFunction(int param1, int param2) {
  ```
+ Parameters must be seperated by a comma and a space, but must not have a space between them and a parenthesis
  ```c
	void myFunction(int param1, int param2) {
  ```
+ Use one tab for indentation (not spaces)
+ Functions should be seperated by exactly one newline
  ```c
	void myFunction(int param1, int param2) {
		int doStuff = param1 + param2;
	}
	
	void myFunction2(int param1, int param2) {
		int doStuff2 = param1 + param2;
	}
  ```
+ Operators and variables must be seperated by a space
  ```c
	int doStuff = param1 + param2;
  ```
+ If statements must not be seperated by a newline
+ Else ifs and elses must start on the same line that the previous if finished on
  ```c
	if (someCondition) {
		doStuff();
	} else if (someOtherCondition) {
		doSomethingElse();
	} else {
		doSomethingCompletelyDifferent();
	}
  ```
